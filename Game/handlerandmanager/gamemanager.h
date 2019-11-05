#ifndef TESTTILEMANAGER_H
#define TESTTILEMANAGER_H
#include "interfaces/iobjectmanager.h"

#include <vector>


class gameManager : public Course::iObjectManager

{
public:
    gameManager();


    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles) override;
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id) override;

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate) override;

    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates) override;

    std::vector<std::shared_ptr<Course::TileBase> > returntilevector();

private:
    std::vector<std::shared_ptr<Course::TileBase> > alltiles_;
};

#endif // TESTTILEMANAGER_H
