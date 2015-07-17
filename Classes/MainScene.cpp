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

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->setLocalZOrder(-1);
    _rootNode->addChild(_map);

    auto battleButton = _rootNode->getChildByName<ui::Button*>("battleButton");
    battleButton->addTouchEventListener(CC_CALLBACK_2(MainScene::_pushBattleButton, this));
    


    // load the character animation timeline
    _timeline = CSLoader::createTimeline("MainScene.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    _state = SceneState::Tutrial;

    addChild(_rootNode);

    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    
    if (_state == SceneState::Tutrial) {
        _playNovel("novel_opening", NULL, false);
    }
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

void MainScene::levelUpEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("zoomout1", false);
    _timeline->setLastFrameCallFunc([](){ WorldManager::getInstance()->setEnableNextAction(true); });
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

void MainScene::_playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton)
{
    // 再生しない
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/novel.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& novelJson = document[novelId.c_str()];

    WorldManager::getInstance()->setEnableNextAction(false);

    // TODO: pause

    // 会話終了後のコールバック
    auto preCallbackFunc = [this]() {
        auto novel = getChildByName<NovelLayer*>("novel");
        if (novel) {
            novel->removeFromParent();
        }
        WorldManager::getInstance()->setEnableNextAction(true);
        
        // TODO: resume
    };
    
    // 会話生成&開始
    auto novel = NovelLayer::create(novelJson, 100, false, preCallbackFunc, callback);
    novel->setPosition(Vec2(0, 0));
    novel->setName("novel");
    if (apearSkipButton == false) {
        novel->removeSkipButton();
    }
    addChild(novel);
    novel->playNovel();

}

void MainScene::_pushBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    
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
        (*it)->pause();
        _pauseRecursive(*it);
    }
}

