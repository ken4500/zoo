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
#include "AbstractBattleEntity.h"

class Animal : public AbstractBattleEntity {
public:
    Animal();
    static Animal* CreateWithSpeceis(std::string specesName);
    static Animal* CreateWithSpeceis(std::string specesName, float size);
    static Animal* CreateWithSpeceis(Species* species);
    bool initWithSpeceis(Species* species, float size);

    float getWorldScale();
    Species* getSpecies();
    Length getHeight();
    Length getSpeed();
    Length getDashSpeed();
    std::string getName();
    bool isEnemy();
    void setIsEnmey(bool isEnemy);
    bool isOpponent();
    void setIsOpponent(bool isOpponent);
    bool isDead();
    bool isFree();
    AnimalState getState();
    Vec2 getCenterPosition();
    int getHash();
    int getCoin();
    Weight getWeight();
    Rect getBodyRect();
    int getId();
    void setId(int id);
    Vec2 getRealPosition();
    void setRealPosition(Vec2 position);
    Vec2 getTargetPointByWalk();
    Vec2 getTargetPointByDash();
    AbstractBattleEntity* getFightTarget();
    float getMaxHp();
    float getHp();
    SizeRank getMaxSizeRank();
    SizeRank getMinSizeRank();

    void updateWorldScale();
    void jump(Vec2 target, float height, std::function<void ()> callback);
    void startFreeAction();
    void startWalk();
    void startWalk(Vec2 targetPoint, Length speed);
    void startStop();
    void startDash(Vec2 targetPoint, Length speed);
    void fight(AbstractBattleEntity* entity);
    void dead();
    void reborn();
    bool addDamage(float damage, Animal* animal);
    bool canAttack();
    void repairHp();
    void escape();
    void endFight();
    
    std::function<void (AbstractBattleEntity* entity)> deadCallback;
    std::function<void (AbstractBattleEntity* entity, AbstractBattleEntity* fightEntity)> startFightCallback;
    std::function<void (AbstractBattleEntity* entity, AbstractBattleEntity* killEntity)> killAnimalCallback;

protected:
    int _id;
    Species* _species;
    cocos2d::Node* _rootNode;
    cocostudio::timeline::ActionTimeline* _timeline;
    cocos2d::Node* _imageNode;
    cocos2d::Sprite* _image;
    cocos2d::Sprite* _backImage;
    Length _height;
    Action* _moveAction;
    bool _isEnemy;
    bool _isOpponent;
    AbstractBattleEntity* _target;
    AnimalState _state;
    float _maxHp;
    float _hp;
    float _offense;
    Vec2 _targetPointByWalk;
    Vec2 _targetPointByDash;
    
    void onEnter() override;
    void update(float dt);
    void _changeAnimalImage();
    void _stopMoveAction();
    Length _calcRandomHeight(Length min, Length max);
    
};

#endif /* defined(__Zoo__Animal__) */
