//
//  LackLife.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/11.
//
//

#ifndef __Zoo__LackLife__
#define __Zoo__LackLife__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"

class LackLife : public cocos2d::Layer {
public:
    CREATE_FUNC(LackLife);
    bool init() override;
    std::function<void ()> pushedYesCallback;
    std::function<void ()> pushedNoCallback;

protected:
    void onEnter() override;
    void _updateLanguage();
    void _pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__LackLife__) */
