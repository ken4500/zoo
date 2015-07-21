//
//  WorldManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldManager.h"
#include "Gacha.h"
#include "Animal.h"
#include "GameResult.h"
#include "ResultLayer.h"
#include "NoticeLayer.h"

USING_NS_CC;

static WorldManager* sharedWorldManager;
WorldManager* WorldManager::getInstance()
{
    if (!sharedWorldManager) {
        sharedWorldManager = new WorldManager();
    }

    return sharedWorldManager;
}

#pragma mark - Constructor and Destructor

WorldManager::WorldManager()
{
    _level = INIT_WORLD_LEVEL;
    _coin = INIT_COIN;
    _life  = INIT_LIFE;
    _info  = _loadWoldInfo(_level);
    _map   = nullptr;
    _enableNextAction = true;
    _state = SceneState::Normal;
}

WorldManager::~WorldManager()
{
}


#pragma - getter / setter

int WorldManager::getGachaId()
{
    return _info->gachaId;
}

WorldInfo* WorldManager::getWorldInfo()
{
    return _info;
}

WorldMap* WorldManager::getMap()
{
    if (_map == nullptr) {
        _map = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
        _map->initSize(_info->maxWidth, _info->width);
    
    
        if (_state != SceneState::Tutorial) {
            _gacha = dynamic_cast<Gacha*>(CSLoader::createNode("Gacha.csb"));
            auto gachaImage = _gacha->getChildByName<Sprite*>("image");
            auto gachaLength = Length::scale(_info->width, 0.2);
            float gachaScale = getImageScale(gachaImage, gachaLength);
            _gacha->setScale(gachaScale);
            _map->setGacha(_gacha);
        }

        auto hero = Animal::CreateWithSpeceis("Hero");
        _map->addAnimal(hero, Vec2(0, -200));
        _animalList.push_back(hero);
    }
    return _map;
}

bool WorldManager::enableNextAction()
{
    return _enableNextAction;
}

void WorldManager::setEnableNextAction(bool enable)
{
    _enableNextAction = enable;
}

SceneState WorldManager::getSceneState()
{
    return _state;
}

std::vector<Animal*> WorldManager::getAnimalList()
{
    return _animalList;
}

std::vector<Animal*> WorldManager::getEnemyAnimalList()
{
    return _enemyAnimalList;
}

int WorldManager::getCoin()
{
    return _coin;
}

int WorldManager::getLife()
{
    return _life;
}

#pragma - public method

void WorldManager::lotteryGacha()
{
    if (_enableNextAction == false) {
        return;
    }
    if (_coin <= 0) {
        
        auto mainScene = _getMainScene();
        if (mainScene) {
            mainScene->showNoticeView("You don't have enough coin!\nPush the battle button", NULL);
        }

        return;
    }
    
    _addCoin(-1);
    _gacha->lotteryGacha();
}

void WorldManager::releaseAnimal(Animal* animal, bool hit)
{
    _animalList.push_back(animal);
    if (hit) {
        _map->releaseAnimal(animal, [this] { levelup(); });
    } else {
        _map->releaseAnimal(animal, nullptr);
    }
}

WorldInfo* WorldManager::levelup()
{
    _level++;
    auto mainScene = _getMainScene();
    if (mainScene) {
        mainScene->levelUpEffect();
    }
    
    auto preWorldInfo = _info;
    _info = _loadWoldInfo(_level);
    if (_info->mapName == preWorldInfo->mapName) {
        _map->setCurrentWidth(_info->width, NULL);
        auto gachaImage = _gacha->getChildByName<Sprite*>("image");
        auto gachaLength = Length::scale(_info->width, 0.2);
        float gachaScale = getImageScale(gachaImage, gachaLength);
        _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));
    } else {
        auto newMap = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
        newMap->initSize(_info->maxWidth, preWorldInfo->width);

        if (mainScene) {
            mainScene->transitionMap(newMap);
        }
        _map->setCurrentWidth(_info->width, NULL);
        newMap->setCurrentWidth(_info->width, [this, newMap, preWorldInfo]{
            auto children = _map->getChildren();
            for(auto node : children) {
                if (node->getTag() == (int)MainSceneTag::Animal) {
                    node->retain();
                    node->removeFromParent();
                    newMap->addChild(node);
                    node->release();
                    auto pos = node->getPosition() * preWorldInfo->maxWidth->getMmLength() / _info->maxWidth->getMmLength();
                    node->setPosition(pos);
                    auto animal = dynamic_cast<Animal*>(node);
                    if (animal) {
                        animal->updateWorldScale();
                        animal->startWalk();
                    }
                }
            }
            _gacha->retain();
            _gacha->removeFromParent();
            newMap->setGacha(_gacha);
            _gacha->release();
            auto pos = _gacha->getPosition() * preWorldInfo->maxWidth->getMmLength() / _info->maxWidth->getMmLength();
            _gacha->setPosition(pos);
            auto scale = _gacha->getScale() * preWorldInfo->maxWidth->getMmLength() / _info->maxWidth->getMmLength();
            _gacha->setScale(scale);
            
            auto gachaImage = _gacha->getChildByName<Sprite*>("image");
            auto gachaLength = Length::scale(_info->width, 0.2);
            float gachaScale = getImageScale(gachaImage, gachaLength);
            _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));

            _map = newMap;
        });
    }
    
    return _info;
}

Vec2 WorldManager::getRadomPlace()
{
    auto back = _map->getChildByName<Sprite*>("background");
    auto imageSize = back->getContentSize();
    auto displaySize = Director::getInstance()->getVisibleSize();
    float w = imageSize.width * _info->width->getMmLength() / _info->maxWidth->getMmLength();
    float h = w * displaySize.height / displaySize.width;
    float x = w * rand_0_1() - w / 2;
    float y = h * rand_0_1() - h / 2;
    return Vec2(x, y);
}

Vec2 WorldManager::getOutRandomPlace()
{
    auto back = _map->getChildByName<Sprite*>("background");
    auto imageSize = back->getContentSize();
    auto displaySize = Director::getInstance()->getVisibleSize();
    float w = imageSize.width * _info->width->getMmLength() / _info->maxWidth->getMmLength();
    float h = w * displaySize.height / displaySize.width;
    float x, y;
    
    if (rand() % 2 == 0) {
        if (rand() % 2 == 0) {
            x = w /2 + 50;
        } else {
            x = -w / 2 - 50;
        }
        y = h * rand_0_1() - h /2;
    } else {
        if (rand() % 2 == 0) {
            y = h /2 + 50;
        } else {
            y = -h / 2 - 50;
        }
        x = w * rand_0_1() - w /2;
    }
    
    return Vec2(x, y);
}

void WorldManager::startBattle()
{
    if (_life <= 0 || _enableNextAction == false) {
        return;
    }

    _state = SceneState::Battle;
    _setLeftTime(BATTLE_TIME);
    _enemyGenerater = new EnemyGenerater(_info);
    
    _setGameActive(true);
    
    auto scene = _getMainScene();
    if (scene) {
        scene->showLeftTIme();
    }
    
    
    for (int i = 0; i < 15; i++) {
        auto enemyAnimal = _enemyGenerater->generate();
        enemyAnimal->setIsEnmey(true);
        _enemyAnimalList.push_back(enemyAnimal);
        _map->addEnemyAnimalAtOutRandomPoint(enemyAnimal);
    }
    
    _map->hideGacha();
}

void WorldManager::startTutorialBattle()
{
    _state = SceneState::TutorialBattle;
    
    auto enemyAnimal = Animal::CreateWithSpeceis("Ari");
    enemyAnimal->setIsEnmey(true);
    _enemyAnimalList.push_back(enemyAnimal);
    _map->addEnemyAnimalAtOutRandomPoint(enemyAnimal);
    
    enemyAnimal->startFightCallback = [this]() {
        auto scene = _getMainScene();
        if (scene) {
            scene->playNovel("novel_tutorial_battle2", NULL, false);
        }
    };
    
    enemyAnimal->deadCallback = [this]() {
        auto scene = _getMainScene();
        if (scene) {
            scene->playNovel("novel_tutorial_battle3", NULL, false);
        }
    };
}

void WorldManager::winBattle()
{
    _endBattle();
    GameResult* result = new GameResult();
    result->resultState = BattleState::Win;
    result->playTime = BATTLE_TIME - _leftTime;
    result->getCoin = 0;
    for (auto animal : _enemyAnimalList) {
        if (animal->isDead()) {
            result->getCoin += 1;
        }
    }
    _addCoin(result->getCoin);
    
    auto mainScene = _getMainScene();
    if (mainScene) {
        mainScene->showResultView(result, CC_CALLBACK_0(WorldManager::_closeResult, this));
    }
}

void WorldManager::loseBattle()
{
    _endBattle();
    GameResult* result = new GameResult();
    result->resultState = BattleState::Lose;
    result->playTime = BATTLE_TIME - _leftTime;
    result->getCoin = 0;
    for (auto animal : _enemyAnimalList) {
        if (animal->isDead()) {
            result->getCoin += 1;
        }
    }
    _addCoin(result->getCoin);
    
    auto mainScene = _getMainScene();
    if (mainScene) {
        mainScene->showResultView(result, CC_CALLBACK_0(WorldManager::_closeResult, this));
    }
}

void WorldManager::endResult()
{
    _map->showGacha();
    auto scene = _getMainScene();
    if (scene) {
        scene->showMenu();
    }
}

#pragma - util method

float WorldManager::getImageScale(Sprite* image, Length* width)
{
    auto contentSize = image->getContentSize();
    float scale = (width->getLength(UnitOfLength::mm) * _info->imageWidth) / (_info->maxWidth->getLength(UnitOfLength::mm) * contentSize.width);
    return scale;
}

float WorldManager::getDisplayLength(Length* length)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    return (length->getLength(UnitOfLength::mm) * visibleSize.width) / worldSize->getLength(UnitOfLength::mm);
}

Length* WorldManager::getLength(float displayLength)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float mm = worldSize->getLength(UnitOfLength::mm) * displayLength / visibleSize.width;
    return new Length(UnitOfLength::mm, mm);
}

Vec2 WorldManager::getDisplayPoint(Length x, Length y)
{
    auto worldSize = getWorldInfo()->width;
    
}

#pragma - private method

void WorldManager::_leftTimeUpdate(float dt)
{
    _leftTime--;
    if (_leftTime == 0) {
        loseBattle();
    }
    _setLeftTime(_leftTime);
}

WorldInfo* WorldManager::_loadWoldInfo(int level)
{
    WorldInfo* info = new WorldInfo(level);
    return info;
}

MainScene* WorldManager::_getMainScene()
{
    auto scene = Director::getInstance()->getRunningScene();
    if (scene) {
        return scene->getChildByName<MainScene*>("main scene");
    } else {
        return NULL;
    }
}

void WorldManager::_endBattle()
{
    if (_state == SceneState::Battle) {
        _state = SceneState::ShowResult;
    } else if (_state == SceneState::TutorialBattle) {
        _state = SceneState::TutorialShowResult;
    }
    this->_setGameActive(false);
}

void WorldManager::_closeResult()
{
    for (auto animal : _animalList) {
        if (animal->isDead()) {
            animal->runAction(Sequence::create(
                DelayTime::create(1.0f),
                CallFunc::create([animal]{
                    animal->reborn();
                }),
                NULL
            ));
        } else {
            animal->startWalk();
        }
    }

    for (auto animal : _enemyAnimalList) {
        animal->runAction(Sequence::create(
            FadeOut::create(0.5f),
            RemoveSelf::create(),
            NULL
        ));
    }
    _enemyAnimalList = std::vector<Animal*>();
    
    auto scene = _getMainScene();
    if (scene) {
        scene->hideLeftTime();
    }
}

void WorldManager::_addCoin(int addCoin)
{
    _coin += addCoin;
    auto scene = _getMainScene();
    if (scene) {
        scene->updateCoinLabel(_coin);
        if (addCoin < 0) {
            scene->showConsumeCoinEffect(abs(addCoin));
        }
    }
}

void WorldManager::_setCoin(int coin)
{
    _coin = coin;
    auto scene = _getMainScene();
    if (scene) {
        scene->updateCoinLabel(_coin);
    }
}

void WorldManager::_setGameActive(bool active)
{
    if (active) {
        Director::getInstance()->getScheduler()->schedule(CC_CALLBACK_1(WorldManager::_leftTimeUpdate, this), this, 1.0f, false, "update_time");
    } else {
        Director::getInstance()->getScheduler()->unschedule("update_time", this);
    }
}

void WorldManager::_setLeftTime(int leftTime)
{
    _leftTime = leftTime;
    auto scene = _getMainScene();
    if (scene) {
        scene->updateLeftTimeLabel(_leftTime);
    }
}
