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

#include "ui_drawtext.h"
#include "ui_drawcurve.h"
#include "ui_hollow_parameter.h"
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

class DrawText_EditPlugin : public QObject, public MeshEditInterface
{
	Q_OBJECT
		Q_INTERFACES(MeshEditInterface)

public:
	DrawText_EditPlugin();
	virtual ~DrawText_EditPlugin() {}

	static const QString Info();

	bool StartEdit(MeshDocument&/*md*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void Decorate(MeshModel&/*m*/, GLArea* /*parent*/, QPainter* p);
	void Decorate(MeshModel&/*m*/, GLArea*) {};
	void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*);
	void mouseMoveEvent(QMouseEvent* event, MeshModel&, GLArea*) {
		cur = event->pos();
	};
	void mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*);
	void keyReleaseEvent(QKeyEvent*, MeshModel&, GLArea*) {};
	void createBase();
	void exportBase();

private:
	QPoint cur;
	QFont qFont;
	bool have_press;
	int picked_index;
	bool have_picked;
	CMeshO::VertexPointer curVertPtr;
	std::vector<vcg::Point3f> picked_points;
	int findNearest(const vcg::Point3f& p);

	Ui::DrawTextParameterDialog parameter_dialog_ui;
	QDialog* parameter_dialog;
	MeshDocument* md;
	GLArea* gla;
	std::map<QString, CMeshO*> left_base_map, right_base_map;
	std::map<QString, std::vector<vcg::Point3f>> picked_points_proj_map; // 8 picked points after project to mesh

signals:
	void suspendEditToggle();

};

// 二维码版的各种信息
struct QRInfo {
	double width;//底板宽度
	double length; //底板长度
	double height; // 底板厚度
	double qr_width;// 二维码信息宽度
	double qr_height;// 二维码信息厚度
	double theta;  //边界角度
	double dim;    //模型非直线部分的精细程度

	// 注意：二维码和底座大小可以调，但是背面数字的大小是写死的不可以调
	QRInfo() {
		width = 25;
		length = 19.95;
		height = 1.5;

		theta = 30;
		dim = 20;

		qr_width = 15;
		qr_height = 1.5;
	}
};

class DrawCurve_EditPlugin : public QObject, public MeshEditInterface {
	Q_OBJECT
		Q_INTERFACES(MeshEditInterface)

		enum PluginMode {
		EMPTY, PICK_ALIGN, PICK_LASER, PICK_ERUPTION,
		SHOW_ERUPTION, DRAW, CONTINUE_DRAW
	};
public:
	DrawCurve_EditPlugin();
	virtual ~DrawCurve_EditPlugin();

	static const QString Info();

	bool StartEdit(MeshDocument&/*md*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void Decorate(MeshModel&/*m*/, GLArea* /*parent*/, QPainter* p);
	void Decorate(MeshModel&/*m*/, GLArea*) {};
	void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*);
	void mouseMoveEvent(QMouseEvent* event, MeshModel&, GLArea*);
	void mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*);
	void mouseDoubleClickEvent(QMouseEvent* event, MeshModel&, GLArea*);

	void slotAlignAllModels();
	void slotExport();
	void slotNextModel();
	void slotLastModel();
	void slotPutEruption();
	void slotTransformEruption(double);
	void slotImportCtrlPoints();
	void slotPutLabelModels();
	void slotComputeCtrlPoints();
	void slotChangeGumHeight();
	void exportModels(QString outPath, MeshModel* current_model);
	void exportOCModels(QString outPath, MeshModel* current_model, CMeshO*& gum_mesh, CMeshO*& other_mesh);

	void addMidPoints(MeshModel* current_model, std::vector<vcg::Point3f>& vect, double height = 1.0); // 在控制点中增加中间点
	void putLabelModels(MeshModel* exportMode); //安放牙龈线标识模型
	void pickLaserPoints(GLArea* gla, QPainter* painter);
	void pickAlignPoints(GLArea* gla, QPainter* painter);
	void pickEruptionPoints(GLArea* gla, QPainter* painter);
	void drawCurve(GLArea*);
	void doInterpolation();
	void doInterpolation2();
	void computeDirection();
	void estimatePointNum();//利用控制点的距离估算切割线的所有点的个数
	int getCtrlIndex(int pIndex);
	void exportCutLine(QString outPath, MeshModel* exportModel);
	void generateBaseModel(MeshModel* exportModel);
	void recomputeCutDirection(MeshModel* exportModel); // 重新计算切割方向
	void moveDownGumLine(MeshModel* current_model, double move_distance);
	void exportLaserCutline(QString outPath, MeshModel* current_model);
	void rotateJawModel(MeshModel* current_model);
	vcg::Matrix44f adjustDirectionToXorYAxis(vcg::Point3f& OA, vcg::Point3f& OB, vcg::Point3f& yAxis, double& degree);
	void initialLaserCutlineParameter();
	void importOneCtrlPoints(MeshModel* current_model, QString& file_path);

private:
	Ui::DrawCutlineDockWidget parameter_widget_ui;
	QDockWidget* parameter_widget;
	MeshDocument* md;
	GLArea* gla;
	MLSceneGLSharedDataContext* context;
	PluginMode mode;
	int current_mesh_index;

	QRInfo qr_info;
	float default_cut_offset = 0.6;

	// 鼠标交互状态点
	vcg::Point2f curPoint;                   // 当前绘制的点
	vcg::Point3f currentSelectedPoint;       // 当前点击选中的点
	bool isdbclicked;                        // 是否双击
	bool isleftdown;                         // 左侧鼠标是否按下
	bool hasPicked;                          // 鼠标左键按下后，已经找过最近的点（不管是否找到）
	int pickedIndex;                         // 选中控制点的索引
	float interval;                          // 离散的切割线两点之间的距离
	int isrightdown;                         // 是否在删除点的模式

	std::vector<vcg::Point3f> pointsForAlign;	// 用于摆正的三个点（先上 后左 再右）
	std::vector<int> interpolationNums;         // 每两个控制点之间的插值点的个数
	std::vector<vcg::Point3f> pointsForEruption;

	typedef std::vector<std::vector<vcg::Point3f>> DiscreteLineVector;
	std::map<MeshModel*, DiscreteLineVector> border_map;
	std::map<MeshModel*, std::vector<std::vector<bool>>> border_flag_map;

	Eigen::MatrixXd base_pin_V;
	Eigen::MatrixXi base_pin_F;
	CMeshO eruption_mesh;

	// 激光切割路径参数
	int startIndex, endIndex;   // 每一段切割路径的端点索引 end points indeices of each cut path
	int buccalStart, buccalEnd; // end points of lingual/buccal side 舌侧和颊侧的分界点 
	int lingualStart, lingualEnd;
	int segNumBuccal, segNumLingual; // 颊侧和舌侧的截个线段个数 number of cut stages of buccal/lingual 
	int stagePointNumber;			 // 每旋转一次，切割路径的点数 points number of each cut stage.
	int cutDirection; // 切割方向控制 1: bucall side  -1 lingual side
	std::vector<std::vector<double>> position; // 存放每次切割前 机械手的预期的位置
	std::vector<std::vector<vcg::Point3f>> cutseg;
	int currentSeg; //当前旋转到第几个切割片段。 取值范围为 0 ~ pathSegNum * 2 - 1
	std::vector<vcg::Point3f> cutlineToLaser; //最终的激光切割路径
	std::vector<vcg::Point3f> initialCutline; //存放只有旋转没有平移的切割点
	int totalSegNum;      // 切割线段个数  = segNumBuccal + segLingualNum + 2
	std::vector<double> degreeForEachPath;        // 存放每一段的切割角度
	vcg::Point3f laserPos; //激光器的位置
};

class AutoHollow_EditPlugin : public QObject, public MeshEditInterface
{
	Q_OBJECT
		Q_INTERFACES(MeshEditInterface)

public:
	AutoHollow_EditPlugin();
	virtual ~AutoHollow_EditPlugin() {}

	static const QString Info();

	bool StartEdit(MeshDocument&/*md*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void Decorate(MeshModel&/*m*/, GLArea* /*parent*/, QPainter* p);
	void Decorate(MeshModel&/*m*/, GLArea*) {};
	void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*) {};
	void mouseMoveEvent(QMouseEvent* event, MeshModel&, GLArea*) {
	};
	void mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*) {};
	void keyReleaseEvent(QKeyEvent*, MeshModel&, GLArea*) {};

private:
	MeshDocument* md;
	GLArea* gla;
	std::vector<MeshModel*> all_models;
	QDialog* hollow_dialog = nullptr;
	Ui::HollowDialog hollow_ui;

private:
	CMeshO* hollowGum(CMeshO* gum);
	void smoothBoundary(std::vector<CVertexO*>& a, int ite);
	void makeBridge(CMeshO* mesh, std::vector<CVertexO*>& a, std::vector<CVertexO*>& b);
	void exportHollowedMQModels(MeshModel* othermeshes_from_other_plugin, CMeshO* gummeshes_from_other_plugin, QString& outpath);

signals:
	void suspendEditToggle();
	//void exportHollowedMQModels(MeshModel* othermeshes_from_other_plugin, CMeshO* gummeshes_from_other_plugin, QString& outpath);
	void sendModelPath(QString& modelpath);
};

/********************************************************************************/
class MergeUndercut_EditPlugin : public QObject, public MeshEditInterface
{
	Q_OBJECT
		Q_INTERFACES(MeshEditInterface)

public:
	MergeUndercut_EditPlugin();
	virtual ~MergeUndercut_EditPlugin() {}

	static const QString Info();

	bool StartEdit(MeshDocument&/*md*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void EndEdit(MeshDocument&/*m*/, GLArea* /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
	void Decorate(MeshModel&/*m*/, GLArea* /*parent*/, QPainter* p) {};
	void Decorate(MeshModel&/*m*/, GLArea*) {};
	void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*) {};
	void mouseMoveEvent(QMouseEvent* event, MeshModel&, GLArea*) {};
	void mouseReleaseEvent(QMouseEvent* event, MeshModel&/*m*/, GLArea*) {};
	void keyReleaseEvent(QKeyEvent*, MeshModel&, GLArea*) {};

	void setModelPath(QString& modelpath) {
		this->modelpath = modelpath;
	};

private:
	MeshDocument* md;
	GLArea* gla;
	QString modelpath;

private:
	void mergeUndercut();
signals:
	void suspendEditToggle();
};
