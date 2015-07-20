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
    Species* species = new Species(specesName);
    if (animal && animal->initWithSpeceis(species))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;
}

Animal* Animal::CreateWithSpeceis(Species* species)
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


bool Animal::initWithSpeceis(Species* species)
{
    if (!Node::init()) {
        return false;
    }
    
    _species = species;
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
    _state = AnimalState::Unkown;
    deadCallback = NULL;
    _maxHp = mm;
    _hp = mm;
    _offense = mm / 2;
    
    setTag((int)MainSceneTag::Animal);
    setCascadeOpacityEnabled(true);

    
    return true;
}

void Animal::onEnter()
{
    Node::onEnter();
    updateWorldScale();
    scheduleUpdate();
}

void Animal::update(float dt)
{
    if (_state == AnimalState::Battle && _targetAnimal && _targetAnimal->isDead() == false) {
        bool kill = _targetAnimal->addDamage(_offense * dt);
        if (kill) {
            _targetAnimal->release();
            _targetAnimal = NULL;
            startWalk();
        }
    }
}

#pragma - publick method

void Animal::updateWorldScale()
{
    float scale = this->getWorldScale();
    this->setScale(scale);
}

void Animal::jump(Vec2 target, float height, std::function<void ()> callback)
{
    _state = AnimalState::Jump;
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
        Vec2 speed = diff * WorldManager::getInstance()->getDisplayLength(getDashSpeed());
        setPosition(getPosition() + speed * dt);
    }
}

void Animal::stopMove()
{
    this->stopAction(_moveAction);
}

void Animal::fight(Animal* animal)
{
    if (_state == AnimalState::Battle) {
        return;
    }

    _state = AnimalState::Battle;
    _targetAnimal = animal;
    _targetAnimal->retain();
    stopAllActions();
    runAction(_timeline);
    _timeline->play("battle", true);
    if (startFightCallback) {
        startFightCallback();
    }
}

void Animal::dead()
{
    if (_state != AnimalState::Dead) {
        _state = AnimalState::Dead;
        stopAllActions();
        runAction(FadeOut::create(1.0f));
        if (deadCallback) {
            deadCallback();
        }
    }
}

bool Animal::addDamage(float damage)
{
    if (_hp > 0 && _hp - damage <= 0) {
        _hp = 0;
        dead();
        return true;
    }
    _hp -= damage;
    return false;
}

void Animal::reborn()
{
    _hp = _maxHp;
    stopAllActions();
    runAction(_timeline);
    _timeline->play("reborn", false);
    _timeline->setLastFrameCallFunc([this]{
        startWalk();
    });
}

void Animal::startWalk()
{
    _state = AnimalState::Walk;
    stopAllActions();
    runAction(_timeline);
    _timeline->play("walk", true);
    _moveNextPoint();
}

#pragma - setter / getter

Length* Animal::getHeight()
{
    return _height;
}

Length* Animal::getSpeed()
{
    Length* speed = _species->getSpeed();
    if (_isEnemy) {
        speed->scale(0.3);
    }

    return speed;
}

Length* Animal::getDashSpeed()
{
    return _species->getDashSpeed();
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
        _image->setColor(Color3B(COLOR_RED));
    } else {
        setTag((int)MainSceneTag::EnemyAnimal);
        _image->setColor(Color3B::WHITE);
    }
}

bool Animal::isDead()
{
    return _state == AnimalState::Dead;
}

AnimalState Animal::getState()
{
    return _state;
}

Vec2 Animal::getCenterPosition()
{
    auto size = _image->getContentSize() * getScale();
    return this->getPosition() + Vec2(0, size.height / 2);
}


#pragma - private method

void Animal::_moveNextPoint()
{
    Vec2 targetP = WorldManager::getInstance()->getRadomPlace();
    Vec2 move = targetP - this->getPosition();
    float speed = WorldManager::getInstance()->getDisplayLength(getSpeed());
    if (speed == 0) {
        return;
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

