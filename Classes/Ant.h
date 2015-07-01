//
//  Ant.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#ifndef __Zoo__Ant__
#define __Zoo__Ant__

#include "cocos2d.h"
#include "Animal.h"

class Ant : public Animal {
public:
    CREATE_FUNC(Ant);
    bool init() override;

protected:

};

#endif /* defined(__Zoo__Ant__) */
