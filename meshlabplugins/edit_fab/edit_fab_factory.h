
#ifndef FAB_EditFactoryPLUGIN_H
#define FAB_EditFactoryPLUGIN_H

#include <QObject>
#include <common/interfaces.h>
#include "process_edit.h"

class FAB_EditFactory : public QObject, public MeshEditInterfaceFactory
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(MESH_EDIT_INTERFACE_FACTORY_IID)
	Q_INTERFACES(MeshEditInterfaceFactory)

public:
	FAB_EditFactory();
	virtual ~FAB_EditFactory() { 
		delete align_model_plugin;
	}

	//gets a list of actions available from this plugin
	virtual QList<QAction *> actions() const;
	
	//get the edit tool for the given action
	virtual MeshEditInterface* getMeshEditInterface(QAction *);
    
	//get the description for the given action
   virtual QString getEditToolDescription(QAction *);
	
private:
	QList <QAction *> actionList;
	QAction *importMesh, *pickPoints, *alignModel, *saveModel;
	QAction* setting;
	AlignModel_EditPlugin* align_model_plugin;
};

#endif
