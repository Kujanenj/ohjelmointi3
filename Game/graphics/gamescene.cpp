#include "gamescene.h"
#include "graphics/mapitem.h"

#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <math.h>


namespace Whiskas {

GameScene::GameScene(QWidget* parent,
                                 int width,
                                 int height,
                                 int scale):
    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(10),
    m_height(10),
    m_scale(50)
{
    setSize(width, height);
    setScale(scale);
}

void GameScene::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    resize();
}

void GameScene::setScale(int scale)
{
    m_scale = scale;
    resize();
}

void GameScene::resize()
{
    if ( m_mapBoundRect != nullptr ){
        QGraphicsScene::removeItem(m_mapBoundRect);
    }
    QRect rect = QRect( 0, 0, m_width * m_scale, m_height * m_scale);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);
    m_mapBoundRect = itemAt(rect.topLeft(), QTransform());
    m_mapBoundRect->setZValue(-1);
}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    for ( auto item : items() ){
        Whiskas::MapItem* mapItem = static_cast<Whiskas::MapItem*>(item);
        if (mapItem->isSameObj(obj)){
            mapItem->updateLoc();
        }
    }
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / m_scale;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * m_scale, QTransform());

            if ( pressed != m_mapBoundRect ){
                lastObjectID=static_cast<Whiskas::MapItem*>(pressed)
                        ->getBoundObject()->ID;
                lastCoordinate = static_cast<Whiskas::MapItem*>(pressed)->getBoundObject()->getCoordinatePtr();
                return true;
            }

        }
    }
    return QGraphicsScene::event(event);
}

int GameScene::getLastID(){
    return lastObjectID;
}

std::shared_ptr<Course::Coordinate> GameScene::getLastCoordinate()
{
    return lastCoordinate;
}

void GameScene::removeItem(std::shared_ptr<Course::GameObject> obj)

{
    for ( auto item : items() ){
        Whiskas::MapItem* mapitem = static_cast<Whiskas::MapItem*>(item);
        if ( mapitem->isSameObj(obj) ){
            delete mapitem;
            break;
        }
    }
}

void GameScene::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    Whiskas::MapItem* nItem = new Whiskas::MapItem(obj, m_scale);
    addItem(nItem);
}

}
