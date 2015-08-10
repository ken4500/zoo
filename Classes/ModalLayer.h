//
//  ModalLayer.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#ifndef __Zoo__ModalView__
#define __Zoo__ModalView__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class ModalLayer : public cocos2d::Layer
{
    
public:
    ModalLayer();
    virtual ~ModalLayer();
    virtual bool init();
    CREATE_FUNC(ModalLayer);
    void setTitleImage(string imageName);
    
protected:
    Vec2 _topPos;

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
private:
    
};

#endif /* defined(__Zoo__ModalView__) */
