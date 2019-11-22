#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/mapitem.h"
#include "functions/functions.h"

#include <math.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Whiskas::gameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_gamescene(new Whiskas::GameScene(this))
{
    m_ui->setupUi(this);

    Whiskas::GameScene* sgs_rawptr =m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    startdialog dialog;
    connect(&dialog,         SIGNAL(size(int, int)),   this,SLOT(initMap(int,int)));
    connect(&buildingdialog, SIGNAL(buildingType(std::string)),this,SLOT(selectBuilding(std::string)));
    dialog.exec();


    //TEST SOUND EFFECT
    testSoundPlayer=new QMediaPlayer();
    //testSoundPlayer->setMedia(QUrl("qrc:/sounds/sounds/testSound.mp3"));
    testPlayList = new QMediaPlaylist();
    testPlayList->addMedia(QUrl("qrc:/sounds/sounds/testSound.mp3"));
    testPlayList->addMedia(QUrl("qrc:/sounds/sounds/backgroundMusic.mp3"));
    testPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    testSoundPlayer->setPlaylist(testPlayList);

   // testSoundPlayer->play();
   //IT WORKS

}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Whiskas::gameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setGManager(std::shared_ptr<Whiskas::gameManager> manager)
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
     std::shared_ptr<Whiskas::gameManager> gmanager =  std::make_shared<Whiskas::gameManager>(m_gamescene);

     std::shared_ptr<Whiskas::LeaguePlayer> firstPlayer = std::make_shared<Whiskas::LeaguePlayer>("player 1");
     std::shared_ptr<Whiskas::LeaguePlayer> secondPlayer = std::make_shared<Whiskas::LeaguePlayer>("player 2");
     qDebug()<<"start of game";
     firstPlayer->getItems();

     std::pair<std::shared_ptr<Whiskas::LeaguePlayer>,
             std::shared_ptr<Whiskas::LeaguePlayer>> playerPair(firstPlayer,secondPlayer);
     setGManager(gmanager);

     m_GManager->addPlayer(playerPair);
     std::shared_ptr<Whiskas::Turn> turn = std::make_shared<Whiskas::Turn>(gmanager);
    std::shared_ptr<Whiskas::gameEventHandler> ghandler =  std::make_shared<Whiskas::gameEventHandler>(turn);





    setGEHandler(ghandler); //TEST



    makeWorldGenerator(x,y,10,ghandler,gmanager);


    for(auto it:m_GManager->getTileVector()){

        drawItem(it);
    }


}
void MapWindow::selectBuilding(std::string buildingType){ // TODO
    selectBuildingTypef(buildingType,m_GEHandler,m_GManager,m_GManager->getPlayerPair().first);
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
  qDebug()<<"updating mwindow view";
  m_ui->graphicsView->viewport()->update();
  if(m_GEHandler->getActiveMinion()!=nullptr){
      m_ui->DescriptionLabel->setText(QString::fromStdString(m_GEHandler->getActiveMinion()->getDescription("minion")));
  }
  else{
      m_ui->DescriptionLabel->clear();
  }

}

void MapWindow::updateDisplays()
{
    //TODO;
}



void MapWindow::on_addButton_clicked()
{
    buildingdialog.show();



}


void MapWindow::on_minionbutton_clicked()
{
    qDebug()<<"spawn minion click";
    qDebug()<<" ";

    m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GManager->getPlayerPair().first, m_GEHandler->getActiveTile(), "minion");
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
    m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GManager->getPlayerPair().second, m_GEHandler->getActiveTile(),"minion");
    m_ui->graphicsView->viewport()->update();
}

void MapWindow::on_endTurnButton_clicked()
{
    m_GEHandler->endTurn(m_GManager, m_GEHandler);
}

void MapWindow::on_champButton_clicked()
{
     m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GManager->getPlayerPair().first, m_GEHandler->getActiveTile(), "champ");
}
