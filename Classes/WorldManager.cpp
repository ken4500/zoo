//
//  WorldManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldManager.h"

USING_NS_CC;

static WorldManager* sharedWorldManager;
WorldManager* WorldManager::getInstance()
{
    if (!sharedWorldManager) {
        sharedWorldManager = new WorldManager();
    }

    return sharedWorldManager;
}

#pragma mark - Constructor and Destructor

WorldManager::WorldManager() :
_info(WorldInfo())
{
}

WorldManager::~WorldManager()
{
}


#pragma - public method

WorldInfo WorldManager::getWorldInfo()
{
    return _info;
}

float WorldManager::getImageScale(Sprite* image, Length heightLength)
{
    auto worldSize = getWorldInfo().getSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto contentSize = image->getContentSize();
    float scale = (heightLength.getLength(UnitOfLength::mm) * visibleSize.height) / (worldSize.getLength(UnitOfLength::mm) * contentSize.height);
    return scale;

}

float WorldManager::getDisplayLength(Length length)
{
    auto worldSize = getWorldInfo().getSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    return (length.getLength(UnitOfLength::mm) * visibleSize.height) / worldSize.getLength(UnitOfLength::mm);
}
