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

class WorldManager
{
public:
    static WorldManager* getInstance();
    
    int getGachaId();
    WorldMap* getMap();
    WorldInfo* getWorldInfo();
    float getImageScale(Sprite* image, Length* heightLength);
    float getDisplayLength(Length* length);
    Length* getLength(float displayLength);

    WorldInfo* levelup();

private:
    int _level;
    WorldInfo* _info;
    WorldMap* _map;
    
    WorldInfo* _loadWoldInfo(int level);

    WorldManager();
    ~WorldManager();

};

#endif /* defined(__Zoo__WorldManager__) */
