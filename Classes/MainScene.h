#ifndef __Main_SCENE_H__
#define __Main_SCENE_H__

#include "cocos2d.h"
#include "CommonInclude.h"
class Gacha;
class Animal;
class WorldMap;
using namespace cocos2d;

class MainScene : public cocos2d::Layer
{
public:
    // there's no "id" in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method "init" in cocos2d-x returns bool, instead of returning "id" in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
private:
    Gacha* _gacha;
    WorldMap* _map;

    void onEnter() override;
    void update(float dt);
    void setupTouchHandling();

    void levelup(WorldMap* map);


};

#endif // __Main_SCENE_H__
