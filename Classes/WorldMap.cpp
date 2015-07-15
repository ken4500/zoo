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
                if (_targetPoint != Vec2::ZERO) {
                    animal->movePoint(_targetPoint, dt);
                }
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
        auto image = _gacha->getChildByName<Sprite*>("image");
        Rect targetBox = image->getBoundingBox();
        targetBox.origin = image->convertToWorldSpaceAR(targetBox.origin);
     
        Point location = touch->getLocationInView();
        auto touchLocation = Director::getInstance()->convertToGL(location);
        
     
        if (targetBox.containsPoint(touchLocation)) {
            _gacha->lotteryGacha();
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


#pragma - private method

int WorldMap::_calcObjectZOrder(Node* node)
{
    return 1000 - (int)node->getPosition().y;
}
