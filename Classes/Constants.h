//
//  Constants.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#ifndef Zoo_Constants_h
#define Zoo_Constants_h

enum class MainSceneTag
{
    None = 0,
    Animal,
};

enum class AnimalType
{
    None = 0,
    Ant,
    Beetle,
    Dog
};

enum class UnitOfLength
{
    Unkown = 0,
    mm = 1,
    cm = 10,
    m  = 1000,
    km = 1000000,
};

static const float GAME_FPS = 60;


// for debug
static const float DEBUG_INIT_WORLD_LEVEL = 3;


#endif
