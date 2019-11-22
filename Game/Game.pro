TEMPLATE = app
TARGET = TheGame

QT += core gui widgets \
    multimedia

CONFIG += c++14

SOURCES += \
    AdvancedResourcses/AdvancedResourcses.cpp \
    attackable.cpp \
    buildings/custombuildingbase.cpp \
    buildings/test_building.cpp \
    dialogs/buildingdialog.cpp \
    buildings/nexus.cpp \
    functions/functions.cpp \
    graphics/mapitem.cpp \
    handlerandmanager/gameeventhandler.cpp \
    handlerandmanager/gamemanager.cpp \
    graphics/gamescene.cpp \
    leagueplayer.cpp \
    main.cpp \
    mapwindow.cc \
    meleechampion.cpp \
    minion/minion.cpp \
    dialogs/startdialog.cpp \
    minion/rangedchampion.cpp \
    turn.cpp \
    unit.cpp


HEADERS += \
    AdvancedResourcses/AdvancedResourceMaps.h \
    AdvancedResourcses/AdvancedResourcses.h \
    attackable.h \
    buildings/custombuildingbase.h \
    buildings/test_building.h \
    dialogs/buildingdialog.h \
    buildings/nexus.h \
    functions/functions.h \
    graphics/mapitem.h \
    handlerandmanager/gameeventhandler.h \
    handlerandmanager/gamemanager.h \
    graphics/gamescene.h \
    leagueplayer.h \
    mapwindow.hh \
    meleechampion.h \
    minion/minion.h \
    dialogs/startdialog.h \
    minion/rangedchampion.h \
    turn.h \
    unit.h

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    dialogs/buildingdialog.ui \
    mapwindow.ui \
    dialogs/startdialog.ui

DISTFILES += \
    ../../pi.png \
    graphics/forest_pic.png \
    graphics/pi.png

RESOURCES += \
    res.qrc
