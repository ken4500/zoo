//
//  MenuLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef __Zoo__MenuLayer__
#define __Zoo__MenuLayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"
#include "ModalLayer.h"
#include "GameResult.h"

USING_NS_CC;
using namespace std;

class MenuLayer : public ModalLayer
{
    
public:
    MenuLayer();
    virtual ~MenuLayer();
    CREATE_FUNC(MenuLayer);
    bool init() override;
    
protected:
    
private:
    cocos2d::ui::TextBMFont* _titleLabel;
    cocos2d::ui::TextBMFont* _multiplayLabel;
    cocos2d::ui::TextBMFont* _encyclepediaLabel;
    cocos2d::ui::TextBMFont* _languageLabel;
    cocos2d::ui::TextBMFont* _closeLabel;

    void onEnter() override;
    void _pushMultiPlayButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushEncyclepediaButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushCloseButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    
    void _updateLanguage();
};

#endif /* defined(__Zoo__MenuLayer__) */
