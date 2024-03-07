#pragma once

#include <QObject>
#include <common/interfaces.h>
#include <meshlab/glarea.h>

#include <wrap/gui/coordinateframe.h>
#include <wrap/io_trimesh/export_obj.h>
#include <wrap/io_trimesh/import_obj.h>
#include <wrap/io_trimesh/export_stl.h>
#include <wrap/qt/gl_label.h>

#include <vcg/simplex/edge/distance.h>
#include <vcg/complex/algorithms/clean.h>
#include <vcg/complex/algorithms/create/resampler.h>
#include <vcg/complex/algorithms/hole.h>
#include <vcg/complex/algorithms/refine.h>
#include <vcg/complex/algorithms/smooth.h>
#include <vcg/space/index/octree.h>
#include <vcg/space/index/aabb_binary_tree/aabb_binary_tree.h>

#include <igl/copyleft/cgal/mesh_boolean.h>
#include <igl/write_triangle_mesh.h>

#include "ui_setting_parameter.h"
#include "common/SGSmooth.h"
#include "common_func.h"

#include <GL/glut.h>

#include <QProgressDialog>
#include <QtGui>
#include <QFileDialog>

#include <map>

typedef vcg::AABBBinaryTreeIndex<CFaceO, float, vcg::EmptyClass> AABBTree;
#define Kr 1.0000
#define L 3 
#define lamda 0
#define EmptyPontic 8
#define ExtractPontic 9
#define FPI 3.14159265354
#define FPi 3.14159265354

class AlignModel_EditPlugin : public QObject, public MeshEditInterface
{
	Q_OBJECT
		Q_INTERFACES(MeshEditInterface)

	enum PluginMode {
		EMPTY, IMPORT_MESH, PICK_ALIGN, 
		ALIGN_MODEL, SAVE_MODEL, SETTING
	};

	// ��ά���ĸ�����Ϣ
	struct QRInfo {
		//double width;//�װ���
		//double length; //�װ峤��
		//double height; // �װ���
		//double theta;  //�߽�Ƕ�
		//double dim;    //ģ�ͷ�ֱ�߲��ֵľ�ϸ�̶�

		double qr_width;// ��ά����Ϣ���
		double qr_height;// ��ά����Ϣ���

		// ע�⣺��ά��͵�����С���Ե������Ǳ������ֵĴ�С��д���Ĳ����Ե�
		QRInfo() {
			//width = 25;
			//length = 15;
			//height = 1.6;

			//theta = 30;
			//dim = 20;

			qr_width  = 19;
			qr_height = 1.4;
		}
	};

public:
	AlignModel_EditPlugin();
	virtual ~AlignModel_EditPlugin() {}

	static const QString Info() { return QString("Align Model Plugin."); }

	bool StartEdit(MeshDocument&/*md*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/) {
		emit suspendEditToggle();
	};
	void Decorate(MeshModel&/*m*/, GLArea* /*parent*/, QPainter* p);
	void Decorate(MeshModel&/*m*/, GLArea*) {};
	void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*);
	void mouseMoveEvent(QMouseEvent* event, MeshModel&, GLArea*);
	void mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*);
	void mouseDoubleClickEvent(QMouseEvent* event, MeshModel&, GLArea*);
	void keyReleaseEvent(QKeyEvent*, MeshModel&, GLArea*) {};

	void pickAlignPoints(GLArea* gla, QPainter* painter);
	void setMode(int m);	
	void alignAllModels();
	void saveModels();
	void generateBaseModel(MeshModel*);
	void exportOneModel(QString outpath, MeshModel* current_model);
private:
	MeshDocument* md	= nullptr;
	GLArea* gla			= nullptr;
	MLSceneGLSharedDataContext* context = nullptr;
	PluginMode mode = PluginMode::EMPTY;
	int current_mesh_index = 0;
	QString root_directory;

	QRInfo qr_info;
	float default_cut_offset = 0.6;

	Ui::SettingDialog* setting_ui	= nullptr;
	QDialog* setting_dialog			= nullptr;

	CMeshO* demo_base = nullptr;

	// ��꽻��״̬��
	vcg::Point2f curPoint;                   // ��ǰ���Ƶĵ�
	vcg::Point3f currentSelectedPoint;       // ��ǰ���ѡ�еĵ�
	bool isdbclicked = false;                        // �Ƿ�˫��
	bool isleftdown  = false;                         // �������Ƿ���
	bool hasPicked   = true;                          // ���������º��Ѿ��ҹ�����ĵ㣨�����Ƿ��ҵ���
	int pickedIndex  = -1;                         // ѡ�п��Ƶ������

	std::vector<vcg::Point3f> pointsForAlign;	// ���ڰ����������㣨���� ���� ���ң�

	Eigen::MatrixXd base_pin_V;
	Eigen::MatrixXi base_pin_F;

signals:
	void suspendEditToggle();
};
