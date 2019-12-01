#include "mapwindow.hh"

#include <QApplication>

/*! \mainpage Documentation
 *
 * \section Overview
 * The bronze adventures game is a two player game. Players both control Nexuses, which the opposing player must destroy.
 * The players construct buildings using resources. The buildings can either produce more resources, or upgrade the players minions.
 * What are minions you i hear you ask? The minions are movable units that can fight the enemy minions, or destroy enemy buildings!
 *
 *
 *
 *
 * \section Instructions
 *  This section contains information on moving, building and attacking.
 * \subsection Moving
 *  To move a friendly minion, first select it with left click of your mouse. This will popup some text on the right side of the screen,
 * detaling the minion in question. Once you have selected a minion, simply right click on your mouse where you want to go!
 * The destination must be with in the minions move value, (Diagonal movement costs 2) and must not contain  minions or enemy buildings.
 * Otherwise the move command might fail, or you might attack the enemy!
 * \subsection Attacking
 * If you wish to attack an enemy minion or building, try to move on top of it. (Movement restrictions apply). If the requirements are met,
 * your unit will deal its attack damage to the opposing unit. Beware, some units have special attacks that can have negative effects for your
 * own units! Some units also take less damage from attacks. If a units health drops down to 0, it will be destroyed and removed from the game.
 * \subsection Building
 * To build a building, first select "Add building". This will open up a dialog to select the diffrent type of buildings. Select the one you wish to construct.
 * A text label will now appear on the right side of your screen. It will detail the cost, production and placement rules of the building. If you are satisfied
 * with your selection, left click on the tile you wish to place your building. Then select confirm build action button. Assuming you had the required
 * resources, and tile placement, the building will now be constructed. Take note however, that only 1 building can be placed on a given tile.
 * \subsection Altars
 * You may have noticed special buildings called Altars. These can be constructed with the same rules as normal buildings, but they have a speccial
 * action at the end of the turn. If a minion ends its turn under an altar, it will be upgraded to a champion. Melee champions are tanky,
 * ranged champions are fast, and magic champions have a special Area of effect attack. This upgrade costs no resources. Afther an upgrade,
 * the altar will go on cooldown for a set amount of turns. Afther the cooldown has expired, the altar can upgrade  another minion.
 * \subsection Winning
 * To win the game, simply destroy the enemy Nexus to instantly win the game, and be declared master of all bronze players! (So silver)
 *
 * \section Work distrubution
 * Safwaneb was in charge of all things graphical. All pictures, and drawing objects/tiles were his responsibility. Several buildings are also made by Safwaneb.
 * Jussi was in charge of the game mechanics. Moving and attacking and the minion, champions and altars were his desing.
 *
 *
 * \section Additonal content
 * * Moving
 * * Attacking
 * * Special Altar buildings
 * * Music (Currenlty only on Windows)
 */

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;
    mapWindow.show();
    return app.exec();
}
