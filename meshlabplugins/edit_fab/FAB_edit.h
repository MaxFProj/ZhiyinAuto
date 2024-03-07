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

// ��ά���ĸ�����Ϣ
struct QRInfo {
	double width;//�װ���
	double length; //�װ峤��
	double height; // �װ���
	double qr_width;// ��ά����Ϣ���
	double qr_height;// ��ά����Ϣ���
	double theta;  //�߽�Ƕ�
	double dim;    //ģ�ͷ�ֱ�߲��ֵľ�ϸ�̶�

	// ע�⣺��ά��͵�����С���Ե������Ǳ������ֵĴ�С��д���Ĳ����Ե�
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

	void addMidPoints(MeshModel* current_model, std::vector<vcg::Point3f>& vect, double height = 1.0); // �ڿ��Ƶ��������м��
	void putLabelModels(MeshModel* exportMode); //���������߱�ʶģ��
	void pickLaserPoints(GLArea* gla, QPainter* painter);
	void pickAlignPoints(GLArea* gla, QPainter* painter);
	void pickEruptionPoints(GLArea* gla, QPainter* painter);
	void drawCurve(GLArea*);
	void doInterpolation();
	void doInterpolation2();
	void computeDirection();
	void estimatePointNum();//���ÿ��Ƶ�ľ�������и��ߵ����е�ĸ���
	int getCtrlIndex(int pIndex);
	void exportCutLine(QString outPath, MeshModel* exportModel);
	void generateBaseModel(MeshModel* exportModel);
	void recomputeCutDirection(MeshModel* exportModel); // ���¼����и��
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

	// ��꽻��״̬��
	vcg::Point2f curPoint;                   // ��ǰ���Ƶĵ�
	vcg::Point3f currentSelectedPoint;       // ��ǰ���ѡ�еĵ�
	bool isdbclicked;                        // �Ƿ�˫��
	bool isleftdown;                         // �������Ƿ���
	bool hasPicked;                          // ���������º��Ѿ��ҹ�����ĵ㣨�����Ƿ��ҵ���
	int pickedIndex;                         // ѡ�п��Ƶ������
	float interval;                          // ��ɢ���и�������֮��ľ���
	int isrightdown;                         // �Ƿ���ɾ�����ģʽ

	std::vector<vcg::Point3f> pointsForAlign;	// ���ڰ����������㣨���� ���� ���ң�
	std::vector<int> interpolationNums;         // ÿ�������Ƶ�֮��Ĳ�ֵ��ĸ���
	std::vector<vcg::Point3f> pointsForEruption;

	typedef std::vector<std::vector<vcg::Point3f>> DiscreteLineVector;
	std::map<MeshModel*, DiscreteLineVector> border_map;
	std::map<MeshModel*, std::vector<std::vector<bool>>> border_flag_map;

	Eigen::MatrixXd base_pin_V;
	Eigen::MatrixXi base_pin_F;
	CMeshO eruption_mesh;

	// �����и�·������
	int startIndex, endIndex;   // ÿһ���и�·���Ķ˵����� end points indeices of each cut path
	int buccalStart, buccalEnd; // end points of lingual/buccal side ���ͼղ�ķֽ�� 
	int lingualStart, lingualEnd;
	int segNumBuccal, segNumLingual; // �ղ�����Ľظ��߶θ��� number of cut stages of buccal/lingual 
	int stagePointNumber;			 // ÿ��תһ�Σ��и�·���ĵ��� points number of each cut stage.
	int cutDirection; // �и����� 1: bucall side  -1 lingual side
	std::vector<std::vector<double>> position; // ���ÿ���и�ǰ ��е�ֵ�Ԥ�ڵ�λ��
	std::vector<std::vector<vcg::Point3f>> cutseg;
	int currentSeg; //��ǰ��ת���ڼ����и�Ƭ�Ρ� ȡֵ��ΧΪ 0 ~ pathSegNum * 2 - 1
	std::vector<vcg::Point3f> cutlineToLaser; //���յļ����и�·��
	std::vector<vcg::Point3f> initialCutline; //���ֻ����תû��ƽ�Ƶ��и��
	int totalSegNum;      // �и��߶θ���  = segNumBuccal + segLingualNum + 2
	std::vector<double> degreeForEachPath;        // ���ÿһ�ε��и�Ƕ�
	vcg::Point3f laserPos; //��������λ��
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
