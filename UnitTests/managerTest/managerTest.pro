QT += testlib
QT += core gui widgets multimedia

TARGET = tst_testmanager
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14
TEMPLATE = app


HEADERS += \
    $$PWD/../../Game/AdvancedResourcses/AdvancedResourceMaps.h \
    $$PWD/../../Game/AdvancedResourcses/AdvancedResourcses.h \
    $$PWD/../../Game/minion/attackable.h \
    $$PWD/../../Game/buildings/AltarBase.h \
    $$PWD/../../Game/buildings/custombuildingbase.h \
    $$PWD/../../Game/buildings/lifepump.h \
    $$PWD/../../Game/buildings/quarry.h \
    $$PWD/../../Game/buildings/magealtar.h \
    $$PWD/../../Game/buildings/meleealtar.h \
    $$PWD/../../Game/buildings/rangedaltar.h \
    $$PWD/../../Game/buildings/sawmill.h \
    $$PWD/../../Game/buildings/nexus.h \
    $$PWD/../../Game/functions/functions.h \
    $$PWD/../../Game/graphics/mapitem.h \
    $$PWD/../../Game/handlerandmanager/gameeventhandler.h \
    $$PWD/../../Game/handlerandmanager/gamemanager.h \
    $$PWD/../../Game/graphics/gamescene.h \
    $$PWD/../../Game/leagueplayer.h \
    $$PWD/../../Game/minion/meleechampion.h \
    $$PWD/../../Game/minion/magicchampion.h \
    $$PWD/../../Game/minion/minion.h \
    $$PWD/../../Game/minion/rangedchampion.h \
    $$PWD/../../Game/tiles/desert.h \
    $$PWD/../../Game/tiles/jungle.h \
    $$PWD/../../Game/tiles/mountain.h \
    $$PWD/../../Game/tiles/spring.h \
    $$PWD/../../Game/turn.h \
    $$PWD/../../Game/minion/unit.h \
    $$PWD/../../Course/CourseLib/buildings/buildingbase.h \
    $$PWD/../../Course/CourseLib/buildings/farm.h \
    $$PWD/../../Course/CourseLib/buildings/headquarters.h \
    $$PWD/../../Course/CourseLib/buildings/outpost.h \
    $$PWD/../../Course/CourseLib/exceptions/baseexception.h \
    $$PWD/../../Course/CourseLib/exceptions/keyerror.h \
    $$PWD/../../Course/CourseLib/exceptions/ownerconflict.h \
    $$PWD/../../Course/CourseLib/exceptions/invalidpointer.h \
    $$PWD/../../Course/CourseLib/exceptions/illegalaction.h \
    $$PWD/../../Course/CourseLib/exceptions/notenoughspace.h \
    $$PWD/../../Course/CourseLib/graphics/simplemapitem.h \
    $$PWD/../../Course/CourseLib/graphics/simplegamescene.h \
    $$PWD/../../Course/CourseLib/interfaces/iobjectmanager.h \
    $$PWD/../../Course/CourseLib/interfaces/igameeventhandler.h \
    $$PWD/../../Course/CourseLib/tiles/grassland.h \
    $$PWD/../../Course/CourseLib/tiles/forest.h \
    $$PWD/../../Course/CourseLib/tiles/tilebase.h \
    $$PWD/../../Course/CourseLib/workers/basicworker.h \
    $$PWD/../../Course/CourseLib/workers/workerbase.h \
    $$PWD/../../Course/CourseLib/core/basicresources.h \
    $$PWD/../../Course/CourseLib/core/placeablegameobject.h \
    $$PWD/../../Course/CourseLib/core/worldgenerator.h \
    $$PWD/../../Course/CourseLib/core/coordinate.h \
    $$PWD/../../Course/CourseLib/core/playerbase.h \
    $$PWD/../../Course/CourseLib/core/gameobject.h \
    $$PWD/../../Course/CourseLib/core/resourcemaps.h


SOURCES +=  tst_testmanager.cpp \
    $$PWD/../../Game/AdvancedResourcses/AdvancedResourcses.cpp \
    $$PWD/../../Game/minion/attackable.cpp \
    $$PWD/../../Game/buildings/AltarBase.cpp \
    $$PWD/../../Game/buildings/custombuildingbase.cpp \
    $$PWD/../../Game/buildings/lifepump.cpp \
    $$PWD/../../Game/buildings/quarry.cpp \
    $$PWD/../../Game/buildings/magealtar.cpp \
    $$PWD/../../Game/buildings/meleealtar.cpp \
    $$PWD/../../Game/buildings/rangedaltar.cpp \
    $$PWD/../../Game/buildings/sawmill.cpp \
    $$PWD/../../Game/buildings/nexus.cpp \
    $$PWD/../../Game/functions/functions.cpp \
    $$PWD/../../Game/graphics/mapitem.cpp \
    $$PWD/../../Game/handlerandmanager/gameeventhandler.cpp \
    $$PWD/../../Game/handlerandmanager/gamemanager.cpp \
    $$PWD/../../Game/graphics/gamescene.cpp \
    $$PWD/../../Game/leagueplayer.cpp \
    $$PWD/../../Game/minion/meleechampion.cpp \
    $$PWD/../../Game/minion/magicchampion.cpp \
    $$PWD/../../Game/minion/minion.cpp \
    $$PWD/../../Game/minion/rangedchampion.cpp \
    $$PWD/../../Game/tiles/desert.cpp \
    $$PWD/../../Game/tiles/jungle.cpp \
    $$PWD/../../Game/tiles/mountain.cpp \
    $$PWD/../../Game/tiles/spring.cpp \
    $$PWD/../../Game/turn.cpp \
    $$PWD/../../Game/minion/unit.cpp \
    $$PWD/../../Course/CourseLib/buildings/buildingbase.cpp \
    $$PWD/../../Course/CourseLib/buildings/headquarters.cpp \
    $$PWD/../../Course/CourseLib/buildings/outpost.cpp \
    $$PWD/../../Course/CourseLib/buildings/farm.cpp \
    $$PWD/../../Course/CourseLib/tiles/grassland.cpp \
    $$PWD/../../Course/CourseLib/graphics/simplemapitem.cpp \
    $$PWD/../../Course/CourseLib/graphics/simplegamescene.cpp \
    $$PWD/../../Course/CourseLib/tiles/forest.cpp \
    $$PWD/../../Course/CourseLib/tiles/tilebase.cpp \
    $$PWD/../../Course/CourseLib/workers/basicworker.cpp \
    $$PWD/../../Course/CourseLib/workers/workerbase.cpp \
    $$PWD/../../Course/CourseLib/core/placeablegameobject.cpp \
    $$PWD/../../Course/CourseLib/core/worldgenerator.cpp \
    $$PWD/../../Course/CourseLib/core/coordinate.cpp \
    $$PWD/../../Course/CourseLib/core/playerbase.cpp \
    $$PWD/../../Course/CourseLib/core/gameobject.cpp \
    $$PWD/../../Course/CourseLib/core/basicresources.cpp


INCLUDEPATH += ../../Course/CourseLib/ \
../../Game/




