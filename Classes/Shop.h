//
//  Shop.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#ifndef __Zoo__Shop__
#define __Zoo__Shop__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Shop : public cocos2d::Node {
public:
    CREATE_FUNC(Shop);
    bool init() override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;

};

#endif /* defined(__Zoo__Shop__) */
