#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <map>
#include <memory>

#include "core/gameobject.h"

namespace Whiskas {

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     *
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     * @param width in tiles for the game map.
     * @param height in tiles for the game map.
     * @param scale is the size in pixels of a single square tile.
     */
    GameScene(QWidget* qt_parent = nullptr,
                    int width = 10,
                    int height = 10,
                    int scale = 50
            );

    /**
     * @brief Default destructor.
     */
    ~GameScene() = default;

    /**
     * @brief Sets the map size
     * @param width (number of tiles)
     * @param height (number of tiles)
     */
    void setSize(int width, int height);

    /**
     * @brief sets the size of individual tiles (=scale)
     * @param scale in pixels
     */
    void setScale(int scale);

    /**
     * @brief resize recalculates the bounding rectangle
     */
    void resize();

    /**
     * @brief draw a new item to the map.
     * @param obj shared ptr to the object
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief tries to remove drawn object at the location obj points to.
     * If there's multiple objects, will remove the one that matches obj.
     * @param obj shared ptr to the object being deleted
     *
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief updates the position of obj.
     * @param obj shared ptr to the obj being updated.
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief simple event handler that notifies when objects or the play
     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    virtual bool event(QEvent* event) override;

    /**
     * @brief return the ID of the last object clicked
     * @return object's ID
     */
    int getLastID();

    /**
     * @brief return the coordinate of the last region clicked
     * @return coordinate
     */
    std::shared_ptr<Course::Coordinate> getLastCoordinate();


private:
    QGraphicsItem* m_mapBoundRect;
    int m_width;
    int m_height;
    int m_scale;
    int lastObjectID=-1;
    std::shared_ptr<Course::Coordinate> lastCoordinate;
};

}

#endif // GAMESCENE_H
