//
//  TitleScene.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/24.
//
//

#ifndef __Zoo__TitleScene__
#define __Zoo__TitleScene__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"


class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(TitleScene);

private:
    void onEnter() override;
    void onExit() override;
    
    void _pushStartButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushCreditButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__TitleScene__) */
