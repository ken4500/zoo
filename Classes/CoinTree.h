//
//  CoinTree.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef __Zoo__CoinTree__
#define __Zoo__CoinTree__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"

class CoinTree : public cocos2d::Node {
public:
    CREATE_FUNC(CoinTree);
    bool init() override;
    void setLength(Length* length);
    

protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    cocos2d::Sprite* _image;

    void onEnter() override;

};

#endif /* defined(__Zoo__CoinTree__) */
