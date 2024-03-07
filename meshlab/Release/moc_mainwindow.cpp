/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[135];
    char stringdata0[2039];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "dispatchCustomSettings"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "RichParameterSet&"
QT_MOC_LITERAL(4, 53, 3), // "rps"
QT_MOC_LITERAL(5, 57, 14), // "filterExecuted"
QT_MOC_LITERAL(6, 72, 16), // "updateLayerTable"
QT_MOC_LITERAL(7, 89, 10), // "newProject"
QT_MOC_LITERAL(8, 100, 8), // "projName"
QT_MOC_LITERAL(9, 109, 11), // "saveProject"
QT_MOC_LITERAL(10, 121, 9), // "meshAdded"
QT_MOC_LITERAL(11, 131, 3), // "mid"
QT_MOC_LITERAL(12, 135, 11), // "meshRemoved"
QT_MOC_LITERAL(13, 147, 29), // "importMeshWithLayerManagement"
QT_MOC_LITERAL(14, 177, 8), // "fileName"
QT_MOC_LITERAL(15, 186, 21), // "changeImportFileNames"
QT_MOC_LITERAL(16, 208, 12), // "importRaster"
QT_MOC_LITERAL(17, 221, 7), // "fileImg"
QT_MOC_LITERAL(18, 229, 11), // "openProject"
QT_MOC_LITERAL(19, 241, 13), // "appendProject"
QT_MOC_LITERAL(20, 255, 20), // "updateCustomSettings"
QT_MOC_LITERAL(21, 276, 17), // "updateLayerDialog"
QT_MOC_LITERAL(22, 294, 36), // "addRenderingDataIfNewlyGenera..."
QT_MOC_LITERAL(23, 331, 6), // "meshid"
QT_MOC_LITERAL(24, 338, 37), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(25, 376, 25), // "QList<MLRenderingAction*>"
QT_MOC_LITERAL(26, 402, 4), // "acts"
QT_MOC_LITERAL(27, 407, 55), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(28, 463, 18), // "MLRenderingAction*"
QT_MOC_LITERAL(29, 482, 3), // "act"
QT_MOC_LITERAL(30, 486, 26), // "QList<MLRenderingAction*>&"
QT_MOC_LITERAL(31, 513, 36), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(32, 550, 54), // "updateRenderingDataAccordingT..."
QT_MOC_LITERAL(33, 605, 31), // "QList<MLRenderingGlobalAction*>"
QT_MOC_LITERAL(34, 637, 7), // "actlist"
QT_MOC_LITERAL(35, 645, 23), // "documentUpdateRequested"
QT_MOC_LITERAL(36, 669, 10), // "importMesh"
QT_MOC_LITERAL(37, 680, 9), // "isareload"
QT_MOC_LITERAL(38, 690, 7), // "endEdit"
QT_MOC_LITERAL(39, 698, 28), // "updateDocumentScriptBindings"
QT_MOC_LITERAL(40, 727, 22), // "loadAndInsertXMLPlugin"
QT_MOC_LITERAL(41, 750, 7), // "xmlpath"
QT_MOC_LITERAL(42, 758, 10), // "scriptname"
QT_MOC_LITERAL(43, 769, 19), // "postFilterExecution"
QT_MOC_LITERAL(44, 789, 17), // "updateProgressBar"
QT_MOC_LITERAL(45, 807, 3), // "pos"
QT_MOC_LITERAL(46, 811, 4), // "text"
QT_MOC_LITERAL(47, 816, 13), // "updateTexture"
QT_MOC_LITERAL(48, 830, 20), // "closeCurrentDocument"
QT_MOC_LITERAL(49, 851, 6), // "reload"
QT_MOC_LITERAL(50, 858, 13), // "reloadAllMesh"
QT_MOC_LITERAL(51, 872, 14), // "openRecentMesh"
QT_MOC_LITERAL(52, 887, 14), // "openRecentProj"
QT_MOC_LITERAL(53, 902, 6), // "saveAs"
QT_MOC_LITERAL(54, 909, 25), // "saveAllPossibleAttributes"
QT_MOC_LITERAL(55, 935, 4), // "save"
QT_MOC_LITERAL(56, 940, 12), // "saveSnapshot"
QT_MOC_LITERAL(57, 953, 19), // "changeFileExtension"
QT_MOC_LITERAL(58, 973, 13), // "applyEditMode"
QT_MOC_LITERAL(59, 987, 15), // "suspendEditMode"
QT_MOC_LITERAL(60, 1003, 11), // "startFilter"
QT_MOC_LITERAL(61, 1015, 15), // "applyLastFilter"
QT_MOC_LITERAL(62, 1031, 15), // "runFilterScript"
QT_MOC_LITERAL(63, 1047, 16), // "showFilterScript"
QT_MOC_LITERAL(64, 1064, 22), // "showXMLPluginEditorGui"
QT_MOC_LITERAL(65, 1087, 11), // "showTooltip"
QT_MOC_LITERAL(66, 1099, 8), // "QAction*"
QT_MOC_LITERAL(67, 1108, 15), // "applyRenderMode"
QT_MOC_LITERAL(68, 1124, 17), // "applyDecorateMode"
QT_MOC_LITERAL(69, 1142, 18), // "switchOffDecorator"
QT_MOC_LITERAL(70, 1161, 10), // "fullScreen"
QT_MOC_LITERAL(71, 1172, 15), // "showToolbarFile"
QT_MOC_LITERAL(72, 1188, 12), // "showInfoPane"
QT_MOC_LITERAL(73, 1201, 13), // "showTrackBall"
QT_MOC_LITERAL(74, 1215, 14), // "resetTrackBall"
QT_MOC_LITERAL(75, 1230, 12), // "showLayerDlg"
QT_MOC_LITERAL(76, 1243, 7), // "visible"
QT_MOC_LITERAL(77, 1251, 10), // "showRaster"
QT_MOC_LITERAL(78, 1262, 16), // "updateWindowMenu"
QT_MOC_LITERAL(79, 1279, 11), // "updateMenus"
QT_MOC_LITERAL(80, 1291, 20), // "updateSubFiltersMenu"
QT_MOC_LITERAL(81, 1312, 17), // "createmenuenabled"
QT_MOC_LITERAL(82, 1330, 12), // "validmeshdoc"
QT_MOC_LITERAL(83, 1343, 15), // "updateMenuItems"
QT_MOC_LITERAL(84, 1359, 6), // "QMenu*"
QT_MOC_LITERAL(85, 1366, 4), // "menu"
QT_MOC_LITERAL(86, 1371, 7), // "enabled"
QT_MOC_LITERAL(87, 1379, 15), // "updateStdDialog"
QT_MOC_LITERAL(88, 1395, 18), // "updateXMLStdDialog"
QT_MOC_LITERAL(89, 1414, 38), // "enableDocumentSensibleActions..."
QT_MOC_LITERAL(90, 1453, 6), // "enable"
QT_MOC_LITERAL(91, 1460, 8), // "setSplit"
QT_MOC_LITERAL(92, 1469, 2), // "qa"
QT_MOC_LITERAL(93, 1472, 10), // "setUnsplit"
QT_MOC_LITERAL(94, 1483, 11), // "linkViewers"
QT_MOC_LITERAL(95, 1495, 8), // "viewFrom"
QT_MOC_LITERAL(96, 1504, 11), // "toggleOrtho"
QT_MOC_LITERAL(97, 1516, 13), // "trackballStep"
QT_MOC_LITERAL(98, 1530, 16), // "readViewFromFile"
QT_MOC_LITERAL(99, 1547, 23), // "viewFromCurrentMeshShot"
QT_MOC_LITERAL(100, 1571, 25), // "viewFromCurrentRasterShot"
QT_MOC_LITERAL(101, 1597, 19), // "copyViewToClipBoard"
QT_MOC_LITERAL(102, 1617, 22), // "pasteViewFromClipboard"
QT_MOC_LITERAL(103, 1640, 15), // "splitFromHandle"
QT_MOC_LITERAL(104, 1656, 17), // "unsplitFromHandle"
QT_MOC_LITERAL(105, 1674, 12), // "setCustomize"
QT_MOC_LITERAL(106, 1687, 5), // "about"
QT_MOC_LITERAL(107, 1693, 12), // "aboutPlugins"
QT_MOC_LITERAL(108, 1706, 10), // "helpOnline"
QT_MOC_LITERAL(109, 1717, 12), // "helpOnscreen"
QT_MOC_LITERAL(110, 1730, 9), // "submitBug"
QT_MOC_LITERAL(111, 1740, 11), // "sendUsAMail"
QT_MOC_LITERAL(112, 1752, 15), // "checkForUpdates"
QT_MOC_LITERAL(113, 1768, 11), // "verboseFlag"
QT_MOC_LITERAL(114, 1780, 9), // "dropEvent"
QT_MOC_LITERAL(115, 1790, 11), // "QDropEvent*"
QT_MOC_LITERAL(116, 1802, 5), // "event"
QT_MOC_LITERAL(117, 1808, 14), // "dragEnterEvent"
QT_MOC_LITERAL(118, 1823, 16), // "QDragEnterEvent*"
QT_MOC_LITERAL(119, 1840, 14), // "connectionDone"
QT_MOC_LITERAL(120, 1855, 14), // "QNetworkReply*"
QT_MOC_LITERAL(121, 1870, 5), // "reply"
QT_MOC_LITERAL(122, 1876, 11), // "sendHistory"
QT_MOC_LITERAL(123, 1888, 22), // "wrapSetActiveSubWindow"
QT_MOC_LITERAL(124, 1911, 8), // "QWidget*"
QT_MOC_LITERAL(125, 1920, 6), // "window"
QT_MOC_LITERAL(126, 1927, 22), // "switchCurrentContainer"
QT_MOC_LITERAL(127, 1950, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(128, 1965, 18), // "scriptCodeExecuted"
QT_MOC_LITERAL(129, 1984, 12), // "QScriptValue"
QT_MOC_LITERAL(130, 1997, 3), // "val"
QT_MOC_LITERAL(131, 2001, 4), // "time"
QT_MOC_LITERAL(132, 2006, 6), // "output"
QT_MOC_LITERAL(133, 2013, 15), // "updateGPUMemBar"
QT_MOC_LITERAL(134, 2029, 9) // "updateLog"

    },
    "MainWindow\0dispatchCustomSettings\0\0"
    "RichParameterSet&\0rps\0filterExecuted\0"
    "updateLayerTable\0newProject\0projName\0"
    "saveProject\0meshAdded\0mid\0meshRemoved\0"
    "importMeshWithLayerManagement\0fileName\0"
    "changeImportFileNames\0importRaster\0"
    "fileImg\0openProject\0appendProject\0"
    "updateCustomSettings\0updateLayerDialog\0"
    "addRenderingDataIfNewlyGeneratedMesh\0"
    "meshid\0updateRenderingDataAccordingToActions\0"
    "QList<MLRenderingAction*>\0acts\0"
    "updateRenderingDataAccordingToActionsToAllVisibleLayers\0"
    "MLRenderingAction*\0act\0"
    "QList<MLRenderingAction*>&\0"
    "updateRenderingDataAccordingToAction\0"
    "updateRenderingDataAccordingToActionToAllVisibleLayers\0"
    "QList<MLRenderingGlobalAction*>\0actlist\0"
    "documentUpdateRequested\0importMesh\0"
    "isareload\0endEdit\0updateDocumentScriptBindings\0"
    "loadAndInsertXMLPlugin\0xmlpath\0"
    "scriptname\0postFilterExecution\0"
    "updateProgressBar\0pos\0text\0updateTexture\0"
    "closeCurrentDocument\0reload\0reloadAllMesh\0"
    "openRecentMesh\0openRecentProj\0saveAs\0"
    "saveAllPossibleAttributes\0save\0"
    "saveSnapshot\0changeFileExtension\0"
    "applyEditMode\0suspendEditMode\0startFilter\0"
    "applyLastFilter\0runFilterScript\0"
    "showFilterScript\0showXMLPluginEditorGui\0"
    "showTooltip\0QAction*\0applyRenderMode\0"
    "applyDecorateMode\0switchOffDecorator\0"
    "fullScreen\0showToolbarFile\0showInfoPane\0"
    "showTrackBall\0resetTrackBall\0showLayerDlg\0"
    "visible\0showRaster\0updateWindowMenu\0"
    "updateMenus\0updateSubFiltersMenu\0"
    "createmenuenabled\0validmeshdoc\0"
    "updateMenuItems\0QMenu*\0menu\0enabled\0"
    "updateStdDialog\0updateXMLStdDialog\0"
    "enableDocumentSensibleActionsContainer\0"
    "enable\0setSplit\0qa\0setUnsplit\0linkViewers\0"
    "viewFrom\0toggleOrtho\0trackballStep\0"
    "readViewFromFile\0viewFromCurrentMeshShot\0"
    "viewFromCurrentRasterShot\0copyViewToClipBoard\0"
    "pasteViewFromClipboard\0splitFromHandle\0"
    "unsplitFromHandle\0setCustomize\0about\0"
    "aboutPlugins\0helpOnline\0helpOnscreen\0"
    "submitBug\0sendUsAMail\0checkForUpdates\0"
    "verboseFlag\0dropEvent\0QDropEvent*\0"
    "event\0dragEnterEvent\0QDragEnterEvent*\0"
    "connectionDone\0QNetworkReply*\0reply\0"
    "sendHistory\0wrapSetActiveSubWindow\0"
    "QWidget*\0window\0switchCurrentContainer\0"
    "QMdiSubWindow*\0scriptCodeExecuted\0"
    "QScriptValue\0val\0time\0output\0"
    "updateGPUMemBar\0updateLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     105,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  539,    2, 0x06 /* Public */,
       5,    0,  542,    2, 0x06 /* Public */,
       6,    0,  543,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  544,    2, 0x08 /* Private */,
       7,    0,  547,    2, 0x28 /* Private | MethodCloned */,
       9,    0,  548,    2, 0x08 /* Private */,
      10,    1,  549,    2, 0x08 /* Private */,
      12,    1,  552,    2, 0x08 /* Private */,
      13,    1,  555,    2, 0x0a /* Public */,
      13,    0,  558,    2, 0x2a /* Public | MethodCloned */,
      15,    0,  559,    2, 0x0a /* Public */,
      16,    1,  560,    2, 0x0a /* Public */,
      16,    0,  563,    2, 0x2a /* Public | MethodCloned */,
      18,    1,  564,    2, 0x0a /* Public */,
      18,    0,  567,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  568,    2, 0x0a /* Public */,
      19,    0,  571,    2, 0x2a /* Public | MethodCloned */,
      20,    0,  572,    2, 0x0a /* Public */,
      21,    0,  573,    2, 0x0a /* Public */,
      22,    1,  574,    2, 0x0a /* Public */,
      24,    2,  577,    2, 0x0a /* Public */,
      27,    1,  582,    2, 0x0a /* Public */,
      24,    3,  585,    2, 0x0a /* Public */,
      31,    2,  592,    2, 0x0a /* Public */,
      32,    1,  597,    2, 0x0a /* Public */,
      31,    3,  600,    2, 0x0a /* Public */,
      24,    1,  607,    2, 0x0a /* Public */,
      35,    0,  610,    2, 0x08 /* Private */,
      36,    2,  611,    2, 0x08 /* Private */,
      36,    1,  616,    2, 0x28 /* Private | MethodCloned */,
      36,    0,  619,    2, 0x28 /* Private | MethodCloned */,
      38,    0,  620,    2, 0x08 /* Private */,
      39,    0,  621,    2, 0x08 /* Private */,
      40,    2,  622,    2, 0x08 /* Private */,
      43,    0,  627,    2, 0x08 /* Private */,
      44,    2,  628,    2, 0x08 /* Private */,
      47,    1,  633,    2, 0x08 /* Private */,
      48,    0,  636,    2, 0x08 /* Private */,
      49,    0,  637,    2, 0x08 /* Private */,
      50,    0,  638,    2, 0x08 /* Private */,
      51,    0,  639,    2, 0x08 /* Private */,
      52,    0,  640,    2, 0x08 /* Private */,
      53,    2,  641,    2, 0x08 /* Private */,
      53,    1,  646,    2, 0x28 /* Private | MethodCloned */,
      53,    0,  649,    2, 0x28 /* Private | MethodCloned */,
      55,    1,  650,    2, 0x08 /* Private */,
      55,    0,  653,    2, 0x28 /* Private | MethodCloned */,
      56,    0,  654,    2, 0x08 /* Private */,
      57,    1,  655,    2, 0x08 /* Private */,
      58,    0,  658,    2, 0x08 /* Private */,
      59,    0,  659,    2, 0x08 /* Private */,
      60,    0,  660,    2, 0x08 /* Private */,
      61,    0,  661,    2, 0x08 /* Private */,
      62,    0,  662,    2, 0x08 /* Private */,
      63,    0,  663,    2, 0x08 /* Private */,
      64,    0,  664,    2, 0x08 /* Private */,
      65,    1,  665,    2, 0x08 /* Private */,
      67,    0,  668,    2, 0x08 /* Private */,
      68,    0,  669,    2, 0x08 /* Private */,
      69,    1,  670,    2, 0x08 /* Private */,
      70,    0,  673,    2, 0x08 /* Private */,
      71,    0,  674,    2, 0x08 /* Private */,
      72,    0,  675,    2, 0x08 /* Private */,
      73,    0,  676,    2, 0x08 /* Private */,
      74,    0,  677,    2, 0x08 /* Private */,
      75,    1,  678,    2, 0x08 /* Private */,
      77,    0,  681,    2, 0x08 /* Private */,
      78,    0,  682,    2, 0x08 /* Private */,
      79,    0,  683,    2, 0x08 /* Private */,
      80,    2,  684,    2, 0x08 /* Private */,
      83,    2,  689,    2, 0x08 /* Private */,
      87,    0,  694,    2, 0x08 /* Private */,
      88,    0,  695,    2, 0x08 /* Private */,
      89,    1,  696,    2, 0x08 /* Private */,
      91,    1,  699,    2, 0x08 /* Private */,
      93,    0,  702,    2, 0x08 /* Private */,
      94,    0,  703,    2, 0x08 /* Private */,
      95,    1,  704,    2, 0x08 /* Private */,
      96,    0,  707,    2, 0x08 /* Private */,
      97,    1,  708,    2, 0x08 /* Private */,
      98,    0,  711,    2, 0x08 /* Private */,
      99,    0,  712,    2, 0x08 /* Private */,
     100,    0,  713,    2, 0x08 /* Private */,
     101,    0,  714,    2, 0x08 /* Private */,
     102,    0,  715,    2, 0x08 /* Private */,
     103,    1,  716,    2, 0x08 /* Private */,
     104,    1,  719,    2, 0x08 /* Private */,
     105,    0,  722,    2, 0x08 /* Private */,
     106,    0,  723,    2, 0x08 /* Private */,
     107,    0,  724,    2, 0x08 /* Private */,
     108,    0,  725,    2, 0x08 /* Private */,
     109,    0,  726,    2, 0x08 /* Private */,
     110,    0,  727,    2, 0x08 /* Private */,
     111,    0,  728,    2, 0x08 /* Private */,
     112,    1,  729,    2, 0x08 /* Private */,
     112,    0,  732,    2, 0x28 /* Private | MethodCloned */,
     114,    1,  733,    2, 0x08 /* Private */,
     117,    1,  736,    2, 0x08 /* Private */,
     119,    1,  739,    2, 0x08 /* Private */,
     122,    0,  742,    2, 0x08 /* Private */,
     123,    1,  743,    2, 0x08 /* Private */,
     126,    1,  746,    2, 0x08 /* Private */,
     128,    3,  749,    2, 0x08 /* Private */,
     133,    2,  756,    2, 0x08 /* Private */,
     134,    0,  761,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   17,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 25,   23,   26,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 28, 0x80000000 | 30,   23,   29,   26,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 28,   23,   29,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 28, QMetaType::Bool,   23,   29,    2,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   14,   37,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   45,   46,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   14,   54,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::Bool,   54,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   76,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   81,   82,
    QMetaType::Void, 0x80000000 | 84, QMetaType::Bool,   85,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   90,
    QMetaType::Void, 0x80000000 | 66,   92,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,   92,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,   92,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,   92,
    QMetaType::Void, 0x80000000 | 66,   92,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  113,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 115,  116,
    QMetaType::Void, 0x80000000 | 118,    2,
    QMetaType::Void, 0x80000000 | 120,  121,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 124,  125,
    QMetaType::Void, 0x80000000 | 127,    2,
    QMetaType::Void, 0x80000000 | 129, QMetaType::Int, QMetaType::QString,  130,  131,  132,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dispatchCustomSettings((*reinterpret_cast< RichParameterSet(*)>(_a[1]))); break;
        case 1: _t->filterExecuted(); break;
        case 2: _t->updateLayerTable(); break;
        case 3: _t->newProject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->newProject(); break;
        case 5: _t->saveProject(); break;
        case 6: _t->meshAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->meshRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->importMeshWithLayerManagement((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->importMeshWithLayerManagement();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: _t->changeImportFileNames(); break;
        case 11: { bool _r = _t->importRaster((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->importRaster();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->openProject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->openProject();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->appendProject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->appendProject();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: _t->updateCustomSettings(); break;
        case 18: _t->updateLayerDialog(); break;
        case 19: { bool _r = _t->addRenderingDataIfNewlyGeneratedMesh((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[2]))); break;
        case 21: _t->updateRenderingDataAccordingToActionsToAllVisibleLayers((*reinterpret_cast< const QList<MLRenderingAction*>(*)>(_a[1]))); break;
        case 22: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< QList<MLRenderingAction*>(*)>(_a[3]))); break;
        case 23: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2]))); break;
        case 24: _t->updateRenderingDataAccordingToActionToAllVisibleLayers((*reinterpret_cast< MLRenderingAction*(*)>(_a[1]))); break;
        case 25: _t->updateRenderingDataAccordingToAction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MLRenderingAction*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 26: _t->updateRenderingDataAccordingToActions((*reinterpret_cast< QList<MLRenderingGlobalAction*>(*)>(_a[1]))); break;
        case 27: _t->documentUpdateRequested(); break;
        case 28: { bool _r = _t->importMesh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->importMesh((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: { bool _r = _t->importMesh();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->endEdit(); break;
        case 32: _t->updateDocumentScriptBindings(); break;
        case 33: _t->loadAndInsertXMLPlugin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 34: _t->postFilterExecution(); break;
        case 35: _t->updateProgressBar((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 36: _t->updateTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->closeCurrentDocument(); break;
        case 38: _t->reload(); break;
        case 39: _t->reloadAllMesh(); break;
        case 40: _t->openRecentMesh(); break;
        case 41: _t->openRecentProj(); break;
        case 42: { bool _r = _t->saveAs((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 43: { bool _r = _t->saveAs((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 44: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 45: { bool _r = _t->save((*reinterpret_cast< const bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 46: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 47: { bool _r = _t->saveSnapshot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 48: _t->changeFileExtension((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->applyEditMode(); break;
        case 50: _t->suspendEditMode(); break;
        case 51: _t->startFilter(); break;
        case 52: _t->applyLastFilter(); break;
        case 53: _t->runFilterScript(); break;
        case 54: _t->showFilterScript(); break;
        case 55: _t->showXMLPluginEditorGui(); break;
        case 56: _t->showTooltip((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 57: _t->applyRenderMode(); break;
        case 58: _t->applyDecorateMode(); break;
        case 59: _t->switchOffDecorator((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 60: _t->fullScreen(); break;
        case 61: _t->showToolbarFile(); break;
        case 62: _t->showInfoPane(); break;
        case 63: _t->showTrackBall(); break;
        case 64: _t->resetTrackBall(); break;
        case 65: _t->showLayerDlg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 66: _t->showRaster(); break;
        case 67: _t->updateWindowMenu(); break;
        case 68: _t->updateMenus(); break;
        case 69: _t->updateSubFiltersMenu((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 70: _t->updateMenuItems((*reinterpret_cast< QMenu*(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 71: _t->updateStdDialog(); break;
        case 72: _t->updateXMLStdDialog(); break;
        case 73: _t->enableDocumentSensibleActionsContainer((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 74: _t->setSplit((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 75: _t->setUnsplit(); break;
        case 76: _t->linkViewers(); break;
        case 77: _t->viewFrom((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 78: _t->toggleOrtho(); break;
        case 79: _t->trackballStep((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 80: _t->readViewFromFile(); break;
        case 81: _t->viewFromCurrentMeshShot(); break;
        case 82: _t->viewFromCurrentRasterShot(); break;
        case 83: _t->copyViewToClipBoard(); break;
        case 84: _t->pasteViewFromClipboard(); break;
        case 85: _t->splitFromHandle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 86: _t->unsplitFromHandle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 87: _t->setCustomize(); break;
        case 88: _t->about(); break;
        case 89: _t->aboutPlugins(); break;
        case 90: _t->helpOnline(); break;
        case 91: _t->helpOnscreen(); break;
        case 92: _t->submitBug(); break;
        case 93: _t->sendUsAMail(); break;
        case 94: _t->checkForUpdates((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 95: _t->checkForUpdates(); break;
        case 96: _t->dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 97: _t->dragEnterEvent((*reinterpret_cast< QDragEnterEvent*(*)>(_a[1]))); break;
        case 98: _t->connectionDone((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 99: _t->sendHistory(); break;
        case 100: _t->wrapSetActiveSubWindow((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 101: _t->switchCurrentContainer((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 102: _t->scriptCodeExecuted((*reinterpret_cast< const QScriptValue(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 103: _t->updateGPUMemBar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 104: _t->updateLog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingAction*> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLRenderingAction* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MLRenderingGlobalAction*> >(); break;
            }
            break;
        case 56:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 59:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 70:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMenu* >(); break;
            }
            break;
        case 74:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 77:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 79:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 85:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 86:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 100:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 101:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMdiSubWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(RichParameterSet & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::dispatchCustomSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::filterExecuted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::updateLayerTable)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "MainWindowInterface"))
        return static_cast< MainWindowInterface*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 105)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 105;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 105)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 105;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::dispatchCustomSettings(RichParameterSet & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::filterExecuted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::updateLayerTable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_FileOpenEater_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileOpenEater_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileOpenEater_t qt_meta_stringdata_FileOpenEater = {
    {
QT_MOC_LITERAL(0, 0, 13) // "FileOpenEater"

    },
    "FileOpenEater"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileOpenEater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void FileOpenEater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject FileOpenEater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileOpenEater.data,
      qt_meta_data_FileOpenEater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileOpenEater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileOpenEater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileOpenEater.stringdata0))
        return static_cast<void*>(const_cast< FileOpenEater*>(this));
    return QObject::qt_metacast(_clname);
}

int FileOpenEater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
