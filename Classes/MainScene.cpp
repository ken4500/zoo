#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
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

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // "scene" is an autorelease object
    auto scene = Scene::create();
    
    // "layer" is an autorelease object
    auto layer = MainScene::create();
    layer->setName("main scene");

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

    _rootNode = CSLoader::createNode("MainScene.csb");
    _rootNode->setAnchorPoint(Vec2(0.5f, 0.5f));
    _rootNode->setPosition(Vec2::ZERO);
    _rootNode->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _timeLeftLabel = _rootNode->getChildByName<ui::TextBMFont*>("timeLabel");

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
    }
    
    updateCoinLabel(WorldManager::getInstance()->getCoin());
    updateLifeLabel(WorldManager::getInstance()->getLife());
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

void MainScene::levelUpEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("zoomout1", false);
    _timeline->setLastFrameCallFunc([](){ WorldManager::getInstance()->setEnableNextAction(true); });
}

void MainScene::hideMenu()
{
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(false);
    _menuNode->runAction(FadeOut::create(0.5f));
}

void MainScene::showMenu()
{
    auto battleButton = _menuNode->getChildByName<ui::Button*>("battleButton");
    battleButton->setEnabled(true);
    _menuNode->runAction(FadeIn::create(0.5f));
}

void MainScene::showLeftTIme()
{
    _timeLeftLabel->setOpacity(0);
    _timeLeftLabel->setVisible(true);
    _timeLeftLabel->runAction(FadeIn::create(0.5f));
}

void MainScene::hideLeftTime()
{
    _timeLeftLabel->runAction(FadeOut::create(0.5f));
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
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/novel.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& novelJson = document[novelId.c_str()];

    WorldManager::getInstance()->setEnableNextAction(false);

    // pause map
    _pauseRecursive(_map);

    // 会話終了後のコールバック
    auto preCallbackFunc = [this]() {
        auto novel = getChildByName<NovelLayer*>("novel");
        if (novel) {
            novel->removeFromParent();
        }
        WorldManager::getInstance()->setEnableNextAction(true);
        
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

void MainScene::updateCoinLabel(int coin)
{
    _coinLabel->setString(StringUtils::format("x %d", coin));
}

void MainScene::updateLifeLabel(int life)
{
    _lifeLabel->setString(StringUtils::format("x %d", life));
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

void MainScene::showResultView(GameResult* result, float delay, std::function<void ()> closeCallback)
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

void MainScene::_setupDebugMenu()
{
    if (DEBUG_BUTOTN_APPEAR == false) {
        return;
    }

    int menuNum = 3;
    auto size = Director::getInstance()->getVisibleSize();
    auto dummyImage = Sprite::create("ui/debug_button.png");
    auto imageSize = dummyImage->getContentSize();
    auto menuHeight = imageSize.height * menuNum;

    auto debugMenu = Node::create();
    debugMenu->setPosition(Vec2(size.width, size.height - menuHeight));
    _rootNode->addChild(debugMenu);

    
    auto repairLife = DebugButton::create("repair life", [this]() { WorldManager::getInstance()->addLife(5);});
    repairLife->setAnchorPoint(Vec2(1.0f, 0.0f));
    repairLife->setPosition(Vec2(0, 0));
    debugMenu->addChild(repairLife, 1);
    
    auto addCoin = DebugButton::create("add coin", [this]() { WorldManager::getInstance()->addCoin(5);});
    addCoin->setAnchorPoint(Vec2(1.0f, 0.0f));
    addCoin->setPosition(Vec2(0, 80));
    debugMenu->addChild(addCoin, 1);

    auto levelup = DebugButton::create("levelup", [this]() { WorldManager::getInstance()->levelup();});
    levelup->setAnchorPoint(Vec2(1.0f, 0.0f));
    levelup->setPosition(Vec2(0, 160));
    debugMenu->addChild(levelup, 1);
    
    static bool isOpenDebugMenu = true;
    auto toggleButton = Button::create("ui/toggle.png");
    toggleButton->setAnchorPoint(Vec2(0.5f, 0.5f));
    toggleButton->setScale(0.4f);
    toggleButton->setPosition(Vec2(-imageSize.width/2, -40));
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
