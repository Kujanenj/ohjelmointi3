#include "mapitem.h"

#include <QDebug>

namespace Whiskas {

std::map<std::string, QColor> MapItem::c_mapcolors = {};
std::map<std::string, QImage> MapItem::c_mapicons = {};
std::map<std::string, std::map<std::string, QImage>> MapItem::c_objecticons = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    addNewColor(m_gameobject->getType());
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );


    if ( c_objecticons.find(m_gameobject->getType()) == c_objecticons.end() ) {
        QRectF source(0.0, 0.0, 500.0, 500.0);
        painter->drawImage(boundingRect(), c_mapicons.at(m_gameobject->getType()), source);
    } else {
        QRectF source(0.0, 0.0, 500.0, 500.0);
        painter->drawImage(boundingRect(),
                           c_objecticons.at(m_gameobject->getType()).at(m_gameobject->getOwner()->getName()), source);
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

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
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

void MapItem::addNewColor(std::string type)
{
    if ( c_mapicons.find(type) == c_mapicons.end()
         && c_objecticons.find(type) == c_objecticons.end() ){
        std::size_t hash = std::hash<std::string>{}(type);
        if (type == "Forest") {
            QImage forest_pic = QImage(":/images/graphics/pi.png");
            c_mapicons.insert({type, forest_pic});
        } else if (type == "Nexus") {
            QImage blue_nexus_pic = QImage(":/images/graphics/nexus_blue.png");
            QImage purple_nexus_pic = QImage(":/images/graphics/nexus_purple.png");

            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_nexus_pic},
                                                        {"Purple", purple_nexus_pic}};
            c_objecticons.insert({type, owner_pic_pair});
        } else if (type == "Minion") {
            QImage blue_minion_pic = QImage(":/images/graphics/minion_blue.png");
            QImage purple_minion_pic = QImage(":/images/graphics/minion_purple.png");

            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_minion_pic},
                                                        {"Purple", purple_minion_pic}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Quarry") {
            QImage blue_quarry_pic = QImage(":/images/graphics/quarry_blue.png");
            QImage purple_quarry_pic = QImage(":/images/graphics/quarry_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_quarry_pic},
                                                        {"Purple", purple_quarry_pic}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Lifepump") {
            QImage blue_lp_pic = QImage(":/images/graphics/lifepump_blue.png");
            QImage purple_lp_pic = QImage(":/images/graphics/lifepump_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_lp_pic},
                                                        {"Purple", purple_lp_pic}};
            c_objecticons.insert({type, owner_pic_pair});

        } else if (type == "Sawmill") {
            QImage blue_sawmill_pic = QImage(":/images/graphics/sawmill_blue.png");
            QImage purple_sawmill_pic = QImage(":/images/graphics/sawmill_purple.png");
            std::map<std::string, QImage> owner_pic_pair =  {{"Blue", blue_sawmill_pic},
                                                        {"Purple", purple_sawmill_pic}};
            c_objecticons.insert({type, owner_pic_pair});

        } /*else if (type == "MeleeChampion") {
            std::size_t hash = std::hash<std::string>{}(type);
            c_mapcolors.insert({type, QColor((hash & 0xFF0000) >> 16, (hash & 0x00FF00 ) >> 8, (hash & 0x0000FF))});
        }*/ else if (type == "Mountain") {
            QImage mountain_pic = QImage(":/images/graphics/mountain.png");
            c_mapicons.insert({type, mountain_pic});
        } else if (type == "Spring") {
            QImage spring_pic = QImage(":/images/graphics/spring.png");
            c_mapicons.insert({type, spring_pic});
        } else if (type == "Jungle") {
            QImage jungle_pic = QImage(":/images/graphics/jungle.png");
            c_mapicons.insert({type, jungle_pic});
        } else {
            QImage nexus_pic = QImage(":/images/graphics/nexus_blue.png");
            c_mapicons.insert({type, nexus_pic});
        }


    }
}

}
