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
#include "ui/CocosGUI.h"
#include "CommonInclude.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
class Animal;

class Gacha : public cocos2d::Node {
public:
    CREATE_FUNC(Gacha);
    bool init() override;
    float getGachaHeight();
    void lotteryGacha(WorldInfo* info);
    void setNewGacha(WorldInfo* info);
    int getPrice();
    void setOpponent(bool isOpponent);
    bool isOpponent();
    bool touchIsInGacha(Vec2 position);
    
    std::function<void()> finishGachaCallback;

protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    int _least;
    int _price;
    bool _isOppnentGacha;
    std::vector<float> _probabilityList;
    std::vector<std::string> _rewardList;
    std::vector<bool> _hitList;
    float _sumProbability;
    cocos2d::ui::TextBMFont* _priceLabel;

    void onEnter() override;
};

#endif /* defined(__Zoo__Gacha__) */
