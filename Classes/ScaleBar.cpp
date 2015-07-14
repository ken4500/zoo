//
//  ScaleBar.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "ScaleBar.h"
#include "WorldManager.h"

bool ScaleBar::init() {
    if (!Node::init()) {
        return false;
    }
    
    return true;
}


void ScaleBar::onEnter()
{
    Node::onEnter();
    _image = this->getChildByName<Sprite*>("image");
    _label = this->getChildByName<ui::TextBMFont*>("label");

    updateScale(false);
}

void ScaleBar::updateScale(bool animation)
{
    auto length = WorldManager::getInstance()->getLength(_image->getContentSize().width);
    float value = length->getLength();
    auto valueStr = StringUtils::format("%.2f", value);
    std::string unit = length->getUnitStr();
    _label->setString(valueStr + unit);
}
