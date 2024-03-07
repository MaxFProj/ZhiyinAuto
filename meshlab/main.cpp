/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#include <common/mlapplication.h>
#include <QMessageBox>
#include "mainwindow.h"
#include <QString>

#ifdef  USE_LICENSE_MANAGE
#include "LicenseManager\QtLicenseManager.h"
#include "LicenseManager\emxMessageHandler.h"
#endif

int main(int argc, char *argv[])
{
    std::ofstream ofs("D://log.txt", std::ios_base::out);
    ofs << __LINE__ << '\n';

    MeshLabApplication app(argc, argv);

    ofs << __LINE__ << '\n';

#ifdef USE_LICENSE_MANAGE
    emxMessageHandler* msgHandler = new emxMessageHandler;
    QtLicenseManager::init(); // init a license manager
    LicenseManager::instance()->setMessageHandler(msgHandler);
    char errInfo[256];
    sprintf(errInfo, "%s", QApplication::translate("QtLicenseManager", "Failed to get license! Please contact to your software provider and get a license to continue to use this software.", nullptr).toLocal8Bit().data());
    if (LicenseManager::instance()->check(errInfo) != LM_SUCCESS)
    {
        QMessageBox::critical(nullptr, QApplication::translate("QtLicenseManager", "Error", 0), QString::fromLocal8Bit(errInfo));
        exit(0);
    }
#endif

    QLocale::setDefault(QLocale::C);
    QCoreApplication::setOrganizationName(MeshLabApplication::organization());
#if QT_VERSION >= 0x050100
    // Enable support for highres images (added in Qt 5.1, but off by default)
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    QString tmp = MeshLabApplication::appArchitecturalName(MeshLabApplication::HW_ARCHITECTURE(QSysInfo::WordSize));
    QCoreApplication::setApplicationName(MeshLabApplication::appArchitecturalName(MeshLabApplication::HW_ARCHITECTURE(QSysInfo::WordSize)));
   
    ofs << __LINE__ << '\n';

    MainWindow window;
    window.showMaximized();

    // This event filter is installed to intercept the open events sent directly by the Operative System.
    FileOpenEater *filterObj=new FileOpenEater(&window);
    app.installEventFilter(filterObj);
    app.processEvents();

    ofs << __LINE__ << '\n';

    if(argc>1)
    {
        QString helpOpt1="-h";
        QString helpOpt2="--help";
        if( (helpOpt1==argv[1]) || (helpOpt2==argv[1]) )
            printf(
            "usage:\n"
            "meshlab <meshfile>\n"
            "Look at http://www.meshlab.net\n"
            "for a longer documentation\n"
            );

        if(QString(argv[1]).endsWith("mlp",Qt::CaseInsensitive) || QString(argv[1]).endsWith("aln",Qt::CaseInsensitive) || QString(argv[1]).endsWith("out",Qt::CaseInsensitive) || QString(argv[1]).endsWith("nvm",Qt::CaseInsensitive))
            window.openProject(argv[1]);
        else
            window.importMeshWithLayerManagement(argv[1]);
    }

    ofs << __LINE__ << '\n';
    ofs.close();

    //else 	if(filterObj->noEvent) window.open();
    return app.exec();
}
