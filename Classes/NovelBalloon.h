//
//  NovelBalloon.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/23.
//
//

#ifndef __ninjya__NovelBalloon__
#define __ninjya__NovelBalloon__

#include "cocos2d.h"
#include "Constants.h"
#include <stdio.h>
#include "NovelAction.h"
#include "NovelTouchHandler.h"
#include "LabelColor.h"

USING_NS_CC;
using namespace std;

class NovelBalloon : public cocos2d::Node, public NovelTouchHandler {

private:
    Node* _balloonSprite = nullptr;
    Label* _contentSprite = nullptr;
    shared_ptr<NovelAction> _action = nullptr;
    int _balloonIdx = 0;
    int _textLength = 0;

    function<void ()> _completionCallback = [](){};
    float _totalTime = 0.0f;
    int _currentTextLength = 0;
    bool _textCompleted = false;
    bool _enableShowEffect = false;
    Point _arrowPos;
    Action* _arrowAction = nullptr;

    void textCompletionUpdated();
    void incrementText(bool forceFinish);
    void showArrow();
    Label* getLabelSprite(const std::string& text);
public:
    static NovelBalloon* create(std::shared_ptr<NovelAction> action,
                                int balloonIdx,
                                std::function<void ()> completionCallback);
    virtual ~NovelBalloon();
    void update(float delta);
    void processTap();
    void setLabelColor(cocos2d::Color3B color);
    void playBalloonSpecificAnimation();
    void setOpacity(GLubyte opacity) override;
};


#endif /* defined(__ninjya__NovelBalloon__) */
