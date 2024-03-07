#include "FAB_edit.h"

typedef vcg::AABBBinaryTreeIndex<CFaceO, float, vcg::EmptyClass> AABBTree;

DrawText_EditPlugin::DrawText_EditPlugin()
{
	qFont.setFamily("Helvetica");
	qFont.setPixelSize(12);

	have_press = false;
	picked_points.clear();
	picked_index = -1;
	have_picked = true;
	parameter_dialog = nullptr;
}

const QString DrawText_EditPlugin::Info()
{
	return tr("Add text model to all teeth mesh.");
}

void DrawText_EditPlugin::mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea* gla)
{
	have_press = false;
	picked_index = -1;
	have_picked = true;
}

void DrawText_EditPlugin::Decorate(MeshModel& m, GLArea* gla, QPainter* p)
{
	if (have_press)
	{
		vcg::Point3f clicked_vert_pos;
		bool result = vcg::Pick<vcg::Point3f>(cur.x(), gla->height() - cur.y(), clicked_vert_pos);

		if (result)
		{
			if (!have_picked) {
				picked_index = findNearest(clicked_vert_pos);
			}

			if (picked_index == -1) {
				if (picked_points.size() < 8) {
					picked_points.push_back(clicked_vert_pos);
				}
				have_press = false;
			}
			else {
				picked_points[picked_index] = clicked_vert_pos;
			}
		}

		have_picked = true; // 只要鼠标左键按下去就认为pick动作已经完成，直到左键松开，该pick动作才算作结束
	}

	glDisable(GL_LIGHTING);
	glColor4f(0, 1, 0, 0.5);
	for (int i = 0; i < 4 && i < picked_points.size(); ++i) {
		drawSphere(picked_points[i].X(), picked_points[i].Y(), picked_points[i].Z(), 0.6);
		vcg::glLabel::render(p, picked_points[i], QString::number(i + 1));
	}

	glColor4f(1, 0, 1, 0.5);
	for (int i = 4; i < picked_points.size(); ++i) {
		drawSphere(picked_points[i].X(), picked_points[i].Y(), picked_points[i].Z(), 0.6);
		vcg::glLabel::render(p, picked_points[i], QString::number(i + 1));
	}

	//glColor4f(1, 1, 0, 0.5);
	//for (int i = 0; i < points_up.size(); ++i) {
	//	drawSphere(points_up[i].X(),  points_up[i].Y(), points_up[i].Z(), 0.6);
	//	drawSphere(points_low[i].X(), points_low[i].Y(), points_low[i].Z(), 0.6);
	//}

	glEnable(GL_LIGHTING);
}

void DrawText_EditPlugin::mousePressEvent(QMouseEvent* event, MeshModel& m, GLArea* gla)
{
	gla->update();
	cur = event->pos();
	have_press = true;
	have_picked = false;
}

void DrawText_EditPlugin::createBase()
{
	std::cout << __FUNCTION__ << std::endl;
	if (picked_points.size() < 8) {
		return;
	}

	QStringList splitted_name = md->mm()->label().split('_');
	// V12 ^ V14
	vcg::Point3f move_dir = (picked_points[1] - picked_points[0]) ^ (picked_points[3] - picked_points[0]);
	move_dir = move_dir.Normalize() * 1.0;

	// move all models to same plane
	vcg::Plane3f plane;
	plane.Init(picked_points[3] - move_dir * 5, move_dir);
	for (MeshModel* m : md->meshList) {
		double move_distance = meshNearestDistanceToPlane(&m->cm, plane) - 5;
		vcg::Matrix44f mat;
		mat.SetTranslate(-move_dir * move_distance);
		vcg::tri::UpdatePosition<CMeshO>::Matrix(m->cm, mat);
	}
	md->resetTrackballFunc();

	auto createbase = [&](MeshModel* m, MeshModel*& base, std::vector<vcg::Point3f>& points) {
		if (base == nullptr) {
			return;
		}

		AABBTree* tree = new AABBTree();
		tree->Set(m->cm.face.begin(), m->cm.face.end());

		const AABBTree::ScalarType MAX_DISTANCE = std::numeric_limits<AABBTree::ScalarType>::max();
		vcg::EmptyClass a;
		vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
		AABBTree::ObjPtr isect_face = nullptr;
		AABBTree::ScalarType ray_len;

		std::vector<vcg::Point3f>points_up, points_low, points_up_, points_low_;
		vcg::Point3f start_up, start_low, start_mid;
		vcg::Point3f end_up, end_low, end_mid;

		start_up  = points[3] + move_dir * 0.1;
		start_low = points[2] + move_dir * 0.1;
		start_mid = (start_up + start_low) * 0.5;
		end_up  = points[0] + move_dir * 0.1;
		end_low = points[1] + move_dir * 0.1;
		end_mid = (end_up + end_low) * 0.5;

		double w = vcg::Distance(start_up, start_low);
		double interval = 2.0;
		int seg_count = vcg::Distance(start_mid, end_mid) / interval;
		double interval_up = vcg::Distance(start_up, end_up) / seg_count;
		double interval_low = vcg::Distance(start_low, end_low) / seg_count;
		vcg::Point3f dir_up, dir_low, dir_mid;
		dir_up  = (end_up - start_up).Normalize();
		dir_low = (end_low - start_low).Normalize();
		dir_mid = (end_mid - start_mid).Normalize();

		for (int i = 0; i <= seg_count; ++i) {
			vcg::Point3f up, low, mid;
			up  = start_up  + dir_up  * interval_up * i;
			low = start_low + dir_low * interval_low * i;
			mid = start_mid + dir_mid * interval * i;

			vcg::Point3f proj_dir_up, proj_dir_low;
			proj_dir_up  = (up  - mid).Normalize();
			proj_dir_low = (low - mid).Normalize();

			vcg::Ray3<AABBTree::ScalarType, false> ray_up(mid + proj_dir_up * w, -proj_dir_up);
			isect_face = tree->DoRay(rayIntersector, a, ray_up, MAX_DISTANCE, ray_len);
			if (isect_face) {
				points_up.push_back(mid + proj_dir_up * (w - ray_len));
			}
			else {
				points_up.push_back(up);
			}

			vcg::Ray3<AABBTree::ScalarType, false> ray_low(mid + proj_dir_low * w, -proj_dir_low);
			isect_face = tree->DoRay(rayIntersector, a, ray_low, MAX_DISTANCE, ray_len);
			if (isect_face) {
				points_low.push_back(mid + proj_dir_low * (w - ray_len));
			}
			else {
				points_low.push_back(low);
			}

			// update position position for text position
			points[0] = points_up.back();
			points[1] = points_low.back();
			points[2] = points_low.front();
			points[3] = points_up.front();

			// ray_up_ means ray_up move along move_dir 
			// move along move_dir and then along proj_dir_up to gum outside
			vcg::Ray3<AABBTree::ScalarType, false> ray_up_(mid + move_dir * 1.5 + proj_dir_up * w, -proj_dir_up);
			isect_face = tree->DoRay(rayIntersector, a, ray_up_, MAX_DISTANCE, ray_len);
			if (isect_face) {
				vcg::Point3f p1 = mid + move_dir * 1.5 + proj_dir_up * (w - ray_len);
				points_up_.push_back(p1);
			}
			else {
				points_up_.push_back(up + move_dir * 1.5);
			}

			vcg::Ray3<AABBTree::ScalarType, false> ray_low_(mid + move_dir * 1.5 + proj_dir_low * w, -proj_dir_low);
			isect_face = tree->DoRay(rayIntersector, a, ray_low_, MAX_DISTANCE, ray_len);
			if (isect_face) {
				vcg::Point3f p1 = mid + move_dir * 1.5 + proj_dir_low * (w - ray_len);
				points_low_.push_back(p1);
			}
			else {
				points_low_.push_back(low + move_dir * 1.5);
			}
		}

		CMeshO::VertexIterator vit = vcg::tri::Allocator<CMeshO>::AddVertices(base->cm, points_low.size() * 4);
		CMeshO::FaceIterator   fit = vcg::tri::Allocator<CMeshO>::AddFaces(base->cm, points_low.size() * 8 - 4);
		std::vector<CMeshO::VertexPointer> vert_point_up, vert_point_low, vert_point_up_, vert_point_low_;
		for (int i = 0; i < points_up.size(); ++i) {
			vit->P() = points_up[i];
			vert_point_up.push_back(&*vit);
			vit++;
		}

		for (int i = 0; i < points_low.size(); ++i) {
			vit->P() = points_low[i];
			vert_point_low.push_back(&*vit);
			vit++;
		}
		for (int i = 0; i < points_up_.size(); ++i) {
			vit->P() = points_up_[i];
			vert_point_up_.push_back(&*vit);
			vit++;
		}

		for (int i = 0; i < points_low_.size(); ++i) {
			vit->P() = points_low_[i];
			vert_point_low_.push_back(&*vit);
			vit++;
		}

		connectVert(vert_point_up, vert_point_low, fit);
		connectVert(vert_point_low, vert_point_low_, fit);
		connectVert(vert_point_low_, vert_point_up_, fit);
		connectVert(vert_point_up_, vert_point_up, fit);

		fit->V(0) = vert_point_up[0];
		fit->V(1) = vert_point_up_[0];
		fit->V(2) = vert_point_low_[0];
		fit++;

		fit->V(0) = vert_point_up[0];
		fit->V(1) = vert_point_low_[0];
		fit->V(2) = vert_point_low[0];
		fit++;

		fit->V(0) = vert_point_up_.back();
		fit->V(1) = vert_point_up.back();
		fit->V(2) = vert_point_low.back();
		fit++;

		fit->V(0) = vert_point_up_.back();
		fit->V(1) = vert_point_low.back();
		fit->V(2) = vert_point_low_.back();
		fit++;
	};

	// create base
	#pragma omp parallel for num_threads(8)
	for (int i = 0; i < md->meshList.size(); ++i)
	{
		MeshModel* m = md->meshList.at(i);
		//qDebug() << QString("Thread %1, deal With %2").arg(omp_get_thread_num()).arg(m->label());
		MeshModel* base_right = new MeshModel(md, "", QString("base_right_") + m->label());
		std::vector<vcg::Point3f> pick_points_proj;
		std::vector<vcg::Point3f> points_right(picked_points.begin(), picked_points.begin() + 4);
		createbase(m, base_right, points_right);
		right_base_map.insert({ base_right->label(), &base_right->cm });

		std::vector<vcg::Point3f> points_left(picked_points.begin() + 4, picked_points.end());
		MeshModel* base_left = new MeshModel(md, "", QString("base_left_") + m->label());
		createbase(m, base_left, points_left);
		left_base_map.insert({ base_left->label(), &base_left->cm });

		pick_points_proj.assign(points_right.begin(), points_right.end());
		pick_points_proj.insert(pick_points_proj.begin() + 4, points_left.begin(), points_left.end());
		picked_points_proj_map.insert({ m->label(), pick_points_proj });
	}

	int ret = QMessageBox::information(this->gla, tr("Information"),
		tr("Succesfully Create Base Model."), QMessageBox::Ok);
}

void DrawText_EditPlugin::exportBase()
{
	std::cout << __FUNCTION__ << std::endl;
	QString id = parameter_dialog_ui.lineEdit_id ? parameter_dialog_ui.lineEdit_id->text() : "000000";

	QString outfile_dir = QFileDialog::getExistingDirectory(this->gla, tr("Save Directory.."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (outfile_dir.isNull() || outfile_dir.isEmpty()) {
		return;
	}

	if (picked_points.size() < 8) { // only change model names
		int model_count = parameter_dialog_ui.tableWidget_modelNames->rowCount();
		for (int row = 0; row < model_count; row++) {
			QTableWidgetItem* item = parameter_dialog_ui.tableWidget_modelNames->item(row, 0);
			QString model_file_name = item->text();

			item = parameter_dialog_ui.tableWidget_modelNames->item(row, 1);
			QString jaw = item->text();

			item = parameter_dialog_ui.tableWidget_modelNames->item(row, 2);
			QString step = item->text();
			step = step.split(' ', QString::SkipEmptyParts).join("");// remove space within step string

			item = parameter_dialog_ui.tableWidget_modelNames->item(row, 3);
			Qt::CheckState is_template = item->checkState();

			MeshModel* export_mesh = md->meshList.at(row);
			QString model_path = outfile_dir + QString("/%3_%1_%2.stl").arg(jaw).arg(step).arg(id);

			std::string model_path_str = model_path.toLocal8Bit().constData();
			int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(export_mesh->cm, model_path_str.c_str(), true);
			if (result != 0) {
				std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
			}
		}
		return;
	}

	double ratio_X = 0.6;
	double ratio_Y = 0.7;
	double text_char_model_width  = 4;
	double text_char_model_height = 6;

	struct PositionInfo {
		double width_space;   // space between next character 
		double width_margin;  // space to base border
		double height_margin;
		vcg::Point3f row_dir;
		vcg::Point3f col_dir;
		vcg::Matrix44f mat;
		int text_character_length;
	};

	auto computeTextPos = [&](std::vector<vcg::Point3f>& points, PositionInfo& pos_info) {
		if (points.size() != 4) {
			return;
		}

		vcg::Point3f x = (points[2] + points[3]) - (points[0] + points[1]);
		x = x.Normalize();
		vcg::Point3f z = x ^ (points[1] - points[0]);
		z = z.Normalize();
		vcg::Point3f y = z ^ x;
		y = y.Normalize();

		double height = (points[2] - points[3]) * y;

		pos_info.width_margin = 2;
		pos_info.width_space  = 2.3;

		pos_info.row_dir = (points[0] + points[1]) - (points[2] + points[3]);
		pos_info.row_dir = pos_info.row_dir.Normalize();
		pos_info.col_dir = points[2] - points[3];
		pos_info.col_dir = pos_info.col_dir.Normalize();

		text_char_model_width  *= ratio_X;
		text_char_model_height *= ratio_Y;
		pos_info.height_margin = (height - text_char_model_height) / 2.0;

		vcg::Matrix44f mat;
		mat.SetIdentity();
		mat[0][0] = -x[0];
		mat[1][0] = -x[1];
		mat[2][0] = -x[2];

		mat[0][1] = -y[0];
		mat[1][1] = -y[1];
		mat[2][1] = -y[2];

		mat[0][2] = z[0];
		mat[1][2] = z[1];
		mat[2][2] = z[2];

		mat[0][3] = points[3][0];
		mat[1][3] = points[3][1];
		mat[2][3] = points[3][2];

		vcg::Matrix44f mat_scale;
		mat_scale.SetScale(ratio_X, ratio_Y, 1.2);
		pos_info.mat = mat * mat_scale;
	};

	// compute text's default place information 
	PositionInfo left_pos_info, right_pos_info;
	computeTextPos(std::vector<vcg::Point3f>(picked_points.begin(), picked_points.begin() + 4), right_pos_info);
	computeTextPos(std::vector<vcg::Point3f>(picked_points.begin() + 4, picked_points.end()), left_pos_info);
	right_pos_info.text_character_length = 4;
	left_pos_info.text_character_length  = 6;

	// import text model
	std::vector<MeshModel*> text_char_model_vector; // 0~9 for id char from '0' to '9' and  10,11,12 for id char 'U ' 'L' 'T' 
	for (int i = 0; i < 13; ++i) {
		QString model_name;;
		if (i < 10) {
			model_name = QString::number(i);
		}
		else if (i == 10) {
			model_name = QString("U");
		}
		else if (i == 11) {
			model_name = QString("L");
		}
		else {
			model_name = QString("T");
		}

		QString model_path = QCoreApplication::applicationDirPath().toLocal8Bit() + "/textmodel/" + model_name + ".stl";
		QByteArray model_path_byte_array = model_path.toLatin1();
		char* model_path_char;
		model_path_char = model_path_byte_array.data();

		MeshModel* id_char_model = new MeshModel(md, model_name, model_name);
		int load_mask = 0;
		int result_import = vcg::tri::io::ImporterSTL<CMeshO>::Open(id_char_model->cm, model_path_char, load_mask);
		if (result_import != 0) {
			std::cout << vcg::tri::io::ImporterSTL<CMeshO>::ErrorMsg(result_import) << std::endl;
		}
		text_char_model_vector.push_back(id_char_model);
	}

	int model_count = parameter_dialog_ui.tableWidget_modelNames->rowCount();
	#pragma omp parallel for num_threads(8)
	for (int row = 0; row < model_count; row++)
	{
		QTableWidgetItem* item  = parameter_dialog_ui.tableWidget_modelNames->item(row, 0);
		QString model_file_name = item->text();

		item = parameter_dialog_ui.tableWidget_modelNames->item(row, 1);
		QString jaw = item->text();

		item = parameter_dialog_ui.tableWidget_modelNames->item(row, 2);
		QString step = item->text();
		step = step.split(' ', QString::SkipEmptyParts).join("");// remove space within step string

		item = parameter_dialog_ui.tableWidget_modelNames->item(row, 3);
		Qt::CheckState is_template = item->checkState();

		MeshModel* m = md->meshList.at(row);
		if (m == 0) {
			qDebug() << " Can't find mesh model at given row!";
			continue;
		}
		qDebug() << QString("Thread %4, Deal with %1, Jaw %2, Step %3").arg(model_file_name).arg(jaw).arg(step).arg(omp_get_thread_num());

		// compute text's place information 
		if (picked_points_proj_map.find(m->label()) != picked_points_proj_map.end()) {
			std::vector<vcg::Point3f>& picked_points_proj = picked_points_proj_map[m->label()];
			computeTextPos(std::vector<vcg::Point3f>(picked_points_proj.begin(), picked_points_proj.begin() + 4), right_pos_info);
			computeTextPos(std::vector<vcg::Point3f>(picked_points_proj.begin() + 4, picked_points_proj.end()), left_pos_info);
		}

		CMeshO* export_mesh = new CMeshO();
		if (right_base_map.find("base_right_" + m->label()) == right_base_map.end() ||
			left_base_map.find("base_left_" + m->label()) == left_base_map.end()) {
			qDebug() << "Map Can't find mesh model accroding given name!";
			continue;
		}

		//generate base MeshModel and its Eigen matrix
		CMeshO* base_right = right_base_map["base_right_" + m->label()];
		CMeshO* base_left  = left_base_map["base_left_" + m->label()];
		Eigen::MatrixXd base_left_V, base_right_V;
		Eigen::MatrixXi base_left_F, base_right_F;
		changeCMeshOToEigenMatrix(base_left, base_left_V, base_left_F);
		changeCMeshOToEigenMatrix(base_right, base_right_V, base_right_F);
		Eigen::VectorXi J;

		// copy id to left base
		CMeshO* content_on_left_base = new CMeshO();
		bool boolean_res;
		for (int i = 0; i < id.size(); ++i) {
			bool ok;
			int num = id.mid(i, 1).toInt(&ok, 10);
			if (!ok) {
				qDebug() << "ID shouldn't include characters that are not numbers.";
				continue;
			}

			vcg::Point3f trans_vec = left_pos_info.row_dir * (left_pos_info.width_margin + 0.5 * text_char_model_width + i * (left_pos_info.width_space + text_char_model_width))
				+ left_pos_info.col_dir * (left_pos_info.height_margin + text_char_model_height * 0.5);
			vcg::Matrix44f mat_trans;
			mat_trans.SetTranslate(trans_vec);

			CMeshO* char_mesh_translated = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*char_mesh_translated, text_char_model_vector[num]->cm);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(*char_mesh_translated, mat_trans * left_pos_info.mat);
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*content_on_left_base, *char_mesh_translated);
			delete char_mesh_translated;
		}

		//do left side boolean
		Eigen::MatrixXd left_V;
		Eigen::MatrixXi left_F;
		changeCMeshOToEigenMatrix(content_on_left_base, left_V, left_F);
		boolean_res = igl::copyleft::cgal::mesh_boolean(base_left_V.eval(), base_left_F.eval(), left_V, left_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_left_V, base_left_F, J);
		if (!boolean_res)
		{
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*base_left, *content_on_left_base);
		}
		delete content_on_left_base;

		// copy jaw to right base
		CMeshO* content_on_right_base = new CMeshO();
		{
			int num = jaw == QString('U') ? 10 : 11;
			vcg::Point3f trans_vec = right_pos_info.row_dir * (right_pos_info.width_margin + 0.5 * text_char_model_width)
				+ right_pos_info.col_dir * (right_pos_info.height_margin + text_char_model_height * 0.5);
			vcg::Matrix44f mat_trans;
			mat_trans.SetTranslate(trans_vec);

			CMeshO* char_mesh_translated = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*(char_mesh_translated), text_char_model_vector[num]->cm);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(*char_mesh_translated, mat_trans * right_pos_info.mat);
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*content_on_right_base, *char_mesh_translated);
			delete char_mesh_translated;
		}

		// copy step to right base
		int step_i = 0;
		for (step_i = 0; step_i < step.size(); ++step_i) {
			bool ok;
			int num = step.mid(step_i, 1).toInt(&ok, 10);
			if (!ok) {
				qDebug() << "Can't convert step string to a number, please check the input file name.";
				continue;
			}

			vcg::Point3f trans_vec = right_pos_info.row_dir * (right_pos_info.width_margin + 0.5 * text_char_model_width +
				(step_i + 1) * (right_pos_info.width_space + text_char_model_width)) +
				right_pos_info.col_dir * (right_pos_info.height_margin + text_char_model_height * 0.5);
			vcg::Matrix44f mat_trans;
			mat_trans.SetTranslate(trans_vec);

			CMeshO* char_mesh_translated = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*(char_mesh_translated), text_char_model_vector[num]->cm);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(*char_mesh_translated, mat_trans * right_pos_info.mat);
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*content_on_right_base, *char_mesh_translated);
			delete char_mesh_translated;
		}

		if (is_template == Qt::Checked) {
			int num = 12;
			vcg::Point3f trans_vec = right_pos_info.row_dir * (right_pos_info.width_margin + 0.5 * text_char_model_width +
				(step_i + 1) * (right_pos_info.width_space + text_char_model_width)) +
				right_pos_info.col_dir * (right_pos_info.height_margin + text_char_model_height * 0.5);
			vcg::Matrix44f mat_trans;
			mat_trans.SetTranslate(trans_vec);

			CMeshO* char_mesh_translated = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*(char_mesh_translated), text_char_model_vector[num]->cm);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(*char_mesh_translated, mat_trans * right_pos_info.mat);
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*content_on_right_base, *char_mesh_translated);
			delete char_mesh_translated;
		}

		// do right side boolean
		Eigen::MatrixXd right_V;
		Eigen::MatrixXi right_F;
		changeCMeshOToEigenMatrix(content_on_right_base, right_V, right_F);
		boolean_res = igl::copyleft::cgal::mesh_boolean(base_right_V.eval(), base_right_F.eval(), right_V, right_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_right_V, base_right_F, J);
		if (!boolean_res)
		{
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*base_right, *content_on_right_base);
		}
		delete content_on_right_base;

		//merge with origin mesh
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*export_mesh, m->cm);
		mergeCMeshWithEigenVector(export_mesh, base_left_V, base_left_F);
		mergeCMeshWithEigenVector(export_mesh, base_right_V, base_right_F);

		// get output path and export final mesh
		QString model_path = outfile_dir + QString("/%3_%1_%2.stl").arg(jaw).arg(step).arg(id);

		std::string model_path_str = model_path.toLocal8Bit().constData();
		int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*export_mesh, model_path_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}
	}

	int ret = QMessageBox::information(this->gla, tr("Information"),
		tr("Successfully Export."), QMessageBox::Ok);
}

int DrawText_EditPlugin::findNearest(const vcg::Point3f& p)
{
	int nearestIndex = -1;
	float nearestDist = std::numeric_limits<float>::max();
	for (int i = 0; i < picked_points.size(); ++i) {
		if (vcg::Distance(picked_points.at(i), p) < nearestDist) {
			nearestDist = vcg::Distance(picked_points.at(i), p);
			nearestIndex = i;
		}
	}
	return nearestDist < 0.5 ? nearestIndex : -1;
}

bool DrawText_EditPlugin::StartEdit(MeshDocument& md, GLArea* gla, MLSceneGLSharedDataContext* /*cont*/)
{
	if (md.meshList.isEmpty()) {
		return false;
	}

	connect(this, SIGNAL(suspendEditToggle()), gla, SLOT(suspendEditToggle()));

	this->md = &md;
	this->gla = gla;
	if (parameter_dialog == nullptr) {
		parameter_dialog = new QDialog();
		parameter_dialog_ui.setupUi(parameter_dialog);

		// split model names and show them in given tableResizeToContents
		//parameter_dialog_ui.tableWidget_modelNames->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
		parameter_dialog_ui.tableWidget_modelNames->setColumnWidth(0, 150);
		parameter_dialog_ui.tableWidget_modelNames->setColumnWidth(1, 60);
		parameter_dialog_ui.tableWidget_modelNames->setColumnWidth(2, 90);
		parameter_dialog_ui.tableWidget_modelNames->setColumnWidth(3, 90);
		parameter_dialog_ui.tableWidget_modelNames->setColumnWidth(4, 100);

		parameter_dialog_ui.tableWidget_modelNames->setRowCount(md.meshList.size());
		for (int row_count = 0; row_count < md.meshList.size(); ++row_count) {
			MeshModel* m = md.meshList.at(row_count);
			QString name_without_suffix = m->label().split('.')[0];
			QStringList splitted_name = name_without_suffix.split('_');
			if (splitted_name.size() < 3) {
				continue;
			}
			QString jaw = splitted_name[1];
			QString step = splitted_name[2];
			QTableWidgetItem* item_is_template = new QTableWidgetItem(QApplication::translate("DrawTextParameterDialog", "\346\230\257\346\250\241\346\235\277", Q_NULLPTR));
			item_is_template->setCheckState(Qt::Unchecked);
			parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 0, new QTableWidgetItem(m->label()));
			parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 1, new QTableWidgetItem(jaw));
			parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 2, new QTableWidgetItem(step));
			parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 3, item_is_template);
		}

		connect(parameter_dialog_ui.pushButton_create_base, &QPushButton::clicked, this, &DrawText_EditPlugin::createBase);
		connect(parameter_dialog_ui.pushButton_export_base, &QPushButton::clicked, this, &DrawText_EditPlugin::exportBase);
		connect(parameter_dialog_ui.pushButton_refreshLoadmodels, &QPushButton::clicked, this, [&]() {
			parameter_dialog_ui.tableWidget_modelNames->clearContents();
			parameter_dialog_ui.tableWidget_modelNames->setRowCount(md.meshList.size());
			for (int row_count = 0; row_count < md.meshList.size(); ++row_count) {
				MeshModel* m = md.meshList.at(row_count);
				qDebug() << m->label();
				QString name_without_suffix = m->label().split('.')[0];
				QStringList splitted_name = name_without_suffix.split('_');
				if (splitted_name.size() < 3) {
					continue;
				}
				QString jaw = splitted_name[1];
				QString step = splitted_name[2];
				QTableWidgetItem* item_is_template = new QTableWidgetItem(QApplication::translate("DrawTextParameterDialog", "\346\230\257\346\250\241\346\235\277", Q_NULLPTR));
				item_is_template->setCheckState(Qt::Unchecked);
				parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 0, new QTableWidgetItem(m->label()));
				parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 1, new QTableWidgetItem(jaw));
				parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 2, new QTableWidgetItem(step));
				parameter_dialog_ui.tableWidget_modelNames->setItem(row_count, 3, item_is_template);
			}
			parameter_dialog_ui.tableWidget_modelNames->update();
			});

		connect(parameter_dialog_ui.pushButton_addOvercorrectionModels, &QPushButton::clicked, this, [&]() {
			int model_count = parameter_dialog_ui.tableWidget_modelNames->rowCount();
			for (int row = 0; row < model_count; row++) {
				QTableWidgetItem* item = parameter_dialog_ui.tableWidget_modelNames->item(row, 1);
				QString jaw = item->text();

				item = parameter_dialog_ui.tableWidget_modelNames->item(row, 2);
				QString step = item->text();
				step = step.split(' ', QString::SkipEmptyParts).join("");// remove space within step string
				int start_step = step.toInt() + 1;

				item = parameter_dialog_ui.tableWidget_modelNames->item(row, 4);
				MeshModel* m = md.meshList.at(row);
				if (item != nullptr) {
					int end_step = step.toInt() + item->text().toInt();
					for (int i = start_step; i <= end_step; i++)
					{
						QString name = parameter_dialog_ui.lineEdit_id->text() + '_' + jaw + '_' + QString::number(i);
						MeshModel* copy_model = md.addNewMesh(name, name, false);
						vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(copy_model->cm, m->cm);

						parameter_dialog_ui.tableWidget_modelNames->insertRow(model_count);
						QTableWidgetItem* item_is_template = new QTableWidgetItem(QApplication::translate("DrawTextParameterDialog", "\346\230\257\346\250\241\346\235\277", Q_NULLPTR));
						item_is_template->setCheckState(Qt::Unchecked);
						parameter_dialog_ui.tableWidget_modelNames->setItem(model_count, 0, new QTableWidgetItem(copy_model->label()));
						parameter_dialog_ui.tableWidget_modelNames->setItem(model_count, 1, new QTableWidgetItem(jaw));
						parameter_dialog_ui.tableWidget_modelNames->setItem(model_count, 2, new QTableWidgetItem(QString::number(i)));
						parameter_dialog_ui.tableWidget_modelNames->setItem(model_count, 3, item_is_template);
						model_count++;
					}
					parameter_dialog_ui.tableWidget_modelNames->update();
					break;
				}
			}
			});
	}
	parameter_dialog->show();
	return true;
}

void DrawText_EditPlugin::EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/)
{
	have_picked = true;
	have_press = false;
	picked_index = -1;
	if (parameter_dialog) {
		parameter_dialog->hide();
	}
}

/**********************************************************************************************************/
DrawCurve_EditPlugin::DrawCurve_EditPlugin()
{
	parameter_widget = nullptr;
	isdbclicked = false;                  // 是否双击
	isleftdown = false;                   // 左侧鼠标是否按下
	hasPicked = false;                    // 鼠标左键按下后，已经找到最近的点
	pickedIndex = -1;                     // 选中点的索引
	interval = 0.5;

	mode = EMPTY;
	current_mesh_index = 0;
}

DrawCurve_EditPlugin::~DrawCurve_EditPlugin()
{

}

bool DrawCurve_EditPlugin::StartEdit(MeshDocument& md, GLArea* gla, MLSceneGLSharedDataContext* cont)
{
	this->gla = gla;
	this->md = &md;
	this->context = cont;

	if (md.meshList.isEmpty()) {
		return false;
	}

	if (parameter_widget == nullptr) {
		parameter_widget = new QDockWidget();
		parameter_widget_ui.setupUi(parameter_widget);
		md.emitAddNewDockWidget(parameter_widget, true);

		std::sort(md.meshList.begin(), md.meshList.end(), [](MeshModel* a, MeshModel* b) {
			QStringList data_a = a->label().mid(0, a->label().lastIndexOf('.')).split('_');
			QStringList data_b = b->label().mid(0, b->label().lastIndexOf('.')).split('_');

			if (data_a.size() >= 3 && data_b.size() >= 3) {
				bool res_a, res_b;
				int step_a = data_a[2].toInt(&res_a, 10);
				int step_b = data_b[2].toInt(&res_b, 10);
				if (res_a && res_b) {
					return step_a < step_b;
				}
				else {
					return a->label() < b->label();
				}
			}
			else {
				return a->label() < b->label();
			}
			});
		md.setCurrentMesh(md.meshList.front()->id());
		parameter_widget_ui.label_currentModel->setText(md.mm()->label());

		// set file path
		QString full_path = md.mm()->pathName();
		QString dirname = full_path.split('/').back();
		parameter_widget_ui.lineEdit_PatientID->setText(dirname);

		//show only one model
		#pragma omp parallel for num_threads(20)
		for (int i = 0; i < md.meshList.size(); ++i) {
			qDebug() << QString("Thread %1, Deal with model %2").arg(omp_get_thread_num()).arg(i);

			MeshModel* current_model = md.meshList.at(i);
			vcg::tri::Clean<CMeshO>::RemoveDuplicateVertex(current_model->cm);
			vcg::tri::Allocator<CMeshO>::CompactEveryVector(current_model->cm);
			current_model->updateDataMask(MeshModel::MM_FACEFACETOPO);

			if (current_model == md.mm()) {
				current_model->visible = true;
			}
			else {
				current_model->visible = false;
			}

			// clear all data for cutline and laser mark
			current_model->curveDir.clear();
			current_model->curve.clear();
			current_model->ctrlPoints.clear();
			current_model->pointsForLaser.clear();
		}

		md.refreshMeshList();
		gla->update();

		connect(parameter_widget_ui.pushButton_pickAlignPoints, &QPushButton::clicked, this, [&]() {
			mode = PICK_ALIGN;
			std::cout << "in picking align point mode \n";
			});

		connect(parameter_widget_ui.pushButton_pickCutline, &QPushButton::clicked, this, [&]() {
			mode = DRAW;
			std::cout << "in drawing curve mode \n";
			});

		connect(parameter_widget_ui.pushButton_pickLaserPosition, &QPushButton::clicked, this, [&]() {
			mode = PICK_LASER;
			std::cout << "in picking marking position mode \n";
			});

		connect(parameter_widget_ui.pushButton_eruptionCtrlPoints, &QPushButton::clicked, this, [&]() {
			std::cout << "in picking eruption control points mode \n";
			mode = PICK_ERUPTION;
			pointsForEruption.clear();

			parameter_widget_ui.doubleSpinBox_tx->setValue(0.0);
			parameter_widget_ui.doubleSpinBox_ty->setValue(0.0);
			parameter_widget_ui.doubleSpinBox_tz->setValue(0.0);

			parameter_widget_ui.doubleSpinBox_rx->setValue(0.0);
			parameter_widget_ui.doubleSpinBox_ry->setValue(0.0);
			parameter_widget_ui.doubleSpinBox_rz->setValue(0.0);

			parameter_widget_ui.doubleSpinBox_sx->setValue(1.0);
			parameter_widget_ui.doubleSpinBox_sy->setValue(1.0);
			parameter_widget_ui.doubleSpinBox_sz->setValue(1.0);
			});

		connect(parameter_widget_ui.pushButton_moveup, &QPushButton::clicked, this, [&]() {
			MeshModel* current_model = md.mm();
			moveDownGumLine(current_model, -0.1);
			});

		connect(parameter_widget_ui.pushButton_movedown, &QPushButton::clicked, this, [&]() {
			MeshModel* current_model = md.mm();
			moveDownGumLine(current_model, 0.1);
			});

		connect(parameter_widget_ui.pushButton_cleanCurrentLine, &QPushButton::clicked, this, [&]() {
			MeshModel* current_model = md.mm();
			current_model->curve.clear();
			current_model->ctrlPoints.clear();
			current_model->curveDir.clear();
			});

		connect(parameter_widget_ui.pushButton_splitModel, &QPushButton::clicked, this, [&]() {
			splitMeshAndSave(this->md);
			});
		connect(parameter_widget_ui.pushButton_mergeModel, &QPushButton::clicked, this, [&]() {
			MergeMesh();
			});

		connect(parameter_widget_ui.pushButton_alignModel, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotAlignAllModels);
		connect(parameter_widget_ui.pushButton_exportCutline, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotExport);
		connect(parameter_widget_ui.pushButton_lastModel, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotLastModel);
		connect(parameter_widget_ui.pushButton_nextModel, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotNextModel);
		connect(parameter_widget_ui.pushButton_putEruption, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotPutEruption);
		connect(parameter_widget_ui.pushButton_importCtrlPoints, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotImportCtrlPoints);
		connect(parameter_widget_ui.pushButton_putCutLabel, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotPutLabelModels);
		connect(parameter_widget_ui.pushButton_computeCtrlPoints, &QPushButton::clicked, this, &DrawCurve_EditPlugin::slotComputeCtrlPoints);

		connect(parameter_widget_ui.doubleSpinBox_tx, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_ty, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_tz, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);

		connect(parameter_widget_ui.doubleSpinBox_rx, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_ry, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_rz, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);

		connect(parameter_widget_ui.doubleSpinBox_sx, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_sy, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);
		connect(parameter_widget_ui.doubleSpinBox_sz, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotTransformEruption);

		connect(parameter_widget_ui.doubleSpinBox_midHeight_buccal, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotChangeGumHeight);
		connect(parameter_widget_ui.doubleSpinBox_midHeight_lingual, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &DrawCurve_EditPlugin::slotChangeGumHeight);

	}
	else {
		parameter_widget->show();
		parameter_widget->raise();
	}
	return true;
}

void DrawCurve_EditPlugin::EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/)
{
	if (parameter_widget) {
		parameter_widget->hide();
	}
}

void DrawCurve_EditPlugin::Decorate(MeshModel& m, GLArea* gla, QPainter* p)
{
	switch (mode) {
	case EMPTY: return;
	case PICK_ALIGN:	pickAlignPoints(gla, p);			return;
	case DRAW:			drawCurve(gla);						return;
	case PICK_LASER:	pickLaserPoints(gla, p);			return;
	case PICK_ERUPTION: pickEruptionPoints(gla, p);			return;
	case CONTINUE_DRAW:										return;
	case SHOW_ERUPTION: [&]() {
		if (m.eruption_rotation_mat.size() == m.eruption_scale_mat.size() && m.eruption_rotation_mat.size() == m.eruption_trans_mat.size()) {
			for (int i = 0; i < m.eruption_rotation_mat.size(); ++i) {
				//绘制萌出帽模型
				drawEllipsoid(5, 2.5, 2.5, m.eruption_mat.at(i));
			}

			//绘制可编辑的模型（暂时定义为最后一个）的局部坐标系
			vcg::MovableCoordinateFrame mcf(8);
			vcg::Point3f x = m.eruption_mat.back() * vcg::Point3f(1.0, 0.0, 0.0) - m.eruption_mat.back() * vcg::Point3f(0.0, 0.0, 0.0);
			vcg::Point3f y = m.eruption_mat.back() * vcg::Point3f(0.0, 1.0, 0.0) - m.eruption_mat.back() * vcg::Point3f(0.0, 0.0, 0.0);
			mcf.AlignWith(x.Normalize(), y.Normalize(), 'X', 'Y');
			mcf.SetPosition(m.eruption_mat.back() * vcg::Point3f(0.0, 0.0, 0.0));
			mcf.Render(gla, p);
		}
	}();							return;
	};
}

void DrawCurve_EditPlugin::mousePressEvent(QMouseEvent* e, MeshModel&, GLArea* gla)
{
	curPoint.X() = e->pos().x();
	curPoint.Y() = e->pos().y();

	if (e->button() == Qt::LeftButton) {
		isleftdown = true;
	}
	else if (e->button() == Qt::RightButton) {
		isrightdown = true;
	}

	hasPicked = false;
	pickedIndex = -1;
}

void DrawCurve_EditPlugin::mouseMoveEvent(QMouseEvent* e, MeshModel&, GLArea* gla)
{
	curPoint = vcg::Point2f(e->pos().x(), e->pos().y());
}

void DrawCurve_EditPlugin::mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*)
{
	isleftdown = false;
	isrightdown = false;
	pickedIndex = -1;
	hasPicked = true;
}

void DrawCurve_EditPlugin::mouseDoubleClickEvent(QMouseEvent* event, MeshModel&, GLArea*)
{
	isdbclicked = true;
}

void DrawCurve_EditPlugin::addMidPoints(MeshModel* current_model, std::vector<vcg::Point3f>& vert, double height)
{
	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;
	AABBTree* tree = current_model->m_AABBTree;

	for (int i = 0; i < vert.size(); ++i) {
		vcg::Point3f p = vert.at(i) + vcg::Point3f(0.0, 0.0, -1.0) * default_cut_offset;
		vcg::Point3f p_pnext, proj_dir, proj_p, mid_p;
		vcg::Ray3<float, false> ray;
		float ray_distance;
		CFaceO* insect_face = nullptr;

		if (i < vert.size() - 1) {
			current_model->ctrlPoints.push_back(vert.at(i));

			// compute middle point and project
			p_pnext = (vert.at(i + 1) - vert.at(i)).Normalize();
			proj_dir = p_pnext ^ vcg::Point3f(0.0, 0.0, 1.0);
			mid_p = (vert.at(i) + vert.at(i + 1)) * 0.5 + vcg::Point3f(0.0, 0.0, 1.0) * height;
			proj_p = mid_p - proj_dir * 10.0;
			ray.Set(proj_p, proj_dir);
			insect_face = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, ray_distance);
			if (insect_face) {
				mid_p = proj_p + proj_dir * ray_distance;
				current_model->ctrlPoints.push_back(mid_p);
			}
		}
		else {
			p_pnext = (vert.at(i) - vert.at(i - 1)).Normalize();
			proj_dir = p_pnext ^ vcg::Point3f(0.0, 0.0, 1.0);
			proj_p = p - proj_dir * 10.0;
			ray.Set(proj_p, proj_dir);
			insect_face = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, ray_distance);
			if (insect_face) {
				p = proj_p + proj_dir * ray_distance;
			}
			else {
				p = vert.at(i);
			}
			current_model->ctrlPoints.push_back(p);
		}
	}
}

void DrawCurve_EditPlugin::putLabelModels(MeshModel* exportModel)
{
	qDebug() << __FUNCTION__;
	//1. 读入标志物模型
	CMeshO* cone_mesh = new CMeshO();
	QString cone_path = QCoreApplication::applicationDirPath() + "/background/sphere.obj";
	std::string cone_path_str = cone_path.toLocal8Bit().constData();
	int load_mask;
	int open_result = vcg::tri::io::ImporterOBJ<CMeshO>::Open(*cone_mesh, cone_path_str.c_str(), load_mask);
	if (open_result != 0) {
		QMessageBox::critical(nullptr, tr("Error"), tr("Can't open cone model files."), QMessageBox::Ok);
	}

	//根据当前刀补的大小调整标记物的大小
	vcg::Matrix44f scale_mat;
	scale_mat.SetScale(1.0, default_cut_offset / 0.8, 1.0);

	//2.对于每一个模型增加标识物标记
	if (exportModel->label_mesh != nullptr) { //一旦标记物生成就则不能再更改其位置
		return;
	}

	// 2.1 先计算标志物的粘贴朝向
	exportModel->label_mesh = new CMeshO();
	exportModel->labelDir.clear();

	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;
	AABBTree* tree = exportModel->m_AABBTree;

	for (int i = 0; i < exportModel->curve.size() - 1; i++) {
		vcg::Point3f dir_horizon = (exportModel->curve[i + 1] - exportModel->curve[i]).Normalize();
		vcg::Point3f z(0.0, 0.0, 1.0);
		vcg::Point3f dir_out = (z ^ dir_horizon).Normalize();

		vcg::Point3f p_move_along_z = exportModel->curve[i] - z;
		vcg::Point3f proj_dir = -dir_out;
		vcg::Ray3<float, false> ray(p_move_along_z + dir_out * 5.0, proj_dir);
		float rayT;
		CFaceO* isectFace = NULL;

		isectFace = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, rayT);
		if (isectFace) {
			p_move_along_z = p_move_along_z + dir_out * 5.0 + proj_dir * rayT;
		}

		exportModel->labelDir.push_back((exportModel->curve[i] - p_move_along_z).Normalize());
	}
	exportModel->labelDir.push_back(exportModel->labelDir.back());

	for (int i = 0; i < exportModel->curve.size() - 1; i += 5) {
		//2.2 调整标识模型的方向
		// x y z 是标志物最终位置的局部坐标轴 
		vcg::Point3f x = (exportModel->curve[i + 1] - exportModel->curve[i]).Normalize();
		vcg::Point3f y = exportModel->labelDir[i];
		vcg::Point3f z = (x ^ y).Normalize();
		//y = (z ^ x).Normalize();

		vcg::Matrix44f rot_mat;
		rot_mat.SetIdentity();
		rot_mat[0][0] = x[0];
		rot_mat[1][0] = x[1];
		rot_mat[2][0] = x[2];

		rot_mat[0][1] = y[0];
		rot_mat[1][1] = y[1];
		rot_mat[2][1] = y[2];

		rot_mat[0][2] = z[0];
		rot_mat[1][2] = z[1];
		rot_mat[2][2] = z[2];

		vcg::Matrix44f trans_mat;
		trans_mat.SetTranslate(exportModel->curve[i]);

		CMeshO* cone_mesh_copy = new CMeshO();
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*cone_mesh_copy, *cone_mesh);
		vcg::tri::UpdatePosition<CMeshO>::Matrix(*cone_mesh_copy, trans_mat * rot_mat * scale_mat, true);

		//4.2.3 融合模型
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*exportModel->label_mesh, *cone_mesh_copy);
		delete cone_mesh_copy;
	}
	delete cone_mesh;
}

void DrawCurve_EditPlugin::pickLaserPoints(GLArea* gla, QPainter* painter)
{
	MeshModel* current_model = md->mm();

	if (isleftdown) {
		vcg::Point3f point3;
		bool result1 = vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3);
		if (result1) {
			// 找到与当前点击位置最近的点
			if (!hasPicked) {
				double minDis = 1 << 30;
				int minIndex = -1;
				for (int i = 0; i < current_model->pointsForLaser.size(); ++i) {
					double dis = (current_model->pointsForLaser[i] - point3).Norm();
					if (dis < minDis) {
						minDis = dis;
						minIndex = i;
					}
				}
				if (minIndex >= 0 && minDis < 0.5) {
					pickedIndex = minIndex;
				}
			}

			if (pickedIndex >= 0) {
				current_model->pointsForLaser[pickedIndex] = point3;
			}
		}
		hasPicked = true; //只在鼠标左键点下的第一次进行最近点查找工作
	}

	// 如果是双击添加打标点
	if (isdbclicked) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			if (current_model->pointsForLaser.size() < 2) {
				current_model->pointsForLaser.push_back(point3);
			}
		}
		isdbclicked = false;
	}

	// 绘制用于激光打标的2个点
	glDisable(GL_LIGHTING);
	glColor4f(0, 1, 0, 0);
	for (int i = 0; i < current_model->pointsForLaser.size(); ++i) {
		drawSphere(current_model->pointsForLaser[i][0], current_model->pointsForLaser[i][1], current_model->pointsForLaser[i][2], 0.6);
		if (i == 0) {
			vcg::glLabel::render(painter, current_model->pointsForLaser[i], QString("Left: ID"));
		}
		else {
			vcg::glLabel::render(painter, current_model->pointsForLaser[i], QString("Right: Logo"));
		}
	}
	glEnable(GL_LIGHTING);
	gla->update();
}

void DrawCurve_EditPlugin::pickAlignPoints(GLArea* gla, QPainter* painter)
{
	if (isleftdown) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			// 找到与当前点击位置最近的点
			if (!hasPicked) {
				double minDis = 1 << 30;
				int minIndex = -1;
				for (int i = 0; i < pointsForAlign.size(); ++i) {
					double dis = (pointsForAlign[i] - point3).Norm();
					if (dis < minDis) {
						minDis = dis;
						minIndex = i;
					}
				}
				if (minIndex >= 0 && minDis < 0.5) {
					pickedIndex = minIndex;
				}
			}

			if (pickedIndex >= 0) {
				pointsForAlign[pickedIndex] = point3;
			}
		}
		hasPicked = true; //只在鼠标左键点下的第一次进行最近点查找工作
	}

	if (isdbclicked) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			if (pointsForAlign.size() < 3) {
				pointsForAlign.push_back(point3);
			}
		}
		isdbclicked = false;
	}

	// 绘制用于摆正的3个点
	glDisable(GL_LIGHTING);
	glColor4f(0, 1, 0, 0);
	for (int i = 0; i < pointsForAlign.size(); ++i) {
		drawSphere(pointsForAlign[i].X(), pointsForAlign[i].Y(), pointsForAlign[i].Z(), 0.6);
		vcg::glLabel::render(painter, pointsForAlign[i], QString::number(i + 1));
	}
	glEnable(GL_LIGHTING);
	gla->update();

	//绘制二维码的示意位置
	if (pointsForAlign.size() == 3) {
		vcg::Point3f* p1 = &pointsForAlign[0];
		vcg::Point3f* p2 = &pointsForAlign[1];
		vcg::Point3f* p3 = &pointsForAlign[2];

		vcg::Point3f F = (*p1 - *p2).Normalize() + (*p1 - *p3).Normalize();
		F = F.Normalize();
		vcg::Point3f N = (*p3 - *p1) ^ (*p2 - *p1);
		N = N.Normalize();
		vcg::Point3f R = (N ^ F).Normalize();
		vcg::Point3f center = (*p1 + *p2 + *p3) * 0.333;

		std::vector<vcg::Point3f> plane_points(4);
		plane_points[0] = center + F * 0.33 * qr_info.width - R * 0.5 * qr_info.length;
		plane_points[1] = center + F * 0.33 * qr_info.width + R * 0.5 * qr_info.length;
		plane_points[2] = center - F * 0.66 * qr_info.width + R * 0.5 * qr_info.length;
		plane_points[3] = center - F * 0.66 * qr_info.width - R * 0.5 * qr_info.length;

		glEnable(GL_BLEND); //Enable blending.
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.

		glColor4f(0.3, 0.3, 0.3, 0.5);
		glBegin(GL_POLYGON);
		for (int i = 0; i < plane_points.size(); i++) {
			glVertex3f(plane_points[i].X(), plane_points[i].Y(), plane_points[i].Z());
		}
		glEnd();

		glDisable(GL_BLEND);
	}

	if (!base_pin_left.empty() && !base_pin_right.empty() && base_pin_left.size() == base_pin_right.size()) {
		std::vector<vcg::Point3f> base_pin_left_L(base_pin_left.size());
		std::vector<vcg::Point3f> base_pin_right_L(base_pin_right.size());
		for (int i = 0; i < base_pin_left.size(); ++i) {
			base_pin_left_L[i] = base_pin_left[i];
			base_pin_left_L[i].Z() = -1.733;

			base_pin_right_L[i] = base_pin_right[i];
			base_pin_right_L[i].Z() = -1.733;
		}

		drawRectangle(base_pin_left, base_pin_left_L);
		drawRectangle(base_pin_right, base_pin_right_L);
	}
}

void DrawCurve_EditPlugin::pickEruptionPoints(GLArea* gla, QPainter* painter)
{
	if (isleftdown) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			// 找到与当前点击位置最近的点
			if (!hasPicked) {
				double minDis = 1 << 30;
				int minIndex = -1;
				for (int i = 0; i < pointsForEruption.size(); ++i) {
					double dis = (pointsForEruption[i] - point3).Norm();
					if (dis < minDis) {
						minDis = dis;
						minIndex = i;
					}
				}
				if (minIndex >= 0 && minDis < 0.5) {
					pickedIndex = minIndex;
				}
			}

			if (pickedIndex >= 0) {
				pointsForEruption[pickedIndex] = point3;
			}
		}
		hasPicked = true; //只在鼠标左键点下的第一次进行最近点查找工作
	}

	// 如果是双击则重新插值重绘曲线
	if (isdbclicked) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			if (pointsForEruption.size() < 2) {
				pointsForEruption.push_back(point3);
			}
		}
		isdbclicked = false;
	}

	// 绘制pointsForEruption
	glDisable(GL_LIGHTING);
	glColor4f(1, 1, 0, 0);
	for (int i = 0; i < pointsForEruption.size(); ++i) {
		drawSphere(pointsForEruption[i].X(), pointsForEruption[i].Y(), pointsForEruption[i].Z(), 0.3);
		vcg::glLabel::render(painter, pointsForEruption[i], QString("Points for eruption: %1").arg(i + 1));
	}
	glEnable(GL_LIGHTING);
	gla->update();

}

void DrawCurve_EditPlugin::slotAlignAllModels()
{
	std::cout << "Align model \n";
	//QString instruction = QString::fromLocal8Bit("<p style='font-size:20px'>  </p>");
	//this->realTimeLog(title, md->mm()->shortName(), "%s", instruction.toStdString().c_str());
	if (pointsForAlign.size() != 3) {
		return;
	}

	vcg::Point3f* p1 = &pointsForAlign[0];
	vcg::Point3f* p2 = &pointsForAlign[1];
	vcg::Point3f* p3 = &pointsForAlign[2];

	vcg::Point3f F = (*p1 - *p2).Normalize() + (*p1 - *p3).Normalize();
	F = F.Normalize();
	vcg::Point3f N = (*p3 - *p1) ^ (*p2 - *p1);
	N = N.Normalize();
	vcg::Point3f R = (N ^ F).Normalize();
	vcg::Point3f center = -(*p1 + *p2 + *p3) * 0.333;

	vcg::Matrix44f matrix, transMatrix;
	matrix.SetIdentity();
	matrix[0][0] = F[0];
	matrix[0][1] = F[1];
	matrix[0][2] = F[2];

	matrix[1][0] = R[0];
	matrix[1][1] = R[1];
	matrix[1][2] = R[2];

	matrix[2][0] = N[0];
	matrix[2][1] = N[1];
	matrix[2][2] = N[2];

	transMatrix.SetTranslate(center);
	matrix = matrix * transMatrix;

	vcg::Plane3f plane;
	vcg::Point3f move_dir = N;
	plane.Init(*p1 - move_dir * 10, move_dir);

	double move_distance_0 = meshNearestDistanceToPlane(&md->mm()->cm, plane);

	for (int i = 0; i < md->meshList.size(); ++i) {
		MeshModel* current_mesh = md->meshList.at(i);
		double move_distance = move_distance_0 - meshNearestDistanceToPlane(&current_mesh->cm, plane);

		vcg::Matrix44f move_mat;
		if (i == 0) {
			move_mat.SetIdentity();
		}
		else {
			move_mat.SetTranslate(move_dir * move_distance);
		}
		vcg::tri::UpdatePosition<CMeshO>::Matrix(current_mesh->cm, matrix * move_mat, true);

		current_mesh->m_AABBTree = new AABBTree();
		current_mesh->m_AABBTree->Set(current_mesh->cm.face.begin(), current_mesh->cm.face.end());

		//std::vector<double> points(current_mesh->cm.vert.size() * 3);
		//std::vector<unsigned> faces(current_mesh->cm.face.size() * 3);

		//for (int i = 0; i < current_mesh->cm.vert.size(); ++i) {
		//	points[3 * i]     = current_mesh->cm.vert[i].P()[0];
		//	points[3 * i + 1] = current_mesh->cm.vert[i].P()[1];
		//	points[3 * i + 2] = current_mesh->cm.vert[i].P()[2];
		//}

		//for (int i = 0; i < current_mesh->cm.face.size(); ++i) {
		//	faces[3 * i]     = vcg::tri::Index(current_mesh->cm, current_mesh->cm.face[i].V(0));
		//	faces[3 * i + 1] = vcg::tri::Index(current_mesh->cm, current_mesh->cm.face[i].V(1));
		//	faces[3 * i + 2] = vcg::tri::Index(current_mesh->cm, current_mesh->cm.face[i].V(2));
		//}

		//current_mesh->mesh_geodesic.initialize_mesh_data(points, faces);
	}
	md->resetTrackballFunc();
	pointsForAlign.clear();

	//ready to show position pin model
	base_pin_left.resize(4);
	base_pin_right.resize(4);

	base_pin_left[0] = vcg::Point3f(8.285728, 39.186485, 3.000000);
	base_pin_left[1] = vcg::Point3f(-3.783070, 10.049999, 3.000000);
	base_pin_left[2] = vcg::Point3f(-9.676305, 11.762362, 3.000000);
	base_pin_left[3] = vcg::Point3f(2.004831, 39.963043, 3.000000);

	base_pin_right[0] = vcg::Point3f(-3.783070, -10.049999, 3.000000);
	base_pin_right[1] = vcg::Point3f(8.285728, -39.186485, 3.000000);
	base_pin_right[2] = vcg::Point3f(2.004831, -39.963043, 3.000000);
	base_pin_right[3] = vcg::Point3f(-9.676305, -11.762362, 3.000000);
}

void DrawCurve_EditPlugin::slotExport()
{
	QString outpath = QFileDialog::getExistingDirectory(this->gla, tr("Save Directory.."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (outpath.isNull() || outpath.isEmpty()) {
		return;
	}

	qDebug() << "Exporting cutline...";
	QString cutline_path = outpath + "/" + "cutline";
	if (!QDir(cutline_path).exists()) {
		QDir().mkdir(cutline_path);
	}
	for (int i = 0; i < md->meshList.size(); ++i) {
		MeshModel* current_model = md->meshList.at(i);
		exportCutLine(cutline_path, current_model);
	}

	qDebug() << "Exporting lasercutline...";
	QString lasercutline_path = outpath + "/" + "lasercutline";
	if (!QDir(lasercutline_path).exists()) {
		QDir().mkdir(lasercutline_path);
	}
	if (parameter_widget_ui.checkBox_saveLaserCutline->isChecked()) {
		for (int i = 0; i < md->meshList.size(); ++i) {
			MeshModel* current_model = md->meshList.at(i);
			exportLaserCutline(lasercutline_path, current_model);
		}
	}

	qDebug() << "Genterating and Exporting model files...";
	QString model_path = outpath + "/" + "print_model";
	if (!QDir(model_path).exists()) {
		QDir().mkdir(model_path);
	}

	//生成八字模型
	generatePinModelEigenMatrix(base_pin_V, base_pin_F);

	// 读入萌出帽模型
	QString eruption_path = QCoreApplication::applicationDirPath() + "/background/eruption.obj";
	std::string eruption_path_str = eruption_path.toLocal8Bit().constData();
	int load_mask;
	int open_result = vcg::tri::io::ImporterOBJ<CMeshO>::Open(eruption_mesh, eruption_path_str.c_str(), load_mask);
	if (open_result != 0) {
		QMessageBox::critical(nullptr, tr("Error"), tr("Can't open eruption model files."), QMessageBox::Ok);
	}

	//导出所有模型
	#pragma omp parallel for num_threads(10)
	for (int i = 0; i < md->meshList.size(); ++i) {
		MeshModel* current_model = md->meshList.at(i);
		qDebug() << QString("Thread %1, Deal with model %2").arg(omp_get_thread_num()).arg(current_model->label());

		generateBaseModel(current_model);
		exportModels(model_path, current_model);
	}

	int overcorrection_step = parameter_widget_ui.spinBox_overcorrection_step->value();
	if (overcorrection_step != 0) {
		qDebug() << "Exporting overcorrection files...";

		MeshModel* current_model = md->meshList.back();
		QString model_name = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
		QString currentJaw = model_name.split('_')[1];
		int step = model_name.split('_')[2].toInt();

		CMeshO* gum_mesh   = nullptr;
		CMeshO* other_mesh = nullptr;

		for (int i = 1; i <= overcorrection_step; i++) {
			current_model->setLabel(parameter_widget_ui.lineEdit_PatientID->text() + "_" + currentJaw + "_" + QString().number(step + i));
			exportCutLine(cutline_path, current_model);
			exportLaserCutline(lasercutline_path, current_model);
			
			//export oc models
			generateBaseModel(current_model);
			exportOCModels(model_path, current_model, gum_mesh, other_mesh);
		}

		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}

	int ret = QMessageBox::information(nullptr, tr("Information"),
		tr("Export Completed."), QMessageBox::Ok);
}

void DrawCurve_EditPlugin::slotNextModel()
{
	MeshModel* last_model = md->mm();
	last_model->visible = false;

	//set current
	current_mesh_index = (current_mesh_index + 1) % md->meshList.size();
	md->setCurrent(md->meshList.at(current_mesh_index));
	md->mm()->visible = true;
	parameter_widget_ui.label_currentModel->setText(md->mm()->label());
	AABBTree* tree = md->mm()->m_AABBTree;

	// parameter for projection
	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;

	// project cutline
	if (md->mm()->ctrlPoints.empty() && !last_model->ctrlPoints.empty()) {
		// 找控制点在曲线上的最近点是为了获取投影方向
		// find the nearest point on curve to each control points, and use its projection direction for projecting
		for (int j = 0; j < last_model->ctrlPoints.size(); ++j) {
			int nearest_index = -1;
			double nearest_dis = std::numeric_limits<double>::max();
			for (int i = 0; i < last_model->curve.size(); ++i) {
				double dis = vcg::Distance(last_model->ctrlPoints.at(j), last_model->curve.at(i));
				if (dis < nearest_dis) {
					nearest_dis = dis;
					nearest_index = i;
				}
			}

			//do projection
			vcg::Point3f proj_dir = last_model->curveDir[nearest_index];
			vcg::Point3f proj_p = last_model->curve[nearest_index] - proj_dir * 10.0;
			vcg::Ray3<float, false> ray(proj_p, proj_dir);
			float proj_distance;
			CFaceO* isectFace = NULL;
			isectFace = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, proj_distance);
			if (isectFace) {
				md->mm()->ctrlPoints.push_back(proj_p + proj_dir * proj_distance);
			}
		}

		doInterpolation();
	}

	// project laser mark position
	if (md->mm()->pointsForLaser.empty() && !last_model->pointsForLaser.empty()) {
		vcg::Point3f projDir(0.0, 0.0, -1.0);

		md->mm()->pointsForLaser.resize(2);

		for (int i = 0; i < last_model->pointsForLaser.size(); ++i) {
			vcg::Point3f pointToProj = last_model->pointsForLaser[i] - projDir * 10.0;
			vcg::Ray3<float, false> ray(pointToProj, projDir);
			float proj_distance;
			CFaceO* isectFace = NULL;
			isectFace = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, proj_distance);
			if (isectFace) {
				md->mm()->pointsForLaser[i] = pointToProj + projDir * proj_distance;
			}
			else {
				md->mm()->pointsForLaser[i] = last_model->pointsForLaser[i];
			}
		}
	}

	// project eruption
	if (md->mm()->eruption_mat.empty() && !last_model->eruption_mat.empty()) {
		md->mm()->eruption_mat.assign(last_model->eruption_mat.begin(), last_model->eruption_mat.end());
		md->mm()->eruption_rotation_mat.assign(last_model->eruption_rotation_mat.begin(), last_model->eruption_rotation_mat.end());
		md->mm()->eruption_scale_mat.assign(last_model->eruption_scale_mat.begin(), last_model->eruption_scale_mat.end());
		md->mm()->eruption_trans_mat.assign(last_model->eruption_trans_mat.begin(), last_model->eruption_trans_mat.end());
	}

	if (!md->mm()->ctrlPoints.empty() && md->mm()->curve.empty()) {
		doInterpolation();//只有控制点，没有切割曲线，则插值生成控制曲线
	}

	md->refreshMeshList();
	gla->update();
}

void DrawCurve_EditPlugin::slotLastModel()
{
	MeshModel* last_model = md->mm();
	md->mm()->visible = false;
	current_mesh_index--;
	if (current_mesh_index < 0) {
		current_mesh_index += md->meshList.size();
	}
	md->setCurrent(md->meshList.at(current_mesh_index));
	md->mm()->visible = true;
	parameter_widget_ui.label_currentModel->setText(md->mm()->label());

	if (!md->mm()->ctrlPoints.empty() && md->mm()->curve.empty()) {
		doInterpolation();//只有控制点，没有切割曲线，则插值生成控制曲线
	}

	md->refreshMeshList();
	gla->update();
}

void DrawCurve_EditPlugin::slotPutEruption()
{
	if (pointsForEruption.size() != 2) {
		return;
	}
	mode = SHOW_ERUPTION;
	std::cout << "in showing eruption mode \n";

	//定义最终局部坐标轴方向
	vcg::Point3f x = (pointsForEruption[0] - pointsForEruption[1]).Normalize();
	vcg::Point3f z(0.0, 0.0, 1.0);
	vcg::Point3f y = z ^ x;
	vcg::Point3f center = (pointsForEruption[0] + pointsForEruption[1]) / 2;
	double scale_factor = (pointsForEruption[0] - pointsForEruption[1]).Norm() / 10.0 * 1.2;

	vcg::Matrix44f rot_mat, trans_mat, scale_mat;
	rot_mat.SetIdentity();
	rot_mat[0][0] = x[0];
	rot_mat[1][0] = x[1];
	rot_mat[2][0] = x[2];

	rot_mat[0][1] = y[0];
	rot_mat[1][1] = y[1];
	rot_mat[2][1] = y[2];

	rot_mat[0][2] = z[0];
	rot_mat[1][2] = z[1];
	rot_mat[2][2] = z[2];

	trans_mat.SetTranslate(center);
	scale_mat.SetScale(scale_factor, 1.0, 1.0);

	MeshModel* current_model = md->mm();
	current_model->eruption_trans_mat.push_back(trans_mat);
	current_model->eruption_rotation_mat.push_back(rot_mat);
	current_model->eruption_scale_mat.push_back(scale_mat);
	current_model->eruption_mat.push_back(trans_mat * rot_mat * scale_mat);

	gla->update();
}

void DrawCurve_EditPlugin::slotTransformEruption(double v)
{
	vcg::Matrix44f trans_mat, rotation_mat_x, rotation_mat_y, rotation_mat_z, scale_mat;
	vcg::Matrix44f rotation_mat;

	trans_mat.SetIdentity();
	rotation_mat_x.SetIdentity();
	rotation_mat_y.SetIdentity();
	rotation_mat_z.SetIdentity();
	scale_mat.SetIdentity();

	double tx, ty, tz;
	tx = parameter_widget_ui.doubleSpinBox_tx->value();
	ty = parameter_widget_ui.doubleSpinBox_ty->value();
	tz = parameter_widget_ui.doubleSpinBox_tz->value();

	double rx, ry, rz;
	rx = parameter_widget_ui.doubleSpinBox_rx->value();
	ry = parameter_widget_ui.doubleSpinBox_ry->value();
	rz = parameter_widget_ui.doubleSpinBox_rz->value();

	double sx, sy, sz;
	sx = parameter_widget_ui.doubleSpinBox_sx->value();
	sy = parameter_widget_ui.doubleSpinBox_sy->value();
	sz = parameter_widget_ui.doubleSpinBox_sz->value();

	rotation_mat_x.SetRotateDeg(rx, vcg::Point3f(1.0, 0.0, 0.0));
	rotation_mat_y.SetRotateDeg(ry, vcg::Point3f(0.0, 1.0, 0.0));
	rotation_mat_z.SetRotateDeg(rz, vcg::Point3f(0.0, 0.0, 1.0));
	rotation_mat = md->mm()->eruption_rotation_mat.back() * rotation_mat_x * rotation_mat_y * rotation_mat_z;

	trans_mat.SetTranslate(rotation_mat * vcg::Point3f(tx, ty, tz));
	trans_mat *= md->mm()->eruption_trans_mat.back();

	scale_mat.SetScale(sx, sy, sz);
	scale_mat *= md->mm()->eruption_scale_mat.back();

	md->mm()->eruption_mat.back() = trans_mat * rotation_mat * scale_mat;
	gla->update();
}

void DrawCurve_EditPlugin::slotImportCtrlPoints()
{
	QStringList files = QFileDialog::getOpenFileNames(this->gla, "Select one or more control points files of SMC2.0 cutpath to open", "", "text(*.txt)");

	for (QString file_path : files) {
		QString file_name = file_path.mid(file_path.lastIndexOf('/') + 1, file_path.size() - 1 - file_path.lastIndexOf('/'));
		file_name = file_name.mid(0, file_name.lastIndexOf('.'));
		QStringList file_name_list = file_name.split('_');
		if (file_name_list.size() < 4) {
			continue;
		}
		qDebug() << file_name_list[2] << " " << file_name_list[3];
		// find related model 找到相对应的模型
		for (MeshModel* current_model : md->meshList) {
			QString model_name = current_model->label();
			model_name = model_name.mid(0, model_name.lastIndexOf('.'));
			QStringList model_name_list = model_name.split('_');
			if (model_name_list.size() < 3) {
				continue;
			}
			QString model_step = QString("%1").arg(model_name_list[2], 2, QLatin1Char('0'));
			if (model_step == file_name_list[3] && model_name_list[1] == file_name_list[2]) {
				importOneCtrlPoints(current_model, file_path);
				break;
			}
		}
	}
	doInterpolation();
	mode = DRAW;
	gla->update();
}

void DrawCurve_EditPlugin::slotPutLabelModels()
{
	for (MeshModel* current_model : md->meshList) {
		putLabelModels(current_model);
	}

	int ret = QMessageBox::information(nullptr, tr("Information"),
		tr("Add Label Models Completed."), QMessageBox::Ok);
}

void DrawCurve_EditPlugin::slotComputeCtrlPoints()
{
	MeshModel* current_model = md->mm();
	if (current_model->m_AABBTree == nullptr) {
		current_model->m_AABBTree = new AABBTree();
		current_model->m_AABBTree->Set(current_model->cm.face.begin(), current_model->cm.face.end());
	}

	if (!current_model->curve.empty()) {
		return;
	}

	//1, 将牙颌模型分解成牙齿和牙龈以及矫治器特征三部分，并只保留牙齿和牙龈
	// split jaw model into three parts-teeth(many),gum and other,and keep teeth models and gum model.
	std::vector< std::pair<int, CMeshO::FacePointer> > connected_components;
	int num_cc = vcg::tri::Clean<CMeshO>::ConnectedComponents(current_model->cm, connected_components);

	CMeshO* gum_mesh;
	vcg::GridStaticPtr<CFaceO, float> gum_tri_grid;
	std::vector<CMeshO*> teeth_meshes, unsorted_teeth_meshes;

	for (size_t i = 0; i < connected_components.size(); ++i)
	{
		vcg::tri::UpdateSelection<CMeshO>::FaceClear(current_model->cm);
		connected_components[i].second->SetS();
		vcg::tri::UpdateSelection<CMeshO>::FaceConnectedFF(current_model->cm);
		vcg::tri::UpdateSelection<CMeshO>::VertexClear(current_model->cm);
		vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceLoose(current_model->cm);

		vcg::Box3f bbox;
		for (CMeshO::VertexIterator vit = current_model->cm.vert.begin(); vit != current_model->cm.vert.end(); ++vit) {
			if (vit->IsS()) {
				bbox.Add(vit->P());
			}
		}

		if (bbox.Diag() > 50) { // is gum
			gum_mesh = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*gum_mesh, current_model->cm, true);
			gum_mesh->face.EnableMark();
			RequirePerFaceMark(*gum_mesh);
			gum_tri_grid.Set(gum_mesh->face.begin(), gum_mesh->face.end());
		}
		else if (bbox.Diag() > 8) {// is teeth
			CMeshO* splitted_mesh = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*splitted_mesh, current_model->cm, true);
			unsorted_teeth_meshes.push_back(splitted_mesh);
		}
	}

	//2. sort teeth meshes
	std::map<CMeshO*, vcg::Point3f> teeth_barycenter_map;
	for (int i = 0; i < unsorted_teeth_meshes.size(); ++i) {
		vcg::Point3f bc = vcg::tri::Stat<CMeshO>::ComputeShellBarycenter(*unsorted_teeth_meshes.at(i));
		teeth_barycenter_map.insert({ unsorted_teeth_meshes.at(i), bc });
	}

	float min_X = std::numeric_limits<float>::max();
	vcg::Point3f min_bc;
	for (int i = 0; i < unsorted_teeth_meshes.size(); ++i) {
		vcg::Point3f bc = teeth_barycenter_map[unsorted_teeth_meshes.at(i)];
		if (bc.Y() > 0 && bc.X() < min_X) {
			min_X = bc.X();
			min_bc = bc;
		}
	}

	while (!unsorted_teeth_meshes.empty()) {
		float nearest_distance = std::numeric_limits<float>::max();
		int nearest_index = -1;
		for (int i = 0; i < unsorted_teeth_meshes.size(); ++i) {
			float distance = vcg::Distance(teeth_barycenter_map[unsorted_teeth_meshes.at(i)], min_bc);
			if (distance < nearest_distance) {
				nearest_distance = distance;
				nearest_index = i;
			}
		}
		teeth_meshes.push_back(unsorted_teeth_meshes.at(nearest_index));
		min_bc = teeth_barycenter_map[unsorted_teeth_meshes.at(nearest_index)];
		unsorted_teeth_meshes.erase(unsorted_teeth_meshes.begin() + nearest_index);
	}

	//3.get intersection(supposed that the models have been aligned)
	std::vector<std::vector<vcg::Point3f>> teeth_intersected_points(teeth_meshes.size());
	for (int i = 0; i < teeth_meshes.size(); ++i) {
		CMeshO* tooth_mesh = teeth_meshes.at(i);
		vcg::tri::UpdateFlags<CMeshO>::FaceClear(*tooth_mesh);
		vcg::tri::UpdateFlags<CMeshO>::VertexClear(*tooth_mesh);

		for (CMeshO::FaceIterator fi_teeth = tooth_mesh->face.begin(); fi_teeth != tooth_mesh->face.end(); ++fi_teeth)
		{
			if (!(*fi_teeth).IsD()) {
				vcg::Box3f teeth_face_bbox;
				fi_teeth->GetBBox(teeth_face_bbox);
				std::vector<CFaceO*> gum_faces_in_bbox;
				vcg::tri::GetInBoxFace(*gum_mesh, gum_tri_grid, teeth_face_bbox, gum_faces_in_bbox);

				for (std::vector<CFaceO*>::iterator fib = gum_faces_in_bbox.begin(); fib != gum_faces_in_bbox.end(); ++fib) {
					if (vcg::tri::Clean<CMeshO>::TestFaceFaceIntersection(&*fi_teeth, *fib)) {
						fi_teeth->SetS();
						break;
					}
				}
			}
		}

		vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceLoose(*tooth_mesh);
		for (CMeshO::VertexIterator vit = tooth_mesh->vert.begin(); vit != tooth_mesh->vert.end(); ++vit) {
			if (vit->IsS()) {
				teeth_intersected_points[i].push_back(vit->P());
			}
		}
	}

	// 将牙齿的一周分成36份（10度为一份）
	std::vector<std::vector<vcg::Point3f>> teeth_border_with_gap;//每个牙齿对应的最外面一圈的36个边界点
	std::vector<std::vector<bool>> teeth_border_flag; //标记是否36个点齐全

	teeth_border_with_gap.resize(teeth_intersected_points.size());
	teeth_border_flag.resize(teeth_intersected_points.size());

	//4.clean intersected points  ==> teeth_border_with_gap
	for (int i = 0; i < teeth_intersected_points.size(); ++i) {
		vcg::Point3f center(0, 0, 0);
		for (int j = 0; j < teeth_intersected_points[i].size(); ++j) {
			center += teeth_intersected_points[i][j];
		}
		center /= teeth_intersected_points[i].size();

		teeth_border_with_gap[i].resize(36, center);
		teeth_border_flag[i].resize(36, false);

		vcg::Point3f x;
		if (i == teeth_intersected_points.size() - 1) {
			x = teeth_barycenter_map[teeth_meshes.at(i)] - teeth_barycenter_map[teeth_meshes.at(i - 1)];
		}
		else {
			x = teeth_barycenter_map[teeth_meshes.at(i + 1)] - teeth_barycenter_map[teeth_meshes.at(i)];
		}
		x = x.Normalize();

		vcg::Point3f z(0.0, 0.0, 1.0);
		vcg::Plane3f xoy;
		xoy.Init(vcg::Point3f(0.0, 0.0, 0.0), z);
		vcg::Point3f proj_center = xoy.Projection(center);

		for (int j = 0; j < teeth_intersected_points[i].size(); ++j) {
			//firstly, find the jth point's index in teeth_border_with_gap[i]
			vcg::Point3f proj_p = xoy.Projection(teeth_intersected_points[i][j]);
			vcg::Point3f dir = (proj_p - proj_center).Normalize();
			float angle = std::acos(dir * x) / FPI * 180.0;
			if ((x ^ dir) * z < 0) {
				angle = 360 - angle;
			}

			int index = int(angle / 10) % 36;
			vcg::Point3f proj_border = xoy.Projection(teeth_border_with_gap[i][index]);
			if (vcg::Distance(proj_center, proj_p) > vcg::Distance(proj_center, proj_border)) {
				teeth_border_with_gap[i][index] = teeth_intersected_points[i][j];
				teeth_border_flag[i][index] = true;
			}
		}
	}
	border_map.insert({ current_model, teeth_border_with_gap });
	border_flag_map.insert({ current_model, teeth_border_flag });

	//5.remove gap. teeth_border_with_gap ==> teeth_border_lingal, teeth_border_buccal
	std::vector<vcg::Point3f> teeth_border_lingal, teeth_border_buccal;

	//buccal
	for (int i = 0; i < teeth_border_with_gap.size(); ++i) {
		if (teeth_border_flag[i][9]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][9]);
		}
		else if (teeth_border_flag[i][8]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][8]);
		}
		else if (teeth_border_flag[i][10]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][10]);
		}
		else if (teeth_border_flag[i][7]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][7]);
		}
	}
	//lingual
	for (int i = teeth_border_with_gap.size() - 1; i > 0; i--) {
		if (teeth_border_flag[i][27]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][27]);
		}
		else if (teeth_border_flag[i][26]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][26]);
		}
		else if (teeth_border_flag[i][28]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][28]);
		}
		else if (teeth_border_flag[i][25]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][25]);
		}
	}

	//6. assign control points
	if (teeth_border_flag.front().at(13)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(13));
	}
	if (teeth_border_flag.front().at(15)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(15));
	}
	if (teeth_border_flag.front().at(17)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(17));
	}

	addMidPoints(current_model, teeth_border_buccal, parameter_widget_ui.doubleSpinBox_midHeight_buccal->value());

	if (teeth_border_flag.back().at(4)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(4));
	}
	if (teeth_border_flag.back().at(2)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(2));
	}
	if (teeth_border_flag.back().at(0)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(0));
	}
	if (teeth_border_flag.back().at(34)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(34));
	}
	if (teeth_border_flag.back().at(32)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(32));
	}
	if (teeth_border_flag.back().at(30)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(30));
	}

	addMidPoints(current_model, teeth_border_lingal, parameter_widget_ui.doubleSpinBox_midHeight_lingual->value());

	if (teeth_border_flag.front().at(13)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(23));
	}
	if (teeth_border_flag.front().at(15)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(21));
	}
	if (teeth_border_flag.front().at(17)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(19));
	}

	// 7. generate cut curve
	doInterpolation();

	//8.move down default distance 
	moveDownGumLine(current_model, default_cut_offset);

	mode = DRAW;
	gla->update();

	// test: save teeth model in order
	//int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*gum_mesh, "E:\\Desktop\\test\\gum.stl", true);
	//if (result != 0) {
	//	std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
	//}
	//for (int i = 0; i < teeth_meshes.size(); ++i) {
	//	std::string path = "E:\\Desktop\\test\\" + std::to_string(i) + ".stl";
	//	vcg::tri::io::ExporterSTL<CMeshO>::Save(*teeth_meshes[i], path.c_str(), true);
	//}
}

void DrawCurve_EditPlugin::slotChangeGumHeight()
{
	MeshModel* current_model = md->mm();

	//1. get border according current model
	if (border_map.find(current_model) == border_map.end()) {
		return;
	}
	std::vector<std::vector<vcg::Point3f>>& teeth_border_with_gap = border_map[current_model];
	std::vector<std::vector<bool>>& teeth_border_flag = border_flag_map[current_model];
	//2.remove gap. teeth_border_with_gap ==> teeth_border_lingal, teeth_border_buccal
	std::vector<vcg::Point3f> teeth_border_lingal, teeth_border_buccal;

	//buccal
	for (int i = 0; i < teeth_border_with_gap.size(); ++i) {
		if (teeth_border_flag[i][9]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][9]);
		}
		else if (teeth_border_flag[i][8]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][8]);
		}
		else if (teeth_border_flag[i][10]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][10]);
		}
		else if (teeth_border_flag[i][7]) {
			teeth_border_buccal.push_back(teeth_border_with_gap[i][7]);
		}
	}
	//lingual
	for (int i = teeth_border_with_gap.size() - 1; i > 0; i--) {
		if (teeth_border_flag[i][27]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][27]);
		}
		else if (teeth_border_flag[i][26]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][26]);
		}
		else if (teeth_border_flag[i][28]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][28]);
		}
		else if (teeth_border_flag[i][25]) {
			teeth_border_lingal.push_back(teeth_border_with_gap[i][25]);
		}
	}

	//3. compute control points
	current_model->ctrlPoints.clear();
	if (teeth_border_flag.front().at(13)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(13));
	}
	if (teeth_border_flag.front().at(15)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(15));
	}
	if (teeth_border_flag.front().at(17)) {
		current_model->ctrlPoints.insert(current_model->ctrlPoints.begin(), teeth_border_with_gap.front().at(17));
	}

	addMidPoints(current_model, teeth_border_buccal, parameter_widget_ui.doubleSpinBox_midHeight_buccal->value());

	if (teeth_border_flag.back().at(4)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(4));
	}
	if (teeth_border_flag.back().at(2)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(2));
	}
	if (teeth_border_flag.back().at(0)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(0));
	}
	if (teeth_border_flag.back().at(34)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(34));
	}
	if (teeth_border_flag.back().at(32)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(32));
	}
	if (teeth_border_flag.back().at(30)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.back().at(30));
	}

	addMidPoints(current_model, teeth_border_lingal, parameter_widget_ui.doubleSpinBox_midHeight_lingual->value());

	if (teeth_border_flag.front().at(13)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(23));
	}
	if (teeth_border_flag.front().at(15)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(21));
	}
	if (teeth_border_flag.front().at(17)) {
		current_model->ctrlPoints.push_back(teeth_border_with_gap.front().at(19));
	}

	doInterpolation();
}

void DrawCurve_EditPlugin::exportModels(QString outpath, MeshModel* current_model)
{
	qDebug() << __FUNCTION__;

	bool create_directory = false;
	CMeshO* gum_mesh    = new CMeshO();    // 输入的模型牙龈部分
	CMeshO* other_mesh  = new CMeshO();    // 输入的模型除了牙龈的部分
	CMeshO* output_mesh = new CMeshO();    // 最终的导出模型

	//1, 将牙颌模型分解成牙龈和其它部分
	std::vector< std::pair<int, CMeshO::FacePointer> > connected_components;
	int num_cc = vcg::tri::Clean<CMeshO>::ConnectedComponents(current_model->cm, connected_components);
	for (size_t i = 0; i < connected_components.size(); ++i)
	{
		vcg::tri::UpdateSelection<CMeshO>::FaceClear(current_model->cm);
		connected_components[i].second->SetS();
		vcg::tri::UpdateSelection<CMeshO>::FaceConnectedFF(current_model->cm);
		vcg::tri::UpdateSelection<CMeshO>::VertexClear(current_model->cm);
		vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceLoose(current_model->cm);

		vcg::Box3f bbox;
		for (CMeshO::VertexIterator vit = current_model->cm.vert.begin(); vit != current_model->cm.vert.end(); ++vit) {
			if (vit->IsS()) {
				bbox.Add(vit->P());
			}
		}
		if (bbox.Diag() > 50) { // is gum
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*gum_mesh, current_model->cm, true);
		}
		else {
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*other_mesh, current_model->cm, true);
		}
	}
	if (gum_mesh->vert.size() + other_mesh->vert.size() != current_model->cm.vert.size()) {
		return;
	}

	//2, 融合八字底座和牙龈模型
	Eigen::MatrixXd gum_V;
	Eigen::MatrixXi gum_F;
	changeCMeshOToEigenMatrix(gum_mesh, gum_V, gum_F);
	Eigen::VectorXi J;
	bool boolean_base_pin = igl::copyleft::cgal::mesh_boolean(gum_V.eval(), gum_F.eval(), base_pin_V, base_pin_F, igl::MESH_BOOLEAN_TYPE_MINUS, gum_V, gum_F, J);
	if (boolean_base_pin) {
		mergeCMeshWithEigenVector(output_mesh, gum_V, gum_F);
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *other_mesh);
	}
	else {// 如果融合失败，导入模型不做任何处理
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*output_mesh, current_model->cm);
		create_directory = true;
	}
	delete gum_mesh;
	delete other_mesh;
	gum_mesh = other_mesh = nullptr;

	//3. 底座和字符信息做差,并融入原始模型
	Eigen::MatrixXd base_V, info_V;
	Eigen::MatrixXi base_F, info_F;
	changeCMeshOToEigenMatrix(current_model->base_mesh, base_V, base_F);
	changeCMeshOToEigenMatrix(current_model->info_mesh, info_V, info_F);
	bool boolean_base_info = igl::copyleft::cgal::mesh_boolean(base_V.eval(), base_F.eval(), info_V, info_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_V, base_F, J);;
	if (boolean_base_info) {
		mergeCMeshWithEigenVector(output_mesh, base_V, base_F);
		//如果融合成功则删除当前信息模型，后续不用分开导出
		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}
	else {
		create_directory = true;
	}

	//4.融合二维码
	vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->qr_mesh);
	delete current_model->qr_mesh;
	current_model->qr_mesh = nullptr;

	//5.是否需要导出牙龈线标识
	if (current_model->label_mesh != nullptr) {
		create_directory = true;
	}

	//6. 是否需要导出萌出帽
	if (!current_model->eruption_rotation_mat.empty() && current_model->eruption_rotation_mat.size() == current_model->eruption_scale_mat.size() &&
		current_model->eruption_rotation_mat.size() == current_model->eruption_trans_mat.size())
	{
		for (int i = 0; i < current_model->eruption_rotation_mat.size(); ++i) {
			CMeshO temp_eruption_mesh;
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(temp_eruption_mesh, eruption_mesh);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(temp_eruption_mesh, current_model->eruption_mat.at(i));
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, temp_eruption_mesh);
		}
	}

	//Ⅲ. 模型导出
	QString new_outpath = outpath;
	QString model_name = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
	QString step = model_name.split('_')[2];
	QString jaw = model_name.split('_')[1];
	if (create_directory) {
		new_outpath = new_outpath + "/" + jaw + step;
		if (!QDir(new_outpath).exists()) {
			QDir().mkpath(new_outpath);
		}
	}

	//1.导出牙颌模型
	QString model_outpath = new_outpath + "/" + model_name + ".stl";
	std::string model_outpath_str = model_outpath.toLocal8Bit().data();
	int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*output_mesh, model_outpath_str.c_str(), true);
	if (result != 0) {
		std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
	}
	delete output_mesh;

	//2.按需导出牙龈线标识模型
	if (current_model->label_mesh != nullptr) {
		QString label_outpath = new_outpath + "/" + model_name + "_label.stl";
		std::string label_outpath_str = label_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->label_mesh, label_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}
	}

	//3.按需导出底座二维码和信息
	if (current_model->info_mesh)
	{
		QString base_outpath = new_outpath + "/" + model_name + "_base.stl";
		std::string base_outpath_str = base_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->base_mesh, base_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}

		QString info_outpath = new_outpath + "/" + model_name + "_info.stl";
		std::string info_outpath_str = info_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->info_mesh, info_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}

		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;

		delete current_model->base_mesh;
		current_model->base_mesh = nullptr;
	}
}

void DrawCurve_EditPlugin::exportOCModels(QString outpath, MeshModel* current_model, CMeshO*& gum_mesh, CMeshO*& other_mesh)
{
	qDebug() << __FUNCTION__;

	bool create_directory = false;
	Eigen::VectorXi J;

	CMeshO* output_mesh = new CMeshO();    // 最终的导出模型
	if (gum_mesh == nullptr) {
		gum_mesh = new CMeshO();
		other_mesh = new CMeshO();

		//1, 将牙颌模型分解成牙龈和其它部分
		std::vector< std::pair<int, CMeshO::FacePointer> > connected_components;
		int num_cc = vcg::tri::Clean<CMeshO>::ConnectedComponents(current_model->cm, connected_components);
		for (size_t i = 0; i < connected_components.size(); ++i)
		{
			vcg::tri::UpdateSelection<CMeshO>::FaceClear(current_model->cm);
			connected_components[i].second->SetS();
			vcg::tri::UpdateSelection<CMeshO>::FaceConnectedFF(current_model->cm);
			vcg::tri::UpdateSelection<CMeshO>::VertexClear(current_model->cm);
			vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceLoose(current_model->cm);

			vcg::Box3f bbox;
			for (CMeshO::VertexIterator vit = current_model->cm.vert.begin(); vit != current_model->cm.vert.end(); ++vit) {
				if (vit->IsS()) {
					bbox.Add(vit->P());
				}
			}
			if (bbox.Diag() > 50) { // is gum
				vcg::tri::Append<CMeshO, CMeshO>::Mesh(*gum_mesh, current_model->cm, true);
			}
			else {
				vcg::tri::Append<CMeshO, CMeshO>::Mesh(*other_mesh, current_model->cm, true);
			}
		}

		//2, 融合八字底座和牙龈模型
		Eigen::MatrixXd gum_V;
		Eigen::MatrixXi gum_F;
		changeCMeshOToEigenMatrix(gum_mesh, gum_V, gum_F);
		bool boolean_base_pin = igl::copyleft::cgal::mesh_boolean(gum_V.eval(), gum_F.eval(), base_pin_V, base_pin_F, igl::MESH_BOOLEAN_TYPE_MINUS, gum_V, gum_F, J);
		if (boolean_base_pin) {
			mergeCMeshWithEigenVector(other_mesh, gum_V, gum_F);
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*output_mesh, *other_mesh);
		}
		else {// 如果融合失败，导入模型不做任何处理
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*output_mesh, current_model->cm);
			create_directory = true;
			delete gum_mesh;
			delete other_mesh;
			gum_mesh = other_mesh = nullptr;
		}
	}
	else {
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*output_mesh, *other_mesh);
	}

	//3. 底座和字符信息做差,并融入原始模型
	Eigen::MatrixXd base_V, info_V;
	Eigen::MatrixXi base_F, info_F;
	changeCMeshOToEigenMatrix(current_model->base_mesh, base_V, base_F);
	changeCMeshOToEigenMatrix(current_model->info_mesh, info_V, info_F);
	bool boolean_base_info = igl::copyleft::cgal::mesh_boolean(base_V.eval(), base_F.eval(), info_V, info_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_V, base_F, J);
	if (boolean_base_info) {
		mergeCMeshWithEigenVector(output_mesh, base_V, base_F);
		//如果融合成功则删除当前信息模型，后续不用分开导出
		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}
	else {
		create_directory = true;
	}

	//4.融合二维码
	vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->qr_mesh);
	delete current_model->qr_mesh;
	current_model->qr_mesh = nullptr;

	//5.是否需要导出牙龈线标识
	if (current_model->label_mesh != nullptr) {
		create_directory = true;
	}

	//6. 是否需要导出萌出帽
	if (!current_model->eruption_rotation_mat.empty() && current_model->eruption_rotation_mat.size() == current_model->eruption_scale_mat.size() &&
		current_model->eruption_rotation_mat.size() == current_model->eruption_trans_mat.size())
	{
		for (int i = 0; i < current_model->eruption_rotation_mat.size(); ++i) {
			CMeshO temp_eruption_mesh;
			vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(temp_eruption_mesh, eruption_mesh);
			vcg::tri::UpdatePosition<CMeshO>::Matrix(temp_eruption_mesh, current_model->eruption_mat.at(i));
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, temp_eruption_mesh);
		}
	}

	//Ⅲ. 模型导出
	QString new_outpath = outpath;
	QString model_name  = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
	QString step = model_name.split('_')[2];
	QString jaw  = model_name.split('_')[1];
	if (create_directory) {
		new_outpath = new_outpath + "/" + jaw + step;
		if (!QDir(new_outpath).exists()) {
			QDir().mkpath(new_outpath);
		}
	}

	//1.导出牙颌模型
	QString model_outpath = new_outpath + "/" + model_name + ".stl";
	std::string model_outpath_str = model_outpath.toLocal8Bit().data();
	int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*output_mesh, model_outpath_str.c_str(), true);
	if (result != 0) {
		std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
	}
	delete output_mesh;

	//2.按需导出牙龈线标识模型
	if (current_model->label_mesh != nullptr) {
		QString label_outpath = new_outpath + "/" + model_name + "_label.stl";
		std::string label_outpath_str = label_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->label_mesh, label_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}
	}

	//3.按需导出底座二维码和信息
	if (current_model->info_mesh)
	{
		QString base_outpath = new_outpath + "/" + model_name + "_base.stl";
		std::string base_outpath_str = base_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->base_mesh, base_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}

		QString info_outpath = new_outpath + "/" + model_name + "_info.stl";
		std::string info_outpath_str = info_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->info_mesh, info_outpath_str.c_str(), true);
		if (result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
		}

		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}
}

void DrawCurve_EditPlugin::drawCurve(GLArea*)
{
	// 根据鼠标按键进行手绘切割线
	// 双击: 增加新的控制点
	// 左侧单击并拖动: 移动相应控制点
	// 右键单击: 删除相应控制点
	MeshModel* current_model = md->mm();

	if (gla->suspendedEditor) {
		isleftdown = false;
		isrightdown = false;
		pickedIndex = -1;
		hasPicked = true;
	}

	if (!gla->suspendedEditor && (isleftdown || isrightdown)) {
		vcg::Point3f point3;
		bool result1 = vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3);
		if (result1) {
			// 找到与当前点击位置最近的点
			if (!hasPicked) {
				double minDis = 1 << 30;
				int minIndex = -1;
				for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
					double dis = (current_model->ctrlPoints[i] - point3).Norm();
					if (dis < minDis) {
						minDis = dis;
						minIndex = i;
					}
				}
				if (minIndex >= 0 && minDis < 0.5) {
					pickedIndex = minIndex;
				}
			}

			if (pickedIndex >= 0) {
				if (isleftdown) { // 移动控制点位置
					current_model->ctrlPoints[pickedIndex] = point3;
				}
				else if (isrightdown) { //删除当前点
					current_model->ctrlPoints.erase(current_model->ctrlPoints.begin() + pickedIndex);
					isrightdown = false;
				}
				doInterpolation();
			}
		}
		hasPicked = true; //只在鼠标左键点下的第一次进行最近点查找工作
	}

	// 如果是双击则重新插值重绘曲线
	if (!gla->suspendedEditor && isdbclicked) {
		vcg::Point3f point3;
		if (vcg::Pick<vcg::Point3f>(curPoint.X(), gla->height() - curPoint.Y(), point3)) {
			int nearestIndex = -1;
			double minDis = 1 << 30;
			for (int j = 0; j < current_model->curve.size(); ++j) {
				double dis = (current_model->curve[j] - point3).Norm();
				if (dis < minDis && dis < 0.5) {
					minDis = dis;
					nearestIndex = j;
				}
			}

			if (nearestIndex != -1) {
				int ctrlIndex = getCtrlIndex(nearestIndex);
				if (ctrlIndex != -1) {
					current_model->ctrlPoints.insert(current_model->ctrlPoints.begin() + ctrlIndex + 1, point3);
				}

			}
			else {
				current_model->ctrlPoints.push_back(point3);
			}
			doInterpolation();
		}
		isdbclicked = false;
	}

	glDisable(GL_LIGHTING);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	//draw curve points
	glColor4f(1, 0, 1, 0.3); //绘制透明刀补区域
	for (int i = 0; i < current_model->curve.size(); ++i) {
		drawSphere(current_model->curve[i].X(), current_model->curve[i].Y(), current_model->curve[i].Z(), default_cut_offset);
	}

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	// 绘制切割曲线的控制点
	glColor4f(1, 0, 0, 1.0);
	for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
		drawSphere(current_model->ctrlPoints[i].X(), current_model->ctrlPoints[i].Y(), current_model->ctrlPoints[i].Z(), 0.3);
	}

	//绘制切割法向
	glColor4f(1, 1, 0, 1.0);
	glLineWidth(1);
	glBegin(GL_LINES);
	for (int i = 0; i < current_model->curveDir.size(); ++i) {
		glVertex3f(current_model->curve[i][0], current_model->curve[i][1], current_model->curve[i][2]);
		glVertex3f(current_model->curve[i][0] + current_model->curveDir[i][0] * 1.5, current_model->curve[i][1] + current_model->curveDir[i][1] * 1.5, current_model->curve[i][2] + current_model->curveDir[i][2] * 1.5);
	}
	glEnd();

	glEnable(GL_LIGHTING);
}

void DrawCurve_EditPlugin::doInterpolation()
{
	MeshModel* current_model = md->mm();
	current_model->curve.clear();

	if (current_model->ctrlPoints.size() <= 2 || current_model->m_AABBTree == nullptr) {
		return;
	}

	//1.估计每两个控制点之间的插值点个数 
	estimatePointNum();
	std::vector<vcg::Point3f> data;
	data.push_back(current_model->ctrlPoints[0] * 1.5 - current_model->ctrlPoints[1] * 0.5);
	for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
		data.push_back(current_model->ctrlPoints[i]);
	}
	data.push_back(current_model->ctrlPoints[current_model->ctrlPoints.size() - 1] * 1.5 - current_model->ctrlPoints[current_model->ctrlPoints.size() - 2] * 0.5);
	current_model->curve = interpolationCurve(data, interpolationNums);

	//2.计算切割方向
	computeDirection();

	//3.将点吸附在牙颌模型上
	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;

	AABBTree* tree = md->mm()->m_AABBTree;

	auto findCtrlpointsIndex = [&](vcg::Point3f& ctrl_p) {
		double nearest_dis = std::numeric_limits<double>::max();
		int nearest_index = -1;
		for (int i = 0; i < current_model->curve.size(); ++i) {
			double dis = vcg::Distance(ctrl_p, current_model->curve[i]);
			if (dis < nearest_dis) {
				nearest_dis = dis;
				nearest_index = i;
			}
		}
		return nearest_index;
	};

	// 投影方法
	std::map<int, int> ctrlpoint_indices;
	for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
		int index = findCtrlpointsIndex(current_model->ctrlPoints[i]);
		ctrlpoint_indices.insert({ index, i });
	}

	bool need_proj = true;
	for (int i = 0; i < current_model->curve.size(); ++i)
	{
		if (ctrlpoint_indices.find(i) != ctrlpoint_indices.end()) { // 当前curve上的点和control points 比较近
			if (interpolationNums[ctrlpoint_indices[i]] <= 5) {
				need_proj = false;
			}
			else {
				need_proj = true;
			}
		}
		if (need_proj) {
			vcg::Point3f projDir = current_model->curveDir[i];
			vcg::Point3f pointToProj = current_model->curve[i] - projDir * 10.0;
			vcg::Ray3<float, false> ray(pointToProj, projDir);
			float rayT;
			CFaceO* isectFace = NULL;
			isectFace = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, rayT);

			if (isectFace) {
				pointToProj = pointToProj + projDir * rayT;
				current_model->curve[i] = pointToProj;
			}
			else {
				std::cout << "missing project\n";
			}
		}
	}
}

void DrawCurve_EditPlugin::doInterpolation2()
{
	MeshModel* current_model = md->mm();
	if (current_model->ctrlPoints.size() < 2) {
		return;
	}
	geodesic::GeodesicAlgorithmExact algorithm(&current_model->mesh_geodesic);

	std::vector<geodesic::SurfacePoint> path;
	//geodesic::SurfacePoint source(&current_model->mesh_geodesic.vertices()[0]);
	//geodesic::SurfacePoint target(&current_model->mesh_geodesic.vertices()[100]);
	// 
	//for (int i = 0; i < current_model->ctrlPoints.size() - 1; ++i) {
	for (int i = 0; i < 1; ++i) {
		std::vector<geodesic::SurfacePoint> path;
		geodesic::SurfacePoint source;
		geodesic::SurfacePoint target;
		source.set(current_model->ctrlPoints[i][0], current_model->ctrlPoints[i][1], current_model->ctrlPoints[i][2]);
		target.set(current_model->ctrlPoints[i + 1][0], current_model->ctrlPoints[i + 1][1], current_model->ctrlPoints[i + 1][2]);

		std::cout << "start at " << i << ", path to " << i + 1 << std::endl;
		algorithm.geodesic(source, target, path);
		qDebug() << "path size " << path.size();
		for (int j = 0; j < path.size(); ++j) {
			current_model->curve.push_back(vcg::Point3f(path[j].x(), path[j].y(), path[j].z()));
		}
	}
}

void DrawCurve_EditPlugin::computeDirection()
{
	MeshModel* current_model = md->mm();
	current_model->curveDir.clear();
	vcg::Point3f z(0.0, 0.0, 1.0);
	for (int i = 0; i < current_model->curve.size() - 1; ++i) {
		vcg::Point3f pNext = (current_model->curve[i + 1] - current_model->curve[i]).Normalize();
		vcg::Point3f outDir = pNext ^ z;
		outDir = outDir.Normalize();
		outDir.Z() = -tan(45.0 / 180.0 * 3.1415926);
		outDir = outDir.Normalize();

		current_model->curveDir.push_back(outDir);
	}
	current_model->curveDir.push_back(current_model->curveDir.back());
}

void DrawCurve_EditPlugin::estimatePointNum()
{
	MeshModel* current_model = md->mm();
	interpolationNums.clear();
	for (int i = 1; i < current_model->ctrlPoints.size(); ++i) {
		double dis = (current_model->ctrlPoints[i] - current_model->ctrlPoints[i - 1]).Norm();
		int num = floor(dis / interval);
		interpolationNums.push_back(num);
	}
}

/* @param int pIndex 给定点在插值曲线curve中的索引
 * @return 返回对应的左侧端点（控制点）的索引i，
*/
int DrawCurve_EditPlugin::getCtrlIndex(int pIndex)
{
	int totalNum = 0;
	int index = -1;
	if (pIndex == 0) {
		return -1;
	}
	for (index = 0; index < interpolationNums.size(); ++index) {
		totalNum += interpolationNums[index] + 1;
		if (totalNum > pIndex) {
			return index;
		}
		else if (totalNum == pIndex) {
			return -1;
		}
	}
	return -1;
}

void DrawCurve_EditPlugin::exportCutLine(QString outPath, MeshModel* exportModel)
{
	QString model_name = exportModel->label().mid(0, exportModel->label().lastIndexOf('.'));
	QStringList datalist = model_name.split('_');
	if (datalist.size() < 3) {
		return;
	}

	QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
	QString currentJaw = datalist[1];
	QString id = QString("%1").arg(parameter_widget_ui.lineEdit_PatientID->text(), 6, QLatin1Char('0'));
	QString modelName = id + currentJaw + step;

	//1.导出控制点
	QString ctrlPointsPath = outPath + "/ctrl_" + id + "_" + currentJaw + "_" + step + ".txt";
	QFile outFile(ctrlPointsPath);
	if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		std::cout << "Can't save control files.\n";
	}
	else {
		QTextStream out(&outFile);
		for (int i = 0; i < exportModel->ctrlPoints.size(); ++i) {
			out << exportModel->ctrlPoints[i].X() << " " << exportModel->ctrlPoints[i].Y() << " " << exportModel->ctrlPoints[i].Z() << '\n';
		}
		outFile.close();
	}

	// 2.导出切割线
	if (exportModel->pointsForLaser.size() < 2 || exportModel->curve.size() < 2) {
		return;
	}
	if (exportModel->pointsForLaser[0].Y() < 0) {  //防止左右点反
		vcg::Point3f p = exportModel->pointsForLaser[1];
		exportModel->pointsForLaser[1] = exportModel->pointsForLaser[0];
		exportModel->pointsForLaser[0] = p;
	}

	QString cutPointsPath = outPath + "/" + modelName + ".txt";
	QFile outFile2(cutPointsPath);
	if (!outFile2.open(QIODevice::WriteOnly | QIODevice::Text)) {
		//QMessageBox::critical(nullptr, tr("Error"), tr("Can't save cutine files."), QMessageBox::Ok);
		std::cout << "Can't save cutline files.\n";
		return;
	}

	//重新计算切割角度（区分颊舌侧）
	recomputeCutDirection(exportModel);

	QTextStream exput(&outFile2);
	exput << "HEAD\n";

	exput << "logo1=";
	exput << exportModel->pointsForLaser[1].X() << " " << exportModel->pointsForLaser[1].Y() << " " << exportModel->pointsForLaser[1].Z() << "/";
	exput << currentJaw + datalist[2] << "\n";

	exput << "logo2=";
	exput << exportModel->pointsForLaser[0].X() << " " << exportModel->pointsForLaser[0].Y() << " " << exportModel->pointsForLaser[0].Z() << "/";
	exput << parameter_widget_ui.lineEdit_PatientID->text() << "\n";

	exput << "END\n";

	for (int i = 0; i < exportModel->curve.size(); i++) {
		vcg::Point3f epi = exportModel->curve[i];
		vcg::Point3f epin = exportModel->curveDir[i];
		exput << epi.X() << " " << epi.Y() << " " << epi.Z() << " " << epin.X() << " " << epin.Y() << " " << epin.Z() << "\n";
	}
	exput << "END" << "\n";
	outFile2.close();
}

void DrawCurve_EditPlugin::generateBaseModel(MeshModel* exportModel)
{
	QString dir = QCoreApplication::applicationDirPath();
	QString model_name = exportModel->label().mid(0, exportModel->label().lastIndexOf('.'));
	QStringList datalist = model_name.split('_');
	if (datalist.size() < 3) {
		return;
	}
	QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
	QString currentJaw = datalist[1];
	QString id = parameter_widget_ui.lineEdit_PatientID->text();

	step = QString("%1").arg(step, 2, QLatin1Char('0'));
	id = QString("%1").arg(id, 6, QLatin1Char('0'));

	exportModel->setLabel(id + "_" + currentJaw + "_" + step + ".stl");
	QString information = id + currentJaw + step;

	//1. 生成二维码模型
	if (exportModel->qr_mesh == nullptr) {
		CMeshO* qr_mesh = generateQRMesh(information, 21, qr_info.qr_width, qr_info.qr_height);

		//将二维码模型平移到相应位置
		vcg::Matrix44f trans_matrix;
		trans_matrix.SetIdentity();
		trans_matrix.SetTranslate(vcg::Point3f(-qr_info.qr_width / 2.0, -qr_info.qr_width / 2.0, qr_info.qr_height - 0.1));
		vcg::tri::UpdatePosition<CMeshO>::Matrix(*qr_mesh, trans_matrix, true);
		exportModel->qr_mesh = qr_mesh;
	}

	//2.动态生成底座模型
	if (exportModel->base_mesh == nullptr) {
		CMeshO* base_mesh = generateBaseMesh(qr_info.width, qr_info.length, qr_info.height, qr_info.theta, qr_info.dim, exportModel->m_AABBTree);
		exportModel->base_mesh = base_mesh;
	}

	//3.生成info模型
	if (exportModel->info_mesh == nullptr) {
		exportModel->info_mesh = generateInfoMesh(information);
	}
}

void DrawCurve_EditPlugin::recomputeCutDirection(MeshModel* exportModel)
{
	std::vector<double> X, Y, Z;
	std::vector<double> Xout, Yout, Zout;
	std::vector<vcg::Point3f> pointsAfterSmooth;
	for (int i = exportModel->curve.size() - 10; i < exportModel->curve.size(); ++i) {
		X.push_back(exportModel->curve[i].X());
		Y.push_back(exportModel->curve[i].Y());
		//Z.push_back(curve[i].Z());
	}
	for (int i = 0; i < exportModel->curve.size(); ++i) {
		X.push_back(exportModel->curve[i].X());
		Y.push_back(exportModel->curve[i].Y());
		//Z.push_back(curve[i].Z());
	}
	for (int i = 0; i < 10; ++i) {
		X.push_back(exportModel->curve[i].X());
		Y.push_back(exportModel->curve[i].Y());
		//Z.push_back(curve[i].Z());
	}
	Xout = sg_smooth(X, 20, 3);
	Yout = sg_smooth(Y, 20, 3);
	pointsAfterSmooth.resize(exportModel->curve.size());
	for (int i = 10; i < Xout.size() - 10; ++i) {
		pointsAfterSmooth[i - 10].X() = Xout[i];
		pointsAfterSmooth[i - 10].Y() = Yout[i];
		pointsAfterSmooth[i - 10].Z() = 0.0;//Zout[i];
	}

	//计算颊舌侧起始点
	int start = 0;
	int end = 0;
	float minX = std::numeric_limits<float>::max();
	for (int i = 0; i < exportModel->curve.size(); ++i)
	{
		if (exportModel->curve[i].Y() > 0 && exportModel->curve[i].X() < minX) {
			minX = exportModel->curve[i].X();
			start = i;
		}
	}
	minX = std::numeric_limits<float>::max();
	for (int i = 0; i < exportModel->curve.size(); ++i)
	{
		if (exportModel->curve[i].Y() < 0 && exportModel->curve[i].X() < minX) {
			minX = exportModel->curve[i].X();
			end = i;
		}
	}

	int start_buccal = (start + 10) % exportModel->curve.size();
	int end_buccal = end - 10;
	if (start_buccal > end_buccal) {
		end_buccal += exportModel->curve.size();
	}

	int start_lingual = end_buccal;
	int end_lingual = start_buccal;
	while (start_lingual > end_lingual) {
		end_lingual += exportModel->curve.size();
	}

	// 重新计算切割方向（按照平滑过后的曲线计算）
	exportModel->curveDir.clear();
	exportModel->curveDir.resize(exportModel->curve.size());
	vcg::Point3f z(0.0, 0.0, 1.0);
	for (int i = start_buccal; i < end_buccal; i++) {
		int index = i % exportModel->curve.size();
		int indexNext = (i + 1) % exportModel->curve.size();

		vcg::Point3f pNext = (pointsAfterSmooth[indexNext] - pointsAfterSmooth[index]).Normalize();
		vcg::Point3f outDir = pNext ^ z;
		outDir = outDir.Normalize();
		outDir.Z() = -tan(15.0 / 180.0 * 3.1415926);
		outDir = outDir.Normalize();

		exportModel->curveDir[index] = outDir;
	}
	for (int i = start_lingual; i < end_lingual; i++) {
		int index = i % exportModel->curve.size();
		int indexNext = (i + 1) % exportModel->curve.size();

		vcg::Point3f pNext = (pointsAfterSmooth[indexNext] - pointsAfterSmooth[index]).Normalize();
		vcg::Point3f outDir = pNext ^ z;
		outDir = outDir.Normalize();
		outDir.Z() = -tan(30.0 / 180.0 * 3.1415926);
		outDir = outDir.Normalize();

		exportModel->curveDir[index] = outDir;
	}
}

void DrawCurve_EditPlugin::moveDownGumLine(MeshModel* current_model, double move_distance)
{
	if (current_model == nullptr || current_model->curve.empty()
		|| current_model->ctrlPoints.empty() || current_model->m_AABBTree == nullptr) {
		return;
	}

	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;
	AABBTree* tree = current_model->m_AABBTree;

	std::vector<vcg::Point3f>& curve_points = current_model->curve;
	std::vector<vcg::Point3f>& curve_dirs = current_model->curveDir;

	auto getCtrlIndex = [&](vcg::Point3f& p) {
		float nearest_dis = std::numeric_limits<float>::max();
		int index = -1;
		for (int i = 0; i < curve_points.size(); ++i) {
			float distance = vcg::Distance(curve_points[i], p);
			if (distance < nearest_dis) {
				nearest_dis = distance;
				index = i;
			}
		}
		return index;
	};

	for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
		int index = getCtrlIndex(current_model->ctrlPoints.at(i));
		vcg::Point3f proj_dir = curve_dirs.at(index);
		vcg::Point3f proj_p = current_model->ctrlPoints.at(i) - proj_dir * 10 + vcg::Point3f(0.0, 0.0, -1.0) * move_distance;
		vcg::Ray3fN ray;
		float ray_distance;
		ray.Set(proj_p, proj_dir);
		CFaceO* isect_face = tree->DoRay(rayIntersector, objectMarker, ray, maxDist, ray_distance);
		if (isect_face) {
			current_model->ctrlPoints.at(i) = proj_p + proj_dir * ray_distance;
		}
	}

	doInterpolation();

}

void DrawCurve_EditPlugin::exportLaserCutline(QString outPath, MeshModel* current_model)
{
	if (current_model == nullptr || current_model->curve.empty()) {
		return;
	}

	QString model_name = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
	QStringList datalist = model_name.split('_');
	if (datalist.size() < 3) {
		return;
	}

	QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
	QString currentJaw = datalist[1];
	QString id = QString("%1").arg(parameter_widget_ui.lineEdit_PatientID->text(), 6, QLatin1Char('0'));
	QString modelName = id + currentJaw + step;

	initialLaserCutlineParameter();

	//1.激光器位于X轴，将模型沿Z轴旋转-90度，使得开始切割线段面向激光器
	vcg::Matrix44f r;
	r.SetIdentity();
	r.SetRotateDeg(90, vcg::Point3f(0.0, 0.0, -1.0));
	for (int i = 0; i < current_model->curve.size(); ++i) {
		vcg::Point3f p = current_model->curve[i];
		p = r * p;
		current_model->curve[i] = p;
		cutlineToLaser.push_back(p);
	}
	initialCutline.resize(current_model->curve.size());

	//2.根据物理路径查找切割的起始点和终止点
	double maxY = std::numeric_limits<double>::min();
	for (int i = 0; i < cutlineToLaser.size(); ++i) {
		if (cutlineToLaser[i].X() > 0 && cutlineToLaser[i].Y() > maxY) {
			buccalStart = i;
			maxY = cutlineToLaser[i].Y();
		}
	}
	maxY = std::numeric_limits<double>::min();
	for (int i = 0; i < cutlineToLaser.size(); ++i) {
		if (cutlineToLaser[i].X() < 0 && cutlineToLaser[i].Y() > maxY) {
			buccalEnd = i;
			maxY = cutlineToLaser[i].Y();
		}
	}

	lingualStart = (buccalStart - 4 + cutlineToLaser.size()) % cutlineToLaser.size();
	buccalStart = (buccalStart + 4) % cutlineToLaser.size();

	lingualEnd = (buccalEnd + 4) % cutlineToLaser.size();
	buccalEnd = (buccalEnd - 4 + cutlineToLaser.size()) % cutlineToLaser.size();

	startIndex = lingualStart;
	endIndex = buccalStart;

	stagePointNumber = buccalEnd - buccalStart;
	if (stagePointNumber < 0) {
		stagePointNumber += cutlineToLaser.size();
	}
	stagePointNumber = int(stagePointNumber / segNumBuccal);

	//3.调整切割姿态，使当前切割线段尽量垂直激光器的发射方向 adjust the posture
	vcg::Point3f OA = cutlineToLaser[startIndex];
	vcg::Point3f OB = cutlineToLaser[endIndex];
	vcg::Point3f xAxis(1.0, 0.0, 0.0);
	double degree = 0.0;
	vcg::Matrix44f rotateMatrixAdjust = adjustDirectionToXorYAxis(OA, OB, xAxis, degree);

	//4.将当前切割线段的中点平移到原点
	vcg::Point3f A_ = rotateMatrixAdjust * OA;
	vcg::Point3f B_ = rotateMatrixAdjust * OB;
	vcg::Point3f C_ = (A_ + B_) / 2.0;

	vcg::Matrix44f transMatrixAdjust;
	transMatrixAdjust.SetIdentity();
	transMatrixAdjust.SetTranslate(-C_);

	//5.读取切割角度
	double degreeY = 30;
	if (degreeForEachPath.size() == totalSegNum) { //是否已经从文件中读取切割角度
		degreeY = degreeForEachPath[currentSeg];
	}
	else {
		degreeY = 30;
	}

	vcg::Matrix44f rotateMatrixY;
	rotateMatrixY.SetRotateDeg(degreeY, vcg::Point3f(0.0, 1.0, 0.0));

	//6.存储机械手的位置
	position[currentSeg].resize(6);
	position[currentSeg][0] = -C_.X();
	position[currentSeg][1] = -C_.Y();
	position[currentSeg][2] = -C_.Z();
	position[currentSeg][3] = 0.0;
	position[currentSeg][4] = degreeY;
	position[currentSeg][5] = degree - 90;

	for (int i = 0; i < cutlineToLaser.size(); ++i) {
		initialCutline[i] = rotateMatrixAdjust * current_model->curve[i];
		cutlineToLaser[i] = rotateMatrixY * initialCutline[i];
		cutlineToLaser[i] = transMatrixAdjust * cutlineToLaser[i];
	}

	//7. 生成切割路径
	QString filename = outPath + "/" + modelName + ".txt";;
	QFile outFile(filename);
	QTextStream exput(&outFile);

	if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		exput << "HEAD\n";
		if (current_model->pointsForLaser.size() == 2) {
			exput << "logo1=";
			exput << current_model->pointsForLaser[1].X() << " " << current_model->pointsForLaser[1].Y() << " " << -current_model->pointsForLaser[1].Z() << "/";
			exput << currentJaw + datalist[2] << "\n";

			exput << "logo2=";
			exput << current_model->pointsForLaser[0].X() << " " << current_model->pointsForLaser[0].Y() << " " << -current_model->pointsForLaser[0].Z() << "/";
			exput << parameter_widget_ui.lineEdit_PatientID->text() << "\n";
		}
		exput << "ENDPRINT\n";

		exput << "HEAD\n";
		exput << totalSegNum << "\n";
		exput << "END\n";

		const int N = 1; //每个激光切割片段之间往后延伸的点的个数
		const double backDistance = 0.05;

		//7.1 先保存第一段切割线段
		std::vector<vcg::Point3f> oneline2;
		//std::vector<vcg::Point3f> oneline2Copy;
		vcg::Point3f lastPoint;
		int index = startIndex;
		do {
			oneline2.push_back(cutlineToLaser[index]);
			index = (index + cutDirection) % cutlineToLaser.size();
		} while (index != endIndex);

		oneline2.push_back(cutlineToLaser[index]);
		lastPoint = cutlineToLaser[index];

		// 往后延伸N + 1个点
		for (int k = 0; k < N + 1; ++k) {
			index = (index + cutDirection) % cutlineToLaser.size();

			// 延伸点错位切割
			vcg::Point3f backDir = (lastPoint - cutlineToLaser[index]).Normalize();
			oneline2.push_back(cutlineToLaser[index] + backDir * backDistance);

			lastPoint = cutlineToLaser[index];
		}

		// 对于第一段往前延伸N + 3个点
		index = startIndex;
		lastPoint = cutlineToLaser[index];
		for (int k = 0; k < N + 3; ++k) {
			index = index - cutDirection;
			if (index < 0) {
				index = (index + cutlineToLaser.size()) % cutlineToLaser.size();
			}

			//对延伸点往回缩进一下，防止拼接点重复切割
			vcg::Point3f backDir = (lastPoint - cutlineToLaser[index]).Normalize();
			oneline2.insert(oneline2.begin(), cutlineToLaser[index] + backDir * backDistance);

			lastPoint = cutlineToLaser[index];
		}
		cutseg.push_back(oneline2);

		//7.2 再保存其他每一段切割线的位置
		for (int i = 0; i < totalSegNum - 1; ++i) {
			rotateJawModel(current_model);

			std::vector<vcg::Point3f> oneline2;
			//std::vector<vcg::Point3f> oneline2Copy;

			int index = startIndex;
			vcg::Point3f lastPoint;
			do {
				oneline2.push_back(cutlineToLaser[index]);
				index = index + cutDirection;
				if (index > 0 && index >= cutlineToLaser.size()) { // 负的int 对 unsigned int取余会有问题 
					index = index % cutlineToLaser.size();
				}
				else {
					if (index < 0) {
						index = index + int(cutlineToLaser.size());
					}
				}
			} while (index != endIndex);

			oneline2.push_back(cutlineToLaser[index]);
			lastPoint = cutlineToLaser[index];

			int extraNum = N;
			if (i == totalSegNum - 2) { //最后一个尾巴 多延伸2个点
				extraNum = N + 3;
			}

			for (int k = 0; k < extraNum; ++k) {
				index = index + cutDirection;
				if (cutDirection > 0) {
					index = index % cutlineToLaser.size();
				}
				else {
					if (index < 0) {
						index = index + cutlineToLaser.size();
					}
				}
				vcg::Point3f backDir = (lastPoint - cutlineToLaser[index]).Normalize();
				oneline2.push_back(cutlineToLaser[index] + backDir * backDistance);
				lastPoint = cutlineToLaser[index];
			}
			cutseg.push_back(oneline2);

			//if (i < segNumBuccal){
			//	copySegment(oneline2Copy, oneline2, 3);
			//}
			//else if(i < totalSegNum - 2){
			//	copySegment(oneline2Copy, oneline2, 3);
			//}
			//else{
			//	copySegment(oneline2Copy, oneline2, 3);
			//}
			//cutseg.push_back(oneline2Copy);
		}

		//8. 保存的内容输出到文件
		exput << "HEAD\n";
		for (int i = 0; i < position.size(); ++i) {
			if (position[i].size() < 6) {
				continue;
			}
			for (int j = 0; j < 6; j++) {
				if (j == 2) {
					position[i][j] -= laserPos.Z();
				}
				QString data = QString::number(position[i][j], 'f', 4);
				QByteArray dataBa = data.toLatin1();
				char* dataChar = dataBa.data();
				exput << dataChar << " ";
			}
			exput << "\n";
		}
		exput << "ENDROBOT\n";

		// 切割段数
		exput << "HEAD\n";

		exput << "N" << parameter_widget_ui.spinBox_rear->value() << "\n";
		for (int i = 1; i < segNumBuccal + 1; ++i) {
			exput << "N" << parameter_widget_ui.spinBox_buccal->value() << "\n";
		}
		for (int i = segNumBuccal + 1; i < totalSegNum - 1; ++i) {
			exput << "N" << parameter_widget_ui.spinBox_lingual->value() << "\n";
		}
		exput << "N" << parameter_widget_ui.spinBox_rear->value() << "\n";
		exput << "END\n";

		for (int i = 0; i < position.size(); ++i) {
			exput << "HEAD" << i + 1 << "\n";

			for (int j = 0; j < cutseg[i].size(); ++j) {
				exput << QString::number(cutseg[i][j].Y(), 'f', 4) << " ";
				exput << QString::number(cutseg[i][j].Z() - laserPos.Z(), 'f', 4) << " ";
				exput << QString::number(cutseg[i][j].X(), 'f', 4) << "\n";
			}

			exput << "END" << i + 1 << "\n";
		}
		outFile.close();
	}

	//使切割线显示正常
	r.SetIdentity();
	r.SetRotateDeg(90, vcg::Point3f(0.0, 0.0, 1.0));
	for (int i = 0; i < current_model->curve.size(); ++i) {
		vcg::Point3f p = current_model->curve[i];
		p = r * p;
		current_model->curve[i] = p;
	}
}

void DrawCurve_EditPlugin::rotateJawModel(MeshModel* current_model)
{
	currentSeg = currentSeg + 1;
	if (currentSeg == totalSegNum) {
		return;
	}

	//std::cout << __FUNCTION__ << " " << currentSeg << std::endl;
	vcg::Matrix44f rotateMatrixX, rotateMatrixY, rotateMatrixAdjust, transMatrix;
	rotateMatrixY.SetIdentity();
	rotateMatrixX.SetIdentity();
	rotateMatrixAdjust.SetIdentity();
	transMatrix.SetIdentity();

	if (currentSeg == 1) { // 颊侧第一段
		startIndex = buccalStart;
		endIndex = (startIndex + stagePointNumber) % (cutlineToLaser.size());
	}
	else if (currentSeg == segNumBuccal + 1) {// 开始切割舌侧
		//std::cout << "切换至舌侧切割" << std::endl;
		cutDirection = -1;

		// 重新读取切割点
		cutlineToLaser.clear();
		initialCutline.clear();
		for (int i = 0; i < current_model->curve.size(); ++i) {
			vcg::Point3f p = current_model->curve[i];
			cutlineToLaser.push_back(p);
			initialCutline.push_back(p);
		}

		// 计算舌侧切割点的个数
		stagePointNumber = lingualStart - lingualEnd;
		if (stagePointNumber < 0) {
			stagePointNumber += cutlineToLaser.size();
		}
		stagePointNumber = int(stagePointNumber / segNumLingual);

		startIndex = lingualStart;
		endIndex = (startIndex - stagePointNumber + cutlineToLaser.size()) % (cutlineToLaser.size());

	}
	else if (currentSeg == totalSegNum - 1) { // 切割最后一段（右侧尾巴）
		startIndex = lingualEnd;
		endIndex = buccalEnd;
	}
	else { // 切割颊侧或者舌侧
		if (cutDirection == 1) {
			startIndex = (startIndex + stagePointNumber) % (cutlineToLaser.size());
			endIndex = (startIndex + stagePointNumber) % (cutlineToLaser.size());
			if (currentSeg == segNumBuccal) { // 颊侧最后一段
				endIndex = buccalEnd;
			}
		}
		else {
			startIndex = (startIndex - stagePointNumber + cutlineToLaser.size()) % (cutlineToLaser.size());
			endIndex = (startIndex - stagePointNumber + cutlineToLaser.size()) % (cutlineToLaser.size());
			if (currentSeg == totalSegNum - 2) { // 舌侧最后一段
				endIndex = lingualEnd;
			}
		}
	}

	// 微调切割角度，使y轴位于激光位置为顶点和切割路径起始端点组成的角的平分线上
	vcg::Point3f OA = initialCutline[startIndex];
	vcg::Point3f OB = initialCutline[endIndex];
	//vcg::Point3f yAxis(0.0, 1.0, 0.0);
	vcg::Point3f xAxis(1.0, 0.0, 0.0);
	double degree = 0.0;
	double degreeY = 0.0;
	xAxis = xAxis * cutDirection;
	rotateMatrixAdjust = adjustDirectionToXorYAxis(OA, OB, xAxis, degree);
	if (currentSeg != 0 && currentSeg != segNumBuccal + 1) {
		degree += position[currentSeg - 1][5];
	}
	else { //舌侧或者颊侧的第一段
		degree = degree - 90;
	}

	vcg::Matrix44f rotateMatrixZ; // test矩阵根据position中的 rz 转换而来
	rotateMatrixZ.SetIdentity();
	rotateMatrixZ.SetRotateDeg(degree, vcg::Point3f(0.0, 0.0, 1.0));
	degree = fmod(degree, 360);

	//是否绕Y轴旋转
	if (degreeForEachPath.size() == totalSegNum) {
		degreeY = degreeForEachPath[currentSeg];
	}
	else {
		if (currentSeg > segNumBuccal && currentSeg < totalSegNum - 1) { // 舌侧倾斜20度, 防止干涉
			degreeY = 20;
		}
		else if (currentSeg <= segNumBuccal) {    //颊侧倾斜10度
			degreeY = 10;
		}
		else if (currentSeg == totalSegNum - 1) {//尾巴上的点
			degreeY = 30;
		}
	}

	rotateMatrixY.SetRotateDeg(degreeY, vcg::Point3f(0.0, 1.0, 0.0));

	//将AB的中点平移到原点
	vcg::Point3f A_ = rotateMatrixY * rotateMatrixAdjust * OA;
	vcg::Point3f B_ = rotateMatrixY * rotateMatrixAdjust * OB;
	vcg::Point3f C_ = (A_ + B_) / 2.0;

	vcg::Matrix44f transMatrixAdjust;
	transMatrixAdjust.SetIdentity();
	transMatrixAdjust.SetTranslate(-C_);

	// 存储机械手的位置
	position[currentSeg].resize(6);
	position[currentSeg][0] = -C_.X();
	position[currentSeg][1] = -C_.Y();
	position[currentSeg][2] = -C_.Z();

	position[currentSeg][3] = 0.0;
	position[currentSeg][4] = degreeY;
	position[currentSeg][5] = degree;

	for (int i = 0; i < cutlineToLaser.size(); ++i) {
		initialCutline[i] = rotateMatrixAdjust * initialCutline[i];
		cutlineToLaser[i] = rotateMatrixY * initialCutline[i];
		cutlineToLaser[i] = transMatrixAdjust * cutlineToLaser[i];
	}
}

/*
* 将三角形OAB绕O旋转，使AB边垂直于Y轴或者X轴
* @param O是原点 AB是任意两点 yAxis是Y(X)轴或者Y(X)负轴向量, degree 是此次调整绕Z轴旋转的角度
* @return 旋转矩阵
*/
vcg::Matrix44f DrawCurve_EditPlugin::adjustDirectionToXorYAxis(vcg::Point3f& OA, vcg::Point3f& OB, vcg::Point3f& yAxis, double& degree)
{
	vcg::Matrix44f rotateMatrixAdjust;
	vcg::Point3f zAxis(0.0, 0.0, 1.0);
	vcg::Point3f AB = OB - OA;
	OA.Z() = OB.Z() = 0.0;
	vcg::Point3f target_ = ((-AB) ^ zAxis).Normalize();

	double rotateRad = std::acos(target_ * yAxis);
	vcg::Point3f rotateAxis = (target_ ^ yAxis).Normalize();
	rotateMatrixAdjust.SetIdentity();
	rotateMatrixAdjust.SetRotateRad(rotateRad, rotateAxis);

	int dir = rotateAxis * zAxis;
	degree = dir * 180 * rotateRad / FPI;

	return rotateMatrixAdjust;
}

void DrawCurve_EditPlugin::initialLaserCutlineParameter()
{
	startIndex = 0;
	endIndex = 0;
	segNumBuccal = 9;
	segNumLingual = 9;
	currentSeg = 0;
	totalSegNum = segNumBuccal + segNumLingual + 2;
	position.resize(totalSegNum);
	laserPos.X() = 240.0;
	laserPos.Z() = 20;
	laserPos.Y() = 0;
	cutDirection = 1; // start from buccal side

	cutseg.clear();
	initialCutline.clear();
	cutlineToLaser.clear();

	QString configFile = QCoreApplication::applicationDirPath() + QString("/cutdegree.txt");
	degreeForEachPath.clear();
	QFile configInfile(configFile);
	if (configInfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		while (!configInfile.atEnd()) {
			QString line = configInfile.readLine();
			degreeForEachPath.push_back(line.toDouble());
		}
	}
}

void DrawCurve_EditPlugin::importOneCtrlPoints(MeshModel* current_model, QString& file_path)
{
	if (file_path.isNull() || file_path.isEmpty()) {
		return;
	}

	if (current_model->m_AABBTree == nullptr) {
		current_model->m_AABBTree = new AABBTree();
		current_model->m_AABBTree->Set(current_model->cm.face.begin(), current_model->cm.face.end());
	}

	QFile inFile(file_path);
	current_model->ctrlPoints.clear();
	if (inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		while (!inFile.atEnd()) {
			QString data = inFile.readLine();

			QStringList strList = data.split(' ');
			if (strList.size() < 3) {
				continue;
			}
			float x = strList[0].toFloat();
			float y = strList[1].toFloat();
			float z = strList[2].toFloat();

			current_model->ctrlPoints.push_back(vcg::Point3f(x, y, z));
		}
	}
	inFile.close();

	// project control points on model
	const float maxDist = std::numeric_limits<float>::max();
	vcg::face::PointDistanceBaseFunctor<float> pointFaceFunctor;
	vcg::RayTriangleIntersectionFunctor<false> rayIntersector;
	vcg::EmptyClass objectMarker;

	for (int i = 0; i < current_model->ctrlPoints.size(); ++i) {
		vcg::Point3f p_pnext;
		if (i == current_model->ctrlPoints.size() - 1) {
			p_pnext = (current_model->ctrlPoints[i] - current_model->ctrlPoints[i - 1]).Normalize();
		}
		else {
			p_pnext = (current_model->ctrlPoints[i + 1] - current_model->ctrlPoints[i]).Normalize();
		}
		vcg::Point3f proj_dir = p_pnext ^ vcg::Point3f(0.0, 0.0, 1.0);
		vcg::Point3f p_proj = current_model->ctrlPoints[i] - proj_dir * 10.0;
		vcg::Ray3<float, false> ray(p_proj, proj_dir);
		float proj_distance;
		CFaceO* isectFace = NULL;
		isectFace = current_model->m_AABBTree->DoRay(rayIntersector, objectMarker, ray, maxDist, proj_distance);
		if (isectFace) {
			current_model->ctrlPoints[i] = p_proj + proj_dir * proj_distance;
		}
	}
}

/**********************************************************************************************************/

AutoHollow_EditPlugin::AutoHollow_EditPlugin() {

}

bool AutoHollow_EditPlugin::StartEdit(MeshDocument& md, GLArea* gla, MLSceneGLSharedDataContext* con)
{
	this->gla = gla;
	this->md = &md;

	if (hollow_dialog == nullptr) {
		hollow_dialog = new QDialog();
		hollow_ui.setupUi(hollow_dialog);
		connect(hollow_dialog, &QDialog::accepted, this, [&]() {
			//1.选择数据文件夹
			QString inputpath = QFileDialog::getExistingDirectory(nullptr, QString("Input Directory.."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
			if (inputpath.isNull() || inputpath.isEmpty()) {
				return false;
			}

			QString jaw = inputpath.split('/').back();
			QDir input_dir(inputpath);
			QStringList dir_list = input_dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

			QString outpath = inputpath + "/output";
			if (!QDir(outpath).exists()) {
				QDir().mkpath(outpath);
			}

			#pragma omp parallel for num_threads(10)		
			for (int d = 0; d < dir_list.size(); ++d)
			{
				QString dir_name = dir_list.at(d);
				qDebug() << QString("***Start working on Thread %1, deal with %2***").arg(omp_get_thread_num()).arg(dir_name);

				bool ok;
				int step = dir_name.mid(0, dir_name.indexOf(QRegularExpression("[^\\d]"))).toInt(&ok);

				if (ok) {//确认是存放当前步骤的文件夹
					//读入所有模型, 牙龈单独处理
					QDir model_dir(inputpath + '/' + dir_name);
					QStringList model_name_list = model_dir.entryList(QDir::Files);
					MeshModel current_model(nullptr, "", jaw + "_" + dir_name + ".stl");
					CMeshO* gum_mesh   = nullptr;
					CMeshO* teeth_mesh = nullptr;

					for (QString& model_name : model_name_list) {
						QString model_path = inputpath + '/' + dir_name + QString('/') + model_name;
						std::string model_path_str = model_path.toLocal8Bit().constData();

						int load_mask = 0;
						QString prefix = model_name.mid(0, 2);

						if (prefix == QString("co")) { //is connector
							continue;
						}
						else if (prefix == QString("ma")) {// is marker
							current_model.info_mesh = new CMeshO();
							vcg::tri::io::ImporterSTL<CMeshO>::Open(*current_model.info_mesh, model_path_str.c_str(), load_mask);
							vcg::tri::UpdateBounding<CMeshO>::Box(*current_model.info_mesh);

							// only when reas '.stl' files will encounter this kind of problems
							int total = vcg::tri::Clean<CMeshO>::MergeCloseVertex(*current_model.info_mesh, current_model.info_mesh->bbox.Diag() / 10000.0);
							current_model.info_mesh->vert.EnableVFAdjacency();
							current_model.info_mesh->face.EnableVFAdjacency();
							current_model.info_mesh->face.EnableFFAdjacency();
							vcg::tri::UpdateTopology<CMeshO>::FaceFace(*current_model.info_mesh);
							vcg::tri::UpdateTopology<CMeshO>::VertexFace(*current_model.info_mesh);

							int filled_hole_num = vcg::tri::Hole<CMeshO>::EarCuttingFill<vcg::tri::MinimumWeightEar< CMeshO> >(*current_model.info_mesh, 100);
						}
						else if (prefix == QString("QR")) {// is QR code
							current_model.qr_mesh = new CMeshO();
							vcg::tri::io::ImporterSTL<CMeshO>::Open(*current_model.qr_mesh, model_path_str.c_str(), load_mask);
						}
						else if (prefix[1] == QChar('0')) { // is gum
							qDebug() << "Read and Hollow gum model...";
							CMeshO* temp_gum = new CMeshO();
							vcg::tri::io::ImporterSTL<CMeshO>::Open(*temp_gum, model_path_str.c_str(), load_mask);
							gum_mesh = hollowGum(temp_gum);
						}
						else if (model_name.mid(2, 2) == QString("In")) {
							current_model.intersected_mesh = new CMeshO();
							vcg::tri::io::ImporterSTL<CMeshO>::Open(*current_model.intersected_mesh, model_path_str.c_str(), load_mask);
						}
						else // is other model attachment
						{
							auto isTeeth = [&]() {
								model_name = model_name.mid(0, model_name.lastIndexOf('.'));// remove suffix
								if (model_name.size() == 3) {
									if (model_name.mid(0, 2) == "UR" || model_name.mid(0, 2) == "UL" ||
										model_name.mid(0, 2) == "LR" || model_name.mid(0, 2) == "LL") {
										return true;
									}
								}
								return false;
							};

							CMeshO* othermesh = new CMeshO();
							vcg::tri::io::ImporterSTL<CMeshO>::Open(*othermesh, model_path_str.c_str(), load_mask);

							if (hollow_ui.checkBox_unionTeeth->isChecked() && isTeeth()) {
								//clean teeth mesh
								othermesh = cleanMesh(othermesh);
								vcg::tri::Append<CMeshO, CMeshO>::Mesh(*teeth_mesh, *othermesh);
							}
							else {
								vcg::tri::Append<CMeshO, CMeshO>::Mesh(current_model.cm, *othermesh);
							}
							delete othermesh;
						}
					}

					// generate Base models
					AABBTree* gum_tree = new AABBTree();
					gum_tree->Set(gum_mesh->face.begin(), gum_mesh->face.end());
					current_model.base_mesh = generateBaseMesh(15, 20, 1.5, 30, 20, gum_tree);

					//do boolean operation and export model
					exportHollowedMQModels(&current_model, gum_mesh, outpath);

					delete gum_tree;
					gum_tree = nullptr;
				}
				qDebug() << QString("***Completing work on Thread %1***").arg(omp_get_thread_num());
			}

			//tell MergeUndercut_EditPlugin the teeth path
			emit sendModelPath(outpath);

			int ret = QMessageBox::information(nullptr, tr("Information"),
				tr("Export Completed."), QMessageBox::Ok);

		});
	}

	hollow_dialog->show();
	return true;
}

void AutoHollow_EditPlugin::EndEdit(MeshDocument&, GLArea*, MLSceneGLSharedDataContext*)
{
}

void AutoHollow_EditPlugin::Decorate(MeshModel&, GLArea*, QPainter* p)
{
}

CMeshO* AutoHollow_EditPlugin::hollowGum(CMeshO* gum)
{
	//1.compact model(only needed for stl model)
	int total = vcg::tri::Clean<CMeshO>::MergeCloseVertex(*gum, 0.1);

	//2. clean mesh and rebuild its topology
	gum = cleanMesh(gum);
	gum->vert.EnableVFAdjacency();
	gum->face.EnableVFAdjacency();
	gum->face.EnableFFAdjacency();
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(*gum);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(*gum);
	vcg::tri::UpdateNormal<CMeshO>::PerFace(*gum);

	//3.remove gum bottom
	vcg::tri::UpdateSelection<CMeshO>::FaceClear(*gum);
	for (CMeshO::FaceIterator fit = gum->face.begin(); fit != gum->face.end(); ++fit) {
		if (!fit->IsD() && fit->N() * vcg::Point3f(0.0, 0.0, 1.0) < -0.99) {
			if (fabs(fit->V(0)->P().Z()) < 0.05 && fabs(fit->V(1)->P().Z()) < 0.05 && fabs(fit->V(2)->P().Z()) < 0.05) {
				fit->SetS();
			}
		}
	}
	vcg::tri::UpdateSelection<CMeshO>::VertexClear(*gum);
	vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceStrict(*gum);

	for (CMeshO::FaceIterator fit = gum->face.begin(); fit != gum->face.end(); ++fit)
		if (!(*fit).IsD() && (*fit).IsS())
			vcg::tri::Allocator<CMeshO>::DeleteFace(*gum, *fit);
	for (CMeshO::VertexIterator vi = gum->vert.begin(); vi != gum->vert.end(); ++vi)
		if (!(*vi).IsD() && (*vi).IsS())
			vcg::tri::Allocator<CMeshO>::DeleteVertex(*gum, *vi);

	vcg::tri::UpdateBounding<CMeshO>::Box(*gum);
	gum->face.EnableMark();

	//4. uniform sampling gum mesh to get its inner mesh
	float offset = -hollow_ui.doubleSpinBox_HollowWidth->value();
	float voxel_size = gum->bbox.Diag() / 50;

	CMeshO* offset_mesh = new CMeshO();
	vcg::Point3i volume_dim; //体数据的维数
	Box3m volume_box = gum->bbox;
	volume_box.Offset(volume_box.Diag() / 10.0f + offset);
	vcg::BestDim(volume_box, voxel_size, volume_dim);//计算采样体数据的最佳维度

	qDebug() << QString("Resampling mesh using a volume of %1 x %2 x %3").arg(volume_dim[0]).arg(volume_dim[1]).arg(volume_dim[2]);
	vcg::tri::Resampler<CMeshO, CMeshO>::Resample(*gum, *offset_mesh, volume_box, volume_dim, voxel_size * 3.5, offset, false, true, false, nullptr);

	if (hollow_ui.checkBox_exportInner->isChecked()) {
		if (!QDir("C://FAB").exists()) {
			QDir().mkdir("C://FAB");
		}
		vcg::tri::io::ExporterSTL<CMeshO>::Save(*offset_mesh,"C://FAB//gum_inner.stl" , true);
	}

	//5. clean inner mesh
	//5.1 merge close
	//total = vcg::tri::Clean<CMeshO>::MergeCloseVertex(*offset_mesh, 0.1);

	//5.2 remove little components
	offset_mesh = removeAllSmallComponents(offset_mesh);

	offset_mesh->vert.EnableVFAdjacency();
	offset_mesh->face.EnableVFAdjacency();
	offset_mesh->face.EnableFFAdjacency();
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(*offset_mesh);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(*offset_mesh);

	//5.3 smooth inner mesh
	vcg::tri::Smooth<CMeshO>::VertexCoordLaplacian(*offset_mesh, 3, false, false, nullptr);

	vcg::tri::UpdateSelection<CMeshO>::VertexClear(*offset_mesh);
	//...select face with value of z coordinate bigger than 0
	if (vcg::tri::Clean<CMeshO>::CountNonManifoldEdgeFF(*offset_mesh) > 0) {
		qDebug() << "Have nonmanifold edge";
		for (CVertexO& v : offset_mesh->vert) {
			if (!v.IsD() && v.P().Z() > 0) {
				v.SetS();
			}
		}
		vcg::tri::UpdateSelection<CMeshO>::FaceFromVertexLoose(*offset_mesh);
	}
	else {
		offset_mesh->vert.EnableQuality();
		vcg::Plane3f xoy;
		xoy.Init(vcg::Point3f(0.0, 0.0, 0.0), vcg::Point3f(0.0, 0.0, 1.0));
		vcg::tri::UpdateQuality<CMeshO>::VertexFromPlane(*offset_mesh, xoy);

		vcg::tri::QualityMidPointFunctor<CMeshO> slicingfunc(0.0);
		vcg::tri::QualityEdgePredicate<CMeshO> slicingpred(0.0, 0.0);
		vcg::tri::RefineE<CMeshO, vcg::tri::QualityMidPointFunctor<CMeshO>, vcg::tri::QualityEdgePredicate<CMeshO> >(*offset_mesh, slicingfunc, slicingpred, false);

		vcg::tri::UpdateSelection<CMeshO>::VertexFromQualityRange(*offset_mesh, 0, std::numeric_limits<float>::max());
		vcg::tri::UpdateSelection<CMeshO>::FaceFromVertexStrict(*offset_mesh);
	}

	//...inside face out
	vcg::tri::Clean<CMeshO>::FlipMesh(*offset_mesh, false);

	//6. add offset mesh to gum mesh and recompute topology
	qDebug() << "Merge innner mesh into origin mesh";
	CMeshO* final_mesh = new CMeshO();
	vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*final_mesh, *gum);
	vcg::tri::Append<CMeshO, CMeshO>::Mesh(*final_mesh, *offset_mesh, true);

	//7. find border
	qDebug() << "Find border and fill it";
	final_mesh->vert.EnableVFAdjacency();
	final_mesh->face.EnableVFAdjacency();
	final_mesh->face.EnableFFAdjacency();
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(*final_mesh);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(*final_mesh);

	vcg::tri::UpdateFlags<CMeshO>::FaceClearV(*final_mesh);
	std::vector<std::vector<CVertexO*>> boundaries;
	for (CFaceO& f : final_mesh->face) {
		for (int j = 0; j < 3; ++j) {
			if (vcg::face::IsBorder(f, j) && !f.IsV()) {
				f.SetV();
				vcg::face::Pos<CFaceO> start_pos(&f, j, f.V(j));
				vcg::face::Pos<CFaceO> end_pos = start_pos;

				// find one boundary
				std::vector<CVertexO*> one_boundary;
				do
				{
					start_pos.f->SetV();
					one_boundary.push_back(start_pos.v);
					start_pos.NextB();
					assert(start_pos.IsBorder());
				} while (start_pos != end_pos);
				boundaries.push_back(one_boundary);
			}
		}
	}

	std::sort(boundaries.begin(), boundaries.end(), [=](std::vector<CVertexO*>& a, std::vector<CVertexO*>& b) {
		return a.size() > b.size();
		});

	//8.
	makeBridge(final_mesh, boundaries.at(0), boundaries.at(1));
	//vcg::tri::io::ExporterSTL<CMeshO>::Save(*final_mesh, "C://FAB//hollow_gum_with_bridge.stl", true);

	final_mesh = cleanMesh(final_mesh, true);

	//test save 
	//vcg::tri::io::ExporterSTL<CMeshO>::Save(*final_mesh, "D://test//hollow_gum.stl", true);

	delete gum;
	delete offset_mesh;
	return final_mesh;
}

void AutoHollow_EditPlugin::smoothBoundary(std::vector<CVertexO*>& a, int ite)
{
	for (int i = 0; i < ite; ++i) {
		std::vector<CVertexO> temp(a.size());
		for (int j = 0; j < a.size(); ++j) {
			temp[j].P() = a[j]->P();
		}

		for (int j = 0; j < a.size() - 1; ++j) {
			a[j]->P() = (temp[j].P() + temp[j + 1].P()) * 0.5;
		}
	}

}

void AutoHollow_EditPlugin::makeBridge(CMeshO* mesh, std::vector<CVertexO*>& a, std::vector<CVertexO*>& b)
{
	if (a.size() < b.size()) {
		return;
	}

	int size_a = a.size();
	int size_b = b.size();
	int add_faces_num = (size_b - 1) * 2 + (size_a - size_b) + 2;
	CMeshO::FaceIterator fit = vcg::tri::Allocator<CMeshO>::AddFaces(*mesh, 2);

	int start_a0, start_a1, start_b0, start_b1;
	start_a0 = start_a1 = start_b0 = start_b1 = 0;
	int end_a0, end_a1, end_b0, end_b1;
	end_a0 = end_a1 = end_b0 = end_b1 = 0;

	float min_x = std::numeric_limits<float>::max();
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i)->P().Y() > 0 && a.at(i)->P().X() < min_x) {
			min_x = a.at(i)->P().X();
			start_a0 = i;
		}
	}

	min_x = std::numeric_limits<float>::max();
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i)->P().Y() < 0 && a.at(i)->P().X() < min_x) {
			min_x = a.at(i)->P().X();
			end_a0 = i;
		}
	}

	min_x = std::numeric_limits<float>::max();
	for (int i = 0; i < b.size(); i++) {
		if (b.at(i)->P().Y() > 0 && b.at(i)->P().X() < min_x) {
			min_x = b.at(i)->P().X();
			start_b0 = i;
		}
	}

	min_x = std::numeric_limits<float>::max();
	for (int i = 0; i < b.size(); i++) {
		if (b.at(i)->P().Y() < 0 && b.at(i)->P().X() < min_x) {
			min_x = b.at(i)->P().X();
			end_b0 = i;
		}
	}

	start_a1 = (start_a0 + 1) % size_a;
	start_b1 = (start_b0 + 1) % size_b;
	end_a1 = (end_a0 + 1) % size_a;
	end_b1 = (end_b0 + 1) % size_b;

	vcg::Point3f dir_a = (a.at(start_a1)->P() - a.at(start_a0)->P()).Normalize();
	vcg::Point3f dir_b = (b.at(start_b1)->P() - b.at(start_b0)->P()).Normalize();
	vcg::Point3f out_dir = (a.at(start_a0)->P() - b.at(start_b0)->P()).Normalize();
	vcg::Point3f out_dir_a = dir_a ^ vcg::Point3f(0.0, 0.0, 1.0);
	vcg::Point3f out_dir_b = dir_b ^ vcg::Point3f(0.0, 0.0, 1.0);

	if (out_dir * out_dir_b < 0) {
		int temp = start_b0;
		start_b0 = start_b1;
		start_b1 = temp;
	}
	if (out_dir * out_dir_a < 0) {
		int temp = start_a0;
		start_a0 = start_a1;
		start_a1 = temp;
	}

	fit->V(0) = a.at(start_a0);
	fit->V(1) = b.at(start_b0);
	fit->V(2) = a.at(start_a1);
	fit++;

	fit->V(0) = a.at(start_a1);
	fit->V(1) = b.at(start_b0);
	fit->V(2) = b.at(start_b1);
}

void AutoHollow_EditPlugin::exportHollowedMQModels(MeshModel* current_model, CMeshO* gum_mesh, QString& outpath)
{
	if (current_model == nullptr || gum_mesh == nullptr) {
		return;
	}
	qDebug() << QString("Exporting Models...");

	//1.融合需要和牙齿做差的模型
	Eigen::VectorXi J;
	Eigen::MatrixXd tooth_V;
	Eigen::MatrixXi tooth_F;
	Eigen::MatrixXd minus_model_V;
	Eigen::MatrixXi minus_model_F;
	changeCMeshOToEigenMatrix(&current_model->cm, tooth_V, tooth_F);
	changeCMeshOToEigenMatrix(current_model->intersected_mesh, minus_model_V, minus_model_F);
	bool boolean_res = igl::copyleft::cgal::mesh_boolean(tooth_V.eval(), tooth_F.eval(), minus_model_V, minus_model_F, igl::MESH_BOOLEAN_TYPE_MINUS, tooth_V, tooth_F, J);
	if (boolean_res) {
		CMeshO temp_teeth;
		mergeCMeshWithEigenVector(&temp_teeth, tooth_V, tooth_F);
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(current_model->cm, temp_teeth);
		delete current_model->intersected_mesh;
		current_model->intersected_mesh = nullptr;
	}

	//2. 融合八字底座和牙龈模型
	Eigen::MatrixXd base_pin_V;
	Eigen::MatrixXi base_pin_F;
	Eigen::MatrixXd gum_V;
	Eigen::MatrixXi gum_F;
	generatePinModelEigenMatrix(base_pin_V, base_pin_F);
	changeCMeshOToEigenMatrix(gum_mesh, gum_V, gum_F);
	boolean_res = igl::copyleft::cgal::mesh_boolean(gum_V.eval(), gum_F.eval(), base_pin_V, base_pin_F, igl::MESH_BOOLEAN_TYPE_MINUS, gum_V, gum_F, J);
	if (boolean_res) {
		mergeCMeshWithEigenVector(&current_model->cm, gum_V, gum_F);
	}
	else {// 如果融合失败，导入模型不做任何处理
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(current_model->cm, *gum_mesh);
	}
	delete gum_mesh;
	gum_mesh = nullptr;

	//3. 底座和字符信息做差,并融入原始模型
	Eigen::MatrixXd base_V, info_V;
	Eigen::MatrixXi base_F, info_F;
	changeCMeshOToEigenMatrix(current_model->base_mesh, base_V, base_F);
	changeCMeshOToEigenMatrix(current_model->info_mesh, info_V, info_F);
	boolean_res = igl::copyleft::cgal::mesh_boolean(base_V.eval(), base_F.eval(), info_V, info_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_V, base_F, J);
	mergeCMeshWithEigenVector(&current_model->cm, base_V, base_F);
	if (boolean_res) {
		//如果融合成功则删除当前信息模型，后续不用分开导出
		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}

	//4.融合二维码
	vcg::tri::Append<CMeshO, CMeshO>::Mesh(current_model->cm, *current_model->qr_mesh);
	delete current_model->qr_mesh;
	current_model->qr_mesh = nullptr;

	//5.export final model 导出模型 
	QString model_outpath = outpath + "/" + current_model->label();
	std::string model_outpath_str = model_outpath.toLocal8Bit().data();
	int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(current_model->cm, model_outpath_str.c_str(), true);
	if (result != 0) {
		std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
	}

	//6. export info model, if needed
	if (current_model->info_mesh) {
		QString info_outpath = outpath + "/info_" + current_model->label();
		std::string info_outpath_str = info_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->info_mesh, info_outpath_str.c_str(), true);
		delete current_model->info_mesh;
		current_model->info_mesh = nullptr;
	}

	if (current_model->intersected_mesh) {
		QString intersect_outpath = outpath + "/intersect_" + current_model->label();
		std::string intersect_outpath_str = intersect_outpath.toLocal8Bit().data();
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*current_model->intersected_mesh, intersect_outpath_str.c_str(), true);
		delete current_model->intersected_mesh;
		current_model->intersected_mesh = nullptr;
	}
}

/**************************************************************************************************************/

MergeUndercut_EditPlugin::MergeUndercut_EditPlugin() {

}

const QString MergeUndercut_EditPlugin::Info()
{
	return QString("Merge Undercut Plugins");
}

bool MergeUndercut_EditPlugin::StartEdit(MeshDocument&, GLArea*, MLSceneGLSharedDataContext*)
{
	//mergeUndercut();
	omp_lock_t writelock;
	omp_init_lock(&writelock);

	#pragma omp parallel for num_threads(10)
	for (int i = 0; i < 8; i++) {
		omp_set_lock(&writelock);
		qDebug() << QString("Thread %1, Deal with model %2").arg(omp_get_thread_num()).arg(i);
		omp_unset_lock(&writelock);

		int local = 3;
		omp_set_lock(&writelock);
		std::cout << omp_get_thread_num() << " " << local << std::endl;
		omp_unset_lock(&writelock);

		for (int j = 0; j < 1000000000; j++) {
			//wait
		}
		local *= i;

		omp_set_lock(&writelock);
		std::cout << omp_get_thread_num() << " " << local << std::endl;
		omp_unset_lock(&writelock);
	}

	omp_destroy_lock(&writelock);
	return false;
}

void MergeUndercut_EditPlugin::EndEdit(MeshDocument&, GLArea*, MLSceneGLSharedDataContext*)
{
}

void MergeUndercut_EditPlugin::mergeUndercut()
{
	if (modelpath.isNull() || modelpath.isEmpty()) {
		QString title = QApplication::translate("", "\345\257\274\345\205\245\345\244\204\347\220\206\345\245\275\347\232\204\347\211\231\351\275\277\346\250\241\345\236\213", Q_NULLPTR);		
		modelpath = QFileDialog::getExistingDirectory(nullptr, title, "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	}
	if (modelpath.isNull() || modelpath.isEmpty()) {
		return;
	}

	QString title = QApplication::translate("", "\345\257\274\345\205\245\345\200\222\345\207\271\346\250\241\345\236\213", Q_NULLPTR);
	QString undercutpath = QFileDialog::getExistingDirectory(nullptr, title, "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (undercutpath.isNull() || undercutpath.isEmpty()) {
		return;
	}

	QDir undercut_dir(undercutpath);
	QStringList step_list = undercut_dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
	for (QString& step: step_list) {
		bool ok;
		int step_int = step.toInt(&ok);
		if (ok) {

			qDebug() << "deal with step " << step;

			int load_mask;
			//firstly, find model files
			std::string model_path_str;
			CMeshO model_mesh;
			QStringList model_list = QDir(modelpath).entryList(QDir::Files);
			for (QString& model_name : model_list) {
				QString model_step = model_name.split('_').back();
				model_step = model_step.mid(0, model_step.lastIndexOf('.'));
				model_step = model_step.mid(0, model_step.indexOf(QRegularExpression("[^\\d]")));

				if (model_step == step) {
					model_path_str = (modelpath + QString('/') + model_name).toLocal8Bit().data();
					vcg::tri::io::ImporterSTL<CMeshO>::Open(model_mesh, model_path_str.c_str(), load_mask);
					break;
				}
			}

			QStringList undercut_list = QDir(undercutpath + QString('/') + step).entryList(QDir::Files);
			for (QString& undercut_name : undercut_list) {
				QString undercut_path = undercutpath + QString('/') + step + QString('/') + undercut_name;
				std::string undercut_path_str = undercut_path.toLocal8Bit().data();
				CMeshO undercut_mesh;
				vcg::tri::io::ImporterSTL<CMeshO>::Open(undercut_mesh, undercut_path_str.c_str(), load_mask);

				vcg::tri::Append<CMeshO, CMeshO>::Mesh(model_mesh, undercut_mesh);
			}

			//save and overwrite original model files
			vcg::tri::io::ExporterSTL<CMeshO>::Save(model_mesh, model_path_str.c_str(), true);
		}
	}
}
