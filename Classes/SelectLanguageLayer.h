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

class SelectLanguageLayer : public ModalLayer
{
    
public:
    SelectLanguageLayer();
    virtual ~SelectLanguageLayer();
    CREATE_FUNC(SelectLanguageLayer));
    bool init() override;
    
protected:
    
private:
    void onEnter() override;
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__ResultLayer__) */
