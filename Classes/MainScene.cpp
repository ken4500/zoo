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

USING_NS_CC;

using namespace cocostudio::timeline;

MainScene::MainScene() :
_preWeight(0)
{
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

    _rootNode = CSLoader::createNode("MainScene.csb");
    _timeLeftLabel = _rootNode->getChildByName<ui::TextBMFont*>("timeLabel");
    _timeLeftLabel->setPosition(Vec2(_timeLeftLabel->getPosition().x, displaySize.height * 0.95f));
    _countUpAction = nullptr;

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->setLocalZOrder(-1);
    _rootNode->addChild(_map);

    _menuNode = _rootNode->getChildByName<Node*>("menuNode");
    _menuNode->setCascadeOpacityEnabled(true);
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushBattleButton, this));
    _coinLabel = _menuNode->getChildByName<ui::TextBMFont*>("coinText");
    _lifeLabel = _menuNode->getChildByName<ui::TextBMFont*>("hartText");
    _repairTimeLabel = _menuNode->getChildByName<ui::TextBMFont*>("repairTimeText");
    _levelLabel = _rootNode->getChildByName<ui::TextBMFont*>("levelLabel");
    _levelLabel->setPosition(Vec2(_levelLabel->getPosition().x, displaySize.height * 0.98f));
    _weightLabel = _rootNode->getChildByName<ui::TextBMFont*>("weightLabel");

    _endButton = _rootNode->getChildByName<ui::Button*>("endButton");
    _endButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushEndButton, this));
    _endButton->setPosition(Vec2(_endButton->getPosition().x, displaySize.height * 0.98f));
    auto otherMenuButton = _menuNode->getChildByName<ui::Button*>("otherMenu");
    otherMenuButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushOtherMenuButton, this));

    _scaleBar = _rootNode->getChildByName<ScaleBar*>("scaleBar");

    _setupDebugMenu();

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
    _timeline->setLastFrameCallFunc([callback](){
        if (callback) {
            callback();
        }
    });
    _scaleBar->updateScale(true);
}

void MainScene::hideMenu()
{
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(false);
    _menuNode->runAction(FadeOut::create(0.5f));
    _levelLabel->runAction(FadeOut::create(0.5f));
    _weightLabel->runAction(FadeOut::create(0.5f));
}

void MainScene::showMenu()
{
    updateCoinLabel();
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(true);
    _menuNode->runAction(FadeIn::create(0.5f));
    _levelLabel->runAction(FadeIn::create(0.5f));
    _weightLabel->runAction(FadeIn::create(0.5f));
}

void MainScene::showLeftTIme()
{
    _timeLeftLabel->setOpacity(0);
    _timeLeftLabel->setVisible(true);
    _timeLeftLabel->runAction(FadeIn::create(0.5f));
    
    _endButton->setOpacity(0);
    _endButton->setVisible(true);
    _endButton->runAction(FadeIn::create(0.5f));
}

void MainScene::hideLeftTime()
{
    _timeLeftLabel->runAction(FadeOut::create(0.5f));
    _endButton->runAction(FadeOut::create(0.5f));
}

void MainScene::updateLevelLabel()
{
    int level = WorldManager::getInstance()->getWorldInfo()->level;
    _levelLabel->setString(StringUtils::format("LEVEL%d", level));
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
    // 再生しない
    auto file = CCLS("NOVEL_FILE_NAME");
    auto jsonStr = FileUtils::getInstance()->getStringFromFile(file);
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& novelJson = document[novelId.c_str()];
    
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
    if (apearSkipButton == false && APPEAR_SKIP_BUTTON == false) {
        novel->removeSkipButton();
    }
    addChild(novel);
    novel->playNovel();

}

void MainScene::updateCoinLabel()
{
    _coinLabel->setString(StringUtils::format("x %ld", WorldManager::getInstance()->getCoin()));
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

void MainScene::showConsumeCoinEffect(int decreaseCoin)
{
    auto text = TextBMFont::create(StringUtils::format("-%d", decreaseCoin), "font/zoo_font2.fnt");
    text->setAnchorPoint(_coinLabel->getAnchorPoint());
    text->setPosition(_coinLabel->getPosition() + Vec2(0, 20));
    text->setZOrder(-1);
    text->setOpacity(200);
    _menuNode->addChild(text);
    text->runAction(Sequence::create(
        Spawn::create(
            MoveBy::create(0.75f, Vec2(0, 200)),
            FadeOut::create(0.75f),
            NULL
        ),
        RemoveSelf::create(),
        NULL
    ));
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

#pragma - private method

static bool isOpenDebugMenu = false;
void MainScene::_setupDebugMenu()
{
    if (DEBUG_BUTOTN_APPEAR == false) {
        return;
    }

    // メニューを増やしたいときは数を増やしてね
    int menuNum = 5;

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

    
    auto repairLife = DebugButton::create("repair life", [this]() { UserDataManager::getInstance()->repairLife(); this->updateLifeLabel(0);});
    repairLife->setAnchorPoint(Vec2(1.0f, 0.0f));
    repairLife->setPosition(Vec2(0, 0));
    debugMenu->addChild(repairLife, 1);
    
    auto addCoin = DebugButton::create("add coin", [this]() {
        UserDataManager::getInstance()->addCoin(WorldManager::getInstance()->getGachaPrice() * 5);
        this->updateCoinLabel();
    });
    addCoin->setAnchorPoint(Vec2(1.0f, 0.0f));
    addCoin->setPosition(Vec2(0, 80));
    debugMenu->addChild(addCoin, 1);

    auto levelup = DebugButton::create("levelup", [this]() { WorldManager::getInstance()->levelup();});
    levelup->setAnchorPoint(Vec2(1.0f, 0.0f));
    levelup->setPosition(Vec2(0, 160));
    debugMenu->addChild(levelup, 1);

    auto resetData = DebugButton::create("reset data", [this]() {
        WorldManager::getInstance()->resetData();
        SceneManager::getInstance()->resetMainScene();
    });
    resetData->setAnchorPoint(Vec2(1.0f, 0.0f));
    resetData->setPosition(Vec2(0, 240));
    debugMenu->addChild(resetData, 1);

    auto endTutorial = DebugButton::create("reset without tutorial", [this]() {
        WorldManager::getInstance()->resetData();
        UserDataManager::getInstance()->clearTutorial();
        SceneManager::getInstance()->resetMainScene();
    });
    endTutorial->setAnchorPoint(Vec2(1.0f, 0.0f));
    endTutorial->setPosition(Vec2(0, 320));
    debugMenu->addChild(endTutorial, 1);



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
}

void MainScene::_pushBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == cocos2d::ui::Widget::TouchEventType::ENDED) {
        if (WorldManager::getInstance()->enableNextAction() == false) {
            return;
        }

        if (UserDataManager::getInstance()->getLife() <= 0) {
            showNoticeView(CCLS("NOTICE_LACK_LIFE"), 0, NULL);
            return;
        }
        if (WorldManager::getInstance()->getSceneState() == SceneState::Tutorial) {
            hideMenu();
            _battleStartEffect();
            WorldManager::getInstance()->startTutorialBattle();
        } else {
            hideMenu();
            _battleStartEffect();
            WorldManager::getInstance()->startBattle();
        }
    }
}

void MainScene::_pushOtherMenuButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == cocos2d::ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        auto layer = MenuLayer::create();
        this->addChild(layer);
    }
}

void MainScene::_pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == cocos2d::ui::Widget::TouchEventType::ENDED) {
        WorldManager::getInstance()->endBattle(false, 0);
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
        _pauseRecursive(*it);
    }
}

void MainScene::_battleStartEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("battle_start", false);
}
