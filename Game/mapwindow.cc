#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/mapitem.h"
#include "functions/functions.h"
#include <QTimer>
#include "dialogs/enddialog.h"
#include <math.h>
std::map<std::string,std::string> BuildingDescriptions{
    {"Lifepump","A building that produces \n"
        "Life Water. Can be construted on \n"
        "a spring tile.\n"
        "Build cost:\n"
        "_____\n"
        "Produces\n"
        "_______"},
    {"Mage Altar","Transforms a minion\n"
        "into a mage, if a minion\n"
        "ends its turn on this building.\n"
        "Cost:"
        "______\n"
        "Has a cooldowwn of 20 turns\n"},
    {"Melee Altar", "Transforms a minion\n"
        "into a melee champion, if a \n"
        "minion ends its turn on this\n"
        "building.\n"
        "Cost:\n"
        "___\n"
        "Has a cooldown of 10 turns"},
    {"Ranged Altar", "Transforms a minion\n"
        "into a Ranged champion\n"
        " if a minion ends\n"
        " its turn on this"
        "building.\n"
        "Cost:\n"
        "___\n"
        "Has a cooldown of 15 turns"},
    {"Quarry", "quarry descript"},
    {"Sawmill","Saw descript"},
    {"Nexus", "Nexus"}
};
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
    connect(&dialog,         SIGNAL(rejected()),this,SLOT(closeWindow()));
    connect(&buildingdialog, SIGNAL(buildingType(std::string)),this,SLOT(selectBuilding(std::string)));


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
    generateLCDList();
    dialog.exec();






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





void MapWindow::initMap(int x, int y)
{

    setSize(x,y);
     std::shared_ptr<Whiskas::gameManager> gmanager =  std::make_shared<Whiskas::gameManager>(m_gamescene);

     std::shared_ptr<Whiskas::LeaguePlayer> firstPlayer = std::make_shared<Whiskas::LeaguePlayer>("Blue");
     std::shared_ptr<Whiskas::LeaguePlayer> secondPlayer = std::make_shared<Whiskas::LeaguePlayer>("Purple");
     qDebug()<<"start of game";
     firstPlayer->getItems();

     std::pair<std::shared_ptr<Whiskas::LeaguePlayer>,
             std::shared_ptr<Whiskas::LeaguePlayer>> playerPair(firstPlayer,secondPlayer);
     setGManager(gmanager);

     m_GManager->addPlayer(playerPair);
     std::shared_ptr<Whiskas::Turn> turn = std::make_shared<Whiskas::Turn>(gmanager);
    std::shared_ptr<Whiskas::gameEventHandler> ghandler =  std::make_shared<Whiskas::gameEventHandler>(turn);





    setGEHandler(ghandler); //TEST

    makeAdvancedWGenerator(x,m_GEHandler,m_GManager);

   // makeWorldGenerator(x,y,10,ghandler,gmanager);


    for(auto it:m_GManager->getTileVector()){

        drawItem(it);
    }
    m_GEHandler->setActiveTile(m_GManager->getTile(0));

    on_confirmButton_clicked();

    m_GEHandler->setActiveTile(m_GManager->getTile((x*x)-1));
    m_GEHandler->getTurn()->setInTurn(playerPair.second);
    on_confirmButton_clicked();
    on_endTurnButton_clicked();






}
void MapWindow::selectBuilding(std::string buildingType){
    buildingToBeBuilt_=buildingType;
    m_ui->DescriptionLabelRight->setText(QString::fromStdString(BuildingDescriptions.at(buildingType)));
    m_ui->confirmButton->setEnabled(true);

}

void MapWindow::closeWindow()
{
    QTimer::singleShot(0, this, SLOT(close()));
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
      m_ui->DescriptionLabel->setText(QString::fromStdString(m_GEHandler->getActiveMinion()->
                                                             getDescription(m_GEHandler->
                                                                            getActiveMinion()->
                                                                            getType())));
  }
  else if(m_GEHandler->getActiveTile()!=nullptr){
      qDebug()<<"DESCRIPTION LABEL ACTIVE TILL NOT NULL";
      qDebug()<<QString::fromStdString(m_GEHandler->getActiveTile()->
                                       getDescription(m_GEHandler->
                                                      getActiveTile()->
                                                      getType()));
      m_ui->DescriptionLabel->setText(QString::fromStdString(m_GEHandler->getActiveTile()->
                                                             getDescription(m_GEHandler->
                                                                            getActiveTile()->
                                                                            getType())));
      if(m_GEHandler->getActiveTile()->getBuildingCount()!=0){
          m_ui->DescriptionLabelRight->setText(QString::fromStdString(BuildingDescriptions.at(m_GEHandler->
                                                                                              getActiveTile()->
                                                                                              getBuildings().at(0)->
                                                                                              getType())));

      }
  }

  else{
      m_ui->DescriptionLabel->clear();
  }
  if(m_GManager->getWinner()!=nullptr){

      endDialog endLog;
      std::string endText{"Game over, "+m_GManager->getWinner()->getName()+
                  " has \n destroyed the enemy Nexus"};
      endLog.setEndText(endText);
      endLog.exec();
      closeWindow();
  }
}

void MapWindow::updateDisplays()
{
    int LCDNumber=0;
    for (auto const& item : m_GManager->getPlayerPair().first->getItems())
    {
        lcdDisplays_.at(LCDNumber)->display(item.second);
        ++LCDNumber;
    }
    for (auto const& item : m_GManager->getPlayerPair().second->getItems())
    {
        lcdDisplays_.at(LCDNumber)->display(item.second);
        ++LCDNumber;
    }

}

void MapWindow::generateLCDList()
{
   lcdDisplays_.push_back(m_ui->blueIronLCD);
   lcdDisplays_.push_back(m_ui->blueWoodLCD);
   lcdDisplays_.push_back(m_ui->blueCrystalLCD);
   lcdDisplays_.push_back(m_ui->blueLifeWaterLCD);
   lcdDisplays_.push_back(m_ui->purpleIronLCD);
   lcdDisplays_.push_back(m_ui->purpleWoodLCD);
   lcdDisplays_.push_back(m_ui->purpleCrystalLCD);
   lcdDisplays_.push_back(m_ui->purpleLifeWaterLCD);
}



void MapWindow::on_addButton_clicked()
{
    buildingdialog.show();



}


void MapWindow::on_minionbutton_clicked()
{
    qDebug()<<"spawn minion click";
    qDebug()<<" ";

    m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GEHandler->getTurn()->getInTurn(),
                            m_GEHandler->getActiveTile(), "minion");

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
    m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GEHandler->getTurn()->getInTurn(),
                            m_GEHandler->getActiveTile(),"Ranged");

    m_ui->graphicsView->viewport()->update();
}

void MapWindow::on_endTurnButton_clicked()
{
    m_GEHandler->endTurn(m_GManager, m_GEHandler);
    updateDisplays();
    m_ui->activePlayerLabel->setText(QString::fromStdString(m_GEHandler->getTurn()->
                                                            getInTurn()->getName()+
                                                            " is the player in turn"));
    m_ui->turnLCD->display(m_GEHandler->getTurn()->getTurnCounter());


}

void MapWindow::on_champButton_clicked()
{
     m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GEHandler->getTurn()->getInTurn(),
                             m_GEHandler->getActiveTile(), "champ");
}

void MapWindow::on_mageButton_clicked()
{
    m_GManager->spawnMinion(m_GEHandler, m_GManager, m_GEHandler->getTurn()->getInTurn(),
                            m_GEHandler->getActiveTile(), "mage");
}

void MapWindow::on_confirmButton_clicked()
{
    selectBuildingTypef(buildingToBeBuilt_,m_GEHandler,m_GManager,m_GEHandler->
                        getTurn()->getInTurn());
    m_ui->DescriptionLabelRight->clear();
    m_ui->confirmButton->setEnabled(false);
}
