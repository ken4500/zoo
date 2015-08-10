//
//  WorldInfo.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#ifndef __Zoo__WorldInfo__
#define __Zoo__WorldInfo__

#include "CommonInclude.h"

class WorldInfo {
public:
    WorldInfo(int level);
    ~WorldInfo();
    
    void levelUp();
    void addLotteryGachaCount();
    WorldInfo* copy();

    Length width;
    Length maxWidth;
    int level;
    int gachaId;
    std::string mapName;
    int imageWidth;
    bool network;
    int getDiamondNum;

    int lotteryGachaCount;
    int totalLotteryGachaCount;

private:
    void _loadLevel();
};

#endif /* defined(__Zoo__WorldInfo__) */
