//
//  UserDataManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserDataManager.h"

static UserDataManager* shared_controller = nullptr;

UserDataManager::UserDataManager()
{
}

UserDataManager::~UserDataManager()
{
    delete shared_controller;
    shared_controller = nullptr;
}

UserDataManager* UserDataManager::getInstance()
{
    if (!shared_controller) {
        shared_controller = new UserDataManager();
        shared_controller->init();
    }
    
    return shared_controller;
}

bool UserDataManager::init()
{
    _userData = UserData::load();
    
    return true;
}

void UserDataManager::reset()
{
    _userData->init();
    _userData->save();
}

bool UserDataManager::isEndTutorial()
{
    return _userData->isEndTutorial();
}

void UserDataManager::clearTutorial()
{
    _userData->setEndTutorial(true);
    _userData->save();
}

WorldInfo* UserDataManager::getWorldInfo()
{
    auto data = _userData->getWorldInfo();
    auto info = new WorldInfo(data["level"].asInt());
    info->lotteryGachaCount = data["gacha_count"].asInt();
    info->totalLotteryGachaCount = data["total_gacha_count"].asInt();
    return info;
}

void UserDataManager::setWorldInfo(WorldInfo* info)
{
    auto data = _userData->getWorldInfo();
    data["level"] = info->level;
    data["gacha_count"] = info->lotteryGachaCount;
    data["total_gacha_count"] = info->totalLotteryGachaCount;
    _userData->setWorldInfo(data);
}

LanguageType UserDataManager::getLanguage()
{
    return _userData->getLanguage();
}

void UserDataManager::setLanguage(LanguageType language)
{
    _userData->setLanguage(language);
    _userData->save();
}

// 最大体力の取得
int UserDataManager::getMaxLife()
{
    auto lifeData = _userData->getLifeData();
    return lifeData["max_life"].asInt();
}

// 現在の体力の取得
int UserDataManager::getLife()
{
    auto lifeData = _userData->getLifeData();
    int lastLife = lifeData["current_life"].asInt();
    if (lastLife >= lifeData["max_life"].asInt()) {
        return lastLife;
    }
    int elpasedTime = (int)time(NULL) - lifeData["last_time"].asInt();
    int life = lastLife + (int)(elpasedTime / REPAIR_LIFE_TIME);
    life = (int)MIN(life, lifeData["max_life"].asInt());

    return life;
}

// 次に体力回復までに必要な時間を返す
int UserDataManager::getNextRepairLifeTime()
{
    auto lifeData = _userData->getLifeData();
    int lastLife = lifeData["current_life"].asInt();
    int elpasedTime = (int)time(NULL) - lifeData["last_time"].asInt();
    int life = lastLife + (int)(elpasedTime / REPAIR_LIFE_TIME);

    // すでに体力満タン
    if (life >= lifeData["max_life"].asInt()) {
        return 0;
    }
    
    int nextRepairTime = REPAIR_LIFE_TIME - elpasedTime % REPAIR_LIFE_TIME;
    return nextRepairTime;
}

// 現在の体力が最大かどうか
bool UserDataManager::isMaxLife()
{
    int life = getLife();
    int maxLife = getMaxLife();
    return life >= maxLife;
}

// 体力を最大まで回復
void UserDataManager::repairLife()
{
    auto lifeData = _userData->getLifeData();
    lifeData["last_time"] = 0;
    _userData->setLifeData(lifeData);
    _userData->save();
}

// 体力の減少
void UserDataManager::decreateLife(int decreseLife)
{
    auto lifeData = _userData->getLifeData();
    int life = getLife();
    int elpasedTime = (int)time(NULL) - lifeData["last_time"].asInt();
    
    if (life >= lifeData["max_life"].asInt()) {
        lifeData["last_time"] = (int)time(NULL);
    } else {
        lifeData["last_time"] = (int)time(NULL) - elpasedTime % REPAIR_LIFE_TIME;
    }

    int nextLife = life - decreseLife;
    lifeData["current_life"] = nextLife;
    _userData->setLifeData(lifeData);
    _userData->save();
}

// 最大体力のセット
void UserDataManager::addMaxLife(int addMaxLife)
{
    auto lifeData = _userData->getLifeData();
    lifeData["max_life"] = lifeData["max_life"].asInt() + addMaxLife;
    int life = getLife();
    int elpasedTime = (int)time(NULL) - lifeData["last_time"].asInt();
    if (life >= lifeData["max_life"].asInt()) {
        lifeData["last_time"] = (int)time(NULL);
    } else {
        lifeData["last_time"] = (int)time(NULL) - elpasedTime % REPAIR_LIFE_TIME;
    }

    int nextLife = life + addMaxLife;
    lifeData["current_life"] = nextLife;

    _userData->setLifeData(lifeData);
    _userData->save();
}

int UserDataManager::getCoin()
{
    return _userData->getCoin();
}

void UserDataManager::addCoin(int addCoin)
{
    int coin = _userData->getCoin();
    _userData->setCoin(coin + addCoin);
    _userData->save();
}

void UserDataManager::setCoin(int coin)
{
    _userData->setCoin(coin);
}

std::vector<Animal*> UserDataManager::getAnimalList()
{
    auto rtnAnimalList = std::vector<Animal*>();
    auto animalList = _userData->getAnimalList();
    for (Value v : animalList) {
        ValueMap animalData = v.asValueMap();
        std::string name = animalData["name"].asString();
        float size = animalData["size"].asFloat();
        auto animal = Animal::CreateWithSpeceis(name, size);
        rtnAnimalList.push_back(animal);
    }
    return rtnAnimalList;
}

void UserDataManager::addAnimal(Animal* animal)
{
    auto animalList = _userData->getAnimalList();
    auto animalData = ValueMap();
    animalData["name"] = Value(animal->getName());
    animalData["size"] = Value(animal->getHeight().getMmLength());
    animalList.push_back(Value(animalData));
    _userData->setAnimalList(animalList);
    
    _userData->save();
}

void UserDataManager::removeAnimal(Animal* animal)
{
    auto animalList = _userData->getAnimalList();
    for (auto it = animalList.begin(); it != animalList.end();) {
        auto tmpAnimal = (*it).asValueMap();
        if (tmpAnimal["name"].asString() == animal->getName()
            && tmpAnimal["size"].asFloat() == animal->getHeight().getMmLength()) {
            it = animalList.erase(it);
            continue;
        }
        it++;
    }
    _userData->setAnimalList(animalList);
    _userData->save();
}
