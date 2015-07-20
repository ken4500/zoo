//
//  ResultLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__ResultLayer__
#define __Zoo__ResultLayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"
#include "ModalLayer.h"
#include "GameResult.h"

USING_NS_CC;
using namespace std;

class ResultLayer : public ModalLayer
{
    
public:
    ResultLayer();
    virtual ~ResultLayer();
    static ResultLayer* createWithResult(GameResult* result);
    virtual bool initWithResult(GameResult* result);
    std::function<void ()> closeResultCallback;
    
protected:
    
private:
    GameResult* _result;

    void onEnter() override;
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__ResultLayer__) */
