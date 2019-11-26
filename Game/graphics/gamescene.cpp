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
    m_scale(80)
{
    setSize(width, height);
    setScale(scale);
}

void GameScene::setSize(int width, int height)
{
    if ( width >= SCENE_WIDTH_LIMITS.first && width <= SCENE_WIDTH_LIMITS.second )
    {
        m_width = width;
    }
    if ( height >= SCENE_HEIGHT_LIMITS.first && height <= SCENE_HEIGHT_LIMITS.second )
    {
        m_height = height;
    }
    resize();
}

void GameScene::setScale(int scale)
{
    if ( scale >= SCENE_SCALE_LIMITS.first && scale <= SCENE_SCALE_LIMITS.second )
    {
        m_scale = scale;
    }
    resize();
}

void GameScene::resize()
{
    if ( m_mapBoundRect != nullptr ){
        QGraphicsScene::removeItem(m_mapBoundRect);
    }

    // Calculates rect with middle at (0,0).
    // Basically left upper corner coords and then width and height
    /*QRect rect = QRect( m_width * m_scale / - 2, m_height * m_scale / -2,
                        m_width * m_scale - 1, m_height * m_scale - 1 );*/
    QRect rect = QRect( 0, 0, m_width * m_scale, m_height * m_scale);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);
    m_mapBoundRect = itemAt(rect.topLeft(), QTransform());
    // Draw on the bottom of all items
    m_mapBoundRect->setZValue(-1);
}

int GameScene::getScale() const
{
    return m_scale;
}

std::pair<int, int> GameScene::getSize() const
{
    return {m_width, m_height};
}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to update.";
    } else {
        for ( auto item : items_list ){
            Whiskas::SimpleMapItem* mapItem = static_cast<Whiskas::SimpleMapItem*>(item);
            if (mapItem->isSameObj(obj)){
                mapItem->updateLoc();
            }
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

            if ( pressed == m_mapBoundRect ){
                qDebug() << "Click on map area.";
            }else{
                lastObjectID=static_cast<Whiskas::SimpleMapItem*>(pressed)
                        ->getBoundObject()->ID;
                lastCoordinate = static_cast<Whiskas::SimpleMapItem*>(pressed)->getBoundObject()->getCoordinatePtr();
                qDebug() << "ObjID: inside scene" <<
                            lastObjectID;
                //qDebug() << "Coordinate X: " << lastCoordinate->x() << ", Y: " << lastCoordinate->y();


                return true;
            }

        }
    }
    /*lastObjectID=-1;*/

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
    qDebug()<<obj->getCoordinate().x()<<obj->getCoordinate().y();
    QList<QGraphicsItem*> items_list = items(obj->getCoordinate().asQpoint());
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to be removed at the location pointed by given obj.";
    } else {

        for (auto test :items()){
            qDebug()<<"super loop";
            Whiskas::SimpleMapItem* mapitem = static_cast<Whiskas::SimpleMapItem*>(test);
            if ( mapitem->isSameObj(obj) ){
                qDebug()<<"Foundstuff";
                qDebug()<<QString::fromStdString(mapitem->getBoundObject()->getType())
                       <<mapitem->getBoundObject()->ID;

                delete mapitem;
                break;
            }
        }

    }
}

void GameScene::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    Whiskas::SimpleMapItem* nItem = new Whiskas::SimpleMapItem(obj, m_scale);
    qDebug()<<"Added item"<<obj->ID<<QString::fromStdString(obj->getType())<<obj->getCoordinate().asQpoint();

    addItem(nItem);
}

}


