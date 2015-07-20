//
//  Animal.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#ifndef __Zoo__Animal__
#define __Zoo__Animal__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"
#include "Species.h"

class Animal : public cocos2d::Node {
public:
    Animal();
    static Animal* CreateWithSpeceis(std::string specesName);
    static Animal* CreateWithSpeceis(Species* species);
    bool initWithSpeceis(Species* species);

    float getWorldScale();
    Length* getHeight();
    Length* getSpeed();
    Length* getDashSpeed();
    std::string getName();
    bool getZOderUpdate();
    bool isEnemy();
    void setIsEnmey(bool isEnemy);
    bool isDead();
    AnimalState getState();
    Vec2 getCenterPosition();

    void updateWorldScale();
    void jump(Vec2 target, float height, std::function<void ()> callback);
    void startWalk();
    void stopMove();
    void movePoint(Vec2 targetPoint, float dt);
    void fight(Animal* animal);
    void dead();
    void reborn();
    bool addDamage(float damage);
    
    std::function<void ()> deadCallback;
    std::function<void ()> startFightCallback;

protected:
    Species* _species;
    cocos2d::Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    std::string _name;
    cocos2d::Sprite* _image;
    Length* _height;
    bool _zOrderUpdate;
    Action* _moveAction;
    bool _isEnemy;
    Animal* _targetAnimal;
    AnimalState _state;
    float _maxHp;
    float _hp;
    float _offense;
    
    void onEnter() override;
    void update(float dt);
    void _moveNextPoint();
    void _changeAnimalImage();
    
};

#endif /* defined(__Zoo__Animal__) */
