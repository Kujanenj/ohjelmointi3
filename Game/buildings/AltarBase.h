#ifndef AltarBase_H
#define AltarBase_H
#include "custombuildingbase.h"
namespace Whiskas {

/**
 * @brief The AltarBase class is the inheritacne class for altar buildings.
 */
class AltarBase :public CustomBuildingBase
{
public:
    explicit AltarBase(const std::shared_ptr<gameEventHandler>& eventhandler,
                       const std::shared_ptr<gameManager>& objectmanager,
                       const std::shared_ptr<Course::PlayerBase>& owner,
                       const int& tilespaces = 1,
                       const AdvancedResourceMap& buildcost = {},
                       const AdvancedResourceMap& production ={},
                       int health =5,
                       int attack = 0);
     std::string getType()const override;
     /**
     * @brief upgradeMinion upgrades a minion on the tile when called.
     */
    virtual void upgradeMinion()=0;
     /**
      * @brief doSpecialAction calls upgrade minion, since all buildings have this method
      */
     void doSpecialAction() override;

protected:
    std::shared_ptr<gameManager>manager_;
    std::shared_ptr<gameEventHandler>handler_;
    std::shared_ptr<Course::PlayerBase>owner_;

};
}
#endif // AltarBase_H
