//
//  MultiplayResult.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/01.
//
//

#ifndef __Zoo__MultiplayResult__
#define __Zoo__MultiplayResult__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CommonInclude.h"
#include "ModalLayer.h"
#include "GameResult.h"

USING_NS_CC;
using namespace std;

class MultiplayResult : public ModalLayer
{
    
public:
    MultiplayResult();
    virtual ~MultiplayResult();
    static MultiplayResult* create();
    virtual bool init();
    std::function<void ()> closeResultCallback;
    void setResult(GameResult result);

protected:
    
private:
    ui::Text* _playerName;
    ui::Text* _opponentName;

    ui::TextBMFont* _playerWeight;
    ui::TextBMFont* _opponentWeight;

    Sprite* _playerResult;

    void onEnter() override;
    void _pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};


#endif /* defined(__Zoo__MultiplayResult__) */
