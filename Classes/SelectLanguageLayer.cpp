//
//  ResultLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#include "SelectLanguageLayer.h"
#include "SoundManager.h"
#include "UserDataManager.h"

bool SelectLanguageLayer::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 160))) {
        return false;
    }
 
    this->setCascadeOpacityEnabled(false);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("SelectLanguage.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    _rootNode = node;
    
    auto buttonEnglish = node->getChildByName<ui::Button*>("buttonEnglish");
    buttonEnglish->addTouchEventListener(CC_CALLBACK_2(SelectLanguageLayer::_pushLanguageButton, this));
    buttonEnglish->setTag((int)LanguageType::ENGLISH);

    auto buttonJapan = node->getChildByName<ui::Button*>("buttonJapanese");
    buttonJapan->addTouchEventListener(CC_CALLBACK_2(SelectLanguageLayer::_pushLanguageButton, this));
    buttonJapan->setTag((int)LanguageType::JAPANESE);
    
    _selectNode = node->getChildByName("select");
    LanguageType lang = UserDataManager::getInstance()->getLanguage();
    float selectPosY = buttonEnglish->getPosition().y;
    switch (lang) {
      case LanguageType::JAPANESE:
        selectPosY = buttonJapan->getPosition().y;
        break;
      default:
        break;
    }
    _selectNode->setPosition(Vec2(_selectNode->getPosition().x, selectPosY));

    auto button = node->getChildByName<ui::Button*>("okButton");
    button->addTouchEventListener(CC_CALLBACK_2(SelectLanguageLayer::_pushButton, this));

    _updateLanguage();
    
    return true;
}

void SelectLanguageLayer::onEnter()
{
    LayerColor::onEnter();
}

void SelectLanguageLayer::_pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        auto button = dynamic_cast<ui::Button*>(pSender);
        LanguageType lang = (LanguageType)button->getTag();
        UserDataManager::getInstance()->setLanguage(lang);
        
        auto hoge = button->getPosition();
        
        _selectNode->runAction(
            EaseBackOut::create(MoveTo::create(0.3, Vec2(_selectNode->getPosition().x, button->getPosition().y)))
        );
        
        _updateLanguage();
    }
}

void SelectLanguageLayer::_pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        this->runAction(Sequence::create(
            FadeOut::create(0.3f),
            CallFunc::create([this](){
                if (closedCallback) {
                    closedCallback();
                }
            }),
            RemoveSelf::create(),
            NULL
        ));
    }
}

// タッチイベント(モーダルの下のイベントを通さないために)
bool SelectLanguageLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void SelectLanguageLayer::_updateLanguage()
{
    PurgeCCLocalizedStringCached();
    auto title = _rootNode->getChildByName<ui::TextBMFont*>("title");
    title->setString(CCLS("LANGUAGE_PAGE_TITLE"));

    auto english = _rootNode->getChildByName("buttonEnglish")->getChildByName<ui::TextBMFont*>("label");
    english->setString(CCLS("ENGLISH"));

    auto japanese = _rootNode->getChildByName("buttonJapanese")->getChildByName<ui::TextBMFont*>("label");
    japanese->setString(CCLS("JAPANESE"));

}
