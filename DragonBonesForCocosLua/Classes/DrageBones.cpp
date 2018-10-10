//
//  DrageBones.cpp
//  DBPros-mobile
//
//  Created by machs on 2018/9/28.
//

#include "DrageBones.h"
#include <string>

bool DrageBones::init()
{
    if(!Layer::init())
        return false;
    return true;
}
void DrageBones::SetDBFils(std::string dbbinName,std::string jsonName,std::string armatureName,std::string animationName)
{
    //const auto factory = dragonBones::CCFactory::getFactory();
    //factory->loadDragonBonesData(dbbinName);
    //factory->loadTextureAtlasData(jsonName);
    //const auto armatureDisplay = factory->buildArmatureDisplay(armatureName);
    //armatureDisplay->getAnimation()->play(animationName);
    //armatureDisplay->setPosition(0,0);
    //addChild(armatureDisplay);
	const auto factory = dragonBones::CCFactory::getFactory();
	//factory->loadDragonBonesData("mecha_1002_101d_show/mecha_1002_101d_show_ske.json");
	factory->loadDragonBonesData("mecha_1002_101d_show_ske.dbbin");
	factory->loadTextureAtlasData("mecha_1002_101d_show_tex.json");
	const auto armatureDisplay = factory->buildArmatureDisplay("mecha_1002_101d", "mecha_1002_101d_show");
	armatureDisplay->getAnimation()->play("idle");

	armatureDisplay->setPosition(0.0f, -200.0f);
	addChild(armatureDisplay);
}
