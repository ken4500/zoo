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
#include "CoinTree.h"
#include "SceneManager.h"

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
    setCascadeOpacityEnabled(true);

    this->setupTouchHandling();
}

void WorldMap::update(float dt)
{
    Node::update(dt);
    
    // 指定点まで移動
    auto children = getChildren();
    if (_targetPoint != Vec2::ZERO) {
        for(auto node : children) {
            int tag = node->getTag();
            if (tag != (int)EntityTag::Animal) {
                continue;
            }

            auto animal = dynamic_cast<Animal*>(node);
            if (animal
                && animal->getState() != AnimalState::Dead
                && animal->getState() != AnimalState::Battle)
            {
                animal->movePoint(_targetPoint, dt);
            }
        }
    }

    // Zオーダー更新
    for(auto node : children) {
        int tag = node->getTag();
        if (tag != (int)EntityTag::Animal
            && tag != (int)EntityTag::EnemyAnimal)
        {
            continue;
        }

        auto animal = dynamic_cast<Animal*>(node);
        if (animal) {
            if (animal->getState() != AnimalState::Jump) {
                node->setLocalZOrder(1000 - (int)node->getPosition().y);
            }
        }
    }

    auto manager = WorldManager::getInstance();
    auto state = manager->getSceneState();
    if (state == SceneState::Battle
        || state == SceneState::TutorialBattle
        || state == SceneState::MultiBattle)
    {
        auto animalList = manager->getAnimalList();
        auto enemyAnimalList = manager->getEnemyAnimalList();
        auto treeList = manager->getCoinTreeList();

        // 接近判定
        for (auto animal : animalList) {
            if (animal->isDead()) {
                continue;
            }
            
            auto rect1 = animal->getBodyRect();
            
            // 敵との接近判定
            for (auto enemy : enemyAnimalList) {
                if (enemy->isDead()) {
                    continue;
                }
                auto rect2 = enemy->getBodyRect();
                
                if(rect1.intersectsRect(rect2)) {
                    if (enemy->canAttack()) {
                        enemy->fight(animal);
                    }
                    if (animal->canAttack()) {
                        animal->fight(enemy);
                    }
                }
            }
            
            // コインツリーとの接近判定
            for (auto tree : treeList) {
                if (tree->isDead()) {
                    continue;
                }
                auto rect2 = tree->getBodyRect();
                
                if(rect1.intersectsRect(rect2)) {
                    if (animal->canAttack()) {
                        animal->fight(tree);
                    }
                }
            }
        }
        

        // バトル終了判定
        if (state == SceneState::Battle) {
            auto battleState = _checkBattleEnd();
            
            if (battleState == BattleState::Win) {
                WorldManager::getInstance()->endBattle(true);
            } else if (battleState == BattleState::Lose) {
                WorldManager::getInstance()->endBattle(false);
            }
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
        auto gacha = WorldManager::getInstance()->getGacha();
        if (gacha && state != SceneState::Battle) {
            auto image = gacha->getChildByName<Sprite*>("image");
            Rect targetBox = image->getBoundingBox();
            targetBox.origin = image->convertToWorldSpaceAR(targetBox.origin);
            Point location = touch->getLocationInView();
            auto touchLocation = Director::getInstance()->convertToGL(location);
            isTouchGacha = targetBox.containsPoint(touchLocation);
        }
     
        if (isTouchGacha) {
            WorldManager::getInstance()->lotteryGacha();
        } else if (WorldManager::getInstance()->enableNextAction()) {
            Vec2 touchPos = this->convertTouchToNodeSpace(touch);
            _targetPoint = touchPos;
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
                if (node->getTag() == (int)EntityTag::Animal) {
                    auto animal = dynamic_cast<Animal*>(node);
                    if (animal && animal->getState() == AnimalState::Dash) {
                        animal->startWalk();
                    }
                }
            }
            particle->removeFromParent();
        }
    };

    touchListener->onTouchCancelled = [&](Touch* touch, Event* event)
    {
        if (_targetPoint != Vec2::ZERO) {
            _targetPoint = Vec2::ZERO;
            auto children = getChildren();
            for(auto node : children) {
                if (node->getTag() == (int)EntityTag::Animal) {
                    auto animal = dynamic_cast<Animal*>(node);
                    if (animal && animal->getState() == AnimalState::Dash) {
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
    if (SceneManager::getInstance()->isNetwork()) {
        gacha->setOpacity(200);
        if (gacha->isOpponent()) {
            gacha->setLocalZOrder(_calcObjectZOrder(gacha));
        } else {
            gacha->setLocalZOrder(_calcObjectZOrder(gacha) - 1);
        }
    } else {
        gacha->setPosition(Vec2(0, 0));
        gacha->setLocalZOrder(_calcObjectZOrder(gacha));
    }
    addChild(gacha);
}

void WorldMap::setCoinTree(CoinTree* tree)
{
    tree->setLocalZOrder(_calcObjectZOrder(tree));
    addChild(tree);
    //tree->sprout();
}

void WorldMap::releaseAnimal(Animal* animal, std::function<void ()> callback)
{
    auto gacha = WorldManager::getInstance()->getGacha();
    float gachaHeight = gacha->getGachaHeight();
    animal->setPosition(gacha->getPosition() + Vec2(0, gachaHeight));
    animal->setLocalZOrder(2000);
    addChild(animal);
    Vec2 target;
    if (SceneManager::getInstance()->isNetwork()) {
        if (SceneManager::getInstance()->isHost()) {
            target = gacha->getPosition() + Vec2(-gachaHeight, -gachaHeight * 1.0f);
        } else {
            target = gacha->getPosition() + Vec2(gachaHeight, -gachaHeight * 1.0f);
        }
    } else {
        target = gacha->getPosition() + Vec2(rand_0_1() * gachaHeight * 2 - gachaHeight, -gachaHeight * 1.0f);
    }
    animal->jump(target, gachaHeight * 2, callback);
}

void WorldMap::releaseOpponentAnimal(Animal* animal, std::function<void ()> callback)
{
    auto gacha = WorldManager::getInstance()->getOpponentGacha();
    float gachaHeight = gacha->getGachaHeight();
    animal->setPosition(gacha->getPosition() + Vec2(0, gachaHeight));
    animal->setLocalZOrder(2000);
    addChild(animal);
    Vec2 target;
    if (SceneManager::getInstance()->isHost()) {
        target = gacha->getPosition() + Vec2(gachaHeight, -gachaHeight * 1.0f);
    } else {
        target = gacha->getPosition() + Vec2(-gachaHeight, -gachaHeight * 1.0f);
    }
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
    animal->setLocalZOrder(2000);
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
    animal->setLocalZOrder(2000);
    addChild(animal);
    animal->startWalk();
}

void WorldMap::hideGacha()
{
    auto gacha = WorldManager::getInstance()->getGacha();
    if (gacha) {
        gacha->runAction(FadeOut::create(0.5f));
    }
}

void WorldMap::showGacha()
{
    auto gacha = WorldManager::getInstance()->getGacha();
    if (gacha) {
        gacha->runAction(FadeIn::create(0.5f));
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

