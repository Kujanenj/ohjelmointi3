#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <map>
#include "startdialog.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "interfaces/iobjectmanager.h"
#include "buildings/farm.h"
#include "core/playerbase.h"

namespace Ui {
class MapWindow;
}


class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<gameEventHandler> GEHandler = {}

                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<gameEventHandler> nHandler);
    void setGManager(std::shared_ptr<gameManager> manager);

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    virtual void mousePressEvent(QMouseEvent *event );

    void addTestBuilding();


public slots:
    /*!
     * \brief initMap
     * Generates the world, accoring to the size of x,y. (ADD MORE PARATMETRES LATER ON?!=!=!!?!!?)
     *
     * \param x
     * \param y
     */
    void initMap(int x, int y);

private slots:
    void on_addButton_clicked();

private:

    Ui::MapWindow* m_ui;
    std::shared_ptr<gameEventHandler> m_GEHandler = nullptr;


    std::shared_ptr<gameManager> m_GManager =nullptr;
    std::shared_ptr<GameScene> m_gamescene = nullptr;
    std::shared_ptr<Course::PlayerBase> testPlayer =nullptr;
};

#endif // MapWINDOW_HH

