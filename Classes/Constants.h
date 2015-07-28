//
//  Constants.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#ifndef Zoo_Constants_h
#define Zoo_Constants_h

#define CCLS(key) CCLocalizedString(key, NULL)

static const bool DEBUG_BUTOTN_APPEAR = true;
static const float INIT_WORLD_LEVEL = 1;
static const float INIT_COIN = 8;
static const float INIT_LIFE = 6;
static const int BATTLE_TIME = 20;
static const int ENEMY_NUM = 15;
static const bool EASY_MODE = true;
static const bool APPEAR_SKIP_BUTTON = true;
static const bool SKIP_TUTORIAL = true;
static const int REPAIR_LIFE_TIME = 1 * 60;
static const int MAX_ANIMAL_NUM = 20;
static const float GAME_FPS = 60;

static const float INIT_MULTIBATTLE_COIN = 3;


enum class MainSceneTag
{
    None = 0,
    Animal,
    EnemyAnimal
};

enum class AnimalState
{
    Unkown = 0,
    Stop,
    Jump,
    Walk,
    MoveTarget,
    Battle,
    Dead,
    Reborn,
    Escape
};

enum class BattleState
{
    Lose = -1,
    Battle = 0,
    Win = 1,
};

enum class UnitOfLength
{
    Unkown = 0,
    mm = 1,
    cm = 10,
    m  = 1000,
    km = 1000000,
};

#endif
