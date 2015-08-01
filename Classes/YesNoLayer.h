//
//  YesNoLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/31.
//
//

#ifndef __Zoo__YesNoLayer__
#define __Zoo__YesNoLayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ModalLayer.h"

USING_NS_CC;
using namespace std;

class YesNoLayer : public ModalLayer
{
    
public:
    YesNoLayer();
    virtual ~YesNoLayer();
    static YesNoLayer* createWithMessage(std::string message);
    virtual bool initWithMessage(std::string message);
    std::function<void ()> pushedYesCallback;
    std::function<void ()> pushedNoCallback;
    
protected:
    
private:

    void onEnter() override;
    void _pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};


#endif /* defined(__Zoo__YesNoLayer__) */
