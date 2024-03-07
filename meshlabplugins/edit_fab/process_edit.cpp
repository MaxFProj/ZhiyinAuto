#include "process_edit.h"

AlignModel_EditPlugin::AlignModel_EditPlugin()
{
	//初始化设置对话框，但是不要显示
	setting_dialog = new QDialog();
	setting_ui = new Ui::SettingDialog();
	setting_ui->setupUi(setting_dialog);
	setting_dialog->hide();

	//load settings from file
	QString dir = QCoreApplication::applicationDirPath() + "//config.ini";
	QSettings* configIni = new QSettings(dir, QSettings::IniFormat);
	QString machine_type = configIni->value("machine/type", "robotic").toString();
	QString base_type    = configIni->value("base/type", "qr").toString();
	int correction_index = configIni->value("qr/correction_index", 0).toInt();
	float qr_width       = configIni->value("qr/width", 0).toFloat();

	if (machine_type == "robotic") {
		setting_ui->radioButton_Robotic->setChecked(true);
	}
	else {
		setting_ui->radioButton_5or4Axis->setChecked(true);
	}

	if (base_type == "info") {
		setting_ui->radioButton_Info->setChecked(true);
	}
	else if(base_type == "qr") {
		setting_ui->radioButton_QR->setChecked(true);
	}
	else {
		setting_ui->radioButton_None->setChecked(true);
	}
	setting_ui->comboBox_correction->setCurrentIndex(correction_index);

	setting_ui->doubleSpinBox_qrwidth->setValue(qr_width);

	connect(setting_dialog, &QDialog::accepted, this, [&]() {
		QString dir = QCoreApplication::applicationDirPath() + "//config.ini";
		QSettings* configIni = new QSettings(dir, QSettings::IniFormat);
		if (setting_ui->radioButton_Robotic->isChecked()) {
			configIni->setValue("machine/type", QString("robotic"));
		}
		else {
			configIni->setValue("machine/type", QString("5or4Axis"));
		}

		if (setting_ui->radioButton_Info->isChecked()) {
			configIni->setValue("base/type", QString("info"));
		}
		else if(setting_ui->radioButton_QR->isChecked()){
			configIni->setValue("base/type", QString("qr"));
		}
		else {
			configIni->setValue("base/type", QString("none"));
		}

		configIni->setValue("qr/correction_index", setting_ui->comboBox_correction->currentIndex());
		configIni->setValue("qr/width", setting_ui->doubleSpinBox_qrwidth->value());
	});
}

bool AlignModel_EditPlugin::StartEdit(MeshDocument& md, GLArea* gla, MLSceneGLSharedDataContext* con)
{
	this->gla = gla;
	this->md = &md;
	this->context = con;

	if (mode == ALIGN_MODEL && pointsForAlign.size() == 3) {
		alignAllModels();
		return false;
	}
	else if (mode == SAVE_MODEL) {
		saveModels();
		return false;
	}
	else if (mode == SETTING) {
		setting_dialog->show();
		return false;
	}
	else if (mode == PICK_ALIGN) {
		delete demo_base;
		demo_base = nullptr;
	}

	return true;
}

void AlignModel_EditPlugin::Decorate(MeshModel& current_model, GLArea* gla, QPainter* p)
{
	switch (mode) {
	case EMPTY: return;
	case PICK_ALIGN:	pickAlignPoints(gla, p);return;
	};
}

void AlignModel_EditPlugin::mousePressEvent(QMouseEvent* e, MeshModel&, GLArea*)
{
	if (mode == PICK_ALIGN) {
		curPoint.X() = e->pos().x();
		curPoint.Y() = e->pos().y();

		if (e->button() == Qt::LeftButton) {
			isleftdown = true;
		}

		hasPicked = false;
		pickedIndex = -1;
	}
}

void AlignModel_EditPlugin::mouseMoveEvent(QMouseEvent* e, MeshModel&, GLArea*)
{
	curPoint = vcg::Point2f(e->pos().x(), e->pos().y());
}

void AlignModel_EditPlugin::mouseReleaseEvent(QMouseEvent* e, MeshModel&, GLArea*)
{
	isleftdown = false;
	pickedIndex = -1;
	hasPicked = true;
}

void AlignModel_EditPlugin::mouseDoubleClickEvent(QMouseEvent* e, MeshModel&, GLArea*)
{
	isdbclicked = true;
}

void AlignModel_EditPlugin::pickAlignPoints(GLArea* gla, QPainter* painter)
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
	glColor4f(115 / 255.0, 59 / 255.0, 59 / 255.0, 1.0);
	for (int i = 0; i < pointsForAlign.size(); ++i) {
		drawSphere(pointsForAlign[i].X(), pointsForAlign[i].Y(), pointsForAlign[i].Z(), 0.6);
	}

	for (int i = 0; i < pointsForAlign.size(); ++i) {
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

		vcg::Matrix44f matrix, transMatrix;
		matrix.SetIdentity();
		matrix[0][0] = F[0];
		matrix[1][0] = F[1];
		matrix[2][0] = F[2];

		matrix[0][1] = R[0];
		matrix[1][1] = R[1];
		matrix[2][1] = R[2];

		matrix[0][2] = N[0];
		matrix[1][2] = N[1];
		matrix[2][2] = N[2];

		transMatrix.SetTranslate(center);
		matrix = transMatrix * matrix;

		// read demo model
		if (demo_base == nullptr) {
			QString demo_base_name;
			if (setting_dialog && setting_ui->radioButton_Info->isChecked()) {
				demo_base_name = "/background/info.stl";
			}
			else if (setting_dialog && setting_ui->radioButton_QR->isChecked()) {
				demo_base_name = "/background/demo_base.stl";
			}

			if (!demo_base_name.isEmpty() && !demo_base_name.isNull()) {
				QString base_path = QCoreApplication::applicationDirPath() + demo_base_name;
				std::string base_path_str = base_path.toLocal8Bit().constData();
				demo_base = new CMeshO();
				int load_mask_temp;
				int open_result = vcg::tri::io::ImporterSTL<CMeshO>::Open(*demo_base, base_path_str.c_str(), load_mask_temp);
			}
		}

		//draw base
		if (demo_base) {
			glColor4f(0.6, 0.6, 0.0, 1);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_TRIANGLES);
			for (CMeshO::FaceIterator fit = demo_base->face.begin(); fit != demo_base->face.end(); ++fit) {
				vcg::Point3f p0, p1, p2;
				p0 = matrix * fit->V(0)->P();
				p1 = matrix * fit->V(1)->P();
				p2 = matrix * fit->V(2)->P();
				glVertex3f(p0.X(), p0.Y(), p0.Z());
				glVertex3f(p1.X(), p1.Y(), p1.Z());
				glVertex3f(p2.X(), p2.Y(), p2.Z());
			}
			glEnd();
		}

		// draw circle around base
		double cx,cy,cz;
		cx = cy = cz = 0;
		float r = 50;

		int num_segments = 50;
		float theta      = 2 * 3.1415926 / float(num_segments);
		float x = r;//we start at angle = 0 
		float y = 0;

		glLineWidth(3.0f);
		glColor4f(0.0,0.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			vcg::Point3f p(cx + r * cosf(theta * ii), cy + r * sinf(theta * ii), 0);
			p = matrix * p;
			glVertex3f(p.X(), p.Y(), p.Z());//output vertex 
		}
		glEnd();

	}
}

void AlignModel_EditPlugin::setMode(int m)
{
	switch (m) {
		case 0: mode = EMPTY;		break;
		case 1: mode = IMPORT_MESH; break;
		case 2: mode = PICK_ALIGN;  break;
		case 3: mode = ALIGN_MODEL; break;
		case 4: mode = SAVE_MODEL;  break;
		case 5: mode = SETTING;     break;
	}
}

void AlignModel_EditPlugin::alignAllModels()
{
	std::cout << "Align model \n";
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
	}
	md->resetTrackballFunc();
	pointsForAlign.clear();
}

void AlignModel_EditPlugin::saveModels()
{
	QString outpath = QFileDialog::getExistingDirectory(this->gla, tr("Save Directory.."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (outpath.isNull() || outpath.isEmpty()) {
		return;
	}

	//导出二维码信息到txt文件
	if (setting_ui->radioButton_Info->isChecked()) {
		QString infofile_path = outpath + "/name_info.txt";
		QFile outFile2(infofile_path);
		if (!outFile2.open(QIODevice::WriteOnly | QIODevice::Text)) {
			//QMessageBox::critical(nullptr, tr("Error"), tr("Can't save cutine files."), QMessageBox::Ok);
			std::cout << "Can't save info files.\n";
			return;
		}

		QTextStream exput(&outFile2);
		exput << "Name_info\n";
		for (int i = 0; i < md->meshList.size(); ++i) {
			MeshModel* current_model = md->meshList.at(i);
			QString model_name = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
			QStringList datalist = model_name.split('&');
			if (datalist.size() < 3) {
				return;
			}
			QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
			QString currentJaw = datalist[1];
			QString id = datalist[0];
			model_name = id + "_" + currentJaw + "_" + step;

			exput << model_name << '\n';
		}
		outFile2.close();
	}

	//读取生成八字模型
	QString base_pin_filename = setting_ui->radioButton_Robotic->isChecked() ? "/background/robotic_base_pin.stl" : "/background/5axis_base_pin.stl";
	QString base_pin_path = QCoreApplication::applicationDirPath() + base_pin_filename;
	std::string base_pin_path_str = base_pin_path.toLocal8Bit().constData();
	CMeshO* base_pin_mesh = new CMeshO();
	int load_mask_temp;
	int open_result = vcg::tri::io::ImporterSTL<CMeshO>::Open(*base_pin_mesh, base_pin_path_str.c_str(), load_mask_temp);
	changeCMeshOToEigenMatrix(base_pin_mesh, base_pin_V, base_pin_F);

	//导出所有模型
	#pragma omp parallel for num_threads(20)
	for (int i = 0; i < md->meshList.size(); ++i) {
		MeshModel* current_model = md->meshList.at(i);
		qDebug() << QString("Thread %1, Deal with model %2").arg(omp_get_thread_num()).arg(current_model->label());

		generateBaseModel(current_model);
		exportOneModel(outpath, current_model);
	}

	QString content = QApplication::translate("", "\345\257\274\345\207\272\345\256\214\346\210\220", Q_NULLPTR);
	QString title   = QApplication::translate("", "\344\277\241\346\201\257", Q_NULLPTR);
	int ret = QMessageBox::information(nullptr, title,
		content, QMessageBox::Ok);
}

void AlignModel_EditPlugin::generateBaseModel(MeshModel* exportModel)
{
	bool need_qr = setting_ui->radioButton_QR->isChecked();

	QString dir = QCoreApplication::applicationDirPath();
	QString model_name = exportModel->label().mid(0, exportModel->label().lastIndexOf('.'));
	QStringList datalist = model_name.split('&');
	if (datalist.size() < 3) {
		return;
	}
	QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
	QString currentJaw = datalist[1];
	QString id = datalist[0];

	step = QString("%1").arg(step, 2, QLatin1Char('0'));
	//id   = QString("%1").arg(id, 6, QLatin1Char('0'));
	//exportModel->setLabel(id + "_" + currentJaw + "_" + step + ".stl");

	QString information = id + "_" + currentJaw + "_" + step;

	//1. 生成二维码模型
	if (exportModel->qr_mesh == nullptr && need_qr) {
		qr_info.qr_width = setting_ui->doubleSpinBox_qrwidth->value();
		CMeshO* qr_mesh = generateQRMesh(information, qr_info.qr_width, qr_info.qr_height, setting_ui->comboBox_correction->currentIndex());

		//将二维码模型平移到相应位置
		vcg::Matrix44f trans_matrix;
		trans_matrix.SetIdentity();
		trans_matrix.SetTranslate(vcg::Point3f(-qr_info.qr_width / 2.0 - 6, -qr_info.qr_width / 2.0, 1.4));
		vcg::tri::UpdatePosition<CMeshO>::Matrix(*qr_mesh, trans_matrix, true);
		exportModel->qr_mesh = qr_mesh;
	}

	//2.读入底座模型
	if (exportModel->base_mesh == nullptr) {
		//read base model
		QString base_path = need_qr ? dir + "/background/base.stl" : dir + "/background/base_short.stl";
		std::string base_path_str = base_path.toLocal8Bit().constData();

		exportModel->base_mesh = new CMeshO();
		int load_mask_temp;
		int open_result = vcg::tri::io::ImporterSTL<CMeshO>::Open(*exportModel->base_mesh, base_path_str.c_str(), load_mask_temp);
		if (open_result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(open_result);
		}
	}

	//3.生成info模型
	if (exportModel->info_mesh == nullptr) {
		exportModel->info_mesh = generateInfoMesh(information, need_qr);
	}
}

void AlignModel_EditPlugin::exportOneModel(QString outpath, MeshModel* current_model)
{
	qDebug() << __FUNCTION__;

	//1.transfrom info mesh
	vcg::Matrix44f info_mat;
	if (setting_ui->radioButton_Info->isChecked()) {
		vcg::Matrix44f scale_mat, trans_mat, trans_mat_2;
		trans_mat.SetIdentity();
		trans_mat.SetTranslate(0.0, 0.0, -1.2);

		scale_mat.SetIdentity();
		scale_mat.SetScale(1.0, 1.0, 3.0 / 1.5);

		trans_mat_2.SetIdentity();
		trans_mat_2.SetTranslate(0.0, 0.0, 1.0);

		vcg::tri::UpdatePosition<CMeshO>::Matrix(*current_model->info_mesh, trans_mat_2 * scale_mat * trans_mat);
	}

	bool create_directory = false;
	CMeshO* output_mesh   = new CMeshO();    // 最终的导出模型

	//2, 融合八字底座和牙颌模型
	Eigen::MatrixXd model_V;
	Eigen::MatrixXi model_F;
	changeCMeshOToEigenMatrix(&current_model->cm, model_V, model_F);
	Eigen::VectorXi J;
	bool boolean_base_pin = igl::copyleft::cgal::mesh_boolean(model_V.eval(), model_F.eval(), base_pin_V, base_pin_F, igl::MESH_BOOLEAN_TYPE_MINUS, model_V, model_F, J);
	if (boolean_base_pin) {
		mergeCMeshWithEigenVector(output_mesh, model_V, model_F);
	}
	else {// 如果融合失败，导入模型不做任何处理
		vcg::tri::Append<CMeshO, CMeshO>::MeshCopy(*output_mesh, current_model->cm);
	}

	//3.融合底座	
	//if (setting_ui->radioButton_Info->isChecked()) { //OCR
	//	Eigen::MatrixXd base_V;
	//	Eigen::MatrixXi base_F;
	//	changeCMeshOToEigenMatrix(current_model->base_mesh, base_V, base_F);

	//	Eigen::MatrixXd info_V;
	//	Eigen::MatrixXi info_F;
	//	changeCMeshOToEigenMatrix(current_model->info_mesh, info_V, info_F);

	//	bool boolean_base = igl::copyleft::cgal::mesh_boolean(base_V.eval(), base_F.eval(), info_V, info_F, igl::MESH_BOOLEAN_TYPE_MINUS, base_V, base_F, J);
	//	if (boolean_base) {
	//		mergeCMeshWithEigenVector(output_mesh, base_V, base_F);
	//	}
	//	else {
	//		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->base_mesh);
	//	}
	//}
	//else {
	//	vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->base_mesh);
	//	vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->info_mesh);
	//}
	if (!setting_ui->radioButton_None->isChecked()) {
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->base_mesh);
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->info_mesh);
	}

	delete current_model->base_mesh;
	current_model->base_mesh = nullptr;

	//4.融合二维码
	if (setting_ui->radioButton_QR->isChecked()) {
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*output_mesh, *current_model->qr_mesh);
	}

	delete current_model->info_mesh;
	current_model->info_mesh = nullptr;
	delete current_model->qr_mesh;
	current_model->qr_mesh = nullptr;

	//Ⅲ. 模型导出
	QString new_outpath = outpath;
	QString model_name  = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
	QStringList datalist = model_name.split('&');
	if (datalist.size() < 3) {
		return;
	}
	QString step = QString("%1").arg(datalist[2], 2, QLatin1Char('0'));
	QString currentJaw = datalist[1];
	QString id = datalist[0];
	model_name = id + "_" + currentJaw + "_" + step;

	QString model_outpath = new_outpath + "/" + model_name + ".stl";
	std::string model_outpath_str = model_outpath.toLocal8Bit().data();
	int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*output_mesh, model_outpath_str.c_str(), true);
	if (result != 0) {
		std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(result);
	}
	delete output_mesh;
}
