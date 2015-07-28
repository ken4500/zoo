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
using namespace cocos2d;

class MultiBattleScene : public cocos2d::Layer, public WorldSceneInterface
{
public:
    // there's no "id" in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method "init" in cocos2d-x returns bool, instead of returning "id" in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MultiBattleScene);
    
    void levelUpEffect();
    void transitionMap(WorldMap* newMap);
    void updateCoinLabel();
    void updateLeftTimeLabel(int leftTime);
    void showConsumeCoinEffect(int decreaseCoin);
    void showResultView(GameResult* result, float delay, std::function<void ()> closeCallback);
    void showNoticeView(std::string message, float delay, std::function<void ()> closeCallback);

    
private:
    WorldMap* _map;
    Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    Node* _menuNode;
    cocos2d::ui::TextBMFont* _timeLeftLabel;
    cocos2d::ui::TextBMFont* _coinLabel;
    cocos2d::ui::Button* _endButton;

    void onEnter() override;
    void update(float dt);
    void setupTouchHandling();
    void _battleStartEffect();
    void _pushEndButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__MultiBattleScene__) */
