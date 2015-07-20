//
//  NoticeLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__NoticeLayer__
#define __Zoo__NoticeLayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ModalLayer.h"

USING_NS_CC;
using namespace std;

class NoticeLayer : public ModalLayer
{
    
public:
    NoticeLayer();
    virtual ~NoticeLayer();
    static NoticeLayer* createWithMessage(std::string message);
    virtual bool initWithMessage(std::string message);
    std::function<void ()> closeNoticeCallback;
    
protected:
    
private:

    void onEnter() override;
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Zoo__NoticeLayer__) */
