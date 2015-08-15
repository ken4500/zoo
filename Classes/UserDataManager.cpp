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
    auto shopData   = _userData->getShopData();
    auto story      = _userData->getStoryData();
    auto reviewed   = _userData->isReviewed();
    
    // 初期化
    _userData->init();
    
    _userData->setLanguage(lang);
    _userData->setDiamondNum(diamond);
    _userData->setAnimalDataList(animalData);
    _userData->setShopData(shopData);
    _userData->setEndTutorial(true);
    _userData->setStroyData(story);
    _userData->setIsReviewed(reviewed);
    
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
void UserDataManager::setMaxLife(int maxLife)
{
    auto lifeData = _userData->getLifeData();
    int addMaxLife = maxLife - lifeData["max_life"].asInt();
    lifeData["max_life"] = maxLife;
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

long long int UserDataManager::getCoin()
{
    return _userData->getCoin();
}

void UserDataManager::addCoin(long long int addCoin)
{
    long long int coin = _userData->getCoin();
    _userData->setCoin(coin + addCoin);
    _userData->save();
}

void UserDataManager::setCoin(long long int coin)
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
    ShopLineup type = ShopLineup::SPAWN_NUM;
    int level = getShopDataLevel(type);
    return (int)ShopData::getInstance()->getValue(type, level);
}

int UserDataManager::getAnimalNum()
{
    ShopLineup type = ShopLineup::ANIMAL_NUM;
    int level = getShopDataLevel(type);
    return (int)ShopData::getInstance()->getValue(type, level);
}

float UserDataManager::getOffenseRate()
{
    ShopLineup type = ShopLineup::OFFESE_UP;
    int level = getShopDataLevel(type);
    return ShopData::getInstance()->getValue(type, level);
}

float UserDataManager::getCoinRate()
{
    ShopLineup type = ShopLineup::GET_COIN;
    int level = getShopDataLevel(type);
    return ShopData::getInstance()->getValue(type, level);
}

float UserDataManager::getEnemyNumRate()
{
    ShopLineup type = ShopLineup::EMERGE_ENEMY;
    int level = getShopDataLevel(type);
    return ShopData::getInstance()->getValue(type, level);
}

int UserDataManager::getShopDataLevel(ShopLineup type)
{
    auto key = ShopData::toString(type);
    auto shopData = _userData->getShopData();
    return shopData[key].asInt();
}

void UserDataManager::addDiamondNum(int addNum)
{
    _userData->setDiamondNum(addNum + _userData->getDiamondNum());
    _userData->save();
}

void UserDataManager::levelupShopData(ShopLineup type)
{
    auto key = ShopData::toString(type);
    auto shopData = _userData->getShopData();
    int level = getShopDataLevel(type);
    int nextLevel = level + 1;
    shopData[key] = nextLevel;
    _userData->setShopData(shopData);
    
    if (type == ShopLineup::MAX_LIFE) {
        int maxLife = (int)ShopData::getInstance()->getValue(type, nextLevel);
        setMaxLife(maxLife);
    }
    
    _userData->save();
}

#pragma - レビューに関するメソッド

bool UserDataManager::isReviewed()
{
    return _userData->isReviewed();
}

void UserDataManager::reviewed()
{
    _userData->setIsReviewed(true);
    _userData->save();
}
