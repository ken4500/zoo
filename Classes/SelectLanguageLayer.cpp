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
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 200))) {
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

    auto buttonChinese = node->getChildByName<ui::Button*>("buttonChinese");
    buttonChinese->addTouchEventListener(CC_CALLBACK_2(SelectLanguageLayer::_pushLanguageButton, this));
    buttonChinese->setTag((int)LanguageType::CHINESE);
    
    _selectNode = node->getChildByName("select");
    LanguageType lang = UserDataManager::getInstance()->getLanguage();
    float selectPosY = buttonEnglish->getPosition().y;
    switch (lang) {
      case LanguageType::JAPANESE:
        selectPosY = buttonJapan->getPosition().y;
        break;
      case LanguageType::CHINESE:
        selectPosY = buttonChinese->getPosition().y;
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
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(SelectLanguageLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void SelectLanguageLayer::_pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
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
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
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
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
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
    title->setString(CCLS1("LANGUAGE_PAGE_TITLE",title));

    auto english = _rootNode->getChildByName("buttonEnglish")->getChildByName<ui::TextBMFont*>("label");
    english->setString(CCLS1("ENGLISH",english));

    auto japanese = _rootNode->getChildByName("buttonJapanese")->getChildByName<ui::TextBMFont*>("label");
    japanese->setString(CCLS1("JAPANESE",japanese));

    auto chinese = _rootNode->getChildByName("buttonChinese")->getChildByName<ui::TextBMFont*>("label");
    chinese->setString(CCLS1("CHINESE",chinese));

}
