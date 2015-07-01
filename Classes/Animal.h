//
//  Animal.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#ifndef __Zoo__Animal__
#define __Zoo__Animal__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"

class Animal : public cocos2d::Node {
public:
    CREATE_FUNC(Animal);
    bool init() override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    std::string csbFile;
    std::string name;
    float speed;
    float size;
    
    void onEnter() override;
    void startWalk();
    void moveNextPoint();
    
};

#endif /* defined(__Zoo__Animal__) */
