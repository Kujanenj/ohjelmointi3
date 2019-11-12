#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/mapitem.h"
#include "functions/functions.h"
#include <math.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<gameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_gamescene(new GameScene(this))
{
    m_ui->setupUi(this);

    GameScene* sgs_rawptr =m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    startdialog dialog;
    connect(&dialog, SIGNAL(size(int, int)),this,SLOT(initMap(int,int)));

    dialog.exec();
    testPlayer=std::make_shared<Course::PlayerBase>("Player 1");


}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<gameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setGManager(std::shared_ptr<gameManager> manager)
{
    m_GManager=manager;
}


void MapWindow::setSize(int width, int height)
{
   m_gamescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_gamescene->setScale(scale);
}

void MapWindow::resize()
{
    m_gamescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->updateItem(obj);
}

void MapWindow::initMap(int x, int y)
{

    setSize(x,y);
    std::shared_ptr<gameEventHandler> ghandler =  std::make_shared<gameEventHandler>();

    std::shared_ptr<gameManager> gmanager =  std::make_shared<gameManager>();


    setGEHandler(ghandler); //TEST
    setGManager(gmanager);

    makeWorldGenerator(x,y,10,ghandler,gmanager);
    Course::Coordinate offset=Course::Coordinate(x/2,y/2);

    for(auto it:m_GManager->returntilevector()){
        it->setCoordinate(it->getCoordinate()-offset); //tiles start counting from the middle, while they should start from
                                                       //the upper left corner... Thanks RITO
        drawItem(it);
    }

}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->drawItem(obj);
}

void MapWindow::mousePressEvent(QMouseEvent *event){
  m_GEHandler->handleMwindowClick(m_gamescene, m_GManager);

}



void MapWindow::on_addButton_clicked()
{

    std::shared_ptr<Course::BuildingBase>  testFarm =  spawnBuilding(m_GEHandler, m_GManager, testPlayer);
    m_GEHandler->spawnBuilding(testFarm, m_GManager);





}


void MapWindow::on_minionbutton_clicked()
{
    qDebug()<<"spawn minion click";
    qDebug()<<"";
    m_GManager->spawnMinion(m_GEHandler, m_GManager, testPlayer, m_GEHandler->getActiveTile());
}
