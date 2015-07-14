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

void WorldMap::initSize(Length* maxWidth, Length* currentWidth)
{
    _maxWidth = maxWidth;
    _currentWidth = currentWidth;
    auto back = getChildByName<Sprite*>("background");
    Size size = Director::getInstance()->getVisibleSize();
    float scale = size.width * _maxWidth->getMmLength() / ( _currentWidth->getMmLength() * back->getContentSize().width);
    this->setScale(scale);
}

Length* WorldMap::getCurrentWidth()
{
    return _currentWidth;
}

Length* WorldMap::getMaxWidth()
{
    return _maxWidth;
}

void WorldMap::setCurrentWidth(Length* width)
{
    if (_maxWidth->getMmLength() < width->getMmLength()) {
        width = new Length(_maxWidth->getMmLength());
    }
    _currentWidth = width;
    auto back = getChildByName<Sprite*>("background");
    Size size = Director::getInstance()->getVisibleSize();
    auto hoge = back->getContentSize();
    float scale = size.width * _maxWidth->getMmLength() / ( _currentWidth->getMmLength() * back->getContentSize().width);
    runAction(EaseOut::create(ScaleTo::create(1.0f, scale), 2));
}


#pragma - public method

void WorldMap::setGacha(Gacha* gacha)
{
    _gacha = gacha;
    _gacha->finishGachaCallback = CC_CALLBACK_1(WorldMap::releaseAnimal, this);
    gacha->setPosition(Vec2(0, 0));
    gacha->setLocalZOrder(_calcObjectZOrder(gacha));
    gacha->setScale(1);
    addChild(gacha);
}

void WorldMap::releaseAnimal(Animal* animal)
{
    animal->setPosition(_gacha->getPosition() + Vec2(0, 400));
    addChild(animal);
    animal->jump(_gacha->getPosition() + Vec2(0, -100), 500);
    
    scaleupCallback(this);
}

bool WorldMap::isMaxScale()
{
    return _maxWidth->getLength() <= _currentWidth->getLength();
}


#pragma - private method

int WorldMap::_calcObjectZOrder(Node* node)
{
    return 1000 - (int)node->getPosition().y;
}
