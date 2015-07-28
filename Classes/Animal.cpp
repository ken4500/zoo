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
    float rnd = CCRANDOM_0_1();
    float mm = (species->getMaxHeight()->getMmLength() - species->getMinHeight()->getMmLength()) * rnd + species->getMinHeight()->getMmLength();
    if (animal && animal->initWithSpeceis(species, mm))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;
}

Animal* Animal::CreateWithSpeceis(std::string specesName, float size)
{
    Animal* animal = new(std::nothrow) Animal();
    Species* species = new Species(specesName);
    if (animal && animal->initWithSpeceis(species, size))
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
    float rnd = CCRANDOM_0_1();
    float mm = (species->getMaxHeight()->getMmLength() - species->getMinHeight()->getMmLength()) * rnd + species->getMinHeight()->getMmLength();
    if (animal && animal->initWithSpeceis(species, mm))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;
}


bool Animal::initWithSpeceis(Species* species, float size)
{
    if (!Node::init()) {
        return false;
    }
    
    _species = species;
    _height = new Length(UnitOfLength::mm, size);

    _rootNode = CSLoader::createNode(_species->getMoveCsbName());
    this->addChild(_rootNode);

    // load the character animation timeline
    _timeline = CSLoader::createTimeline(_species->getMoveCsbName());
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _image = _rootNode->getChildByName<Sprite*>("image");
    _changeAnimalImage();
    _state = AnimalState::Stop;
    deadCallback = NULL;
    _maxHp = size;
    _hp = size;
    _offense = size / 3;
    _battleEffect = NULL;
    _timeLineAction = NULL;
    
    setTag((int)MainSceneTag::Animal);
    setCascadeOpacityEnabled(true);

    
    return true;
}

void Animal::onEnter()
{
    Node::onEnter();
    updateWorldScale();
    scheduleUpdate();
    _timeLineAction = runAction(_timeline);
}

void Animal::update(float dt)
{
    if (_state == AnimalState::Battle && _target) {
        if (_target->isDead()) {
            endFight();
        } else {
            bool kill = _target->addDamage(_offense * dt);
            if (kill) {
                endFight();
                if (killAnimalCallback) {
                    killAnimalCallback();
                }
            }
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
    if (_state == AnimalState::Dead) {
        return;
    }
    _state = AnimalState::Jump;
    float jumpInterval = ZUtil::calcDurationTime(_timeline, "drop");
    this->runAction(Sequence::create(
        JumpTo::create(1, target, height, 1),
        CallFunc::create([this]{
            _timeline->play("drop", false);
        }),
        DelayTime::create(jumpInterval),
        CallFunc::create([this, callback]{
            startWalk();
            if (callback) {
                callback();
            }
        }),
        NULL
    ));
}

void Animal::movePoint(Vec2 targetPoint, float dt)
{
    if (isDead()) {
        return;
    }
    
    if (_state != AnimalState::MoveTarget) {
        _state = AnimalState::MoveTarget;
        stopAllActions();
        _timeLineAction = runAction(_timeline);
        _timeline->play("dash", true);
    }

//    int errorX = rand_0_1() * 150 - 75;
//    int errorY = rand_0_1() * 150 - 75;
//    targetPoint += Vec2(errorX, errorY);

    auto parent = getParent();
    if (parent == NULL) {
        return;
    }
    Vec2 diff = targetPoint - getPosition();
    if (diff.length() > 30) {
        diff.normalize();
        Vec2 speed = diff * 200 / parent->getScale();
        setPosition(getPosition() + speed * dt);
    }
}

void Animal::fight(AbstractBattleEntity* entity)
{
    if (canAttack() == false) {
        return;
    }

    _state = AnimalState::Battle;
    _target = entity;
    _target->retain();
    stopAllActions();
    
    Vec2 originPoint = getPosition();
    Vec2 targetPoint = ZMath::divideInternally(getPosition(), entity->getPosition(), 1, 2);
        auto size = _image->getContentSize() * getScale();
    Vec2 effectPoint = ZMath::divideInternally(getPosition(), entity->getPosition(), 1, 1) + Vec2(0, size.height / 2);
    
    _moveAction = runAction(RepeatForever::create(Sequence::create(
        MoveTo::create(0.1f, targetPoint),
        CallFunc::create([this, effectPoint](){
            auto effect = ParticleSystemQuad::create("effect/hit3.plist");
            effect->setScale(getScale());
            effect->setPosition(effectPoint);
            effect->setZOrder(100000);
            auto parent = getParent();
            if (parent) {
                parent->addChild(effect);
            }
        }),
        MoveTo::create(0.3f, originPoint),
        DelayTime::create(0.5f),
        NULL
    )));
    
    if (startFightCallback) {
        startFightCallback();
    }
}

void Animal::dead()
{
    if (_state != AnimalState::Dead) {
        _state = AnimalState::Dead;
        if (_battleEffect) {
            _battleEffect->removeFromParent();
            _battleEffect = NULL;
        }
        stopAllActions();
        _timeLineAction = runAction(_timeline);
        _timeline->play("dead", false);
        _timeline->setLastFrameCallFunc([&]{
            if (deadCallback) {
                deadCallback();
            }
            _timeline->clearLastFrameCallFunc();
        });
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
    _state = AnimalState::Reborn;
    repairHp();
    stopAllActions();
    _timeLineAction = runAction(_timeline);
    setOpacity(255);
    _timeline->play("reborn", false);
    _timeline->setLastFrameCallFunc([this]{
        startWalk();
        _timeline->clearLastFrameCallFunc();
    });
}

void Animal::startFreeAction()
{
    int rnd = rand() % 2;
    switch (rnd) {
    case 0:
        startWalk();
        break;
    case 1:
        startStop();
    default:
        break;
    }
}

void Animal::startWalk()
{
    if (isDead()) {
        return;
    }

    if (_state != AnimalState::Walk) {
        _state = AnimalState::Walk;
        _timeline->play("walk", true);
    }
    
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
            startFreeAction();
        }),
        NULL
    ));
}

void Animal::startStop()
{
    if (isDead()) {
        return;
    }
    
    if (_state != AnimalState::Stop) {
        _state = AnimalState::Stop;
        _timeline->play("stop", true);
    }
    
    _moveAction = runAction(Sequence::create(
        DelayTime::create(1.5f),
        CallFunc::create([this]{
            startFreeAction();
        }),
        NULL
    ));
}

bool Animal::canAttack()
{
    if (_state == AnimalState::Battle
        || _state == AnimalState::Dead) {
        return false;
    }
    return true;
}

void Animal::repairHp()
{
    _hp = _maxHp;
}

void Animal::escape()
{
    _state = AnimalState::Escape;
    auto target = WorldManager::getInstance()->getOutRandomPlace();
    float delay = rand_0_1() * 0.5;
    runAction(Sequence::create(
        DelayTime::create(delay),
        JumpTo::create(0.5f, target, 100, 1),
        RemoveSelf::create(),
        NULL
    ));
}

void Animal::endFight()
{
    _target->release();
    _target = NULL;
    if (_battleEffect) {
        _battleEffect->removeFromParent();
        _battleEffect = NULL;
    }
    stopAction(_moveAction);
    stopAction(_timeLineAction);
    startWalk();
}

#pragma - setter / getter

Length* Animal::getHeight()
{
    return _height;
}

Length* Animal::getSpeed()
{
    Length* speed = _species->getSpeed();

    return speed;
}

Length* Animal::getDashSpeed()
{
    return WorldManager::getInstance()->getLength(100);
//    return _species->getDashSpeed();
}

std::string Animal::getName()
{
    return _species->getName();
}

float Animal::getWorldScale()
{
    float scale = WorldManager::getInstance()->getImageScale(_image, _height);
    return scale;
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

bool Animal::isFree()
{
    bool isFree = true;
    switch (_state) {
    case AnimalState::Battle:
    case AnimalState::MoveTarget:
    case AnimalState::Dead:
        isFree = false;
        break;
    default:
        break;
    }
    return isFree;
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

int Animal::getHash()
{
    std::string name = getName();
    uint8_t bytes_array[4 + name.size()];
    *((float *)bytes_array) = _height->getMmLength();
    for (int i = 0; i < name.size(); i++) {
        bytes_array[4 + i] = name[i];
    }
    
    return ZUtil::toHash32(bytes_array, 4 + name.size());
}

int Animal::getCoin()
{
    return MAX(1, (int)_height->getLength(UnitOfLength::cm));
}

Rect Animal::getBodyRect()
{
    auto imageRect = _image->getBoundingBox();
    imageRect.origin *= getScale();
    imageRect.origin += getPosition();
    imageRect.size = imageRect.size * getScale();
    return imageRect;
}

#pragma - private method

void Animal::_changeAnimalImage()
{
    _image->setTexture(_species->getImageName());
}

