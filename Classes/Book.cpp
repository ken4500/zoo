//
//  Book.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#include "Book.h"
#include "SoundManager.h"
#include "UserDataManager.h"

const int ANIMAL_NUM_IN_A_PAGE = 9;
using namespace cocos2d;

bool Book::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Book.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);
    
    return true;
}

void Book::onEnter()
{
    Layer::onEnter();
    
    _page = 1;
    _selectImage = nullptr;
    _allSpecies    = Species::getAllSpecies();
    _bookNode      = this->getChildByName("book");
    _animalImage   = _bookNode->getChildByName<Sprite*>("image");
    _minCrownImage = _bookNode->getChildByName<Sprite*>("minCrown");
    _maxCrownImage = _bookNode->getChildByName<Sprite*>("maxCrown");
    _animalName    = _bookNode->getChildByName<ui::TextBMFont*>("name");
    _sizeDescription = _bookNode->getChildByName<ui::Text*>("speciesSize");
    _pageLabel = this->getChildByName<ui::TextBMFont*>("pageLabel");
    _getNum = _bookNode->getChildByName<ui::Text*>("getNum");
    _getMinSize = _bookNode->getChildByName<ui::Text*>("getMinSize");
    _getMaxSize = _bookNode->getChildByName<ui::Text*>("getMaxSize");
    auto back = this->getChildByName("leftButton")->getChildByName<ui::TextBMFont*>("back");
    back->setString(CCLS("BOOK_BACK"));
    auto next = this->getChildByName("rightButton")->getChildByName<ui::TextBMFont*>("next");
    next->setString(CCLS("BOOK_NEXT"));

    auto description  = _bookNode->getChildByName("description");
    for (int line = 1; line <= 4; line++) {
        auto lineText = description->getChildByName<ui::Text*>(StringUtils::format("line%d", line));
        _description.push_back(lineText);
    }

    for (int pos = 1; pos <= ANIMAL_NUM_IN_A_PAGE; pos++) {
        auto button = _bookNode->getChildByName<ui::Button*>(StringUtils::format("position%d", pos));
        button->addTouchEventListener(CC_CALLBACK_2(Book::_pushAnimalButton, this));
        button->setTag(pos);
    }
    
    _selectPos = 1;
    _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
    
    _rightButton = getChildByName<ui::Button*>("rightButton");
    _rightButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushRightButton, this));
    _leftButton = getChildByName<ui::Button*>("leftButton");
    _leftButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushLeftButton, this));
    auto closeButton = getChildByName<ui::Button*>("closeButton");
    closeButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushCloseButton, this));

    // タッチイベントの設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(Book::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    _loadPage(_page);
}

// タッチイベント(モーダルの下のイベントを通さないために)
bool Book::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void Book::_loadPage(int page)
{
    int min = (page - 1) * ANIMAL_NUM_IN_A_PAGE;
    int max = page * ANIMAL_NUM_IN_A_PAGE;
    int maxSpecies = (int)_allSpecies.size();
    
    _pageLabel->setString(StringUtils::format("%d / %d", page, _getMaxPage()));
    
    for (int i = min, pos = 1; i < max; i++, pos++) {
        auto button = _bookNode->getChildByName<ui::Button*>(StringUtils::format("position%d", pos));
        if (i >= maxSpecies) {
            button->setVisible(false);
            button->setEnabled(false);
            continue;
        } else {
            button->setVisible(true);
            button->setEnabled(true);
        }

        auto species = _allSpecies[i];
        auto size = button->getContentSize();
        auto image = button->getChildByName("image");
        if (image) {
            image->removeFromParent();
        }

        Sprite* newImage;
        if (UserDataManager::getInstance()->haveHadAnimalInPast(species->getName()) == false) {
            newImage = Sprite::create("book/unkonwn_animal.png");
        } else {
            newImage = Sprite::create(species->getImageName());
            newImage->setScale(0.25f);
            
            auto max = UserDataManager::getInstance()->getMaxHeight(species->getName());
            auto min = UserDataManager::getInstance()->getMinHeight(species->getName());
            auto maxRank = species->getMaxHeightRank(max);
            auto minRank = species->getMinHeightRank(min);
            int offset = 0;
            if ((int)maxRank != 0) {
                auto maxRankImage = Sprite::create(StringUtils::format("ui/max_crown%d.png", maxRank));
                maxRankImage->setScale(0.25f / newImage->getScale());
                maxRankImage->setAnchorPoint(Vec2(1.0f, 1.0f));
                maxRankImage->setPosition(Vec2(newImage->getContentSize().width, -10));
                newImage->addChild(maxRankImage, 1);
                offset = maxRankImage->getContentSize().width;
            }
            if ((int)minRank != 0) {
                auto minRankImage = Sprite::create(StringUtils::format("ui/max_crown%d.png", minRank));
                minRankImage->setScale(0.25f / newImage->getScale());
                minRankImage->setAnchorPoint(Vec2(1.0f, 1.0f));
                minRankImage->setPosition(Vec2(newImage->getContentSize().width - offset, -10));
                newImage->addChild(minRankImage, 1);
            }
        }

        newImage->setName("image");
        newImage->setPosition(Vec2(size.width / 2, size.height / 2));
        button->addChild(newImage);
    }
    
    if (page == 1) {
        _leftButton->setEnabled(false);
        _leftButton->setOpacity(100);
        _rightButton->setEnabled(true);
        _rightButton->setOpacity(255);
    } else if (page == _getMaxPage()) {
        _leftButton->setEnabled(true);
        _leftButton->setOpacity(255);
        _rightButton->setEnabled(false);
        _rightButton->setOpacity(100);
    } else {
        _leftButton->setEnabled(true);
        _leftButton->setOpacity(255);
        _rightButton->setEnabled(true);
        _rightButton->setOpacity(255);
    }
}

void Book::_loadAnimal(Species* species)
{
    auto name = species->getName();
    _animalImage->setTexture(species->getImageName());
    auto mgr = UserDataManager::getInstance();

    if (false && mgr->haveHadAnimalInPast(name) == false) {
        // 取得したことがない
        _animalImage->setColor(Color3B::BLACK);
        _animalName->setString("????");
        _getNum->setString(StringUtils::format("%s:0", CCLS("BOOK_GET_NUM")));
        _getMinSize->setString(StringUtils::format("%s:-", CCLS("BOOK_MIN")));
        _getMaxSize->setString(StringUtils::format("%s:-", CCLS("BOOK_MAX")));
        _sizeDescription->setString("????");
        _setDescription("????");
    } else {
        // 取得したことがある
        _animalImage->setColor(Color3B::WHITE);
        _animalName->setString(CCLS(name.c_str()));
        if (_animalName->getContentSize().width > 350) {
            _animalName->setScale(0.4f * 350 / _animalName->getContentSize().width);
        } else {
            _animalName->setScale(0.4f);
        }

        auto count = mgr->getAnimalCount(name);
        auto min = mgr->getMinWeight(name);
        auto max = mgr->getMaxWeight(name);
        _getNum->setString(StringUtils::format("%s:%d", CCLS("BOOK_GET_NUM"), count));
        _getMinSize->setString(StringUtils::format("%s:%.02f%s", CCLS("BOOK_MIN"), min.getWeight(), min.getUnitStr().c_str()));
        _getMaxSize->setString(StringUtils::format("%s:%.02f%s", CCLS("BOOK_MAX"), max.getWeight(), max.getUnitStr().c_str()));
        auto minHeight = mgr->getMinHeight(name);
        auto maxHeight = mgr->getMaxHeight(name);
        auto maxRank = species->getMaxHeightRank(maxHeight);
        auto minRank = species->getMinHeightRank(minHeight);
        if ((int)maxRank == 0) {
            _maxCrownImage->setVisible(false);
        } else {
            _maxCrownImage->setVisible(true);
            _maxCrownImage->setTexture(StringUtils::format("ui/max_crown%d.png", (int)maxRank));
        }
        if ((int)minRank == 0) {
            _minCrownImage->setVisible(false);
        } else {
            _minCrownImage->setVisible(true);
            _minCrownImage->setTexture(StringUtils::format("ui/min_crown%d.png", (int)minRank));
        }

        min = species->getMinWeight();
        max = species->getMaxWeight();
        _sizeDescription->setString(StringUtils::format("%.02f%s 〜 %.02f%s", min.getWeight(), min.getUnitStr().c_str(), max.getWeight(), max.getUnitStr().c_str()));
        _setDescription(
            CCLS(StringUtils::format("%s_DESC", name.c_str()).c_str())
        );
    }
}

void Book::_pushAnimalButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        auto button = dynamic_cast<ui::Button*>(pSender);
        auto size = button->getContentSize();
        auto pos = Vec2(size.width / 2, size.height / 2);
        if (_selectImage == nullptr) {
            _selectImage = Sprite::create("book/select_animal.png");
            button->addChild(_selectImage);
        } else {
            _selectImage->retain();
            _selectImage->removeFromParent();
            button->addChild(_selectImage);
            _selectImage->release();
        }

        _selectImage->setPosition(pos);
        
        int index = button->getTag() + (_page - 1) * ANIMAL_NUM_IN_A_PAGE - 1;
        auto species = _allSpecies[index];
        _loadAnimal(species);
    }
}

void Book::_pushRightButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                _page = MIN(_page + 1, _getMaxPage());
                _loadPage(_page);
                _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Book::_pushLeftButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                _page = MAX(_page - 1, 1);
                _loadPage(_page);
                _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Book::_pushCloseButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        this->runAction(Sequence::create(FadeOut::create(0.3f), RemoveSelf::create(), NULL));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}


int Book::_getMaxPage()
{
    return (int)ceilf(float(_allSpecies.size()) / ANIMAL_NUM_IN_A_PAGE);
}

void Book::_setDescription(std::string description)
{
    int charNumPerLine = 16;
    for (int line = 0; line < 4; line++) {
        auto lineStr = ZUtil::submbstr(description, line * charNumPerLine, charNumPerLine);
        _description[line]->setString(lineStr);
    }
}
