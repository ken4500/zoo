//
//  Gacha.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Gacha.h"
#include "WorldManager.h"
#include "Animal.h"
#include "SoundManager.h"

bool Gacha::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("Gacha.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    std::srand((int)time(NULL));
    setTag((int)EntityTag::Gacha);
    
    return true;
}

void Gacha::onEnter()
{
    Node::onEnter();
    
    auto price = getChildByName("price");
    auto priceTimeline = CSLoader::createTimeline("Price.csb");
    price->runAction(priceTimeline);
    priceTimeline->play("rotate", true);
    _priceLabel = price->getChildByName<ui::TextBMFont*>("label");
    
    if (_price) {
       _priceLabel->setString(StringUtils::format("%ld", _price));
    }
}

float Gacha::getGachaHeight()
{
    auto image = this->getChildByName<Sprite*>("image");
    return image->getContentSize().height * getScale();
}

void Gacha::lotteryGacha(WorldInfo* _info)
{
    _info->addLotteryGachaCount();

    bool isHit = false;
    bool canLotteryHit = _least < _info->lotteryGachaCount;
    std::string animalStr;

    do {
        float rnd = _sumProbability * rand_0_1();
        float lot = 0;
        for (int i = 0; i < _probabilityList.size(); i++) {
            lot += _probabilityList[i];
            if (rnd < lot) {
                animalStr = _rewardList[i];
                isHit = _hitList[i];
                break;
            }
        }
    } while (isHit && canLotteryHit == false);
    
    if (isHit) {
    } else {
        SoundManager::getInstance()->playGachaEffect2();
    }
    
    std::string animationName = (isHit) ? "gacha1" : "gacha2";
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play(animationName, false);
    float durationTime = ZUtil::calcDurationTime(_timeline, animationName);
    this->runAction(Sequence::create(
        DelayTime::create(durationTime - 0.1f),
        CallFunc::create([this, animalStr, isHit](){
            auto animal = Animal::CreateWithSpeceis(animalStr);
            WorldManager::getInstance()->releaseAnimal(animal, isHit);
            if (finishGachaCallback && isHit == false) {
                finishGachaCallback();
            }
        }),
        NULL
    ));
}

void Gacha::setNewGacha(WorldInfo* info)
{
    _sumProbability = 0;
    _probabilityList = std::vector<float>();
    _rewardList = std::vector<std::string>();
    _hitList = std::vector<bool>();
    _least = 0;
    _price = 1;

    std::string fileName = "data/gacha.json";
    if (info->network) {
        fileName = "data/gacha_multi.json";
    }
    auto jsonStr = FileUtils::getInstance()->getStringFromFile(fileName);
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& gachaDoc = document[std::to_string(info->gachaId).c_str()];
    _least = gachaDoc["least"].GetInt();
    _price = gachaDoc["price"].GetInt();
    rapidjson::Value& listDoc = gachaDoc["list"];
    for (int i = 0; i < listDoc.Size(); i++) {
        rapidjson::Value& v = listDoc[i];
        float p = v["probability"].GetDouble();
        _sumProbability += p;
        _probabilityList.push_back(p);
        _rewardList.push_back(v["reward"].GetString());
        if (v["hit"].IsNull()) {
            _hitList.push_back(false);
        } else {
            _hitList.push_back(v["hit"].GetBool());
        }
    }
    
    if (_priceLabel) {
        _priceLabel->setString(StringUtils::format("-%ld", _price));
    }
}

long int Gacha::getPrice()
{
    return _price;
}

void Gacha::setOpponent(bool isOpponent)
{
    _isOppnentGacha = isOpponent;
    auto image = this->getChildByName<Sprite*>("image");
    image->setColor(Color3B(COLOR_RED));
    if (isOpponent) {
        _hidePrice();
    } else {
        _showPrice();
    }
}

bool Gacha::isOpponent()
{
    return _isOppnentGacha;
}

bool Gacha::touchIsInGacha(Vec2 position)
{
    // FIXME:
    if (-200 < position.x && position.x < 200
        && 60 < position.y && position.y < 300)
    {
        return true;
    }
    return false;
}

void Gacha::_hidePrice()
{
    auto price = getChildByName("price");
    price->setVisible(false);
}

void Gacha::_showPrice()
{
    auto price = getChildByName("price");
    price->setVisible(true);
}

