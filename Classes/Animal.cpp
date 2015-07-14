//
//  Animal.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Animal.h"
#include "WorldManager.h"

#pragma - Lifecycle

Animal::Animal()
{
}

Animal* Animal::CreateWithSpeceis(AbstractSpecies* species)
{
    Animal* animal = new(std::nothrow) Animal();
    if (animal && animal->initWithSpeceis(species))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;

}

bool Animal::initWithSpeceis(AbstractSpecies* species)
{
    if (!Node::init()) {
        return false;
    }
    
    _species = species;
    float rnd = CCRANDOM_0_1();
    float mm = (species->getMaxHeight()->getMmLength() - species->getMinHeight()->getMmLength()) * rnd + species->getMinHeight()->getMmLength();
    _height = new Length(UnitOfLength::mm, mm);

    _rootNode = CSLoader::createNode(_species->getMoveCsbName());
    this->addChild(_rootNode);

    // load the character animation timeline
    _timeline = CSLoader::createTimeline(species->getMoveCsbName());
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _image = _rootNode->getChildByName<Sprite*>("image");
    _changeAnimalImage();

    return true;
}

void Animal::onEnter()
{
    Node::onEnter();
    updateWorldScale();
}

#pragma - publick method

void Animal::updateWorldScale()
{
    float scale = this->getWorldScale();
    this->setScale(scale);
}

void Animal::jump(Vec2 target, float height)
{
    this->runAction(Sequence::create(
        JumpTo::create(1, target, height, 1),
        CallFunc::create([this]{
            runAction(_timeline);
            _timeline->play("drop", false);
            _startWalk();
        }),
        NULL
    ));
}

#pragma - setter / getter

Length* Animal::getHeight()
{
    return _height;
}

Length* Animal::getSpeed()
{
    return _species->getSpeed();
}

std::string Animal::getName()
{
    return _name;
}


float Animal::getWorldScale()
{
    float scale = WorldManager::getInstance()->getImageScale(_image, _height);
    return scale;
}

#pragma - private method


void Animal::_startWalk()
{
    this->runAction(_timeline);
    _timeline->play("walk", true);
    _moveNextPoint();
}

void Animal::_moveNextPoint()
{
    Vec2 targetP = ZUtil::getRadomPlace();
    Vec2 move = targetP - this->getPosition();
    float speed = WorldManager::getInstance()->getDisplayLength(getSpeed());
    float duration = move.length() / speed;
    if (move.x < 0) {
        _image->setFlippedX(false);
    } else {
        _image->setFlippedX(true);
    }
    this->runAction(Sequence::create(
        MoveBy::create(duration, move),
        CallFunc::create([this](){
            _moveNextPoint();
        }),
        NULL
    ));
}

void Animal::_changeAnimalImage()
{
    _image->setTexture(_species->getImageName());
}

