//
//  CreditLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__CreditLayer__
#define __Zoo__CreditLayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"

USING_NS_CC;
using namespace std;

class CreditLayer : public cocos2d::LayerColor
{
    
public:
    CREATE_FUNC(CreditLayer);
    bool init() override;
    
    std::function<void ()> closedCallback;
    
protected:
    
private:
    Node* _rootNode;

    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__CreditLayer__) */
