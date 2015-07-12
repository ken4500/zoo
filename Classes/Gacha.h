//
//  Gacha.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#ifndef __Zoo__Gacha__
#define __Zoo__Gacha__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
class Animal;

class Gacha : public cocos2d::Node {
public:
    CREATE_FUNC(Gacha);
    bool init() override;
    std::function<void(Animal* animal)> finishGachaCallback;

protected:
    bool _enableGacha;
    int _level;
    rapidjson::Document _settingDoc;

    void onEnter() override;
    cocostudio::timeline::ActionTimeline* timeline;
    void setupTouchHandling();
    void lotteryGacha();
};

#endif /* defined(__Zoo__Gacha__) */
