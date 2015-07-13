//
//  WorldMap.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#include "WorldMap.h"
#include "Gacha.h"
#include "Animal.h"

using namespace cocos2d;

#pragma - life cycle

bool WorldMap::init() {
    if (!Node::init()) {
        return false;
    }

    return true;
}


void WorldMap::onEnter()
{
    Node::onEnter();
    
    this->scheduleUpdate();
    
    auto mapObjects = getChildren();
    for (Node* object : mapObjects) {
        if (object->getName() != "background") {
            object->setLocalZOrder(_calcObjectZOrder(object));
        }
    }
    
    
}

void WorldMap::update(float dt)
{
    Node::update(dt);
    
    auto children = getChildren();
    for(auto node : children) {
        if (node->getTag() == (int)MainSceneTag::Animal) {
            node->setLocalZOrder(1000 - (int)node->getPosition().y);
        }
    }
}

#pragma - getter/setter


#pragma - public method

void WorldMap::setGacha(Gacha* gacha)
{
    _gacha = gacha;
    _gacha->finishGachaCallback = CC_CALLBACK_1(WorldMap::releaseAnimal, this);
    gacha->setPosition(Vec2(0, 0));
    gacha->setLocalZOrder(_calcObjectZOrder(gacha));
    addChild(gacha);
}

void WorldMap::releaseAnimal(Animal* animal)
{
    animal->setPosition(_gacha->getPosition() + Vec2(0, 400));
    addChild(animal);
    animal->jump(_gacha->getPosition() + Vec2(0, -100), 500);
}

#pragma - private method

int WorldMap::_calcObjectZOrder(Node* node)
{
    return 1000 - (int)node->getPosition().y;
}
