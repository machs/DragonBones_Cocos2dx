//
//  DrageBones.hpp
//  DBPros-mobile
//
//  Created by machs on 2018/9/28.
//

#ifndef DrageBones_hpp
#define DrageBones_hpp
#include "cocos2d.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"
#include <string>
using namespace cocos2d;
/**
 * How to use
 * 1. Load data.
 *    factory.loadDragonBonesData();
 *    factory.loadTextureAtlasData();
 *
 * 2. Build armature.
 *    armatureDisplay = factory.buildArmatureDisplay("armatureName");
 *
 * 3. Play animation.
 *    armatureDisplay->getAnimation()->play("animationName");
 *
 * 4. Add armature to stage.
 *    addChild(armatureDisplay);
 */
class DrageBones : public Layer
{
    public:
    
	DrageBones();
	~DrageBones();
    
    bool init();
    void SetDBFils(std::string dbbinName,std::string jsonName,std::string armatureName,std::string dragonBonesName,std::string animationName);
};
#endif /* DrageBones_hpp */
