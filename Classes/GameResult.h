//
//  GameResult.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__GameResult__
#define __Zoo__GameResult__

#include "Constants.h"
#include "Weight.h"

class GameResult {
public:
    BattleState resultState       = BattleState::Battle;
    long int getCoin              = 0;
    int   killTime                = 0;
    float playTime                = 0;
    Weight playerWeight           = 0;
    Weight opponentWeight         = 0;
    std::string playerName        = "";
    std::string opponentName      = "";
};


#endif /* defined(__Zoo__GameResult__) */
