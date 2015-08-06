//
//  MenuLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#include "MenuLayer.h"
#include "SoundManager.h"
#include "WorldManager.h"
#include "SelectLanguageLayer.h"
#include "SceneManager.h"
#include "NoticeLayer.h"
#include "Book.h"

MenuLayer::MenuLayer()
{
    
}

MenuLayer::~MenuLayer()
{
    
}


bool MenuLayer::init()
{
    int height = 600;

    if (!ModalLayer::initWithHeight(height)) {
        return false;
    }
        this->setCascadeOpacityEnabled(true);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("Menu.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    
    _titleLabel = node->getChildByName<ui::TextBMFont*>("title");
    
    auto multiplayButton = node->getChildByName<ui::Button*>("multiplayButton");
    multiplayButton->addTouchEventListener(CC_CALLBACK_2(MenuLayer::_pushMultiPlayButton, this));
    _multiplayLabel = multiplayButton->getChildByName<ui::TextBMFont*>("label");

    auto encyclepediaButton = node->getChildByName<ui::Button*>("encyclepediaButton");
    encyclepediaButton->addTouchEventListener(CC_CALLBACK_2(MenuLayer::_pushEncyclepediaButton, this));
    _encyclepediaLabel = encyclepediaButton->getChildByName<ui::TextBMFont*>("label");

    auto languageButton = node->getChildByName<ui::Button*>("languageButton");
    languageButton->addTouchEventListener(CC_CALLBACK_2(MenuLayer::_pushLanguageButton, this));
    _languageLabel = languageButton->getChildByName<ui::TextBMFont*>("label");
    
    auto closeButton = node->getChildByName<ui::Button*>("okButton");
    closeButton->addTouchEventListener(CC_CALLBACK_2(MenuLayer::_pushCloseButton, this));
    _closeLabel = closeButton->getChildByName<ui::TextBMFont*>("label");
    
    closeCallback = nullptr;
    
    return true;
}

void MenuLayer::onEnter()
{
    Layer::onEnter();
    _updateLanguage();
}

void MenuLayer::_pushMultiPlayButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                auto notice = NoticeLayer::createWithMessage(CCLS("NOTICE_MULTIPLAY"));
                notice->setFontSize(24);
                this->getParent()->addChild(notice);
                notice->closeNoticeCallback = []{
                    SceneManager::getInstance()->receiveMultiplayerInvitations();
                    SceneManager::getInstance()->showPeerList();
                };
                
                this->removeFromParent();
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void MenuLayer::_pushEncyclepediaButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
//        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                auto book = CSLoader::createNode("Book.csb");
                getParent()->addChild(book);
                removeFromParent();
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void MenuLayer::_pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                auto layer = SelectLanguageLayer::create();
                layer->closedCallback = [this]() {
                    _updateLanguage();
                };
                this->addChild(layer, 20);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}


void MenuLayer::_pushCloseButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
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
            RemoveSelf::create(),
            NULL
        ));
        if (closeCallback) {
            closeCallback();
        }
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void MenuLayer::_updateLanguage()
{
    _titleLabel->setString(CCLS("MENU_PAGE_TITLE"));
    _multiplayLabel->setString(CCLS("MENU_PAGE_MULTIPLAY"));
    _encyclepediaLabel->setString(CCLS("MENU_PAGE_ENCYCLEPEDIA"));
    _languageLabel->setString(CCLS("MENU_PAGE_LANGUAGE"));
    _closeLabel->setString(CCLS("MENU_PAGE_CLOSE"));
}
