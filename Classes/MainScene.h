#ifndef __Main_SCENE_H__
#define __Main_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"
#include "CommonInclude.h"
#include "WorldSceneInterface.h"
class Gacha;
class Animal;
class WorldMap;
class ScaleBar;
using namespace cocos2d;

class MainScene : public cocos2d::Layer, public WorldSceneInterface
{
public:
    MainScene();
    ~MainScene();

    // there's no "id" in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method "init" in cocos2d-x returns bool, instead of returning "id" in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
    void levelUpEffect(std::function<void()> callback);
    void transitionMap(WorldMap* newMap);
    void playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton, float delay);
    void playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton);
    void hideMenu();
    void showMenu();
    void showLeftTIme();
    void hideLeftTime();
    void updateCoinLabel();
    void updateLifeLabel(float dt);
    void updateLeftTimeLabel(int leftTime);
    void updateLevelLabel();
    void updateWeightLabel(Weight weight);
    void showConsumeCoinEffect(int decreaseCoin);
    void showNoticeView(std::string message, float delay, std::function<void ()> closeCallback);
    void showResultView(GameResult result, float delay, std::function<void ()> closeCallback);
    
private:
    WorldMap* _map;
    Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    Node* _menuNode;
    cocos2d::ui::TextBMFont* _timeLeftLabel;
    cocos2d::ui::TextBMFont* _coinLabel;
    cocos2d::ui::TextBMFont* _lifeLabel;
    cocos2d::ui::TextBMFont* _repairTimeLabel;
    cocos2d::ui::TextBMFont* _levelLabel;
    cocos2d::ui::TextBMFont* _weightLabel;
    cocos2d::ui::Button* _endButton;
    cocos2d::ui::Button* _otherMenuButton;
    Weight _preWeight;
    Action* _countUpAction;
    ScaleBar* _scaleBar;

    void onEnter() override;
    void update(float dt);
    void setupTouchHandling();
    void _setupDebugMenu();
    void _pushBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushOtherMenuButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _battleStartEffect();
    void _pauseRecursive(Node* node);
    void _resumeRecursive(Node* node);

};

#endif // __Main_SCENE_H__
