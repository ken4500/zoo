//
//  ScaleBar.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#ifndef __Zoo__ScaleBar__
#define __Zoo__ScaleBar__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

class ScaleBar : public cocos2d::Node {
public:
    CREATE_FUNC(ScaleBar);
    bool init() override;

protected:
    cocos2d::ui::TextBMFont* _label;
    cocos2d::Sprite* _image;

    void onEnter() override;
    void updateScale(bool animation);
};

#endif /* defined(__Zoo__ScaleBar__) */
