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
    WorldInfo();
    ~WorldInfo();
    Length getSize();
    int getLevel();
    
protected:
    Length _size;
    int _level;
};

#endif /* defined(__Zoo__WorldInfo__) */
