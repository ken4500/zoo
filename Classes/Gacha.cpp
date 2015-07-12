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
    _timeline = CSLoader::createTimeline("Gacha.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _enableGacha = true;
    _level = 1;
    std::srand((int)time(NULL));
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/gacha.json");
    _settingDoc.Parse<0>(jsonStr.c_str());

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
    
    std::vector<float> probabilityList;
    std::vector<std::string> rewardList;
    rapidjson::Value& gachaDoc = _settingDoc[std::to_string(_level).c_str()];
    for (int i = 0; i < gachaDoc.Size(); i++) {
        rapidjson::Value& v = gachaDoc[i];
        probabilityList.push_back(v["probability"].GetDouble());
        rewardList.push_back(v["reward"].GetString());
    }

    float rnd = CCRANDOM_0_1();
    AnimalType type;
    if (_level == 1) {
        if (rnd > 0.05) {
            type = AnimalType::Ant;
        } else {
            type = AnimalType::Beetle;
//            _enableGacha = false;
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
    
    _enableGacha = false;
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("gacha", false);
    this->runAction(Sequence::create(
        DelayTime::create(1.0f),
        CallFunc::create([this, type](){
            auto animal = AnimalFactory::getInstance()->createAnimal(type);
            animal->setTag((int)MainSceneTag::Animal);
            this->finishGachaCallback(animal);
            _enableGacha = true;
        }),
        NULL
    ));

    
}