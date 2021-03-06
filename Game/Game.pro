TEMPLATE = app
TARGET = TheGame

QT += core gui widgets \
    multimedia

CONFIG += c++14

SOURCES += \
    AdvancedResourcses/AdvancedResourcses.cpp \
    minion/attackable.cpp \
    buildings/AltarBase.cpp \
    buildings/custombuildingbase.cpp \
    buildings/lifepump.cpp \
    buildings/quarry.cpp \
    buildings/magealtar.cpp \
    buildings/meleealtar.cpp \
    buildings/rangedaltar.cpp \
    buildings/sawmill.cpp \
    dialogs/buildingdialog.cpp \
    buildings/nexus.cpp \
    dialogs/enddialog.cpp \
    dialogs/sizedialog.cpp \
    functions/functions.cpp \
    graphics/mapitem.cpp \
    handlerandmanager/gameeventhandler.cpp \
    handlerandmanager/gamemanager.cpp \
    graphics/gamescene.cpp \
    leagueplayer.cpp \
    main.cpp \
    mapwindow.cc \
    minion/meleechampion.cpp \
    minion/magicchampion.cpp \
    minion/minion.cpp \
    dialogs/startdialog.cpp \
    minion/rangedchampion.cpp \
    tiles/desert.cpp \
    tiles/jungle.cpp \
    tiles/mountain.cpp \
    tiles/spring.cpp \
    turn.cpp \
    minion/unit.cpp


HEADERS += \
    AdvancedResourcses/AdvancedResourceMaps.h \
    AdvancedResourcses/AdvancedResourcses.h \
    minion/attackable.h \
    buildings/AltarBase.h \
    buildings/custombuildingbase.h \
    buildings/lifepump.h \
    buildings/quarry.h \
    buildings/magealtar.h \
    buildings/meleealtar.h \
    buildings/rangedaltar.h \
    buildings/sawmill.h \
    dialogs/buildingdialog.h \
    buildings/nexus.h \
    dialogs/enddialog.h \
    dialogs/sizedialog.h \
    functions/functions.h \
    graphics/mapitem.h \
    handlerandmanager/gameeventhandler.h \
    handlerandmanager/gamemanager.h \
    graphics/gamescene.h \
    leagueplayer.h \
    mapwindow.hh \
    minion/meleechampion.h \
    minion/magicchampion.h \
    minion/minion.h \
    dialogs/startdialog.h \
    minion/rangedchampion.h \
    tiles/desert.h \
    tiles/jungle.h \
    tiles/mountain.h \
    tiles/spring.h \
    turn.h \
    minion/unit.h

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
    dialogs/enddialog.ui \
    dialogs/sizedialog.ui \
    mapwindow.ui \
    dialogs/startdialog.ui



RESOURCES += \
    res.qrc
