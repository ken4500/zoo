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
#include "UserDataManager.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "WorldMap.h"
#include "MainScene.h"
#include "MultiBattleScene.h"
#include "CoinTree.h"


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
    _info = UserDataManager::getInstance()->getWorldInfo();
    _map   = nullptr;
    _enableNextAction = true;
    _isNetwork = false;
    _state = SceneState::Tutorial;
    if (SKIP_TUTORIAL || UserDataManager::getInstance()->isEndTutorial()
        || _info->level > 1) {
        _state = SceneState::Normal;
    }
}

WorldManager::~WorldManager()
{
}

#pragma - getter / setter

WorldInfo* WorldManager::getWorldInfo()
{
    return _info;
}

WorldMap* WorldManager::getMap()
{
    bool network = SceneManager::getInstance()->isNetwork();
    
    if (_map == nullptr || network ^ _isNetwork) {
        _isNetwork = network;
        if (network) {
            _createMultiBattlwMap();
        } else {
            _createMap();
        }
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

std::vector<CoinTree*> WorldManager::getCoinTreeList()
{
    return _coinTreeList;
}

int WorldManager::getGachaPrice()
{
    return _gacha->getPrice();
}

int WorldManager::getCoin()
{
    if (_isNetwork) {
        return _multiBattleCoin;
    } else {
        return UserDataManager::getInstance()->getCoin();
    }
}

void WorldManager::addCoin(int addCoin)
{
    if (_isNetwork) {
        _multiBattleCoin += addCoin;
    } else {
        UserDataManager::getInstance()->addCoin(addCoin);
    }
}

#pragma - public method

void WorldManager::resetData()
{
    UserDataManager::getInstance()->reset();
    sharedWorldManager = nullptr;
    delete this;
}

void WorldManager::lotteryGacha()
{
    if (_enableNextAction == false) {
        return;
    }
    int coin = getCoin();
    auto worldScene = SceneManager::getInstance()->getWorldScene();
    if (coin < _gacha->getPrice()) {
        std::string noticeMessage = "You don't have enough coin!\nPush the battle button";
        if (_isNetwork) {
            noticeMessage = "You don't have enough coin!\nCollect from coin tree";
        }
        worldScene->showNoticeView(noticeMessage, 0.0f, NULL);
        return;
    }
    
    if (_isNetwork) {
        _multiBattleCoin -= _gacha->getPrice();
    } else {
        UserDataManager::getInstance()->setWorldInfo(_info);
        UserDataManager::getInstance()->setCoin(coin - _gacha->getPrice());
    }
    worldScene->updateCoinLabel();
    _gacha->lotteryGacha(_info);
}

void WorldManager::releaseAnimal(Animal* animal, bool hit)
{
    if (_isNetwork == false) {
        UserDataManager::getInstance()->addAnimal(animal);
    }

    _animalList.push_back(animal);
    if (hit) {
        _map->releaseAnimal(animal, [this] {
            _checkAndRemoveAnimal();
            levelup();
        });
    } else {
        _map->releaseAnimal(animal, [this] {
            _checkAndRemoveAnimal();
        });
    }
}

WorldInfo* WorldManager::levelup()
{
    auto preWorldInfo = _info->copy();
    _info->levelUp();
    _gacha->setNewGacha(_info);
    
    // for tutorial
    if (_info->level == 2 && SKIP_TUTORIAL == false) {
        _startTutrialLevelupScene1();
    } else {
        SceneManager::getInstance()->getWorldScene()->levelUpEffect();
        if (_info->mapName == preWorldInfo->mapName) {
            _map->setCurrentWidth(_info->width, NULL);
            auto gachaImage = _gacha->getChildByName<Sprite*>("image");
            auto gachaLength = Length::scale(_info->width, 0.2);
            float gachaScale = getImageScale(gachaImage, gachaLength);
            _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));
        } else {
            _transitionMap(preWorldInfo, _info);
        }
    }
    
    // 小さすぎる動物を削除
    for (auto it = _animalList.begin(); it != _animalList.end(); ) {
        auto animal = (*it);
        if (animal->getHeight()->getMmLength() * 50 < _info->width->getMmLength()) {
            animal->runAction(Sequence::create(ScaleTo::create(0.5, 0), RemoveSelf::create(), NULL));
            it = _animalList.erase(it);
            if (_isNetwork == false) {
                UserDataManager::getInstance()->removeAnimal(animal);
            }
            continue;
        }
        it++;
    }
    
    if (_isNetwork == false) {
        UserDataManager::getInstance()->setWorldInfo(_info);
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
    if (UserDataManager::getInstance()->getLife() <= 0 || _enableNextAction == false) {
        return;
    }

    _state = SceneState::Battle;
    _beforeBattleCoin = getCoin();
    _setLeftTime(BATTLE_TIME);
    _enemyGenerater = new EnemyGenerater(_info);
    UserDataManager::getInstance()->decreateLife(1);
    _setGameActive(true);
    SoundManager::getInstance()->playBattleStartEffect();
    SoundManager::getInstance()->fadeOutBgm(0.5f);
    SoundManager::getInstance()->playBattleBgm();
    _enemyAnimalList = std::vector<Animal*>();
    _coinTreeList = std::vector<CoinTree*>();
    
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->showLeftTIme();
        scene->updateLifeLabel(0);
    }

    for (int i = 0; i < ENEMY_NUM; i++) {
        auto enemyAnimal = _enemyGenerater->generate();
        enemyAnimal->setIsEnmey(true);
        _enemyAnimalList.push_back(enemyAnimal);
        _map->addEnemyAnimalAtOutRandomPoint(enemyAnimal);
        enemyAnimal->deadCallback = [this, enemyAnimal]() {
            addCoin(enemyAnimal->getCoin());
            auto coinEffect = CSLoader::createNode("GetCoin.csb");
            coinEffect->setPosition(enemyAnimal->getCenterPosition());
            coinEffect->setZOrder(2000);
            coinEffect->setScale(1.0f / _map->getScale());
            auto text = coinEffect->getChildByName<ui::TextBMFont*>("text");
            text->setString(StringUtils::format("+%d", enemyAnimal->getCoin()));
            _map->addChild(coinEffect);
            auto timeLine = CSLoader::createTimeline("GetCoin.csb");
            coinEffect->runAction(timeLine);
            timeLine->play("get", false);
        };
    }
    
    _makeCoinTree();
    
    _map->hideGacha();
}

void WorldManager::startTutorial()
{
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->playNovel("novel_opening", [this]{
            _enableNextAction = false;
        }, false);
    }
}

void WorldManager::startTutorialBattle()
{
   SoundManager::getInstance()->playBattleStartEffect();
   SoundManager::getInstance()->fadeOutBgm(0.5f);
   SoundManager::getInstance()->playBattleBgm();
    auto scene = SceneManager::getInstance()->getMainScene();
    scene->playNovel("novel_tutorial_battle1", [this]{
        _enableNextAction = true;
    }, false, 2.0f);

    _state = SceneState::TutorialBattle;
    _startTutrialBattleScene1();
}

void WorldManager::endBattle(bool win, float showResultViewDelay)
{
    if (_state != SceneState::Battle && _state != SceneState::TutorialBattle) {
        return;
    }

    _endBattle();
    GameResult* result = new GameResult();
    result->resultState = (win) ? BattleState::Win : BattleState::Lose;
    result->playTime = BATTLE_TIME - _leftTime;
    result->getCoin = getCoin() - _beforeBattleCoin;
    
    auto mainScene = SceneManager::getInstance()->getMainScene();
    if (mainScene) {
        mainScene->showResultView(result, showResultViewDelay, CC_CALLBACK_0(WorldManager::_closeResult, this));
    }
}

void WorldManager::endBattle(bool win)
{
    endBattle(win, 1.0f);
}

void WorldManager::endResult()
{
    _map->showGacha();
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->showMenu();
    }
    _enableNextAction = true;
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

#pragma - private method

void WorldManager::_leftTimeUpdate(float dt)
{
    _leftTime--;
    if (_leftTime == 0) {
        endBattle(false, 0.0f);
    }
    _setLeftTime(_leftTime);
}

void WorldManager::_endBattle()
{
    if (_state == SceneState::Battle) {
        _state = SceneState::ShowResult;
    } else if (_state == SceneState::TutorialBattle) {
        _state = SceneState::TutorialGacha;
    }
    this->_setGameActive(false);
    _enableNextAction = false;
}

void WorldManager::_closeResult()
{
    SoundManager::getInstance()->fadeOutBgm(1.0f);
    SoundManager::getInstance()->playMainBgm();

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
            animal->repairHp();
            animal->startWalk();
        }
    }

    for (auto animal : _enemyAnimalList) {
        if (animal->isDead()) {
            animal->removeFromParent();
        } else {
            animal->escape();
        }
    }
    _enemyAnimalList = std::vector<Animal*>();

    for (auto tree : _coinTreeList) {
        tree->disappear();
    }
    _coinTreeList = std::vector<CoinTree*>();
    
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->hideLeftTime();
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
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->updateLeftTimeLabel(_leftTime);
    }
}

void WorldManager::_repairAllAnimalHp()
{
    for (auto animal : _animalList) {
        animal->repairHp();
    }
}

bool WorldManager::_checkAllEnemyDead()
{
    bool allDead = true;
    for (auto animal : _enemyAnimalList) {
        if (animal->isDead() == false) {
            allDead = false;
            break;
        }
    }
    return allDead;
}

void WorldManager::_transitionMap(WorldInfo* preWorldInfo, WorldInfo* newWorldInfo)
{
    auto newMap = dynamic_cast<WorldMap*>(CSLoader::createNode(newWorldInfo->mapName));
    newMap->initSize(newWorldInfo->maxWidth, preWorldInfo->width);

    auto mainScene = SceneManager::getInstance()->getMainScene();
    mainScene->transitionMap(newMap);
    _map->setCurrentWidth(newWorldInfo->width, NULL);
    newMap->setCurrentWidth(newWorldInfo->width, [this, newMap, preWorldInfo, newWorldInfo]{
        auto children = _map->getChildren();
        for(auto node : children) {
            if (node->getTag() == (int)MainSceneTag::Animal) {
                node->retain();
                node->removeFromParent();
                newMap->addChild(node);
                node->release();
                auto pos = node->getPosition() * preWorldInfo->maxWidth->getMmLength() / newWorldInfo->maxWidth->getMmLength();
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
        auto pos = _gacha->getPosition() * preWorldInfo->maxWidth->getMmLength() / newWorldInfo->maxWidth->getMmLength();
        _gacha->setPosition(pos);
        auto scale = _gacha->getScale() * preWorldInfo->maxWidth->getMmLength() / newWorldInfo->maxWidth->getMmLength();
        _gacha->setScale(scale);
        
        auto gachaImage = _gacha->getChildByName<Sprite*>("image");
        auto gachaLength = Length::scale(newWorldInfo->width, 0.2);
        float gachaScale = getImageScale(gachaImage, gachaLength);
        _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));

        _map = newMap;
    });
}

void WorldManager::_checkAndRemoveAnimal()
{
    if (_animalList.size() > MAX_ANIMAL_NUM) {
        float min = INT_MAX;
        std::vector<Animal*>::iterator minIt;
        for (auto it = _animalList.begin(); it != _animalList.end(); it++) {
            auto animal = *it;
            if (min > animal->getHeight()->getMmLength()) {
                min = animal->getHeight()->getMmLength();
                minIt = it;
            }
        }
        auto removeAnimal = *minIt;
        if (_isNetwork == false) {
            UserDataManager::getInstance()->removeAnimal(removeAnimal);
        }
        _animalList.erase(minIt);
        removeAnimal->escape();
    }
}

void WorldManager::_createMap()
{
    _info = UserDataManager::getInstance()->getWorldInfo();
    _map = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
    _map->initSize(_info->maxWidth, _info->width);

    if (_state == SceneState::Tutorial) {
        _enableNextAction = false;
    } else {
        _gacha = dynamic_cast<Gacha*>(CSLoader::createNode("Gacha.csb"));
        auto gachaImage = _gacha->getChildByName<Sprite*>("image");
        auto gachaLength = Length::scale(_info->width, 0.2);
        float gachaScale = getImageScale(gachaImage, gachaLength);
        _gacha->setScale(gachaScale);
        _gacha->setNewGacha(_info);
        _map->setGacha(_gacha);
    }

    auto animalList = UserDataManager::getInstance()->getAnimalList();
    if (animalList.size() == 0) {
        auto hero = Animal::CreateWithSpeceis("Hero");
        _map->addAnimal(hero, Vec2(0, -200));
        _animalList.push_back(hero);
        UserDataManager::getInstance()->addAnimal(hero);
    } else {
        for (Animal* animal : animalList) {
            _map->addAnimal(animal, getRadomPlace());
            _animalList.push_back(animal);
        }
    }
}

void WorldManager::_createMultiBattlwMap()
{
    _info = new WorldInfo(1);
    _info->network = true;
    _multiBattleCoin = INIT_MULTIBATTLE_COIN;
    _map = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
    _map->initSize(_info->maxWidth, _info->width);

    _gacha = dynamic_cast<Gacha*>(CSLoader::createNode("Gacha.csb"));
    auto gachaImage = _gacha->getChildByName<Sprite*>("image");
    auto gachaLength = Length::scale(_info->width, 0.2);
    float gachaScale = getImageScale(gachaImage, gachaLength);
    _gacha->setScale(gachaScale);
    _gacha->setNewGacha(_info);
    _map->setGacha(_gacha);

    _animalList = std::vector<Animal*>();
    _enemyAnimalList = std::vector<Animal*>();
}

void WorldManager::_makeCoinTree()
{
    auto tree = dynamic_cast<CoinTree*>(CSLoader::createNode("CoinTree.csb"));
    tree->setPosition((getRadomPlace() + Vec2(0, -100)) * 0.8f);
    tree->setLength(new Length(_info->width->getMmLength() * 0.2));
    _map->setCoinTree(tree);
    tree->sprout();
    _coinTreeList.push_back(tree);
}

#pragma - tutorial

void WorldManager::_startTutrialBattleScene1()
{
    auto enemyAnimal = Animal::CreateWithSpeceis("Ari");
    enemyAnimal->setIsEnmey(true);
    _enemyAnimalList.push_back(enemyAnimal);
    _map->addEnemyAnimalAtOutRandomPoint(enemyAnimal);
    auto scene = SceneManager::getInstance()->getMainScene();

    // 1匹目の敵と接触
    enemyAnimal->startFightCallback = [this, scene]() {
        scene->playNovel("novel_tutorial_battle2", NULL, false);
    };
    
    // 1匹目の敵死亡
    enemyAnimal->deadCallback = [this, scene]() {
        scene->playNovel("novel_tutorial_battle3", [this]{
            _startTutrialBattleScene2();
        }, false);
    };
}

void WorldManager::_startTutrialBattleScene2()
{
    auto scene = SceneManager::getInstance()->getMainScene();
    // 敵5匹追加
    for (int i = 0; i < 5; i++) {
        auto ant = Animal::CreateWithSpeceis("Ari");
        ant->setIsEnmey(true);
        _enemyAnimalList.push_back(ant);
        _map->addEnemyAnimalAtOutRandomPoint(ant);
        ant->deadCallback = [this, scene]{
            _repairAllAnimalHp();
            if (_checkAllEnemyDead()) {
                auto beetleSpecies = new Species("Kabutomushi");
                auto beetle = Animal::CreateWithSpeceis("Kabutomushi", beetleSpecies->getMaxHeight()->getMmLength());
                beetle->setIsEnmey(true);
                _enemyAnimalList.push_back(beetle);
                _map->addEnemyAnimal(beetle, Vec2(500, 0));
                beetle->killAnimalCallback = [this] {
                    _startTutrialBattleScene3();
                };
                scene->playNovel("novel_tutorial_battle4", NULL, false);
            }
        };
    }
}

void WorldManager::_startTutrialBattleScene3()
{
    auto scene = SceneManager::getInstance()->getMainScene();
    scene->playNovel("novel_tutorial_battle_end", [this]{
        _startTutrialGachScene1();
    }, false, 1.0f);
}

void WorldManager::_startTutrialGachScene1()
{
    _state =SceneState::TutorialGacha;
    _enableNextAction = false;

    for (auto animal : _animalList) {
        animal->reborn();
        animal->startWalk();
    }

    for (auto animal : _enemyAnimalList) {
        animal->removeFromParent();
    }
    _enemyAnimalList = std::vector<Animal*>();
    
    auto scene = SceneManager::getInstance()->getMainScene();
    scene->showMenu();
    
    _gacha = dynamic_cast<Gacha*>(CSLoader::createNode("Gacha.csb"));
    auto gachaImage = _gacha->getChildByName<Sprite*>("image");
    auto gachaLength = Length::scale(_info->width, 0.2);
    float gachaScale = getImageScale(gachaImage, gachaLength);
    _gacha->setScale(gachaScale);
    _gacha->setNewGacha(_info);
    _map->setGacha(_gacha);

    scene->playNovel("novel_tutorial_gacha1", [this]{
    }, false, 2.0f);
    
    _gacha->finishGachaCallback = [this] (){
        _startTutrialGachScene2();
    };
}

void WorldManager::_startTutrialGachScene2()
{
    _state = SceneState::Normal;
    UserDataManager::getInstance()->clearTutorial();
    _gacha->finishGachaCallback = NULL;
    _enableNextAction = false;
    auto scene = SceneManager::getInstance()->getMainScene();
    scene->playNovel("novel_tutorial_gacha2", [this]{
    }, false, 2.0f);
}

void WorldManager::_startTutrialLevelupScene1()
{
    auto scene = SceneManager::getInstance()->getMainScene();
    _enableNextAction = false;
    scene->playNovel("novel_tutorial_levelup1", [this]{
        _startTutrialLevelupScene2();
    }, false);

}

void WorldManager::_startTutrialLevelupScene2()
{
    _enableNextAction = false;
    auto scene = SceneManager::getInstance()->getMainScene();
    scene->levelUpEffect();
    _map->setCurrentWidth(_info->width, NULL);
    auto gachaImage = _gacha->getChildByName<Sprite*>("image");
    auto gachaLength = Length::scale(_info->width, 0.2);
    float gachaScale = getImageScale(gachaImage, gachaLength);
    _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));
    scene->playNovel("novel_tutorial_levelup2", NULL, false, 2.5f);
}
