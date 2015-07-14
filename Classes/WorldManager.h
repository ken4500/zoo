//
//  WorldManager.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#ifndef __Zoo__WorldManager__
#define __Zoo__WorldManager__

#include "cocos2d.h"
#include "WorldInfo.h"
#include "WorldMap.h"
#include "MainScene.h"
class Gacha;
class WorldManager
{
public:
    static WorldManager* getInstance();
    
    // getter, setter
    int getGachaId();
    WorldMap* getMap();
    WorldInfo* getWorldInfo();
    float getImageScale(Sprite* image, Length* width);
    float getDisplayLength(Length* length);
    Length* getLength(float displayLength);
    bool enableNextAction();
    void setEnableNextAction(bool enable);

    // game logic
    void releaseAnimal(Animal* animal);
    WorldInfo* levelup();

private:
    int _level;
    bool _enableNextAction;
    WorldInfo* _info;
    WorldMap* _map;
    Gacha* _gacha;
    WorldInfo* _loadWoldInfo(int level);
    MainScene* _getMainScene();

    WorldManager();
    ~WorldManager();

};

#endif /* defined(__Zoo__WorldManager__) */
