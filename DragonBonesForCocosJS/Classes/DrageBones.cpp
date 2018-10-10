//
//  DrageBones.cpp
//  DBPros-mobile
//
//  Created by machs on 2018/9/28.
//

#include "DrageBones.h"
#include <string>


DrageBones::DrageBones()
{

}
DrageBones::~DrageBones()
{

}


bool DrageBones::init()
{
    if(!Layer::init())
        return false;
    return true;
}

void DrageBones::SetDBFils(std::string dbbinName,std::string jsonName,std::string armatureName, std::string dragonBonesName,std::string animationName)
{
    const auto factory = new dragonBones::CCFactory();
    factory->loadDragonBonesData(dbbinName);
    factory->loadTextureAtlasData(jsonName);
	auto armatureDisplay = factory->buildArmatureDisplay(armatureName);
	if (dragonBonesName.size() != 0)
	{
		armatureDisplay = factory->buildArmatureDisplay(armatureName, dragonBonesName);
	}
	
    armatureDisplay->getAnimation()->play(animationName);
    armatureDisplay->setPosition(0,0);
    addChild(armatureDisplay);
}
