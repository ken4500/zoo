//
//  Shop.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#ifndef __Zoo__Shop__
#define __Zoo__Shop__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"
#include "ShopData.h"

class Shop : public cocos2d::Layer {
public:
    CREATE_FUNC(Shop);
    bool init() override;

protected:
    ShopData* _shopData;
    cocos2d::ui::TextBMFont* _hasDiamondNum;
    float _buttonScale;

    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void _pushOkButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushShopButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _setData(Node* node);
    void _purchase(ShopLineup lineup);
    void _updateLanguage();

};

#endif /* defined(__Zoo__Shop__) */
