QT += testlib
QT += core gui widgets

TARGET = tst_testmanager
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES +=  tst_testmanager.cpp

INCLUDEPATH += \
 $$PWD/../../Course/CourseLib \
 $$PWD/../../Game/
DEPENDPATH  += \
    $$PWD/../../Course/CourseLib \
 $$PWD/../../Game/
