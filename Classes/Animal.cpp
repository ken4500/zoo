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

Animal* Animal::CreateWithSpeceis(std::string specesName)
{
    Animal* animal = new(std::nothrow) Animal();
    if (animal && animal->initWithSpeceis(specesName))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;

}

bool Animal::initWithSpeceis(std::string specesName)
{
    if (!Node::init()) {
        return false;
    }
    
    _species = new Species(specesName);
    float rnd = CCRANDOM_0_1();
    float mm = (_species->getMaxHeight()->getMmLength() - _species->getMinHeight()->getMmLength()) * rnd + _species->getMinHeight()->getMmLength();
    _height = new Length(UnitOfLength::mm, mm);

    _rootNode = CSLoader::createNode(_species->getMoveCsbName());
    this->addChild(_rootNode);

    // load the character animation timeline
    _timeline = CSLoader::createTimeline(_species->getMoveCsbName());
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _image = _rootNode->getChildByName<Sprite*>("image");
    _changeAnimalImage();
    _zOrderUpdate = false;
    _isDead = false;
    deadCallback = NULL;
    
    setTag((int)MainSceneTag::Animal);
    setCascadeOpacityEnabled(true);

    
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

void Animal::jump(Vec2 target, float height, std::function<void ()> callback)
{
    _zOrderUpdate = false;
    float jumpInterval = ZUtil::calcDurationTime(_timeline, "drop");
    this->runAction(Sequence::create(
        JumpTo::create(1, target, height, 1),
        CallFunc::create([this]{
            runAction(_timeline),
            _timeline->play("drop", false);
        }),
        DelayTime::create(jumpInterval),
        CallFunc::create([this, callback]{
            startWalk();
            if (callback) {
                callback();
            }
            _zOrderUpdate = true;
        }),
        NULL
    ));
}

void Animal::movePoint(Vec2 targetPoint, float dt)
{
    Vec2 diff = targetPoint - getPosition();
    if (diff.length() > 10) {
        diff.normalize();
        Vec2 speed = 2 * diff * WorldManager::getInstance()->getDisplayLength(getSpeed());
        setPosition(getPosition() + speed * dt);
    }
}

void Animal::stopMove()
{
    this->stopAction(_moveAction);
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

bool Animal::getZOderUpdate()
{
    return _zOrderUpdate;
}

bool Animal::isEnemy()
{
    return _isEnemy;
}

void Animal::setIsEnmey(bool isEnemy)
{
    _isEnemy = isEnemy;
    if (isEnemy) {
        setTag((int)MainSceneTag::EnemyAnimal);
        _image->setColor(Color3B::RED);
    } else {
        setTag((int)MainSceneTag::EnemyAnimal);
        _image->setColor(Color3B::WHITE);
    }
}

bool Animal::isDead()
{
    return _isDead;
}

void Animal::setIsDead(bool isDead)
{
    if (isDead && _isDead ^ isDead && deadCallback) {
        deadCallback();
    }
    _isDead = isDead;
}

#pragma - private method


void Animal::startWalk()
{
    stopAllActions();
    runAction(_timeline);
    _timeline->play("walk", true);
    _moveNextPoint();
}

void Animal::_moveNextPoint()
{
    Vec2 targetP = WorldManager::getInstance()->getRadomPlace();
    Vec2 move = targetP - this->getPosition();
    float speed = WorldManager::getInstance()->getDisplayLength(getSpeed());
    if (_isEnemy) {
        speed /= 3;
    }
    float duration = move.length() / speed;
    if (move.x < 0) {
        _image->setFlippedX(false);
    } else {
        _image->setFlippedX(true);
    }
    _moveAction = this->runAction(Sequence::create(
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

