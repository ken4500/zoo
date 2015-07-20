//
//  GameResult.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__GameResult__
#define __Zoo__GameResult__

#include <stdio.h>
#include "CommonInclude.h"

class GameResult {
public:
    BattleState resultState       = BattleState::Battle;
    int   getCoin                 = 0;
    int   killTime                = 0;
    float playTime                = 0;
};


#endif /* defined(__Zoo__GameResult__) */
