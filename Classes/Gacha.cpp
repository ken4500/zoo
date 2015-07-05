//
//  Gacha.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Gacha.h"
#include "AnimalFactory.h"

bool Gacha::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Gacha.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();
    
    _enableGacha = true;
    _level = 1;

    return true;
}

void Gacha::onEnter()
{
    Node::onEnter();
    this->setupTouchHandling();
}


void Gacha::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        auto image = this->getChildByName<Sprite*>("image");
        Rect targetBox = image->getBoundingBox();
        targetBox.origin = image->convertToWorldSpaceAR(targetBox.origin);
     
        Point location = touch->getLocationInView();
        auto touchLocation = Director::getInstance()->convertToGL(location);
        
     
        //touchPointがtargetBoxの中に含まれているか判定
        if (targetBox.containsPoint(touchLocation))
        {
            this->lotteryGacha();
        }
        return true;
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void Gacha::lotteryGacha()
{
    if (_enableGacha == false) {
        return;
    }
    float rnd = rand_0_1();
    float jump;
    float scale;
    AnimalType type;
    if (_level == 1) {
        if (rnd > 0.05) {
            type = AnimalType::Ant;
        } else {
            type = AnimalType::Beetle;
            _enableGacha = false;
//            runAction(Sequence::create(
//                DelayTime::create(1.0f),
//                CallFunc::create([this](){this->levelup();}),
//                NULL
//            ));
        }
    } else {
        if (rnd > 0.05) {
            type = AnimalType::Beetle;
        } else {
            type = AnimalType::Dog;
        }
    }

    auto animal = AnimalFactory::getInstance()->createAnimal(type);
//    animal->setScale(scale);
    animal->setTag((int)MainSceneTag::Animal);
    this->finishGachaCallback(animal);
    
}