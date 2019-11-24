#ifndef AltarBase_H
#define AltarBase_H
#include "custombuildingbase.h"
namespace Whiskas {


class AltarBase :public CustomBuildingBase
{
public:
    explicit AltarBase(const std::shared_ptr<gameEventHandler>& eventhandler,
                       const std::shared_ptr<gameManager>& objectmanager,
                       const std::shared_ptr<Course::PlayerBase>& owner,
                       const int& tilespaces = 1,
                       const Course::ResourceMap& buildcost = {},
                       const AdvancedResourceMap production ={},
                       int health =5,
                       int attack = 0);
    virtual std::string getType()const override;
    virtual void upgradeMinion()=0;
    virtual void doSpecialAction() override;
protected:
    std::shared_ptr<gameManager>manager_;
    std::shared_ptr<gameEventHandler>handler_;
    std::shared_ptr<Course::PlayerBase>owner_;
};
}
#endif // AltarBase_H
