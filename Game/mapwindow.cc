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
    connect(&dialog,         SIGNAL(size(int, int)),   this,SLOT(initMap(int,int)));
    connect(&buildingdialog, SIGNAL(buildingType(std::string)),this,SLOT(selectBuilding(std::string)));
    dialog.exec();
    testPlayer=std::make_shared<Course::PlayerBase>("Player 1");
    enemyTestPlayer=std::make_shared<Course::PlayerBase>("Player 2");

    //TEST SOUND EFFECT
    testSoundPlayer=new QMediaPlayer();
    //testSoundPlayer->setMedia(QUrl("qrc:/sounds/sounds/testSound.mp3"));
    testPlayList = new QMediaPlaylist();
    testPlayList->addMedia(QUrl("qrc:/sounds/sounds/testSound.mp3"));
    testPlayList->addMedia(QUrl("qrc:/sounds/sounds/backgroundMusic.mp3"));
    testPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    testSoundPlayer->setPlaylist(testPlayList);

    testSoundPlayer->play();
   //IT WORKS

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

    std::shared_ptr<gameManager> gmanager =  std::make_shared<gameManager>(m_gamescene);


    setGEHandler(ghandler); //TEST
    setGManager(gmanager);

    makeWorldGenerator(x,y,10,ghandler,gmanager);
    Course::Coordinate offset=Course::Coordinate(x/2,y/2);

    for(auto it:m_GManager->returntilevector()){
        it->setCoordinate(it->getCoordinate()-offset); //tiles start counting from the middle, while they should start from
                                                       //the upper left corner... Thanks RITO
        drawItem(it);
    }

    // Nexus genesis
    m_GManager->spawnNexus(m_GEHandler, m_GManager, testPlayer, m_GManager->getTile(0));
}
void MapWindow::selectBuilding(std::string buildingType){ // TODO
    selectBuildingTypef(buildingType,m_GEHandler,m_GManager,testPlayer);
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
  m_GEHandler->handleMwindowClick(m_gamescene, m_GManager, *event);
  m_ui->graphicsView->viewport()->update();
}



void MapWindow::on_addButton_clicked()
{
    buildingdialog.show();



}


void MapWindow::on_minionbutton_clicked()
{
    qDebug()<<"spawn minion click";
    qDebug()<<" ";
    m_GManager->spawnMinion(m_GEHandler, m_GManager, testPlayer, m_GEHandler->getActiveTile());
    m_ui->graphicsView->viewport()->update();
}

void MapWindow::on_MusicButton_clicked()
{

    testSoundPlayer->setMuted(!testSoundPlayer->isMuted());
}

void MapWindow::on_enemyMinions_clicked()
{
    qDebug()<<" ";
    qDebug()<<"spawn enemy minion click";

m_GManager->spawnMinion(m_GEHandler, m_GManager, enemyTestPlayer, m_GEHandler->getActiveTile());
}
