//
//  SelectLanguageLayer.cpp
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

USING_NS_CC;
using namespace std;

class SelectLanguageLayer : public cocos2d::LayerColor
{
    
public:
    CREATE_FUNC(SelectLanguageLayer);
    bool init() override;
    
protected:
    
private:
    Node* _selectNode;
    Node* _rootNode;

    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void _pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _updateLanguage();
};

#endif /* defined(__Zoo__ResultLayer__) */
