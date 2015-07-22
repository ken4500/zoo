//
//  DebugButton.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/22.
//
//

#include "DebugButton.h"
#include "ColorConstants.h"

USING_NS_CC;

DebugButton* DebugButton::create(std::string labelName, std::function<void ()> func)
{
    DebugButton* button = new(std::nothrow) DebugButton();
    if (button && button->init(labelName, func))
    {
        button->autorelease();
        return button;
    }
    
    CC_SAFE_DELETE(button);
    return nullptr;
}

bool DebugButton::init(std::string labelName, std::function<void ()> func)
{
    if (!ui::Button::init("ui/debug_button.png"))
    {
        return false;
    }
    
    _func = func;
    setTitleColor(Color3B(COLOR_OUTLINE));
    setTitleFontSize(32);
    setTitleText(labelName);
    addTouchEventListener(CC_CALLBACK_2(DebugButton::_pusheButton, this));

    return true;
}

#pragma mark - View lifecycle

void DebugButton::onEnter()
{
    ui::Button::onEnter();
}

void DebugButton::onExit()
{
    ui::Button::onExit();
}

void DebugButton::_pusheButton(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        _func();
    }
}
