//
//  MultiBattleScene.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef __Zoo__MultiBattleScene__
#define __Zoo__MultiBattleScene__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"
#include "CommonInclude.h"
#include "WorldSceneInterface.h"
class Gacha;
class Animal;
class WorldMap;
class MultiplayResult;
using namespace cocos2d;

class MultiBattleScene : public cocos2d::Layer, public WorldSceneInterface
{
public:
    MultiBattleScene();
    ~MultiBattleScene();

    // there's no "id" in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method "init" in cocos2d-x returns bool, instead of returning "id" in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MultiBattleScene);
    
    void levelUpEffect(std::function<void()> callback);
    void transitionMap(WorldMap* newMap);
    void updateCoinLabel();
    void updateLeftTimeLabel(int leftTime);
    void showResultView(std::function<void ()> closeCallback);
    void showNoticeView(std::string message, float delay, std::function<void ()> closeCallback);
    void updateWeightLabel(Weight weight);
    void updateLevelLabel();
    void setResult(GameResult result);

private:
    WorldMap* _map;
    Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    Node* _menuNode;
    Node* _timeBack;
    cocos2d::ui::TextBMFont* _timeLeftLabel;
    cocos2d::ui::TextBMFont* _coinLabel;
    cocos2d::ui::Button* _endButton;
    cocos2d::ui::TextBMFont* _levelLabel;
    cocos2d::ui::TextBMFont* _weightLabel;
    Action* _countUpAction;
    Weight _preWeight;
    MultiplayResult* _resultLayer;

    void onEnter() override;
    void update(float dt);
    void setupTouchHandling();
    void _battleStartEffect();
    void _pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__MultiBattleScene__) */
