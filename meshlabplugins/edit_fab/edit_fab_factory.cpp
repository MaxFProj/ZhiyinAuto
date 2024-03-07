#include "edit_fab_factory.h"

FAB_EditFactory::FAB_EditFactory()
{
	importMesh = new QAction(QIcon(":/images/importMesh.png"), "Import Mesh", this);
	importMesh->setIconText(QApplication::translate("", "\346\211\223\345\274\200\346\250\241\345"
		"\236\213\346\226\207\344\273\266", Q_NULLPTR));

	pickPoints = new QAction(QIcon(":/images/pick align.png"),"", this);//Pick Points
	pickPoints->setIconText(QApplication::translate("", "\346\221\206\346\255\243\351\200\211\347\202\271", Q_NULLPTR));
	
	alignModel = new QAction(QIcon(":/images/align model.png"), "", this); //Align Model
	alignModel->setIconText(QApplication::translate("", "\347\241\256\350\256\244\346\221\206\346\255\243", Q_NULLPTR));

	saveModel = new QAction(QIcon(":/images/save mesh.png"), "", this);//Save Model
	saveModel->setIconText(QApplication::translate("", "\345\257\274\345\207\272\346\250\241\345\236\213", Q_NULLPTR));

	setting = new QAction(QIcon(":/images/setting.png"), "", this); //Setting
	setting->setIconText(QApplication::translate("", "\350\256\276\347\275\256", Q_NULLPTR));

	actionList << pickPoints << alignModel  << saveModel << setting;

	foreach(QAction *editAction, actionList)
		editAction->setCheckable(true); 

	align_model_plugin = new AlignModel_EditPlugin();
}
	
//gets a list of actions available from this plugin
QList<QAction *> FAB_EditFactory::actions() const
{
	return actionList;
}

//get the edit tool for the given action
MeshEditInterface* FAB_EditFactory::getMeshEditInterface(QAction *action)
{
	if (action == importMesh) {
		std::cout << "Change to import mesh mode\n";
		align_model_plugin->setMode(1);
		return align_model_plugin;
	}
	if(action == pickPoints){
		std::cout << "Change to pick align points mode\n";
		align_model_plugin->setMode(2);
		return align_model_plugin;
	}
	else if (action == alignModel) {
		std::cout << "Change to align model mode\n";
		align_model_plugin->setMode(3);
		return align_model_plugin;
	}
	else if (action == saveModel) {
		std::cout << "Change to save model mode\n";
		align_model_plugin->setMode(4);
		return align_model_plugin;
	}
	else if (action == setting) {
		std::cout << "Change to setting mode\n";
		align_model_plugin->setMode(5);
		return align_model_plugin;
	}

	else assert(0); //should never be asked for an action that isnt here
}

QString FAB_EditFactory::getEditToolDescription(QAction * action)
{
	if (action == pickPoints) {
		return AlignModel_EditPlugin::Info();
	}
}

MESHLAB_PLUGIN_NAME_EXPORTER(FAB_EditFactory)
