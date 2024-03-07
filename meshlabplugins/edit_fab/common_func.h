#pragma once
#include <GL/glew.h>
#include <wrap/gl/picking.h>
#include <wrap/io_trimesh/import_stl.h>
#include <wrap/io_trimesh/export_stl.h>
#include <wrap/io_trimesh/import_obj.h>

#include <math.h>
#include <stdlib.h>
#include <unordered_map>

#include <tmesh.h>
#include "qrencode.h"

#include <QFileDialog>

#ifdef _OPENMP
#include <omp.h>
#endif

#define FPI 3.14159265354

static std::vector<vcg::Point3f> base_pin_left, base_pin_right;

/* 绘制6面体
   @param std::vector<vcg::Point3f> up/down 按顺时针存贮的6面体的上下面的点
*/
static void drawRectangle(std::vector<vcg::Point3f>& up, std::vector<vcg::Point3f>& down) 
{
	glColor4f(0.6, 0.6, 0.0, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex3f(up[0].X(), up[0].Y(), up[0].Z());
	glVertex3f(up[1].X(), up[1].Y(), up[1].Z());
	glVertex3f(up[2].X(), up[2].Y(), up[2].Z());

	glVertex3f(up[0].X(), up[0].Y(), up[0].Z());
	glVertex3f(up[2].X(), up[2].Y(), up[2].Z());
	glVertex3f(up[3].X(), up[3].Y(), up[3].Z());

	glVertex3f(down[0].X(), down[0].Y(), down[0].Z());
	glVertex3f(down[2].X(), down[2].Y(), down[2].Z());
	glVertex3f(down[1].X(), down[1].Y(), down[1].Z());

	glVertex3f(down[0].X(), down[0].Y(), down[0].Z());
	glVertex3f(down[3].X(), down[3].Y(), down[3].Z());
	glVertex3f(down[2].X(), down[2].Y(), down[2].Z());

	for (int i = 0; i <= 3; ++i) {
		int i_next = (i + 1) % 3;
		glVertex3f(up[i].X(), up[i].Y(), up[i].Z());
		glVertex3f(up[i_next].X(), up[i_next].Y(), up[i_next].Z());
		glVertex3f(down[i_next].X(), down[i_next].Y(), down[i_next].Z());

		glVertex3f(up[i].X(), up[i].Y(), up[i].Z());
		glVertex3f(down[i_next].X(), down[i_next].Y(), down[i_next].Z());
		glVertex3f(down[i].X(), down[i].Y(), down[i].Z());
	}
	glEnd();
}

/************************************************************************/
/* 绘制椭球
   @param float a b c 分别表示椭球沿x y z轴的轴长
   @param svcg::Matrix44f& mat 椭球的变换矩阵
*/
/************************************************************************/
static void drawEllipsoid(float a, float b, float c, vcg::Matrix44f& mat) 
{
	GLfloat M = 20;
	GLfloat N = 20;
	float step_z = FPI / M;
	float step_xy = 2 * FPI / N;
	std::vector<vcg::Point3f> quad_points(4);

	float angle_z = 0.0;
	float angle_xy = 0.0;
	int i = 0, j = 0;

	glColor4f (0.6,0.6,0.0,1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	for (i = 0; i < M; i++)
	{
		angle_z = i * step_z;

		for (j = 0; j < N; j++)
		{
			angle_xy = j * step_xy;

			quad_points[0].X() = a * sin(angle_z) * cos(angle_xy);
			quad_points[0].Y() = b * sin(angle_z) * sin(angle_xy);
			quad_points[0].Z() = c * cos(angle_z);

			quad_points[1].X() = a * sin(angle_z + step_z) * cos(angle_xy);
			quad_points[1].Y() = b * sin(angle_z + step_z) * sin(angle_xy);
			quad_points[1].Z() = c * cos(angle_z + step_z);

			quad_points[2].X() = a * sin(angle_z + step_z) * cos(angle_xy + step_xy);
			quad_points[2].Y() = b * sin(angle_z + step_z) * sin(angle_xy + step_xy);
			quad_points[2].Z() = c * cos(angle_z + step_z);

			quad_points[3].X() = a * sin(angle_z) * cos(angle_xy + step_xy);
			quad_points[3].Y() = b * sin(angle_z) * sin(angle_xy + step_xy);
			quad_points[3].Z() = c * cos(angle_z);

			for (int k = 0; k < 4; k++)
			{
				quad_points[k] = mat * quad_points[k];
			}

			glVertex3f(quad_points[0].X(), quad_points[0].Y(), quad_points[0].Z());
			glVertex3f(quad_points[1].X(), quad_points[1].Y(), quad_points[1].Z());
			glVertex3f(quad_points[2].X(), quad_points[2].Y(), quad_points[2].Z());

			glVertex3f(quad_points[0].X(), quad_points[0].Y(), quad_points[0].Z());
			glVertex3f(quad_points[2].X(), quad_points[2].Y(), quad_points[2].Z());
			glVertex3f(quad_points[3].X(), quad_points[3].Y(), quad_points[3].Z());
		}
	}
	glEnd();
}

static void drawSphere(GLfloat xx, GLfloat yy, GLfloat zz, GLfloat radius)
{
	GLfloat M = 5;
	GLfloat N = 5;
	float step_z = FPI / M;
	float step_xy = 2 * FPI / N;
	float x[4], y[4], z[4];

	float angle_z = 0.0;
	float angle_xy = 0.0;
	int i = 0, j = 0;
	//glEnable(GL_BLEND);
	//glColor4f (0.0,0.0,0.0,1);
	glBegin(GL_QUADS);
	for (i = 0; i < M; i++)
	{
		angle_z = i * step_z;

		for (j = 0; j < N; j++)
		{
			angle_xy = j * step_xy;

			x[0] = radius * sin(angle_z) * cos(angle_xy);
			y[0] = radius * sin(angle_z) * sin(angle_xy);
			z[0] = radius * cos(angle_z);

			x[1] = radius * sin(angle_z + step_z) * cos(angle_xy);
			y[1] = radius * sin(angle_z + step_z) * sin(angle_xy);
			z[1] = radius * cos(angle_z + step_z);

			x[2] = radius * sin(angle_z + step_z) * cos(angle_xy + step_xy);
			y[2] = radius * sin(angle_z + step_z) * sin(angle_xy + step_xy);
			z[2] = radius * cos(angle_z + step_z);

			x[3] = radius * sin(angle_z) * cos(angle_xy + step_xy);
			y[3] = radius * sin(angle_z) * sin(angle_xy + step_xy);
			z[3] = radius * cos(angle_z);

			for (int k = 0; k < 4; k++)
			{
				glVertex3f(xx + x[k], yy + y[k], zz + z[k]);
			}
		}
	}
	glEnd();
}

static vcg::Point3f HermiteInterpolation(vcg::Point3f y0, vcg::Point3f y1, vcg::Point3f y2, vcg::Point3f y3, double mu,
	double tension, double bias) {
	vcg::Point3f m0, m1;
	double a0, a1, a2, a3, mu2, mu3;

	mu2 = mu * mu;
	mu3 = mu2 * mu;
	m0 = (y1 - y0) * (1 + bias) * (1 - tension) / 2;
	m0 += (y2 - y1) * (1 - bias) * (1 - tension) / 2;
	m1 = (y2 - y1) * (1 + bias) * (1 - tension) / 2;
	m1 += (y3 - y2) * (1 - bias) * (1 - tension) / 2;
	a0 = 2 * mu3 - 3 * mu2 + 1;
	a1 = mu3 - 2 * mu2 + mu;
	a2 = mu3 - mu2;
	a3 = -2 * mu3 + 3 * mu2;

	return(y1 * a0 + m0 * a1 + m1 * a2 + y2 * a3);
}

static std::vector<vcg::Point3f> interpolationCurve(std::vector<vcg::Point3f> data, int interpolationNum) {
	std::vector<vcg::Point3f> res;
	double bias = 0;
	if (data.size() <= 3) {
		return res;
	}
	double interval = 1.0 / (interpolationNum + 1);
	std::vector<double> mus;
	for (int i = 0; i < interpolationNum + 1; ++i) {
		mus.push_back(i * interval);
	}
	for (int i = 0; i < data.size() - 3; ++i) {
		vcg::Point3f y0, y1, y2, y3;
		double mu;
		y0 = data[i];
		y1 = data[i + 1];
		y2 = data[i + 2];
		y3 = data[i + 3];
		for (int j = 0; j < mus.size(); ++j) {
			mu = mus[j];
			//res.push( CubicInterpolate(y0,y1,y2,y3,mu) );
			//res.push( CatmullRom(y0,y1,y2,y3,mu) );
			res.push_back(HermiteInterpolation(y0, y1, y2, y3, mu, 0, bias));
		}
	}
	return res;
}

/************************************************************************/
/* 每两个相邻控制点之间的插值曲线的点的个数和他们之间的距离成正比
   @param std::vector<Point3f> data 用于插值的控制点
   @param std::vector<Point3f> interpolationNums 每两个插值控制点之间插值点的个数（除去开头个结尾的两个点）
   @return std::vector<vcg::Point3f>  插值后的曲线点
*/
/************************************************************************/
static std::vector<vcg::Point3f> interpolationCurve(std::vector<vcg::Point3f> data, std::vector<int>interpolationNums) {
	std::vector<vcg::Point3f> res;
	double bias = 0;
	if (data.size() <= 3 || data.size() != interpolationNums.size() + 3) {
		return res;
	}
	for (int i = 0; i < data.size() - 3; ++i) {
		int interpolationNum = interpolationNums[i];

		double interval = 1.0 / (interpolationNum + 1);
		std::vector<double> mus;
		for (int i = 0; i < interpolationNum + 1; ++i) {
			mus.push_back(i * interval);
		}

		vcg::Point3f y0, y1, y2, y3;
		double mu;
		y0 = data[i];
		y1 = data[i + 1];
		y2 = data[i + 2];
		y3 = data[i + 3];
		for (int j = 0; j < mus.size(); ++j) {
			mu = mus[j];
			res.push_back(HermiteInterpolation(y0, y1, y2, y3, mu, 0, bias));
		}
	}
	return res;
}

/************************************************************************/
/*  根据一个二维码的二维矩阵生成相应的三维Mesh模型
@param QString information 要生成二维码的内容
@param len double 二维码长和宽
@param height double 二维码高度
*/
/************************************************************************/
static CMeshO* generateQRMesh(QString& information, double length, double height, int level = 0)
{
	//1.先生成二维码对应的灰度矩阵
	std::string information_str = information.toLocal8Bit().data();
	QRcode* qr = QRcode_encodeString(information_str.c_str(), 1, static_cast<QRecLevel>(level), QR_MODE_8, 1);
	int qr_len = qr->width;
	double len = length / qr_len;

	std::vector<std::vector<bool>> code(qr_len); //二维码对应的灰度矩阵
	for (int i = 0; i < qr_len; ++i) {
		code[i].resize(qr_len, false);
	}

	for (int y = 0; y < qr_len; y++) {
		for (int x = 0; x < qr_len; x++) {
			unsigned char b = qr->data[y * qr_len + x];
			if (b & 0x01) {
				code[y][x] = true;
			}
			else {
				code[y][x] = false;
			}
		}
	}
	QRcode_free(qr);

	//2.确定Mesh的点
	std::vector<std::vector<int>> vertices; //点矩阵(len + 1) X (len + 1)
	int VN = 0;
	vertices.resize(qr_len + 1);
	for (int i = 0; i < qr_len + 1; ++i) {
		vertices[i].resize(qr_len + 1, -1);
	}

	for (int i = 0; i < qr_len; ++i) {
		for (int j = 0; j < qr_len; ++j) {
			if (code[i][j]) {
				vertices[i][j] = vertices[i + 1][j] = vertices[i + 1][j + 1] = vertices[i][j + 1] = 1;
			}
		}
	}

	for (int i = 0; i < qr_len + 1; ++i) {
		for (int j = 0; j < qr_len + 1; ++j) {
			if (vertices[i][j] > -1) {
				vertices[i][j] = VN;
				VN += 2;
			}
		}
	}

	//3.再确定Mesh面
	int FN = 0;
	for (int i = 0; i < qr_len; ++i) {
		for (int j = 0; j < qr_len; ++j) {
			if (code[i][j]) {
				FN += 4;//顶面和底面共四个三角面片

				// 侧面的三角面片
				if (j + 1 < qr_len && !code[i][j + 1] || j + 1 == qr_len) {
					FN += 2;
				}

				if (j > 0 && !code[i][j - 1] || j == 0) {
					FN += 2;
				}

				if (i > 0 && !code[i - 1][j] || i == 0) {
					FN += 2;
				}

				if (i + 1 < qr_len && !code[i + 1][j] || i + 1 == qr_len) {
					FN += 2;
				}
			}
		}
	}

	//4.构建QR Mesh
	CMeshO* QRMesh = new CMeshO();
	CMeshO::VertexIterator newVertIndex = vcg::tri::Allocator<CMeshO>::AddVertices(*QRMesh, VN);
	for (int i = 0; i < vertices.size(); ++i) {
		for (int j = 0; j < vertices.size(); ++j) {
			if (vertices[i][j] > -1) {
				newVertIndex->P()[0] = i * len;
				newVertIndex->P()[1] = j * len;
				newVertIndex->P()[2] = 0.0;
				newVertIndex++;

				newVertIndex->P()[0] = i * len;
				newVertIndex->P()[1] = j * len;
				newVertIndex->P()[2] = height;
				newVertIndex++;
			}
		}
	}

	CMeshO::FaceIterator newFaceIndex = vcg::tri::Allocator<CMeshO>::AddFaces(*QRMesh, FN);
	for (int i = 0; i < qr_len; ++i) {
		for (int j = 0; j < qr_len; ++j) {
			if (code[i][j]) {
				//立方体的8个顶点
				CVertexO* p0, * p1, * p2, * p3, * p0_, * p1_, * p2_, * p3_;
				p0 = &*(vertices[i][j] + QRMesh->vert.begin());
				p0_ = &*(vertices[i][j] + 1 + QRMesh->vert.begin());
				p1 = &*(vertices[i + 1][j] + QRMesh->vert.begin());
				p1_ = &*(vertices[i + 1][j] + 1 + QRMesh->vert.begin());
				p2 = &*(vertices[i + 1][j + 1] + QRMesh->vert.begin());
				p2_ = &*(vertices[i + 1][j + 1] + 1 + QRMesh->vert.begin());
				p3 = &*(vertices[i][j + 1] + QRMesh->vert.begin());
				p3_ = &*(vertices[i][j + 1] + 1 + QRMesh->vert.begin());

				newFaceIndex->V(0) = p0;
				newFaceIndex->V(1) = p3;
				newFaceIndex->V(2) = p1;
				newFaceIndex++;

				newFaceIndex->V(0) = p3;
				newFaceIndex->V(1) = p2;
				newFaceIndex->V(2) = p1;
				newFaceIndex++;

				newFaceIndex->V(0) = p0_;
				newFaceIndex->V(1) = p1_;
				newFaceIndex->V(2) = p3_;
				newFaceIndex++;

				newFaceIndex->V(0) = p3_;
				newFaceIndex->V(1) = p1_;
				newFaceIndex->V(2) = p2_;
				newFaceIndex++;


				// 侧面的三角面片
				if (j + 1 == qr_len || !code[i][j + 1]) {
					newFaceIndex->V(0) = p3_;
					newFaceIndex->V(1) = p2;
					newFaceIndex->V(2) = p3;
					newFaceIndex++;

					newFaceIndex->V(0) = p3_;
					newFaceIndex->V(1) = p2_;
					newFaceIndex->V(2) = p2;
					newFaceIndex++;
				}

				if (j == 0 || !code[i][j - 1]) {
					newFaceIndex->V(0) = p0_;
					newFaceIndex->V(1) = p0;
					newFaceIndex->V(2) = p1;
					newFaceIndex++;

					newFaceIndex->V(0) = p0_;
					newFaceIndex->V(1) = p1;
					newFaceIndex->V(2) = p1_;
					newFaceIndex++;
				}

				if (i > 0 && !code[i - 1][j] || i == 0) {
					newFaceIndex->V(0) = p3_;
					newFaceIndex->V(1) = p3;
					newFaceIndex->V(2) = p0;
					newFaceIndex++;

					newFaceIndex->V(0) = p3_;
					newFaceIndex->V(1) = p0;
					newFaceIndex->V(2) = p0_;
					newFaceIndex++;
				}

				if (i + 1 < qr_len && !code[i + 1][j] || i + 1 == qr_len) {
					newFaceIndex->V(0) = p2_;
					newFaceIndex->V(1) = p1;
					newFaceIndex->V(2) = p2;
					newFaceIndex++;

					newFaceIndex->V(0) = p2_;
					newFaceIndex->V(1) = p1_;
					newFaceIndex->V(2) = p1;
					newFaceIndex++;
				}
			}
		}
	}

	return QRMesh;
}

/************************************************************************/
/* 按顺时针给定对应的上下两个平面的点，生成连接他们的侧边
@param up, bottom std::vector<CMeshO::VertexPointer> 要连接的两个平面的点指针的数组
@param fit 新增面的索引
*/
/************************************************************************/
static void connectVert(std::vector<CMeshO::VertexPointer>& up, std::vector<CMeshO::VertexPointer>& low, CMeshO::FaceIterator& fit) {
	if (up.size() != low.size()) {
		return;
	}
	for (int i = 0; i < up.size() - 1; ++i) {
		fit->V(0) = up[i];
		fit->V(1) = low[i];
		fit->V(2) = up[i + 1];
		fit++;

		fit->V(0) = low[i];
		fit->V(1) = low[i + 1];
		fit->V(2) = up[i + 1];
		fit++;
	}
};

/************************************************************************/
/*  生成底部的数字信息模型
@param information QString 信息字符串（支持26个大小写字母和_-）
*/
/************************************************************************/
static CMeshO* generateInfoMesh(QString& information, bool need_qr = true) 
{
	CMeshO* info_mesh = new CMeshO();
	QString dir = QCoreApplication::applicationDirPath();

	QRegularExpression upper_case_re("[A-Z]");
	QRegularExpression lower_case_re("[a-z-_]");
	bool need_rotate = false;

	// 位数必须小于18位
	for (int i = 0; i < information.size() && i <= 17; ++i)
	{
		QString character = information[i];
		need_rotate = false; // 字母和数字的初始位置不一样要做旋转

		//识别字符且区分大小写
		QRegularExpressionMatch match_upper = upper_case_re.match(character);
		QRegularExpressionMatch match_lower = lower_case_re.match(character);
		if (match_upper.hasMatch()) {
			character += '_';
			need_rotate = true;
		}
		else if (match_lower.hasMatch()) {
			need_rotate = true;
		}

		QString character_path = dir + "/background/" + character + ".obj";
		std::string character_path_str = character_path.toLocal8Bit().constData();

		CMeshO* character_mesh = new CMeshO();
		int load_mask_temp;
		int open_result = vcg::tri::io::ImporterOBJ<CMeshO>::Open(*character_mesh, character_path_str.c_str(), load_mask_temp);
		if (open_result != 0) {
			std::cout << vcg::tri::io::ExporterSTL<CMeshO>::ErrorMsg(open_result);
		}

		float scale_z = 1.5;
		vcg::Matrix44f initial_transform_matrix;
		if (need_rotate) {
			vcg::Matrix44f initial_rotate_matrix1, initial_rotate_matrix2;
			vcg::Matrix44f trans_z;
			initial_rotate_matrix1.SetRotateDeg(-90, vcg::Point3f(0.0, 0.0, 1.0));
			initial_rotate_matrix2.SetRotateDeg(180, vcg::Point3f(1.0, 0.0, 0.0));
			trans_z.SetTranslate(0.0,0.0,1.0);
			initial_transform_matrix = trans_z * initial_rotate_matrix2 * initial_rotate_matrix1;
		}
		else {
			initial_transform_matrix.SetIdentity();
		}

		vcg::Matrix44f rotate_matrix;
		rotate_matrix.SetRotateDeg(180, vcg::Point3f(1.0,0.0,0.0));
		vcg::Matrix44f trans_matrix;
		trans_matrix.SetIdentity();

		double y_pos[6];
		double start = need_qr ? 7.0 : 7.5;
		double space = 3;
		for (int y_i = 0; y_i <= 5; y_i++) {
			y_pos[y_i] = start - space * y_i;
		}

		double trans_x;
		if (need_qr) {
			trans_x = 23;
			switch (i) {
			case 0:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[0];	 trans_matrix[2][3] = 2.5; break;
			case 1:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[1];	 trans_matrix[2][3] = 2.5; break;
			case 2:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[2];	 trans_matrix[2][3] = 2.5; break;
			case 3:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[3];	 trans_matrix[2][3] = 2.5; break;
			case 4:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[4];	 trans_matrix[2][3] = 2.5; break;
			case 5:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[5];	 trans_matrix[2][3] = 2.5; break;

			case 6:trans_matrix.SetScale(0.4, 0.48, scale_z);   trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[0]; trans_matrix[2][3] = 2.5; break;
			case 7:trans_matrix.SetScale(0.4, 0.48, scale_z);   trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[1]; trans_matrix[2][3] = 2.5; break;
			case 8:trans_matrix.SetScale(0.4, 0.48, scale_z);   trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[2]; trans_matrix[2][3] = 2.5; break;
			case 9:trans_matrix.SetScale(0.4, 0.48, scale_z);   trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[3]; trans_matrix[2][3] = 2.5; break;
			case 10:trans_matrix.SetScale(0.4, 0.48, scale_z);  trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[4]; trans_matrix[2][3] = 2.5; break;
			case 11:trans_matrix.SetScale(0.4, 0.48, scale_z);  trans_matrix[0][3] = -13.0 + trans_x; trans_matrix[1][3] = y_pos[5]; trans_matrix[2][3] = 2.5; break;

			case 12:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[0]; trans_matrix[2][3] = 2.5; break;
			case 13:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[1]; trans_matrix[2][3] = 2.5; break;
			case 14:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[2]; trans_matrix[2][3] = 2.5; break;
			case 15:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[3]; trans_matrix[2][3] = 2.5; break;
			case 16:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[4]; trans_matrix[2][3] = 2.5; break;
			case 17:trans_matrix.SetScale(0.4, 0.48, scale_z); trans_matrix[0][3] = -16.0 + trans_x; trans_matrix[1][3] = y_pos[5]; trans_matrix[2][3] = 2.5; break;
			}
		}
		else {
			trans_x = 21;
			switch (i) {
			case 0:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[0];	 trans_matrix[2][3] = 2.5; break;
			case 1:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[1];	 trans_matrix[2][3] = 2.5; break;
			case 2:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[2];	 trans_matrix[2][3] = 2.5; break;
			case 3:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[3];	 trans_matrix[2][3] = 2.5; break;
			case 4:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[4];	 trans_matrix[2][3] = 2.5; break;
			case 5:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -10 + trans_x; trans_matrix[1][3] = y_pos[5];	 trans_matrix[2][3] = 2.5; break;

			case 6:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[0]; trans_matrix[2][3] = 2.5; break;
			case 7:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[1]; trans_matrix[2][3] = 2.5; break;
			case 8:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[2]; trans_matrix[2][3] = 2.5; break;
			case 9:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[3]; trans_matrix[2][3] = 2.5; break;
			case 10:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[4]; trans_matrix[2][3] = 2.5; break;
			case 11:trans_matrix.SetScale(0.5, 0.6, scale_z);  trans_matrix[0][3] = -14.0 + trans_x; trans_matrix[1][3] = y_pos[5]; trans_matrix[2][3] = 2.5; break;

			case 12:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[0]; trans_matrix[2][3] = 2.5; break;
			case 13:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[1]; trans_matrix[2][3] = 2.5; break;
			case 14:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[2]; trans_matrix[2][3] = 2.5; break;
			case 15:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[3]; trans_matrix[2][3] = 2.5; break;
			case 16:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[4]; trans_matrix[2][3] = 2.5; break;
			case 17:trans_matrix.SetScale(0.5, 0.6, scale_z); trans_matrix[0][3] = -18.0 + trans_x; trans_matrix[1][3] = y_pos[5]; trans_matrix[2][3] = 2.5; break;
			}
		}

		vcg::tri::UpdatePosition<CMeshO>::Matrix(*character_mesh, trans_matrix * rotate_matrix * initial_transform_matrix, true);
		vcg::tri::Append<CMeshO, CMeshO>::Mesh(*info_mesh, *character_mesh);

		delete character_mesh;
	}
	return info_mesh;
}

static double meshNearestDistanceToPlane(CMeshO* cm, vcg::Plane3f& plane) {
	double nearesr_distance = std::numeric_limits<double>::max();
	vcg::Point3f nearest_p;
	for (CMeshO::VertexIterator vit = cm->vert.begin(); vit != cm->vert.end(); vit++) {
		double distance = SignedDistancePlanePoint(plane, vit->P());
		if (std::fabs(distance) < std::fabs(nearesr_distance)) {
			nearesr_distance = distance;
			nearest_p = vit->P();
		}
	}
	return nearesr_distance;
}

static void changeCMeshOToEigenMatrix(CMeshO* cmesh, Eigen::MatrixXd& V, Eigen::MatrixXi& F) {
	if (cmesh == nullptr || cmesh->vert.empty() || cmesh->face.empty()) {
		return;
	}

	V.resize(cmesh->vert.size(), 3);
	F.resize(cmesh->face.size(), 3);

	int vert_count = 0;
	for (CMeshO::VertexIterator vit = cmesh->vert.begin(); vit != cmesh->vert.end(); ++vit, ++vert_count) {
		V(vert_count, 0) = vit->P()[0];
		V(vert_count, 1) = vit->P()[1];
		V(vert_count, 2) = vit->P()[2];
	}

	int face_count = 0;
	for (CMeshO::FaceIterator fit = cmesh->face.begin(); fit != cmesh->face.end(); ++fit, ++face_count) {
		F(face_count, 0) = vcg::tri::Index(*cmesh, fit->V(0));
		F(face_count, 1) = vcg::tri::Index(*cmesh, fit->V(1));
		F(face_count, 2) = vcg::tri::Index(*cmesh, fit->V(2));
	}
}

static void mergeCMeshWithEigenVector(CMeshO* cmesh, Eigen::MatrixXd& V, Eigen::MatrixXi& F) {
	int origin_vert_count = cmesh->vert.size();
	CMeshO::VertexIterator vit = vcg::tri::Allocator<CMeshO>::AddVertices(*cmesh, V.rows());
	CMeshO::FaceIterator   fit = vcg::tri::Allocator<CMeshO>::AddFaces(*cmesh, F.rows());

	for (int i = 0; i < V.rows(); ++i, ++vit) {
		vit->P()[0] = V(i, 0);
		vit->P()[1] = V(i, 1);
		vit->P()[2] = V(i, 2);
	}

	for (int i = 0; i < F.rows(); ++i, ++fit) {
		fit->V(0) = &*(cmesh->vert.begin() + origin_vert_count + F(i, 0));
		fit->V(1) = &*(cmesh->vert.begin() + origin_vert_count + F(i, 1));
		fit->V(2) = &*(cmesh->vert.begin() + origin_vert_count + F(i, 2));
	}
}

static CMeshO* cleanMesh(CMeshO* mesh, bool onlyfillholes = false) {
	if (mesh == nullptr) {
		return nullptr;
	}
	qDebug() << "Begin clean mesh";
	//must compact mesh firstly, in order to get the correct index
	vcg::tri::Allocator<CMeshO>::CompactEveryVector(*mesh);

	//CMeshO to TMesh
	T_MESH::TMesh::init(); // This is mandatory
	T_MESH::TMesh::quiet = true;
	T_MESH::Basic_TMesh basic_tmesh;
	
	//add vertices
	T_MESH::ExtVertex** var = (T_MESH::ExtVertex**)malloc(sizeof(T_MESH::ExtVertex*) * mesh->vert.size());
	int i = 0;
	for (CMeshO::VertexIterator vit = mesh->vert.begin(); vit != mesh->vert.end(); ++vit, ++i) {
		if (!vit->IsD()) {
			T_MESH::Vertex* v = basic_tmesh.newVertex(vit->P().X(), vit->P().Y(), vit->P().Z());
			basic_tmesh.V.appendTail(v);
			var[i] = new T_MESH::ExtVertex(v);
		}
	}

	//add faces
	for (CMeshO::FaceIterator fit = mesh->face.begin(); fit != mesh->face.end(); ++fit) {
		if (!fit->IsD()) {
			int i1, i2, i3;
			i1 = fit->V(0) - &*mesh->vert.begin();
			i2 = fit->V(1) - &*mesh->vert.begin();
			i3 = fit->V(2) - &*mesh->vert.begin();
			basic_tmesh.CreateIndexedTriangle(var, i1, i2, i3);
		}
	}

	for (i = 0; i < mesh->vert.size(); i++) {
		delete(var[i]);
	}	
	free(var);

	basic_tmesh.fixConnectivity();

	if (!onlyfillholes) {
		int sc = basic_tmesh.removeSmallestComponents();
		std::cout << "	Removed " << sc << " small components \n";
	}

	// Fill holes
	if (basic_tmesh.boundaries())
	{
		std::cout << "	Patching holes\n";
		basic_tmesh.fillSmallBoundaries(0, false);
	}

	// Run geometry correction
	if (!onlyfillholes) {
		std::cout << "	Fixing degeneracies and intersections \n";
		if (basic_tmesh.boundaries() || !basic_tmesh.meshclean()) {
			std::cout << "	!!!MeshFix could not fix everything \n";
		}
	}

	//test
	CMeshO* out_mesh = new CMeshO();
	CMeshO::VertexIterator vit = vcg::tri::Allocator<CMeshO>::AddVertices(*out_mesh, basic_tmesh.V.numels());
	CMeshO::FaceIterator   fit = vcg::tri::Allocator<CMeshO>::AddFaces(*out_mesh, basic_tmesh.T.numels());

	// assign vertex
	for (T_MESH::Node* n = basic_tmesh.V.head(); n != NULL; n = n->next(), vit++) {
		T_MESH::Vertex* v = (T_MESH::Vertex*)n->data;
		vit->P()[0] = float(v->x);
		vit->P()[1] = float(v->y);
		vit->P()[2] = float(v->z);
	}

	int index = 0;
	for (T_MESH::Node* n = basic_tmesh.V.head(); n != NULL; n = n->next(), index++) {
		T_MESH::Vertex* v = (T_MESH::Vertex*)n->data;
		v->x = index;
	}

	//assign face
	CVertexO* begin_vert_pointer = &*out_mesh->vert.begin();
	for (T_MESH::Node* n = basic_tmesh.T.head(); n != NULL; n = n->next(), fit++) {
		T_MESH::Triangle* tri = (T_MESH::Triangle*)n->data;
		fit->V(0) = begin_vert_pointer + int(tri->v1()->x);
		fit->V(1) = begin_vert_pointer + int(tri->v2()->x);
		fit->V(2) = begin_vert_pointer + int(tri->v3()->x);
	}

	delete mesh;
	qDebug() << "Finish clean mesh";
	return out_mesh;
}

static void splitMeshAndSave(MeshDocument* md) {
	QString outpath = QFileDialog::getExistingDirectory(nullptr, QString("Save Directory.."), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (outpath.isNull() || outpath.isEmpty()) {
		return;
	}

	for (int i = 0; i < md->meshList.size(); ++i) {
		MeshModel* current_model = md->meshList.at(i);

		CMeshO* gum_mesh   = new CMeshO();
		CMeshO* other_mesh = new CMeshO();
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

		//Save
		QString model_name    = current_model->label().mid(0, current_model->label().lastIndexOf('.'));
		QString gum_outpath   = outpath  + "/"  + model_name + "_gum.stl";
		QString teeth_outpath = outpath  + "/"  + model_name + "_teeth.stl";

		std::string gum_outpath_str   = gum_outpath.toLocal8Bit().data();
		std::string teeth_outpath_str = teeth_outpath.toLocal8Bit().data();

		int result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*gum_mesh, gum_outpath_str.c_str(), true);
		result = vcg::tri::io::ExporterSTL<CMeshO>::Save(*other_mesh, teeth_outpath_str.c_str(), true);

		delete gum_mesh;
		delete other_mesh;
	}
}

static void MergeMesh() {
	QStringList files = QFileDialog::getOpenFileNames(nullptr, "Select models to merge", "", "STL(*.stl)");
	std::vector<QString> files_gum, files_teeth;
	for (QString& filepath : files) {
		QString file_name = filepath.split('/').back();
		file_name = file_name.mid(0, file_name.lastIndexOf('.'));

		if (file_name.split('_').back() == QString("gum")) {
			files_gum.push_back(filepath);
		}
		else if (file_name.split('_').back() == QString("teeth")) {
			files_teeth.push_back(filepath);
		}
	}

	for (QString& gum_file_path : files_gum) {
		QString gum_file_name = gum_file_path.split('/').back();
		gum_file_name = gum_file_name.mid(0, gum_file_name.lastIndexOf('.'));
		gum_file_name = gum_file_name.mid(0, gum_file_name.lastIndexOf('_'));

		std::string gum_file_path_str = gum_file_path.toLocal8Bit().constData();
		CMeshO* gum_mesh = new CMeshO();
		int load_mask;
		vcg::tri::io::ImporterSTL<CMeshO>::Open(*gum_mesh, gum_file_path_str.c_str(), load_mask);

		for (QString& teeth_file_path : files_teeth) {
			QString teeth_file_name = teeth_file_path.split('/').back();
			teeth_file_name = teeth_file_name.mid(0, teeth_file_name.lastIndexOf('.'));
			teeth_file_name = teeth_file_name.mid(0, teeth_file_name.lastIndexOf('_'));

			if (gum_file_name == teeth_file_name) {
				CMeshO* teeth_mesh = new CMeshO();
				std::string teeth_file_path_str = teeth_file_path.toLocal8Bit().constData();
				vcg::tri::io::ImporterSTL<CMeshO>::Open(*teeth_mesh, teeth_file_path_str.c_str(), load_mask);
				vcg::tri::Append<CMeshO, CMeshO>::Mesh(*teeth_mesh, *gum_mesh, false);

				QString outputfile = teeth_file_path.mid(0, teeth_file_path.lastIndexOf('/') + 1);
				outputfile += teeth_file_name + ".stl";
				qDebug() << outputfile;

				std::string outputfile_str = outputfile.toLocal8Bit().constData();
				vcg::tri::io::ExporterSTL<CMeshO>::Save(*teeth_mesh, outputfile_str.c_str(), true);

				delete gum_mesh;
				delete teeth_mesh;
				break;
			}
		}
	}
}

/************************************************************************/
/*  生成八字模型的Eigen矩阵
*/
/************************************************************************/
static void generatePinModelEigenMatrix(Eigen::MatrixXd& base_pin_V, Eigen::MatrixXi& base_pin_F)
{
	base_pin_V.resize(16,3);
	base_pin_F.resize(24,3);
	base_pin_F <<
		0, 3, 1, 1, 3, 2, 4, 5, 7,
		5, 6, 7, 0, 1, 5, 0, 5, 4,
		1, 2, 6, 1, 6, 5, 2, 3, 7,
		2, 7, 6, 3, 0, 4, 3, 4, 7,
		8, 11, 9, 9, 11, 10, 12, 13, 15,
		13, 14, 15, 8, 9, 13, 8, 13, 12,
		9, 10, 14, 9, 14, 13, 10, 11, 15,
		10, 15, 14, 11, 8, 12, 11, 12, 15;

	base_pin_left.resize(4);
	base_pin_right.resize(4);

	base_pin_left[0] = vcg::Point3f(10.1987, 44.5046, 3.000000);
	base_pin_left[1] = vcg::Point3f(-4.7031, 8.48, 3.000000);
	base_pin_left[2] = vcg::Point3f(-11.241, 8.5093, 3.000000);
	base_pin_left[3] = vcg::Point3f(3.6473, 44.5046, 3.000000);

	base_pin_right[0] = vcg::Point3f(-4.7031, -8.48, 3.000000);
	base_pin_right[1] = vcg::Point3f(10.1987, -44.5046, 3.000000);
	base_pin_right[2] = vcg::Point3f(3.6473, -44.5046, 3.000000);
	base_pin_right[3] = vcg::Point3f(-11.241, -8.5093, 3.000000);

	for (int i = 0; i < 4; ++i) {
		base_pin_V(i, 0) = base_pin_left[i][0];
		base_pin_V(i, 1) = base_pin_left[i][1];
		base_pin_V(i, 2) = base_pin_left[i][2];
	}
	for (int i = 4; i < 8; ++i) {
		base_pin_V(i, 0) = base_pin_left[i - 4][0];
		base_pin_V(i, 1) = base_pin_left[i - 4][1];
		base_pin_V(i, 2) = -1.733;
	}

	for (int i = 8; i < 12; ++i) {
		base_pin_V(i, 0) = base_pin_right[i - 8][0];
		base_pin_V(i, 1) = base_pin_right[i - 8][1];
		base_pin_V(i, 2) = base_pin_right[i - 8][2];
	}
	for (int i = 12; i < 16; ++i) {
		base_pin_V(i, 0) = base_pin_right[i - 12][0];
		base_pin_V(i, 1) = base_pin_right[i - 12][1];
		base_pin_V(i, 2) = -1.733;
	}
}

static CMeshO* removeAllSmallComponents(CMeshO* input_mesh){
	input_mesh->vert.EnableVFAdjacency();
	input_mesh->face.EnableVFAdjacency();
	input_mesh->face.EnableFFAdjacency();
	vcg::tri::UpdateTopology<CMeshO>::FaceFace(*input_mesh);
	vcg::tri::UpdateTopology<CMeshO>::VertexFace(*input_mesh);

	std::vector< std::pair<int, CMeshO::FacePointer> > connected_components;
	int num_cc = vcg::tri::Clean<CMeshO>::ConnectedComponents(*input_mesh, connected_components);

	CMeshO* out_mesh;
	vcg::GridStaticPtr<CFaceO, float> gum_tri_grid;
	std::vector<CMeshO*> teeth_meshes, unsorted_teeth_meshes;

	for (size_t i = 0; i < connected_components.size(); ++i)
	{
		vcg::tri::UpdateSelection<CMeshO>::FaceClear(*input_mesh);
		connected_components[i].second->SetS();
		vcg::tri::UpdateSelection<CMeshO>::FaceConnectedFF(*input_mesh);
		vcg::tri::UpdateSelection<CMeshO>::VertexClear(*input_mesh);
		vcg::tri::UpdateSelection<CMeshO>::VertexFromFaceLoose(*input_mesh);

		vcg::Box3f bbox;
		for (CMeshO::VertexIterator vit = input_mesh->vert.begin(); vit != input_mesh->vert.end(); ++vit) {
			if (vit->IsS()) {
				bbox.Add(vit->P());
			}
		}

		if (bbox.Diag() > 50) { // is gum
			out_mesh = new CMeshO();
			vcg::tri::Append<CMeshO, CMeshO>::Mesh(*out_mesh, *input_mesh, true);
			delete input_mesh;
			return out_mesh;
		}
	}
	return input_mesh;
}

