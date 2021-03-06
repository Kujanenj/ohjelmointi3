#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/mapitem.h"
#include "functions/functions.h"
#include <QTimer>
#include <utility>
#include "dialogs/enddialog.h"
#include <cmath>
std::map<std::string,std::string> BuildingDescriptions{
    {"Lifepump","A building that produces \n"
        "LIFE WATER. Can be construted on \n"
        "a spring tile.\n"
        "Build cost:\n"
        "IRON 15\n"
        "WOOD 15\n"
        "LIFEWATER 5\n"
        "Produces\n"
        "LIFE WATER 1"},
    {"Mage Altar","Transforms a minion\n"
        "into a mage, if a minion\n"
        "ends its turn on this building.\n"
        "Can be constructed on\n"
        "Spring Tiles\n"
        "Cost:\n"
        "IRON 5\n"
        "WOOD 5\n"
        "CRYSTAL 15\n"
        "LIFEWATER 20\n"
        "Has a cooldowwn of 20 turns\n"},
    {"Melee Altar", "Transforms a minion\n"
        "into a melee champion, if a \n"
        "minion ends its turn on this\n"
        "building. Can be constructed\n"
        "on Desert and Mountan tiles\n"
        "Cost:\n"
        "IRON 15\n"
        "WOOD 5\n"
        "CRYSTAL 5\n"
        "LIFEWAWTER 5\n"
        "Has a cooldown of 10 turns"},
    {"Ranged Altar", "Transforms a minion\n"
        "into a Ranged champion\n"
        " if a minion ends\n"
        " its turn on this building.\n"
        "Can be constructed on \n"
        "Jungle Tiles\n"
        "Cost:\n"
        "IRON 5\n"
        "WOOD 20\n"
        "CRYSTAL 4\n"
        "LIFEWWATER 5\n"
        "Has a cooldown of 15 turns"},
    {"Quarry", "A mine that produces IRON\n"
        "and CRYSTAL. Can be constructed on\n"
        "Mountain tiles\n"
        "Cost:\n"
        "IRON 5\n"
        "WOOD 5\n"
        "CRYSTAL 2\n"
        "LIFEWATER 2\n"
        "\nProduction:\n"
        "IRON 1\n"
            },
    {"Sawmill","A sawmill that produces WOOD\n"
        "Can be constructed on \n"
        "Jungle tiles.\n"
        "Cost:\n"
        "IRON 5\n"
        "WOOD 5\n"
        "CRYSTAL 4\n"
        "LIFEWATER 4\n"
        "\n"
        "Production:\n"
        "WOOD 1\n"},
    {"Nexus", "The Nexus is your base.\n"
        "If it is destroyed, instantly lose\n"
        "the game. Nexus produces 1 resource\n"
        "each at the end of the turn.\n"
        "It also spawns a minion every 5 turns\n"
        "if no minion is on top of it. "}
};
MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Whiskas::gameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(std::move(handler)),
    m_gamescene(new Whiskas::GameScene(this))
{
    m_ui->setupUi(this);

    Whiskas::GameScene* sgs_rawptr =m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    startdialog dialog;
    connect(&dialog,         SIGNAL(size(int, int)),   this,SLOT(initMap(int,int)));
    connect(&dialog,         SIGNAL(rejected()),this,SLOT(closeWindow()));
    connect(&buildingdialog, SIGNAL(buildingType(std::string)),this,SLOT(selectBuilding(std::string)));

    m_ui->activePlayerLabel->setAlignment(Qt::AlignCenter);


    //IF YOU WISH TO ENABLE MUSIC:
    //REMOVE COMMENT MARKERS AND ENABLE MusicButton!!
    /*SoundPlayer=new QMediaPlayer();

    PlayList = new QMediaPlaylist();
    PlayList->addMedia(QUrl("qrc:/sounds/sounds/testSound.mp3"));
    PlayList->addMedia(QUrl("qrc:/sounds/sounds/backgroundMusic.mp3"));
    PlayList->setPlaybackMode(QMediaPlaylist::Loop);
    SoundPlayer->setPlaylist(PlayList);

    SoundPlayer->play();
    */
    m_ui->MusicButton->setEnabled(false);
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
    m_GEHandler = std::move(nHandler);
}

void MapWindow::setGManager(std::shared_ptr<Whiskas::gameManager> manager)
{
    m_GManager=std::move(manager);
}

void MapWindow::setSize(int width, int height)
{
    m_gamescene->setSize(width, height);
}

void MapWindow::initMap(int x, int y)
{

    setSize(x,y);

    std::shared_ptr<QTextBrowser> textBrowser(m_ui->textBrowser);
    std::shared_ptr<QTextBrowser> textBrowserRight(m_ui->textBrowserRight);

    std::shared_ptr<Whiskas::gameManager> gmanager =
            std::make_shared<Whiskas::gameManager>(m_gamescene, textBrowser);
    std::shared_ptr<Whiskas::LeaguePlayer> firstPlayer = std::make_shared<Whiskas::LeaguePlayer>("Blue");
    std::shared_ptr<Whiskas::LeaguePlayer> secondPlayer = std::make_shared<Whiskas::LeaguePlayer>("Purple");

    qDebug()<<"start of game";
    firstPlayer->getItems();

    std::pair<std::shared_ptr<Whiskas::LeaguePlayer>,
    std::shared_ptr<Whiskas::LeaguePlayer>> playerPair(firstPlayer,secondPlayer);
    setGManager(gmanager);

    m_GManager->addPlayer(playerPair);
    std::shared_ptr<Whiskas::Turn> turn = std::make_shared<Whiskas::Turn>(gmanager);
    std::shared_ptr<Whiskas::gameEventHandler> ghandler =
            std::make_shared<Whiskas::gameEventHandler>(turn, textBrowserRight);

    setGEHandler(ghandler);

    makeAdvancedWGenerator(x,m_GEHandler,m_GManager);




    for(const auto &it:m_GManager->getTileVector()){

        drawItem(it);
    }
    m_GEHandler->setActiveTile(m_GManager->getTile(0));

    on_confirmButton_clicked();

    m_GEHandler->setActiveTile(m_GManager->getTile((x*x)-1));
    m_GEHandler->getTurn()->setInTurn(playerPair.second);
    on_confirmButton_clicked();
    on_endTurnButton_clicked();
}

void MapWindow::selectBuilding(const std::string &buildingType){
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
    m_gamescene->drawItem(std::move(obj));
}

void MapWindow::mousePressEvent(QMouseEvent *event){
  m_GEHandler->handleMwindowClick(m_gamescene, m_GManager, *event);
  qDebug()<<"updating mwindow view";
  m_ui->graphicsView->viewport()->update();

  if(m_GEHandler->getActiveTile()!=nullptr) {
     updateDescriptions();
  } else {
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


void MapWindow::updateDescriptions()
{
    if(m_GEHandler->getActiveTile()->getWorkerCount() != 0){
        for(const auto& it: m_GManager->getMinionVector()){
            if(m_GEHandler->getActiveTile()->getWorkers().front()==it){
                m_ui->DescriptionLabel->setText(
                            QString::fromStdString(  it->getDescription(it->getType())  )
                            );
            }
        }
    } else {
        m_ui->DescriptionLabel->setText(QString::fromStdString(m_GEHandler->getActiveTile()->
                                                               getDescription(m_GEHandler->
                                                                              getActiveTile()->
                                                                              getType())));
    }
    if(m_GEHandler->getActiveTile()->getBuildingCount()!=0){
              m_ui->DescriptionLabelRight->setText(QString::fromStdString(BuildingDescriptions.at(m_GEHandler->
                                                                                                  getActiveTile()->
                                                                                                  getBuildings().at(0)->
                                                                                                  getType())));
    } else {
        m_ui->DescriptionLabelRight->clear();
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




void MapWindow::on_MusicButton_clicked()
{

    SoundPlayer->setMuted(!SoundPlayer->isMuted());
}



void MapWindow::on_endTurnButton_clicked()
{
    m_GEHandler->endTurn(m_GManager, m_GEHandler);
    updateDisplays();
    m_ui->activePlayerLabel->setText(QString::fromStdString(m_GEHandler->getTurn()->
                                                            getInTurn()->getName()+
                                                            " is playing"));
    if (m_GEHandler->getTurn()->getInTurn()->getName() == "Blue") {
        m_ui->activePlayerLabel->setStyleSheet("QLabel { background-color : #00adef; color : black;}");
    } else {
        m_ui->activePlayerLabel->setStyleSheet("QLabel { background-color : magenta; color : black;}");
}
    m_ui->turnLCD->display(m_GEHandler->getTurn()->getTurnCounter());


}




void MapWindow::on_confirmButton_clicked()
{
    selectBuildingTypef(buildingToBeBuilt_,m_GEHandler,m_GManager,m_GEHandler->
                        getTurn()->getInTurn());
    m_ui->DescriptionLabelRight->clear();
    m_ui->confirmButton->setEnabled(false);
    updateDisplays();
    m_ui->graphicsView->viewport()->update();
}
