
#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QLCDNumber>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <map>
#include "dialogs/startdialog.h"
#include "dialogs/buildingdialog.h"

#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "interfaces/iobjectmanager.h"
#include "buildings/farm.h"
#include "core/playerbase.h"

#include "buildings/nexus.h"
#include "minion/minion.h"
#include "turn.h"

namespace Ui {
class MapWindow;
}

/**
 * @brief The MapWindow class Manages the UI interface
 */
class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Whiskas::gameEventHandler> GEHandler = {}

                       );
    ~MapWindow();
    /**
     * @brief setGEHandler sets the current Game Handler
     * @param nHandler the new game handler
     */
    void setGEHandler(std::shared_ptr<Whiskas::gameEventHandler> nHandler);
    /**
     * @brief setGManager sets the curretn game manager
     * @param manager the new game manager
     */
    void setGManager(std::shared_ptr<Whiskas::gameManager> manager);
    /**
     * @brief setSize sets the game size
     * @param width in tiles
     * @param height int tiles
     */
    void setSize(int width, int height);
    /**
     * @brief drawItem draws a new item to the map
     * @param obj to be drawn
     */

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief mousePressEvent calls event handler to manage the click
     * and updates the description labels
     * @param event the click event
     */

    virtual void mousePressEvent(QMouseEvent *event );
    /**
     * @brief openBuildingDialog opens a dialog to select the building to be
     * built
     * @param manager ObjectManager that recieves the building
     * @param handler buildings handler
     * @param owner player that owns the building
     */
    void openBuildingDialog(std::shared_ptr<Whiskas::gameManager> manager,
                            std::shared_ptr<Whiskas::gameEventHandler> handler,
                            std::shared_ptr<Course::PlayerBase> owner
                            );
    /**
     * @brief updateDisplays updates resource icons
     */
    void updateDisplays();
    /**
     * @brief generateLCDList makes a vector of the lcd widgets
     */
    void generateLCDList();


public slots:
    /*!
     * \brief initMap
     * Generates the world, accoring to the size of x,y
     * \param x
     * \param y
     */
    void initMap(int x, int y);
    /**
     * @brief selectBuilding updates the type of building to be built
     */
    void selectBuilding(const std::string &type);
    /**
     * @brief Closes the mainwidow
     */
    void closeWindow();

private slots:
    //REMOVE most of these
    void on_addButton_clicked();



    void on_minionbutton_clicked();
    //NOT THIS
    void on_MusicButton_clicked();


    void on_enemyMinions_clicked();

    void on_endTurnButton_clicked();

    void on_champButton_clicked();

    void on_mageButton_clicked();
    //NOT THis
    void on_confirmButton_clicked();

private:

    Ui::MapWindow* m_ui;
    std::shared_ptr<Whiskas::gameEventHandler> m_GEHandler = nullptr;


    std::shared_ptr<Whiskas::gameManager> m_GManager =nullptr;
    std::shared_ptr<Whiskas::GameScene> m_gamescene = nullptr;



    QMediaPlayer* testSoundPlayer; //TEST MEDIA PLAYER
    QMediaPlaylist* testPlayList; //test playlist
    buildingDialog buildingdialog;
    QList<QLCDNumber*> lcdDisplays_;
    std::string buildingToBeBuilt_="Nexus";

};

#endif // MapWINDOW_HH

