TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    functions/functions.cpp \
    graphics/mapitem.cpp \
    handlerandmanager/gameeventhandler.cpp \
    handlerandmanager/gamemanager.cpp \
    gamescene.cpp \
    main.cpp \
    mapwindow.cc \
    minion/minion.cpp \
    startdialog.cpp


HEADERS += \
    functions/functions.h \
    graphics/mapitem.h \
    handlerandmanager/gameeventhandler.h \
    handlerandmanager/gamemanager.h \
    gamescene.h \
    mapwindow.hh \
    minion/minion.h \
    startdialog.h

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
    mapwindow.ui \
    startdialog.ui

DISTFILES += \
    graphics/forest_pic.png

RESOURCES += \
    test.qrc
