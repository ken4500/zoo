#include "MultiBattleScene.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "ScaleBar.h"
#include "ScaleBarReader.h"
#include "WorldMap.h"
#include "WorldMapReader.h"
#include "WorldManager.h"
#include "Animal.h"
#include "MultiplayResult.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "NoticeLayer.h"
#include "YesNoLayer.h"

USING_NS_CC;

using namespace cocostudio::timeline;

MultiBattleScene::MultiBattleScene() :
_preWeight(0)
{
}

MultiBattleScene::~MultiBattleScene()
{
}


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
    _timeLeftLabel = _rootNode->getChildByName<ui::TextBMFont*>("timeLabel");
    _timeLeftLabel->setPosition(Vec2(_timeLeftLabel->getPosition().x, displaySize.height * 0.98f));

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->setLocalZOrder(-1);
    _rootNode->addChild(_map);

    _menuNode = _rootNode->getChildByName<Node*>("menuNode");
    _menuNode->setCascadeOpacityEnabled(true);
    _coinLabel = _menuNode->getChildByName<ui::TextBMFont*>("coinText");
    _levelLabel = _rootNode->getChildByName<ui::TextBMFont*>("levelLabel");
    _levelLabel->setPosition(Vec2(_levelLabel->getPosition().x, displaySize.height * 0.98f));
    _weightLabel = _rootNode->getChildByName<ui::TextBMFont*>("weightLabel");

    _endButton = _rootNode->getChildByName<ui::Button*>("endButton");
    _endButton->addTouchEventListener(CC_CALLBACK_2(MultiBattleScene::_pushEndButton, this));
    _endButton->setPosition(Vec2(_endButton->getPosition().x, displaySize.height * 0.98f));

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("MainScene.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _resultLayer = nullptr;
    
    addChild(_rootNode);

    return true;
}

void MultiBattleScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    
    updateCoinLabel();
    updateLevelLabel();
    SoundManager::getInstance()->playBattleStartEffect();
    SoundManager::getInstance()->fadeOutBgm(0.5f);
    SoundManager::getInstance()->playBattleBgm();
    _battleStartEffect();
    WorldManager::getInstance()->startMultiplayBattle();
    
    _preWeight = WorldManager::getInstance()->getTotalWeight();
    _weightLabel->setString(StringUtils::format("%.02f %s", _preWeight.getWeight(), _preWeight.getUnitStr().c_str()));
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
    updateLevelLabel();
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

void MultiBattleScene::showResultView(std::function<void ()> closeCallback)
{
    _resultLayer = MultiplayResult::create();
    _resultLayer->closeResultCallback = closeCallback;
    this->addChild(_resultLayer);
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

void MultiBattleScene::updateWeightLabel(Weight weight)
{
    int devision = 5;
    float duration = 0.30f / devision;

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
    _weightLabel->runAction(_countUpAction);
}

void MultiBattleScene::updateLevelLabel()
{
    int level = WorldManager::getInstance()->getWorldInfo()->level;
    _levelLabel->setString(StringUtils::format("LEVEL%d", level));
}

void MultiBattleScene::updateLeftTimeLabel(int leftTime)
{
    _timeLeftLabel->setString(to_string(leftTime));
}

void MultiBattleScene::setResult(GameResult result)
{
    if (_resultLayer) {
        _resultLayer->setResult(result);
    }
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
        auto yesno = YesNoLayer::createWithMessage(CCLS("YESNO_END_MULTIPLAY"));
        yesno->pushedYesCallback = []{
            WorldManager::getInstance()->endMultiplayBattle();
            SceneManager::getInstance()->backMainScene();
        };
        addChild(yesno);
    }
}

