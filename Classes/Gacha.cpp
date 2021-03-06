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
#include "UserDataManager.h"

bool Gacha::init()
{
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
}

float Gacha::getGachaHeight()
{
    auto image = this->getChildByName<Sprite*>("image");
    return image->getContentSize().height * getScale();
}

void Gacha::lotteryGacha(WorldInfo* _info, int spawnNum)
{
    bool isHit = false;

    std::vector<std::string> animalNameList;
    for (int i = 0; i < spawnNum; i++) {
        _info->addLotteryGachaCount();
        bool canLotteryHit = _least < _info->lotteryGachaCount;

        int j;
        bool hit;
        do {
            float rnd = _sumProbability * rand_0_1();
            float lot = 0;
            for (j = 0; j < _probabilityList.size(); j++) {
                lot += _probabilityList[j];
                if (rnd < lot) {
                    hit = _hitList[j];
                    break;
                }
            }
        } while ((_isDebug && hit == false) || (_isDebug == false && hit && canLotteryHit == false));
        isHit = (isHit == false) ? hit : isHit;
        animalNameList.push_back(_rewardList[j]);
    }

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
        CallFunc::create([this, animalNameList, isHit](){
            std::vector<Animal*> animalList;
            for (auto animalStr : animalNameList) {
                Animal* animal;
                if (isHit) {
                    Species* species = new Species(animalStr);
                    animal = Animal::CreateWithSpeceis(animalStr, species->getAverageHeight().getMmLength());
                    delete species;
                } else {
                    animal = Animal::CreateWithSpeceis(animalStr);
                }
                animalList.push_back(animal);
            }

            WorldManager::getInstance()->releaseAnimal(animalList, isHit);
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
    _price = (long long int)gachaDoc["price"].GetDouble();
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
    
    auto preFukidashi = getChildByName("fukidashi");
    if (preFukidashi) {
        preFukidashi->removeFromParent();
    }
}

long long int Gacha::getPrice()
{
    return _price;
}

void Gacha::setOpponent(bool isOpponent)
{
    _isOppnentGacha = isOpponent;
    auto image = this->getChildByName<Sprite*>("image");
    image->setColor(Color3B(COLOR_RED));
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

void Gacha::say(std::string message)
{
    auto preFukidashi = getChildByName("fukidashi");
    if (preFukidashi) {
        preFukidashi->removeFromParent();
    }

    Sprite* fukidashi = Sprite::create("ui/small_fukidashi.png");
    fukidashi->setAnchorPoint(Vec2(0, 0));
    fukidashi->setPosition(Vec2(40, 55));
    fukidashi->setName("fukidashi");
    addChild(fukidashi);
    
    Label* label;
    
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    if (curLanguage == LanguageType::CHINESE) {
       label = Label::createWithTTF(message, "font/simiyo.ttf", 44);
    } else {
       label = Label::createWithTTF(message, "font/yasashisa.ttf", 44);
    }
    
    label->setColor(Color3B(COLOR_OUTLINE));
    label->setAnchorPoint(Vec2(0.5f, 0.5f));
    Vec2 pos = Vec2(fukidashi->getContentSize() / 2) + Vec2(20, 0);
    label->setPosition(pos);
    fukidashi->addChild(label);
    
    fukidashi->setOpacity(0);
    fukidashi->setCascadeOpacityEnabled(true);
    fukidashi->runAction(Sequence::create(
        FadeIn::create(0.2f),
        DelayTime::create(2.0f),
        FadeOut::create(0.2f),
        RemoveSelf::create(),
        NULL
    ));
}

void Gacha::sayRandom()
{
    auto info = WorldManager::getInstance()->getWorldInfo();
    int rnd = 11;
    if (info->level != MAX_LEVEL) {
        rnd = rand() % 10 + 1;
    }
    auto message = CCLS(StringUtils::format("GACHA_SAY_LEVELUP_%d", rnd).c_str());
    say(message);
}

void Gacha::setDebugMode(bool isDebug)
{
    _isDebug = isDebug;
}
