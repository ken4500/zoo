//
//  Book.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#ifndef __Zoo__Book__
#define __Zoo__Book__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"
#include "CommonInclude.h"

class Book : public cocos2d::Layer {
public:
    CREATE_FUNC(Book);
    bool init() override;

protected:
    cocostudio::timeline::ActionTimeline* timeline;
    int _page;
    std::vector<Species*> _allSpecies;
    Node* _bookNode;
    Sprite* _selectImage;

    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void _loadPage(int page);
    void _pushAnimalButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushRightButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void _pushLeftButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);

};

#endif /* defined(__Zoo__Book__) */
