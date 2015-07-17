#ifndef __Main_SCENE_H__
#define __Main_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"
class Gacha;
class Animal;
class WorldMap;
using namespace cocos2d;

enum class SceneState {
    Tutrial,
    TutrialBattle,
    Normal,
    Battle
};


class MainScene : public cocos2d::Layer
{
public:
    // there's no "id" in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method "init" in cocos2d-x returns bool, instead of returning "id" in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
    void levelUpEffect();
    void transitionMap(WorldMap* newMap);
    
private:
    Gacha* _gacha;
    WorldMap* _map;
    Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    SceneState _state;

    void onEnter() override;
    void update(float dt);
    void setupTouchHandling();
    void _playNovel(std::string novelId, std::function<void ()> callback, bool apearSkipButton);
    void _pushBattleButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pauseRecursive(Node* node);
    void _resumeRecursive(Node* node);

};

#endif // __Main_SCENE_H__
