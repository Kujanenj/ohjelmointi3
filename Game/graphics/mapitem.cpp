#include "mapitem.h"

#include <QDebug>
#include <utility>

namespace Whiskas {

std::map<std::string, QColor> MapItem::c_mapcolors = {};
std::map<std::string, QImage> MapItem::c_mapicons = {};
std::map<std::string, std::map<std::string, QImage>> MapItem::c_objecticons = {};

MapItem::MapItem(std::shared_ptr<Course::GameObject> obj, int size ):
    m_gameobject(std::move(obj)), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    addNewColor(m_gameobject->getType());
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ) Q_UNUSED( widget )


    if ( c_objecticons.find(m_gameobject->getType()) == c_objecticons.end() ) {
        QRectF source(0.0, 0.0, 50.0, 50.0);
        QImage image = c_mapicons.at(m_gameobject->getType())
                .scaled(50, 50, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        painter->drawImage(boundingRect(), image, source);
    } else {
        QRectF source(0.0, 0.0, 50.0, 50.0);
        QImage image = c_objecticons.at(m_gameobject->getType())
                .at(m_gameobject->getOwner()->getName())
                .scaled(50, 50, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        painter->drawImage(boundingRect(),
                           image, source);
    }

}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(const std::shared_ptr<Course::GameObject>& obj)
{
    return obj == m_gameobject;
}

int MapItem::getSize() const
{
    return m_size;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}

void MapItem::addNewColor(const std::string& type)
{
    if ( c_mapicons.find(type) == c_mapicons.end()
         && c_objecticons.find(type) == c_objecticons.end() ){

        if (type == "Desert") {
            QImage desert_pic = QImage(":/images/graphics/pi.png");
            c_mapicons.insert({type, desert_pic});
        } else if (type == "Nexus") {
            QImage blue_nexus = QImage(":/images/graphics/nexus_blue.png");
            QImage purple_nexus = QImage(":/images/graphics/nexus_purple.png");

            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_nexus},
                                                        {"Purple", purple_nexus}};
            c_objecticons.insert({type, owner_pic_pair});
        } else if (type == "Minion") {
            QImage blue_minion = QImage(":/images/graphics/minion_blue.png");
            QImage purple_minion = QImage(":/images/graphics/minion_purple.png");

            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_minion},
                                                        {"Purple", purple_minion}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Quarry") {
            QImage blue_quarry = QImage(":/images/graphics/quarry_blue.png");
            QImage purple_quarry = QImage(":/images/graphics/quarry_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_quarry},
                                                        {"Purple", purple_quarry}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Lifepump") {
            QImage blue_lifepump = QImage(":/images/graphics/lifepump_blue.png");
            QImage purple_lifepump = QImage(":/images/graphics/lifepump_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_lifepump},
                                                        {"Purple", purple_lifepump}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Sawmill") {
            QImage blue_sawmill = QImage(":/images/graphics/sawmill_blue.png");
            QImage purple_sawmill = QImage(":/images/graphics/sawmill_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_sawmill},
                                                        {"Purple", purple_sawmill}};
            c_objecticons.insert({type, owner_pic_pair});
        } else if (type == "Mountain") {
            QImage mountain = QImage(":/images/graphics/mountain.png");
            c_mapicons.insert({type, mountain});
        } else if (type == "Spring") {
            QImage spring = QImage(":/images/graphics/spring.png");
            c_mapicons.insert({type, spring});
        } else if (type == "Jungle") {
            QImage jungle = QImage(":/images/graphics/jungle.png");
            c_mapicons.insert({type, jungle});
        } else if (type == "Melee Altar") {
            QImage blue_altar = QImage(":/images/graphics/meleealtar_blue.png");
            QImage purple_altar = QImage(":/images/graphics/meleealtar_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_altar},
                                                        {"Purple", purple_altar}};
            c_objecticons.insert({type, owner_pic_pair});
        } else if (type == "Mage Altar") {
            QImage blue_altar = QImage(":/images/graphics/magealtar_blue.png");
            QImage purple_altar = QImage(":/images/graphics/magealtar_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_altar},
                                                        {"Purple", purple_altar}};
            c_objecticons.insert({type, owner_pic_pair});
        } else if (type == "Ranged Altar") {
            QImage blue_altar = QImage(":/images/graphics/rangedaltar_blue.png");
            QImage purple_altar = QImage(":/images/graphics/rangedaltar_purple_2.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_altar},
                                                        {"Purple", purple_altar}};
            c_objecticons.insert({type, owner_pic_pair});
        } else {
            QImage nexus_pic = QImage(":/images/graphics/nexus_blue.png");
            c_mapicons.insert({type, nexus_pic});
        }


    }
}

}
