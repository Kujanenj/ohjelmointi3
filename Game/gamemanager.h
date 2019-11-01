#ifndef TESTTILEMANAGER_H
#define TESTTILEMANAGER_H
#include "interfaces/iobjectmanager.h"
#include "../Game/mapwindow.hh"
#include <vector>
using namespace Course;
class gameManager : public iObjectManager

{
public:
    gameManager();


    void addTiles(const std::vector<std::shared_ptr<TileBase> > &tiles) override;
    std::shared_ptr<TileBase> getTile(const ObjectId &id) override;

    std::shared_ptr<TileBase> getTile(const Coordinate &coordinate) override;

    std::vector<std::shared_ptr<TileBase> > getTiles(const std::vector<Coordinate> &coordinates) override;

    std::vector<std::shared_ptr<TileBase> > returntilevector();

private:
    std::vector<std::shared_ptr<TileBase> > alltiles_;
};

#endif // TESTTILEMANAGER_H
