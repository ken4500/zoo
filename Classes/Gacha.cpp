//
//  Gacha.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Gacha.h"
#include "AnimalFactory.h"
#include "WorldManager.h"


bool Gacha::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("Gacha.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _enableGacha = true;
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
    
    int gachaId = WorldManager::getInstance()->getGachaId();
    std::vector<float> probabilityList;
    std::vector<std::string> rewardList;
    rapidjson::Value& gachaDoc = _settingDoc[std::to_string(gachaId).c_str()];
    float total = 0;
    for (int i = 0; i < gachaDoc.Size(); i++) {
        rapidjson::Value& v = gachaDoc[i];
        float p = v["probability"].GetDouble();
        total += p;
        probabilityList.push_back(p);
        rewardList.push_back(v["reward"].GetString());
    }
    
    float rnd = total * rand_0_1();
    float lot = 0;
    std::string animalStr;
    for (int i = 0; i < probabilityList.size(); i++) {
        lot += probabilityList[i];
        if (rnd < lot) {
            animalStr = rewardList[i];
            break;
        }
    }

    _enableGacha = false;
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("gacha2", false);
    this->runAction(Sequence::create(
        DelayTime::create(0.3f),
        CallFunc::create([this, animalStr](){
            auto animal = AnimalFactory::getInstance()->createAnimal(animalStr);
            animal->setTag((int)MainSceneTag::Animal);
            this->finishGachaCallback(animal);
            _enableGacha = true;
        }),
        NULL
    ));

    
}