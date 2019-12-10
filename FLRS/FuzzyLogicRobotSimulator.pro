QT += core widgets
TEMPLATE = app
TARGET = FuzzyLogicRobotSimulator
VERSION_PE_HEADER = 1.0

#INCLUDEPATH += ../../../../Praca_dyplomowa/Informatyka_2019_20

# Temporary Include Path to Experimental Version of DataBase and Objects of DataBase
INCLUDEPATH += ../SharedCode

CFLAGS += -Wnoextra-semi-stmt

HEADERS += \
    ../SharedCode/DataBase/database.hpp \
    ../SharedCode/DataBase/databasecategory.hpp \
    ../SharedCode/DataBase/databasecategoryparameters.hpp \
    ../SharedCode/DataBase/databasecategorytype.hpp \
    ../SharedCode/DataBase/databaseobject.hpp \
    ../SharedCode/DataBase/databaseobjectparameters.hpp \
    ../SharedCode/DataBase/databaseobjectsreadfilecontainer.hpp \
    ../SharedCode/DataBase/databaseobjecttype.hpp \
    ../SharedCode/DataBase/databaseparams.hpp \
    ../SharedCode/DataBase/databasesearchengine.hpp \
    ../SharedCode/DataBase/databasesearchengineenums.hpp \
    ../SharedCode/DataBase/databasesearchenginefilter.hpp \
    ../SharedCode/DataBase/databasesearchenginefiltererror.hpp \
    ../SharedCode/DataBase/getparamrules.hpp \
    ../SharedCode/DataBase/setparamrules.hpp \
    ../SharedCode/DataBaseMenager/databasemenager.hpp \
    ../SharedCode/DataBaseMenager/databasemenagerparameters.hpp \
    ../SharedCode/DataBaseMenager/databasereader.hpp \
    ../SharedCode/DataBaseMenager/databasewriter.hpp \
    ../SharedCode/Dialog/dialog.hpp \
    ../SharedCode/Dialog/dialogquestion.hpp \
    ../SharedCode/Dialog/dialogresultenum.hpp \
    ../SharedCode/Dialog/dialogtypeenum.hpp \
    ../SharedCode/Dialog/dialogyesnoquestion.hpp \
    ../SharedCode/Enum/DataBaseFiles/databaseerror.hpp \
    ../SharedCode/Enum/DataBaseFiles/databasefileoperationstat.hpp \
    ../SharedCode/Enum/FilesMenegment/filereaderror.hpp \
    ../SharedCode/Enum/FilesMenegment/filereadingstat.hpp \
    ../SharedCode/Enum/UnderUseObject/underuseobjecttypes.hpp \
    ../SharedCode/ExpandButton/expandbutton.hpp \
    ../SharedCode/FileableObject/fileableobject.hpp \
    ../SharedCode/GeneralPurposeMacros/databasemenegmentmacros.hpp \
    ../SharedCode/GeneralPurposeMacros/filemenegmentmacros.hpp \
    ../SharedCode/GeneralPurposeMacros/layoutmacros.hpp \
    ../SharedCode/GeneralPurposeMacros/memorymenegementmacros.hpp \
    ../SharedCode/GeneralPurposeMacros/programcontrolmenegment.hpp \
    ../SharedCode/GeneralPurposeMacros/standardclassdefinitions.hpp \
    App/AppWindow/ComponentListPanel/componentlist.hpp \
    App/AppWindow/ComponentListPanel/componentlistelement.hpp \
    App/AppWindow/ComponentListPanel/componentlistelementlist.hpp \
    App/AppWindow/ComponentListPanel/componentlistpanel.hpp \
    App/AppWindow/MenuBar/menubar.hpp \
    App/AppWindow/SATListPanel/list.hpp \
    App/AppWindow/SATListPanel/listelement.hpp \
    App/AppWindow/SATListPanel/listelementlist.hpp \
    App/AppWindow/SATListPanel/listpanel.hpp \
    App/AppWindow/SimulationAreaTemplatePanel/Area/area.hpp \
    App/AppWindow/SimulationAreaTemplatePanel/Tools/tools.hpp \
    App/AppWindow/SimulationAreaTemplatePanel/templatepanel.hpp \
    App/AppWindow/ToolBar/toolbar.hpp \
    App/AppWindow/appwindow.hpp \
    App/AppWindow/appwindowlayoutmacros.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/Robot/robot.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/Robot/robotparams.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/elipse.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/elipseparams.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Ellipse/obstacleellipse.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Ellipse/obstacleellipseparam.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Rect/obstaclerect.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Rect/obstaclerectparam.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/obstacle.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/obstacleparam.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/obstacleshape.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Rect/rect.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Rect/rectparams.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/Rect/SARect.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/Rect/SARectParam.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/simarea.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/simareaparam.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/element.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/elementparams.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/elementtypes.hpp \
    App/FLRS_DB/SimulationAreaTemplate/EventChangeMode/eventcm.hpp \
    App/FLRS_DB/SimulationAreaTemplate/Mode/mode.hpp \
    App/FLRS_DB/SimulationAreaTemplate/satemplateparams.hpp \
    App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp \
    App/FLRS_DB/flrsdatabase.hpp \
    App/FLRS_DB/flrsdatabaseparameters.hpp \
    App/FLRS_DB/flrsdatabasetypes.hpp \
    App/app.hpp

SOURCES += \
    ../SharedCode/DataBase/database.cpp \
    ../SharedCode/DataBase/databasecategory.cpp \
    ../SharedCode/DataBase/databaseobject.cpp \
    ../SharedCode/DataBase/databaseobjectsreadfilecontainer.cpp \
    ../SharedCode/DataBase/databasesearchengine.cpp \
    ../SharedCode/DataBase/databasesearchenginefilter.cpp \
    ../SharedCode/DataBaseMenager/databasemenager.cpp \
    ../SharedCode/DataBaseMenager/databasereader.cpp \
    ../SharedCode/DataBaseMenager/databasewriter.cpp \
    ../SharedCode/Dialog/dialog.cpp \
    ../SharedCode/Dialog/dialogquestion.cpp \
    ../SharedCode/Dialog/dialogyesnoquestion.cpp \
    ../SharedCode/ExpandButton/expandbutton.cpp \
    ../SharedCode/FileableObject/fileableobject.cpp \
    App/AppWindow/ComponentListPanel/componentlist.cpp \
    App/AppWindow/ComponentListPanel/componentlistelement.cpp \
    App/AppWindow/ComponentListPanel/componentlistelementlist.cpp \
    App/AppWindow/ComponentListPanel/componentlistpanel.cpp \
    App/AppWindow/MenuBar/menubar.cpp \
    App/AppWindow/SATListPanel/list.cpp \
    App/AppWindow/SATListPanel/listelement.cpp \
    App/AppWindow/SATListPanel/listelementlist.cpp \
    App/AppWindow/SATListPanel/listpanel.cpp \
    App/AppWindow/SimulationAreaTemplatePanel/Area/area.cpp \
    App/AppWindow/SimulationAreaTemplatePanel/Tools/tools.cpp \
    App/AppWindow/SimulationAreaTemplatePanel/templatepanel.cpp \
    App/AppWindow/ToolBar/toolbar.cpp \
    App/AppWindow/appwindow.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/Robot/robot.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/elipse.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Ellipse/obstacleellipse.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Rect/obstaclerect.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/obstacle.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/Rect/rect.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/Rect/simarearect.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/simarea.cpp \
    App/FLRS_DB/SimulationAreaTemplate/Element/element.cpp \
    App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.cpp \
    App/FLRS_DB/flrsdatabase.cpp \
    App/app.cpp \
    main.cpp


