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
    
    _targetPoint = Vec2::ZERO;

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

    this->setupTouchHandling();
}

void WorldMap::update(float dt)
{
    Node::update(dt);
    
    auto children = getChildren();
    for(auto node : children) {
        if (node->getTag() == (int)MainSceneTag::Animal) {
            auto animal = dynamic_cast<Animal*>(node);
            if (animal) {
                if (animal->getZOderUpdate()) {
                    node->setLocalZOrder(1000 - (int)node->getPosition().y);
                }
                float distance = (animal->getPosition() - _targetPoint).length();
                distance *= getScale();
                if (_targetPoint != Vec2::ZERO && distance < 300) {
                    animal->movePoint(_targetPoint, dt);
                }
            }
        }
    }
    
    auto manager = WorldManager::getInstance();
    auto state = manager->getSceneState();
    if (state == SceneState::Battle
        || state == SceneState::TutorialBattle) {
        auto animalList = manager->getAnimalList();
        auto enemyAnimalList = manager->getEnemyAnimalList();

        // 接近判定
        for (auto enemy : enemyAnimalList) {
            if (enemy->isDead()) {
                continue;
            }
            for (auto animal : animalList) {
                if (animal->isDead()) {
                    continue;
                }
                float displayDistanse = enemy->getCenterPosition().distance(animal->getCenterPosition()) * getScale();
                auto distance = Length::createWithDisplayLength(displayDistanse);
                float r1 = animal->getHeight()->getMmLength() / 3;
                float r2 = enemy->getHeight()->getMmLength() / 3;
                if (distance->getMmLength() < r1 + r2) {
                    enemy->fight(animal);
                    animal->fight(enemy);
                }
            }
        }

        // バトル終了判定
        auto battleState = _checkBattleEnd();
        if (battleState == BattleState::Win) {
            WorldManager::getInstance()->winBattle();
        } else if (battleState == BattleState::Lose) {
            WorldManager::getInstance()->loseBattle();
        }
    }
}

void WorldMap::setupTouchHandling()
{
    static ParticleSystemQuad* particle = nullptr;
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        bool isTouchGacha = false;
        auto state = WorldManager::getInstance()->getSceneState();
        if (_gacha && state != SceneState::Battle) {
            auto image = _gacha->getChildByName<Sprite*>("image");
            Rect targetBox = image->getBoundingBox();
            targetBox.origin = image->convertToWorldSpaceAR(targetBox.origin);
            Point location = touch->getLocationInView();
            auto touchLocation = Director::getInstance()->convertToGL(location);
            isTouchGacha = targetBox.containsPoint(touchLocation);
        }
     
        if (isTouchGacha) {
            WorldManager::getInstance()->lotteryGacha();
        } else {
            Vec2 touchPos = this->convertTouchToNodeSpace(touch);
            _targetPoint = touchPos;
            auto children = getChildren();
            for(auto node : children) {
                if (node->getTag() == (int)MainSceneTag::Animal) {
                    auto animal = dynamic_cast<Animal*>(node);
                    if (animal && animal->getZOderUpdate()) {
                        animal->stopMove();
                    }
                }
            }
            particle = ParticleSystemQuad::create("effect/particle_circle.plist");
            particle->setScale(1 / this->getScale());
            particle->setPosition(touchPos);
            addChild(particle);
        }
        
        return true;
    };

    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        if (_targetPoint != Vec2::ZERO) {
            Vec2 touchPos = this->convertTouchToNodeSpace(touch);
            _targetPoint = touchPos;
            particle->setPosition(touchPos);
        }
    };


    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        if (_targetPoint != Vec2::ZERO) {
            _targetPoint = Vec2::ZERO;
            auto children = getChildren();
            for(auto node : children) {
                if (node->getTag() == (int)MainSceneTag::Animal) {
                    auto animal = dynamic_cast<Animal*>(node);
                    if (animal && animal->getZOderUpdate()) {
                        animal->startWalk();
                    }
                }
            }
            particle->removeFromParent();
        }
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

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

void WorldMap::setCurrentWidth(Length* width, std::function<void ()> callback)
{
    _currentWidth = width;
    auto back = getChildByName<Sprite*>("background");
    Size size = Director::getInstance()->getVisibleSize();
    auto hoge = back->getContentSize();
    float scale = size.width * _maxWidth->getMmLength() / ( _currentWidth->getMmLength() * back->getContentSize().width);
    if (callback) {
        runAction(Sequence::create(
            EaseIn::create(ScaleTo::create(1.0f, scale), 2),
            CallFunc::create(callback),
            NULL
        ));
    } else {
        runAction(EaseIn::create(ScaleTo::create(1.0f, scale), 2));
    }
}


#pragma - public method

void WorldMap::setGacha(Gacha* gacha)
{
    _gacha = gacha;
    gacha->setPosition(Vec2(0, 0));
    gacha->setLocalZOrder(_calcObjectZOrder(gacha));
    addChild(gacha);
}

Gacha* WorldMap::getGacha()
{
    return _gacha;
}

void WorldMap::releaseAnimal(Animal* animal, std::function<void ()> callback)
{
    float gachaHeight = _gacha->getGachaHeight();
    animal->setPosition(_gacha->getPosition() + Vec2(0, gachaHeight));
    animal->setLocalZOrder(1000);
    addChild(animal);
    auto target = _gacha->getPosition() + Vec2(rand_0_1() * gachaHeight * 2 - gachaHeight, -gachaHeight * 1.0f);
    animal->jump(target, gachaHeight * 2, callback);
}

bool WorldMap::isMaxScale()
{
    return _maxWidth->getLength() <= _currentWidth->getLength();
}

void WorldMap::addAnimalAtRandomPoint(Animal* animal)
{
    Vec2 randomPoint = WorldManager::getInstance()->getRadomPlace();
    this->addAnimal(animal, randomPoint);
}

void WorldMap::addAnimal(Animal* animal, Vec2 targetPoint)
{
    animal->setPosition(targetPoint);
    animal->setLocalZOrder(1000);
    addChild(animal);
    animal->startWalk();
}

void WorldMap::addEnemyAnimalAtOutRandomPoint(Animal* animal)
{
    Vec2 randomPoint = WorldManager::getInstance()->getOutRandomPlace();
    this->addEnemyAnimal(animal, randomPoint);
}

void WorldMap::addEnemyAnimal(Animal* animal, Vec2 targetPoint)
{
    animal->setPosition(targetPoint);
    animal->setLocalZOrder(1000);
    addChild(animal);
    animal->startWalk();
}

void WorldMap::hideGacha()
{
    if (_gacha) {
        _gacha->runAction(FadeOut::create(0.5f));
    }
}

void WorldMap::showGacha()
{
    if (_gacha) {
        _gacha->runAction(FadeIn::create(0.5f));
    }
}

#pragma - private method

int WorldMap::_calcObjectZOrder(Node* node)
{
    return 1000 - (int)node->getPosition().y;
}

BattleState WorldMap::_checkBattleEnd()
{
        auto animalList      = WorldManager::getInstance()->getAnimalList();
        auto enemyAnimalList = WorldManager::getInstance()->getEnemyAnimalList();
        bool allEnemyIsDead = true;
        for (auto enemy : enemyAnimalList) {
            if (enemy->isDead() == false) {
                allEnemyIsDead = false;
                break;
            }
        }
        if (allEnemyIsDead) {
            return BattleState::Win;
        }
    
    
        bool allAnimalIsDead = true;
        for (auto animal : animalList) {
            if (animal->isDead() == false) {
                allAnimalIsDead = false;
                break;
            }
        }
        if (allAnimalIsDead) {
            return BattleState::Lose;
        }
    
        return BattleState::Battle;
}

