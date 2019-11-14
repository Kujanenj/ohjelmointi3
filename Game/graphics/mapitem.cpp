#include "mapitem.h"

#include <QDebug>

namespace Whiskas {

std::map<std::string, QColor> SimpleMapItem::c_mapcolors = {};
std::map<std::string, QImage> SimpleMapItem::c_mapicons = {};


SimpleMapItem::SimpleMapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    addNewColor(m_gameobject->getType());
}

QRectF SimpleMapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void SimpleMapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->setBrush(QBrush(c_mapcolors.at(m_gameobject->getType())));
    if ( m_gameobject->getType() == "Forest" ){
        QRectF source(0.0, 0.0, 500.0, 500.0);
        painter->drawImage(boundingRect(), c_mapicons.at(m_gameobject->getType()), source);
    } else {
    painter->drawRect(boundingRect()); }
}

const std::shared_ptr<Course::GameObject> &SimpleMapItem::getBoundObject()
{
    return m_gameobject;
}

void SimpleMapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool SimpleMapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}

int SimpleMapItem::getSize() const
{
    return m_size;
}

void SimpleMapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}

void SimpleMapItem::addNewColor(std::string type)
{
    if ( c_mapcolors.find(type) == c_mapcolors.end() ){
        std::size_t hash = std::hash<std::string>{}(type);
        c_mapcolors.insert({type, QColor((hash & 0xFF0000) >> 16, (hash & 0x00FF00 ) >> 8, (hash & 0x0000FF))});
        if (type == "Forest") {
            QImage forest_pic = QImage(":/graphics/pi.png");
            c_mapicons.insert({type, forest_pic});
        }

    }
}

}
