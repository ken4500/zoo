//
//  Transmigration.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#ifndef __Zoo__Transmigration__
#define __Zoo__Transmigration__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

class Transmigration : public cocos2d::Layer {
public:
    CREATE_FUNC(Transmigration);
    bool init() override;

protected:    
    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void _pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);


};

#endif /* defined(__Zoo__Transmigration__) */
