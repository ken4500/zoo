//
//  DebugButton.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/22.
//
//

#ifndef __Zoo__DebugButton__
#define __Zoo__DebugButton__

#include "cocos2d.h"
#include "CocosGUI.h"

class DebugButton : public cocos2d::ui::Button
{
public:
    static DebugButton* create(std::string labelName, std::function<void ()> func);
    bool init(std::string labelName, std::function<void ()> func);

private:
    std::function<void()> _func;

    void onEnter() override;
    void onExit() override;
    void _pusheButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);


};

#endif /* defined(__Zoo__DebugButton__) */
