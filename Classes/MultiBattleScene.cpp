#include "MultiBattleScene.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "ScaleBar.h"
#include "ScaleBarReader.h"
#include "WorldMap.h"
#include "WorldMapReader.h"
#include "WorldManager.h"
#include "Animal.h"
#include "ResultLayer.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "NoticeLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MultiBattleScene::createScene()
{
    // "scene" is an autorelease object
    auto scene = Scene::create();
    
    // "layer" is an autorelease object
    auto layer = MultiBattleScene::create();
    layer->setName("world scene");

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MultiBattleScene::init()
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

    _rootNode = CSLoader::createNode("MultiBattleScene.csb");
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
    _coinLabel = _menuNode->getChildByName<ui::TextBMFont*>("coinText");

    _endButton = _rootNode->getChildByName<ui::Button*>("endButton");
    _endButton->addTouchEventListener(CC_CALLBACK_2(MultiBattleScene::_pushEndButton, this));


    // load the character animation timeline
    _timeline = CSLoader::createTimeline("MainScene.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    addChild(_rootNode);

    return true;
}

void MultiBattleScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    
    updateCoinLabel();
    SoundManager::getInstance()->playBattleStartEffect();
    SoundManager::getInstance()->fadeOutBgm(0.5f);
    SoundManager::getInstance()->playBattleBgm();
    _battleStartEffect();
    WorldManager::getInstance()->startMultiplayBattle();
}

void MultiBattleScene::update(float dt)
{
    Layer::update(dt);
}

void MultiBattleScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        return true;
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

#pragma - public method

void MultiBattleScene::levelUpEffect(std::function<void()> callback)
{
    SoundManager::getInstance()->playLevelupEffect();
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("zoomout1", false);
    _timeline->setLastFrameCallFunc([callback](){
        if (callback) {
            callback();
        }
    });
}


void MultiBattleScene::transitionMap(WorldMap* newMap)
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

void MultiBattleScene::updateCoinLabel()
{
    _coinLabel->setString(StringUtils::format("x %d", WorldManager::getInstance()->getCoin()));
}

void MultiBattleScene::showConsumeCoinEffect(int decreaseCoin)
{
    auto text = ui::TextBMFont::create(StringUtils::format("-%d", decreaseCoin), "font/zoo_font2.fnt");
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

void MultiBattleScene::showResultView(GameResult* result, float delay, std::function<void ()> closeCallback)
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

void MultiBattleScene::showNoticeView(std::string message, float delay, std::function<void ()> closeCallback)
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


#pragma - private method

void MultiBattleScene::_battleStartEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("battle_start", false);
}

void MultiBattleScene::_pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == cocos2d::ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->backMainScene();
    }
}

