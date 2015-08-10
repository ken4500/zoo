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

void UserDataManager::transmigration()
{
    // 引き継ぎデータ
    auto lang       = _userData->getLanguage();
    auto diamond    = _userData->getDiamondNum();
    auto animalData = _userData->getAnimalDataList();
    auto status     = _userData->getStatus();
    auto story      = _userData->getStoryData();
    
    // 初期化
    _userData->init();
    
    _userData->setLanguage(lang);
    _userData->setDiamondNum(diamond);
    _userData->setAnimalDataList(animalData);
    _userData->setStatus(status);
    _userData->setEndTutorial(true);
    _userData->setStroyData(story);
    
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

bool UserDataManager::alreadyRead(std::string novelId)
{
    auto storyData = _userData->getStoryData();
    if (storyData.find(novelId) == storyData.end()) {
        return false;
    } else {
        return true;
    }
}

void UserDataManager::setAlreadyRead(std::string novelId)
{
    auto storyData = _userData->getStoryData();
    storyData[novelId] = 1;
    _userData->setStroyData(storyData);
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

long int UserDataManager::getCoin()
{
    return _userData->getCoin();
}

void UserDataManager::addCoin(long int addCoin)
{
    long int coin = _userData->getCoin();
    _userData->setCoin(coin + addCoin);
    _userData->save();
}

void UserDataManager::setCoin(long int coin)
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

bool UserDataManager::haveHadAnimalInPast(std::string animalName)
{
    auto animalData = _userData->getAnimalDataList();
    if (animalData.find(animalName) == animalData.end()) {
        return false;
    } else {
        return true;
    }
}

void UserDataManager::getAnimal(Animal* animal)
{
    auto animalData = _userData->getAnimalDataList();
    if (haveHadAnimalInPast(animal->getName()) == false) {
        ValueMap data;
        data["get_count"] = 1;
        data["min_weight"] = animal->getWeight().getMgWeight();
        data["max_weight"] = animal->getWeight().getMgWeight();
        data["min_length"] = animal->getHeight().getMmLength();
        data["max_length"] = animal->getHeight().getMmLength();
        animalData[animal->getName()] = data;
        _userData->setAnimalDataList(animalData);
    } else {
        ValueMap data = animalData[animal->getName()].asValueMap();
        data["get_count"] = data["get_count"].asInt() + 1;
        data["min_weight"] = MIN(data["min_weight"].asDouble(), animal->getWeight().getMgWeight());
        data["max_weight"] = MAX(data["max_weight"].asDouble(), animal->getWeight().getMgWeight());
        data["min_length"] = MIN(data["min_length"].asDouble(), animal->getHeight().getMmLength());
        data["max_length"] = MAX(data["max_length"].asDouble(), animal->getHeight().getMmLength());
        animalData[animal->getName()] = data;
        _userData->setAnimalDataList(animalData);
    }
}

Weight UserDataManager::getMaxWeight(std::string animalName)
{
    if (haveHadAnimalInPast(animalName) == false) {
        return Weight(0);
    } else {
        auto animalData = _userData->getAnimalDataList();
        auto data = animalData[animalName].asValueMap();
        return Weight(data["max_weight"].asDouble());
    }
}

Weight UserDataManager::getMinWeight(std::string animalName)
{
    if (haveHadAnimalInPast(animalName) == false) {
        return Weight(0);
    } else {
        auto animalData = _userData->getAnimalDataList();
        auto data = animalData[animalName].asValueMap();
        return Weight(data["min_weight"].asDouble());
    }
}

Length UserDataManager::getMaxHeight(std::string animalName)
{
    if (haveHadAnimalInPast(animalName) == false) {
        return Length(0);
    } else {
        auto animalData = _userData->getAnimalDataList();
        auto data = animalData[animalName].asValueMap();
        return Length(data["max_length"].asDouble());
    }
}

Length UserDataManager::getMinHeight(std::string animalName)
{
    if (haveHadAnimalInPast(animalName) == false) {
        return Length(0);
    } else {
        auto animalData = _userData->getAnimalDataList();
        auto data = animalData[animalName].asValueMap();
        return Length(data["min_length"].asDouble());
    }
}

int UserDataManager::getAnimalCount(std::string animalName)
{
    if (haveHadAnimalInPast(animalName) == false) {
        return 0;
    } else {
        auto animalData = _userData->getAnimalDataList();
        auto data = animalData[animalName].asValueMap();
        return data["get_count"].asInt();
    }
}

#pragma - ステータスに関するメソッド

int UserDataManager::getDiamondNum()
{
    return _userData->getDiamondNum();
}

int UserDataManager::getSpawnAnimalNum()
{
    return 1 + _userData->getStatus()["add_spawn_animal_num"].asInt();
}

int UserDataManager::getAnimalNum()
{
    return INIT_MAX_ANIMAL_NUM + _userData->getStatus()["add_animal_num"].asInt();
}

float UserDataManager::getOffenseRate()
{
    return 1 + _userData->getStatus()["add_offense_rate"].asFloat();
}

float UserDataManager::getCoinRate()
{
    return 1 + _userData->getStatus()["add_coin_rate"].asFloat();
}

float UserDataManager::getEnemyNumRate()
{
    return 1 + _userData->getStatus()["enemy_num_rate"].asFloat();
}

void UserDataManager::addDiamondNum(int addNum)
{
    _userData->setDiamondNum(addNum + _userData->getDiamondNum());
}

void UserDataManager::setSpawnAnimalNum(int spawnAnimalNum)
{
    auto status = _userData->getStatus();
    status["add_spawn_animal_num"] = spawnAnimalNum;
    _userData->setStatus(status);
    _userData->save();
}

void UserDataManager::setAnimalNum(int animalNum)
{
    auto status = _userData->getStatus();
    status["add_animal_num"] = animalNum;
    _userData->setStatus(status);
    _userData->save();
}

void UserDataManager::setOffenseRate(float offenseRate)
{
    auto status = _userData->getStatus();
    status["add_offense_rate"] = offenseRate;
    _userData->setStatus(status);
    _userData->save();
}

void UserDataManager::setCoinRate(float coinRate)
{
    auto status = _userData->getStatus();
    status["add_coin_rate"] = coinRate;
    _userData->setStatus(status);
    _userData->save();
}

void UserDataManager::setEnemyNumRate(float enemyRate)
{
    auto status = _userData->getStatus();
    status["enemy_num_rate"] = enemyRate;
    _userData->setStatus(status);
    _userData->save();
}
