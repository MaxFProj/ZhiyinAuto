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

	// 二维码版的各种信息
	struct QRInfo {
		//double width;//底板宽度
		//double length; //底板长度
		//double height; // 底板厚度
		//double theta;  //边界角度
		//double dim;    //模型非直线部分的精细程度

		double qr_width;// 二维码信息宽度
		double qr_height;// 二维码信息厚度

		// 注意：二维码和底座大小可以调，但是背面数字的大小是写死的不可以调
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

	// 鼠标交互状态点
	vcg::Point2f curPoint;                   // 当前绘制的点
	vcg::Point3f currentSelectedPoint;       // 当前点击选中的点
	bool isdbclicked = false;                        // 是否双击
	bool isleftdown  = false;                         // 左侧鼠标是否按下
	bool hasPicked   = true;                          // 鼠标左键按下后，已经找过最近的点（不管是否找到）
	int pickedIndex  = -1;                         // 选中控制点的索引

	std::vector<vcg::Point3f> pointsForAlign;	// 用于摆正的三个点（先上 后左 再右）

	Eigen::MatrixXd base_pin_V;
	Eigen::MatrixXi base_pin_F;

signals:
	void suspendEditToggle();
};
