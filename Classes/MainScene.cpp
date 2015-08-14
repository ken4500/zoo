#include "MainScene.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "ScaleBar.h"
#include "ScaleBarReader.h"
#include "WorldMap.h"
#include "WorldMapReader.h"
#include "WorldManager.h"
#include "Animal.h"
#include "NovelLayer.h"
#include "ResultLayer.h"
#include "NoticeLayer.h"
#include "DebugButton.h"
#include "UserDataManager.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "MenuLayer.h"
#include "CoinTreeReader.h"
#include "BookReader.h"
#include "HpGauge.h"
#include "HpGaugeReader.h"
#include "ShopReader.h"
#include "TransmigrationReader.h"
#include "LackLife.h"
#include "LackLifeReader.h"
#include "NetworkingWrapper.h"

USING_NS_CC;
using namespace cocos2d::plugin;
using namespace cocostudio::timeline;

MainScene::MainScene() :
_preWeight(0)
{
    _loadNovelJson();
}
MainScene::~MainScene()
{
}

Scene* MainScene::createScene()
{
    // "scene" is an autorelease object
    auto scene = Scene::create();
    
    // "layer" is an autorelease object
    auto layer = MainScene::create();
    layer->setName("world scene");

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto displaySize = Director::getInstance()->getVisibleSize();

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("GachaReader", (ObjectFactory::Instance) GachaReader::getInstance);
    instance->registReaderObject("ScaleBarReader", (ObjectFactory::Instance) ScaleBarReader::getInstance);
    instance->registReaderObject("WorldMapReader", (ObjectFactory::Instance) WorldMapReader::getInstance);
    instance->registReaderObject("CoinTreeReader", (ObjectFactory::Instance) CoinTreeReader::getInstance);
    instance->registReaderObject("BookReader", (ObjectFactory::Instance) BookReader::getInstance);
    instance->registReaderObject("HpGaugeReader", (ObjectFactory::Instance) HpGaugeReader::getInstance);
    instance->registReaderObject("ShopReader", (ObjectFactory::Instance) ShopReader::getInstance);
    instance->registReaderObject("TransmigrationReader", (ObjectFactory::Instance) TransmigrationReader::getInstance);
    instance->registReaderObject("LackLifeReader", (ObjectFactory::Instance) LackLifeReader::getInstance);

    _rootNode = CSLoader::createNode("MainScene.csb");
    Size size = Director::getInstance()->getVisibleSize();
    _rootNode->setContentSize(size);
    ui::Helper::doLayout(_rootNode);
    
    _timeBack = _rootNode->getChildByName("time_back");
    _timeLeftLabel = _timeBack->getChildByName<ui::TextBMFont*>("timeLabel");
    _countUpAction = nullptr;

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->setLocalZOrder(-1);
    _rootNode->addChild(_map);
    
    _endButton = _rootNode->getChildByName<ui::Button*>("endButton");
    if (DEBUG_MODE) {
        _endButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushEndButton, this));
    } else {
        _endButton->setVisible(false);
    }

    _menuNode = _rootNode->getChildByName<Node*>("menuNode");
    _menuNode->setCascadeOpacityEnabled(true);
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushBattleButton, this));
    _coinLabel = _menuNode->getChildByName<ui::TextBMFont*>("coinText");
    _lifeLabel = _menuNode->getChildByName<ui::TextBMFont*>("hartText");
    _repairTimeLabel = _menuNode->getChildByName<ui::TextBMFont*>("repairTimeText");
    _levelBack    = _rootNode->getChildByName("levelBack");
    _levelLabel   = _levelBack->getChildByName<ui::TextBMFont*>("levelLabel");
    _weightLabel  = _rootNode->getChildByName<ui::TextBMFont*>("weightLabel");
    _weightImage  = _rootNode->getChildByName<Sprite*>("weightImage");
    _diamondLabel = _menuNode->getChildByName<ui::TextBMFont*>("diamondText");
    _diamonImage  = _menuNode->getChildByName<Sprite*>("diamond");

    _otherMenuButton = _menuNode->getChildByName<ui::Button*>("otherMenu");
    _otherMenuButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushOtherMenuButton, this));
    _scaleBar = _rootNode->getChildByName<ScaleBar*>("scaleBar");
    _hpGauge  = _rootNode->getChildByName<HpGauge*>("hpGauge");

    _setupDebugMenu();
    _setupAdColony();

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("MainScene.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    addChild(_rootNode);

    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    
    if (WorldManager::getInstance()->getSceneState() == SceneState::Tutorial) {
        WorldManager::getInstance()->startTutorial();
    } else {
        SoundManager::getInstance()->playMainBgm();
    }
    
    updateLevelLabel();
    updateCoinLabel();
    updateDiamondLabel();
    updateLifeLabel(0);
    _preWeight = WorldManager::getInstance()->getTotalWeight();
    _weightLabel->setString(StringUtils::format("%.02f %s", _preWeight.getWeight(), _preWeight.getUnitStr().c_str()));
    
    Director::getInstance()->getScheduler()->schedule(CC_CALLBACK_1(MainScene::updateLifeLabel, this), this, 1.0f, false, "update_life");
}

void MainScene::update(float dt)
{
    Layer::update(dt);
}

void MainScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        return true;
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

#pragma - public method

void MainScene::levelUpEffect(std::function<void()> callback)
{
    SoundManager::getInstance()->playLevelupEffect();
    updateLevelLabel();
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("zoomout1", false);
    _timeline->setLastFrameCallFunc([this, callback](){
        if (callback) {
            callback();
        }
        _timeline->clearLastFrameCallFunc();
    });
    _scaleBar->updateScale(true);
}

void MainScene::hideMenu()
{
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(false);
    _menuNode->runAction(FadeOut::create(0.2f));
    _levelBack->runAction(FadeOut::create(0.2f));
    _weightLabel->runAction(FadeOut::create(0.2f));
    _otherMenuButton->setEnabled(false);
    _scaleBar->runAction(FadeOut::create(0.2f));
    _weightImage->runAction(FadeOut::create(0.2f));
}

void MainScene::showMenu()
{
    updateCoinLabel();
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(true);
    _menuNode->runAction(FadeIn::create(0.5f));
    _levelBack->runAction(FadeIn::create(0.5f));
    _weightLabel->runAction(FadeIn::create(0.5f));
    _otherMenuButton->setEnabled(true);
    _scaleBar->runAction(FadeIn::create(0.5f));
    _weightImage->runAction(FadeIn::create(0.5f));
}

void MainScene::showBattleMenu()
{
    _timeBack->setOpacity(0);
    _timeBack->setVisible(true);
    _timeBack->runAction(FadeIn::create(0.5f));
    
    _hpGauge->setOpacity(0);
    _hpGauge->setVisible(true);
    _hpGauge->runAction(FadeIn::create(0.5f));
    float maxHp = WorldManager::getInstance()->getMaxHp();
    float hp    = WorldManager::getInstance()->getHp();
    _hpGauge->setInitHp(maxHp, hp);

    if (DEBUG_MODE) {
        _endButton->setOpacity(0);
        _endButton->setVisible(true);
        _endButton->runAction(FadeIn::create(0.2f));
    }
}

void MainScene::hideBattleMenu()
{
    _timeBack->runAction(FadeOut::create(0.2f));
    _hpGauge->runAction(FadeOut::create(0.2f));
    if (DEBUG_MODE) {
        _endButton->runAction(FadeOut::create(0.2f));
    }
}

void MainScene::updateLevelLabel()
{
    int level = WorldManager::getInstance()->getWorldInfo()->level;
    _levelLabel->setString(StringUtils::format("%s %d", CCLS1("LEVEL",_levelLabel), level));
}

void MainScene::updateWeightLabel(Weight weight)
{
    if (_countUpAction) {
        _countUpAction->stop();
        _countUpAction->release();
    }

    int devision = 10;
    float duration = 1.0f / devision;

    // make count up animation
    float diff = weight.getMgWeight() - _preWeight.getMgWeight();
    Weight incre = Weight(diff / devision);
    Vector<FiniteTimeAction*> actionList;
    for (int i = 0; i < devision; i++) {
        actionList.pushBack(CallFunc::create([this, duration, incre]{
            _preWeight = _preWeight + incre;
            _weightLabel->setString(StringUtils::format("%.02f %s", _preWeight.getWeight(), _preWeight.getUnitStr().c_str()));
        }));
        actionList.pushBack(DelayTime::create(duration));
    }
    
    float w = weight.getWeight();
    std::string u = weight.getUnitStr();
    actionList.pushBack(CallFunc::create([this, w, u, weight]{
        _weightLabel->setString(StringUtils::format("%.02f %s", w, u.c_str()));
        _preWeight = weight;
    }));
    
    _countUpAction = Sequence::create(actionList);
    _countUpAction->retain();
    _weightLabel->runAction(_countUpAction);
}

void MainScene::transitionMap(WorldMap* newMap)
{
    auto displaySize = Director::getInstance()->getVisibleSize();
    newMap->setAnchorPoint(Vec2(0.5f, 0.5f));
    newMap->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    newMap->setLocalZOrder(-2);
    _rootNode->addChild(newMap);
    newMap->runAction(Sequence::create(
        DelayTime::create(1.0f),
        CallFunc::create([newMap]{
            newMap->setLocalZOrder(-1);
        }),
        NULL
    ));
    _map->runAction(Sequence::create(
        FadeOut::create(1.0f),
        RemoveSelf::create(),
        NULL
    ));
    _map = newMap;
}

void MainScene::playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton, float delay)
{
    runAction(Sequence::create(
        DelayTime::create(delay),
        CallFunc::create([this, novelId, callback, apearSkipButton] {
            playNovel(novelId, callback, apearSkipButton);
        }),
        NULL
    ));
}

void MainScene::playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton)
{
    // すでに読んだので再生しない
    bool alreadyRead = UserDataManager::getInstance()->alreadyRead(novelId);
    if (alreadyRead) {
        if (callback) {
            callback();
        }
        return;
    }
    
    // 存在しないので再生しない
    if (_novelLangType != UserDataManager::getInstance()->getLanguage()) {
        _loadNovelJson();
    }
    if (_novelDocument.HasMember(novelId.c_str()) == false) {
        if (callback) {
            callback();
        }
        return;
    }
    
    rapidjson::Value& novelJson = _novelDocument[novelId.c_str()];
    
    // pause map
    _pauseRecursive(_map);

    // 会話終了後のコールバック
    auto preCallbackFunc = [this]() {
        auto novel = getChildByName<NovelLayer*>("novel");
        if (novel) {
            novel->removeFromParent();
        }
        
        // resume map
        _resumeRecursive(_map);
    };
    
    // 会話生成&開始
    auto novel = NovelLayer::create(novelJson, 100, false, preCallbackFunc, callback);
    novel->setPosition(Vec2(0, 0));
    novel->setName("novel");
    if (apearSkipButton == false && DEBUG_MODE == false) {
        novel->removeSkipButton();
    }
    addChild(novel);
    novel->playNovel();

    UserDataManager::getInstance()->setAlreadyRead(novelId);
}

void MainScene::updateDiamondLabel()
{
    int diamondNum = UserDataManager::getInstance()->getDiamondNum();
    _diamondLabel->setString(StringUtils::format("x %d", diamondNum));
}

void MainScene::updateCoinLabel()
{
    _coinLabel->setString(StringUtils::format("x %lld", WorldManager::getInstance()->getCoin()));
}

void MainScene::updateLifeLabel(float dt)
{
    auto manager = UserDataManager::getInstance();
    int maxLife = manager->getMaxLife();
    int life = manager->getLife();
    int repirTime = manager->getNextRepairLifeTime();
    _lifeLabel->setString(StringUtils::format("%d / %d", life, maxLife));
    
    _repairTimeLabel->setString(StringUtils::format("%01d:%02d", int(repirTime / 60), repirTime % 60));
}

void MainScene::updateLeftTimeLabel(int leftTime)
{
    _timeLeftLabel->setString(to_string(leftTime));
}

void MainScene::updateHpGauge(float hp)
{
    _hpGauge->setHp(hp);
}

void MainScene::showConsumeCoinEffect(int decreaseCoin)
{
}

void MainScene::showNoticeView(std::string message, float delay, std::function<void ()> closeCallback)
{
    
    runAction(Sequence::create(
        DelayTime::create(delay),
        CallFunc::create([this, message, closeCallback ]{
            auto layer = NoticeLayer::createWithMessage(message);
            layer->closeNoticeCallback = closeCallback;
            this->addChild(layer);
        }),
        NULL
    ));
}

void MainScene::showResultView(GameResult result, float delay, std::function<void ()> closeCallback)
{
    runAction(Sequence::create(
        DelayTime::create(delay),
        CallFunc::create([this, result, closeCallback ]{
            auto layer = ResultLayer::createWithResult(result);
            layer->closeResultCallback = closeCallback;
            this->addChild(layer);
        }),
        NULL
    ));
}

void MainScene::battleStartEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("battle_start", false);
}

void MainScene::showLackLifeNotice()
{
    auto layer = (LackLife*)CSLoader::createNode("LackLife.csb");
    addChild(layer);
    layer->pushedYesCallback = [this]{
        _adcolonyAds->showV4VC(ADCOLONY_ZONE_ID_1.c_str(), false, false);
    };
}

#pragma - adcolony

void MainScene::onAdColonyAdAvailabilityChange(bool success, const char* zoneID, const char* msg)
{
  CCLOG("onAdColonyAdAvailabilityChange, success : %d, zoneID: %s msg : %s", success, zoneID, msg);

  if (success) {
  }
}

void MainScene::onAdColonyV4VCReward(bool success, const char* name,int points)
{
    CCLOG("onAdColonyV4VCReward, success:%d name:%s points:%d", success, name, points);
    SoundManager::getInstance()->resumeBgm();

    if(success){
        UserDataManager::getInstance()->repairLife();
        this->updateLifeLabel(0);
        showNoticeView(CCLS("NOTICE_REPAIR_LIFE"), 0, NULL);
    }
}

void MainScene::onAdColonyAdStarted()
{
    CCLOG("onAdColonyV4VCReward");
    SoundManager::getInstance()->pauseBgm();
}

void MainScene::onAdColonyAdAttemptFinished(bool adShown)
{
    CCLOG("onAdColonyAdAttemptFinished adShown:%d", adShown);
    if (adShown == false) {
        showNoticeView(CCLS("NOTICE_REPAIR_LIFE_FAILED"), 0, NULL);
    }
}

#pragma - private method

void MainScene::_setupAdColony()
{
    auto uuid = NetworkingWrapper::getUUID();
    
    //Load plugin
    _adcolonyAds = AdColonyAgent::getInstance();
    //set custom id, used for V4VC
    _adcolonyAds->setCustomID(uuid);
    //configure adcolony
    std::vector<std::string> zoneIDs =  { ADCOLONY_ZONE_ID_1 };
    _adcolonyAds->configure("", ADCOLONY_APP_ID.c_str(), zoneIDs, this);
}

static bool isOpenDebugMenu = false;
void MainScene::_setupDebugMenu()
{
    if (DEBUG_MODE == false) {
        return;
    }

    // メニューを増やしたいときは数を増やしてね
    int menuNum = 7;

    auto size = Director::getInstance()->getVisibleSize();
    auto dummyImage = Sprite::create("ui/debug_button.png");
    auto imageSize = dummyImage->getContentSize();
    auto menuHeight = imageSize.height * menuNum;

    auto debugMenu = Node::create();
    if (isOpenDebugMenu) {
        debugMenu->setPosition(Vec2(size.width, size.height - menuHeight));
    } else {
        debugMenu->setPosition(Vec2(size.width, size.height));
    }
    _rootNode->addChild(debugMenu);

    
    auto repairLife = DebugButton::create("体力回復", [this]() {
        UserDataManager::getInstance()->repairLife(); this->updateLifeLabel(0);
    });
    repairLife->setAnchorPoint(Vec2(1.0f, 0.0f));
    repairLife->setPosition(Vec2(0, 0));
    debugMenu->addChild(repairLife, 1);
    
    auto addCoin = DebugButton::create("コイン追加", [this]() {
        UserDataManager::getInstance()->addCoin(WorldManager::getInstance()->getGachaPrice() * 5);
        this->updateCoinLabel();
    });
    addCoin->setAnchorPoint(Vec2(1.0f, 0.0f));
    addCoin->setPosition(Vec2(0, 80));
    debugMenu->addChild(addCoin, 1);

    auto levelup = DebugButton::create("レベルアップ", [this]() { WorldManager::getInstance()->levelup();});
    levelup->setAnchorPoint(Vec2(1.0f, 0.0f));
    levelup->setPosition(Vec2(0, 160));
    debugMenu->addChild(levelup, 1);

    auto resetData = DebugButton::create("データリセット", [this]() {
        PurgeCCLocalizedStringCached();
        WorldManager::getInstance()->resetData();
        SceneManager::getInstance()->resetMainScene();
    });
    resetData->setAnchorPoint(Vec2(1.0f, 0.0f));
    resetData->setPosition(Vec2(0, 240));
    debugMenu->addChild(resetData, 1);

    auto endTutorial = DebugButton::create("チュートリアルなしリセット", [this]() {
        PurgeCCLocalizedStringCached();
        WorldManager::getInstance()->resetData();
        UserDataManager::getInstance()->clearTutorial();
        SceneManager::getInstance()->resetMainScene();
    });
    endTutorial->setAnchorPoint(Vec2(1.0f, 0.0f));
    endTutorial->setPosition(Vec2(0, 320));
    debugMenu->addChild(endTutorial, 1);

    auto test = DebugButton::create("必ず当たり", [this]() {
        auto gacha = WorldManager::getInstance()->getGacha();
        UserDataManager::getInstance()->addCoin(gacha->getPrice());
        this->updateCoinLabel();
        
        gacha->setDebugMode(true);
        WorldManager::getInstance()->lotteryGacha();
        gacha->setDebugMode(false);
    });
    test->setAnchorPoint(Vec2(1.0f, 0.0f));
    test->setPosition(Vec2(0, 400));
    debugMenu->addChild(test, 1);
    
    auto addDiamond = DebugButton::create("ダイアモンド追加", [this]() {
        UserDataManager::getInstance()->addDiamondNum(50);
        this->updateDiamondLabel();
    });
    addDiamond->setAnchorPoint(Vec2(1.0f, 0.0f));
    addDiamond->setPosition(Vec2(0, 480));
    debugMenu->addChild(addDiamond, 1);


    auto toggleButton = Button::create("ui/toggle.png");
    toggleButton->setAnchorPoint(Vec2(0.5f, 0.5f));
    toggleButton->setScale(0.4f);
    toggleButton->setPosition(Vec2(-imageSize.width/2, -40));
    if (isOpenDebugMenu == false) {
        toggleButton->setFlippedY(true);
    }
    toggleButton->addTouchEventListener(
        [this, size, menuHeight, debugMenu, toggleButton](Ref* sender,Widget::TouchEventType type){
            if (type == Widget::TouchEventType::ENDED) {
                if (isOpenDebugMenu) {
                    isOpenDebugMenu = false;
                    toggleButton->setFlippedY(true);
                    debugMenu->runAction(EaseOut::create(MoveTo::create(0.3f, Vec2(size.width, size.height)), 2));
                } else {
                    isOpenDebugMenu = true;
                    toggleButton->setFlippedY(false);
                    debugMenu->runAction(EaseOut::create(MoveTo::create(0.3f, Vec2(size.width, size.height - menuHeight)), 2));
                }
            }
        }
    );
    debugMenu->addChild(toggleButton, 1);
    
    auto debugLabel = ui::Text::create("DEBUG", "", 24);
    debugLabel->setColor(Color3B::WHITE);
    debugLabel->setAnchorPoint(Vec2(0.0f, 0.5f));
    debugLabel->setPosition(Vec2(-imageSize.width/2 + 40, -40));
    debugMenu->addChild(debugLabel);
    debugMenu->setCascadeOpacityEnabled(true);
    debugMenu->setOpacity(200);
}

void MainScene::_pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.7f * 0.9f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, 0.7f),
            CallFunc::create([this]{
                WorldManager::getInstance()->endBattle(false, 0);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 0.7f));
    }
}

void MainScene::_pushBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (WorldManager::getInstance()->enableNextAction() == false) {
        return;
    }

    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.9f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, 1),
            CallFunc::create([this]{
                if (WorldManager::getInstance()->getSceneState() == SceneState::Tutorial) {
                    WorldManager::getInstance()->startTutorialBattle();
                } else {
                    WorldManager::getInstance()->startBattle();
                }
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void MainScene::_pushOtherMenuButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (WorldManager::getInstance()->enableNextAction() == false) {
        return;
    }

    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->setEnabled(false);
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, 1),
            CallFunc::create([this, button]{
                button->setEnabled(true);
                auto layer = MenuLayer::create();
                this->addChild(layer);
                layer->closeCallback = [this]{
                    _updateLanguage();
                };
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void MainScene::_pauseRecursive(Node* node)
{
    auto children = node->getChildren();
    for(Vector<Node*>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->pause();
        _pauseRecursive(*it);
    }
}

void MainScene::_resumeRecursive(Node* node)
{
    auto children = node->getChildren();
    for(Vector<Node*>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->resume();
        _resumeRecursive(*it);
    }
}

void MainScene:: _updateLanguage()
{
    int level = WorldManager::getInstance()->getWorldInfo()->level;
    _levelLabel->setString(StringUtils::format("%s %d", CCLS1("LEVEL",_levelLabel), level));
}

void MainScene::_loadNovelJson()
{
    auto lang = UserDataManager::getInstance()->getLanguage();
    CCLOG("LOAD NOVEL JSON");
    if (lang == LanguageType::JAPANESE) {
        CCLOG("日本語");
    } else {
        CCLOG("英語");
    }
    auto file = CCLS("NOVEL_FILE_NAME");
    auto jsonStr = FileUtils::getInstance()->getStringFromFile(file);
    _novelDocument.Parse<0>(jsonStr.c_str());
    _novelLangType = lang;
}
