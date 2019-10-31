#ifndef TEST_FEATURES_H
#define TEST_FEATURES_H

#include "core/gameobject.h"
#include "mapwindow.hh"
#include "tiles/forest.h"
#include "core/worldgenerator.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"
#include "testtilemanager.h"
#include "tiles/tilebase.h"
#include "uselesseventhandler.h"
using namespace Course;

 std::shared_ptr<Course::Forest> get_test_tile();
void make_test_wgenerator();






#endif // TEST_FEATURES_H

