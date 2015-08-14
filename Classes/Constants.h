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
#define CCLS1(key,label) CCLocalizedStringAndFont(key, NULL,label)

static const bool  DEBUG_MODE = true;
static const float INIT_WORLD_LEVEL = 1;
static const float INIT_COIN = 10;
static const float INIT_LIFE = 3;
static const int   BATTLE_TIME = 20;
static const int   ENEMY_NUM = 15;
static const int   REPAIR_LIFE_TIME = 10 * 60;
static const float GAME_FPS = 60;
static const int   MAX_SIZE_ID = 27;
static const int   MAX_LEVEL = 27;
static const float APPEAR_COIN_TREE_RATE = 0.2f;
static const float INIT_MULTIBATTLE_COIN = 3;
static const int   MUTLPLAY_BATTLE_TIME = 100;
static const int   GET_DIAMOND_NUM_OF_SILVER_CROWN = 1;
static const int   GET_DIAMOND_NUM_OF_GOLD_CROWN = 3;


enum class EntityTag
{
    None = 0,
    Animal = 100,
    EnemyAnimal,
    OpponentAnimal,
    CoinTree,
    Gacha,
};

enum class AnimalState
{
    Unkown = 0,
    Stop,
    Jump,
    Walk,
    Dash,
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

enum class UnitOfWeight
{
    Unkown = 0,
    mg,
    g,
    kg,
    t,
    Mt,
    Gt,
    Tt,
    Pt,
    Et,
    Zt,
    Yt,
};

enum class SizeRank
{
    None   = 0,
    Silver = 1,
    Gold   = 2,
};


#endif
