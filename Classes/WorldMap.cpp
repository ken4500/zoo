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

WorldMap::WorldMap() :
_maxWidth(0),
_currentWidth(0)
{
}

WorldMap::~WorldMap()
{
}


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
    this->schedule(CC_CALLBACK_1(WorldMap::updateDash, this), 0.25f, "updateDash");
    
//    auto mapObjects = getChildren();
//    for (Node* object : mapObjects) {
//        if (object->getName() != "background") {
//            object->setZOrder(_calcObjectZOrder(object));
//        }
//    }
    setCascadeOpacityEnabled(true);

    this->setupTouchHandling();
}

void WorldMap::updateDash(float dt)
{
    if (_targetPoint == Vec2::ZERO) {
        return;
    }

    Length dashSpeed = WorldManager::getInstance()->getDashSpeed();
    
    // 指定点まで移動
    auto children = getChildren();
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
            animal->startDash(_targetPoint, dashSpeed);
        }
    }
}


void WorldMap::update(float dt)
{
    Node::update(dt);
    auto children = getChildren();
    
    // Zオーダー更新
    for(auto node : children) {
        int tag = node->getTag();
        if (tag != (int)EntityTag::Animal
            && tag != (int)EntityTag::EnemyAnimal
            && tag != (int)EntityTag::OpponentAnimal)
        {
            continue;
        }

        auto animal = dynamic_cast<Animal*>(node);
        if (animal) {
            if (animal->getState() != AnimalState::Jump) {
                node->setZOrder(1000 - (int)node->getPosition().y);
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
            auto battleState = WorldManager::getInstance()->checkBattleState();            
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
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        bool isTouchGacha = false;
        auto state = WorldManager::getInstance()->getSceneState();
        auto gacha = WorldManager::getInstance()->getGacha();
        if (gacha && state != SceneState::Battle) {
            Point location = touch->getLocationInView();
            auto touchLocation = Director::getInstance()->convertToGL(location);
            auto gachaP = gacha->convertToNodeSpace(touchLocation);
            isTouchGacha = gacha->touchIsInGacha(gachaP);
        }
     
        if (isTouchGacha) {
            WorldManager::getInstance()->lotteryGacha();
        } else {
            Vec2 touchPos = this->convertTouchToNodeSpace(touch);
            _allAnimalDashToPoint(touchPos);
            
            auto particle = ParticleSystemQuad::create("effect/tap.plist");
            particle->setScale(1 / this->getScale());
            particle->setPosition(touchPos);
            addChild(particle, 2000);
        }
        
        return true;
    };

    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
    };


    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
    };

    touchListener->onTouchCancelled = [&](Touch* touch, Event* event)
    {
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

}

#pragma - getter/setter

void WorldMap::initSize(Length maxWidth, Length currentWidth)
{
    _maxWidth = maxWidth;
    _currentWidth = currentWidth;
    auto back = getChildByName<Sprite*>("background");
    Size size = Director::getInstance()->getVisibleSize();
    float scale = size.width * _maxWidth.getMmLength() / ( _currentWidth.getMmLength() * back->getContentSize().width);
    this->setScale(scale);
}

Length WorldMap::getCurrentWidth()
{
    return _currentWidth;
}

Length WorldMap::getMaxWidth()
{
    return _maxWidth;
}

void WorldMap::setCurrentWidth(Length width, std::function<void ()> callback)
{
    _currentWidth = width;
    auto back = getChildByName<Sprite*>("background");
    Size size = Director::getInstance()->getVisibleSize();
    auto hoge = back->getContentSize();
    float scale = size.width * _maxWidth.getMmLength() / ( _currentWidth.getMmLength() * back->getContentSize().width);
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
            gacha->setZOrder(_calcObjectZOrder(gacha));
        } else {
            gacha->setZOrder(_calcObjectZOrder(gacha) - 1);
        }
    } else {
        gacha->setPosition(Vec2(0, 0));
        gacha->setZOrder(_calcObjectZOrder(gacha));
    }
    addChild(gacha);
}

void WorldMap::setCoinTree(CoinTree* tree)
{
    tree->setZOrder(_calcObjectZOrder(tree));
    addChild(tree);
    tree->sprout();
}

void WorldMap::releaseAnimal(Animal* animal, std::function<void ()> callback)
{
    auto gacha = WorldManager::getInstance()->getGacha();
    float gachaHeight = gacha->getGachaHeight();
    animal->setPosition(gacha->getPosition() + Vec2(0, gachaHeight));
    animal->setZOrder(2000);
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
    return _maxWidth.getLength() <= _currentWidth.getLength();
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

void WorldMap::vibrationMap()
{
    Vector<FiniteTimeAction*> actionList;
    for (int i = 0; i < 5; i++) {
        float scale = 1.05f;
        auto scale1 = ScaleBy::create(0.05f, scale);
        auto scale2 = ScaleBy::create(0.05f, 1 / scale);
        actionList.pushBack(scale1);
        actionList.pushBack(scale2);
    }
    auto action = Sequence::create(actionList);
    this->runAction(action);
    
    actionList.clear();
    for (int i = 0; i < 5; i++) {
        int x = (i % 2 == 1) ? 10 : -10;
        int y = rand() % 40 - 20;
        auto move1 = MoveBy::create(0.05f, Vec2(x, y));
        auto move2 = MoveBy::create(0.05f, Vec2(-x, -y));
        actionList.pushBack(move1);
        actionList.pushBack(move2);
    }
    action = Sequence::create(actionList);
    runAction(action);
}

#pragma - private method

int WorldMap::_calcObjectZOrder(Node* node)
{
    return 1000 - (int)node->getPosition().y;
}

void WorldMap::_allAnimalDashToPoint(Vec2 point)
{
    Length dashSpeed = WorldManager::getInstance()->getDashSpeed();
    float range = 400 / getScale();
    float closeThreshold = 40 / getScale();
    float dashTime = 0.15f;
    
    // 指定点まで移動
    std::vector<Vec2> targetPointList;
    auto children = getChildren();
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
            float distance = (animal->getPosition() - point).length();
            if (distance > range) {
                continue;
            }
            
            Vec2 move = point - animal->getPosition();
            float speed = dashSpeed.getDisplayLength();
            if (move.length() > speed * dashTime) {
                move.normalize();
                move *= speed * dashTime;
            }
            Vec2 target = animal->getPosition() + move;
            Vec2 originTarget = target;
            int i;
            for (i = 1; i <= 10; i++) {
                if (_isThereCloseAnimal(target, targetPointList, closeThreshold) == false) {
                    break;
                }
                float width = closeThreshold * i;
                target = originTarget + Vec2(rand_0_1() * width - width / 2, rand_0_1() * width - width / 2);
            }
            targetPointList.push_back(target);
            
            animal->startDashToPoint(target, dashTime);
        }
    }
}

bool WorldMap::_isThereCloseAnimal(Vec2 point, std::vector<Vec2> otherAnimalPoints, float threshold)
{
    for (auto otherPos : otherAnimalPoints) {
        if ((point - otherPos).length() < threshold) {
            return true;
        }
    }
    return false;
}
