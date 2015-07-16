//
//  LabelColor.cpp
//  zoo
//
//  Created by Ken Watanabe on 2014/09/25.
//
//

#include "LabelColor.h"

USING_NS_CC;

Color3B LabelColor::colorFromString(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
#define LABEL_COLOR(x, y, r, g, b) if (lowerStr == #x) return LabelColor::get##y##Color();
#include "LabelColorDefinition.h"
#undef LABEL_COLOR
    return Color3B::BLACK;
}

LabelColor::LabelColor(const std::string& str) {
    this->_colorRanges = std::make_shared<std::vector<Range> >();
    
    std::stringstream colorStr;
    std::stringstream rawStr;
    // 0 = not in tag
    // 1 = found [
    // 2 = found c
    // 3 = found = i.e. in color tag
    // 4 = found ] i.e. in colored text
    // 5 = found [ i.e. found start of closing tag
    // 6 = found /
    // 7 = found c
    int inTagState = 0;
    int rawCharCount = 0;
    Range range;
    for (int i = 0; i < str.size(); i++) {
        const char currentChar = str[i];
        // ASCII 文字以外はタグ認識しない
        bool isAscii = (currentChar & 0x80) != 0x80;
        
        switch (inTagState) {
            case 0: // not in tag
                if (isAscii && currentChar == '[') {
                    inTagState++;
                    _hasColorTag = true; // タグが一つでも見つかったらtrueですね
                } else {
                    rawStr << currentChar;
                    rawCharCount++;
                }
                break;
            case 1: // found [
                if (isAscii && (currentChar == 'c' || currentChar == 'C')) {
                    inTagState++;
                } else {
                    rawStr << str[i - 1] << currentChar;
                    rawCharCount += 2;
                    inTagState = 0;
                }
                break;
            case 2: // found c
                if (isAscii && currentChar == '=') {
                    inTagState++;
                } else {
                    rawStr << str[i - 2] << str[i - 1] << currentChar;
                    rawCharCount += 3;
                    inTagState = 0;
                }
                break;
            case 3: // found = i.e. in color tag
                if (isAscii && currentChar == ']') {
                    inTagState++;
                    Color3B color = this->colorFromString(colorStr.str());
                    range.start = rawCharCount;
                    range.length = 0;
                    range.color = color;
                    colorStr.str(std::string());
                    colorStr.clear();
                } else {
                    colorStr << currentChar;
                }
                break;
            case 4: // found ] i.e. in colored text
                // 色が付いたテキストに入った
                if (isAscii && currentChar == '[') {
                    inTagState++;
                } else {
                    rawStr << currentChar;
                    rawCharCount++;
                    range.length++;
                }
                break;
            case 5: // found [ i.e. found start of closing tag
                if (isAscii && currentChar == '/') {
                    inTagState++;
                } else {
                    rawStr << str[i - 1] << currentChar;
                    rawCharCount += 2;
                    range.length += 2;
                    inTagState = 4;
                }
                break;
            case 6: // found /
                if (isAscii && (currentChar == 'c' || currentChar == 'C')) {
                    inTagState++;
                } else {
                    rawStr << str[i - 2] << str[i - 1] << currentChar;
                    rawCharCount += 3;
                    range.length += 3;
                    inTagState = 4;
                }
                break;
            case 7: // found c
                if (isAscii && currentChar == ']') {
                    inTagState = 0;
                    this->_colorRanges->push_back(range);
                } else {
                    rawStr << str[i - 3] << str[i - 2] << str[i - 1] << currentChar;
                    rawCharCount += 4;
                    range.length += 4;
                    inTagState = 4;
                }
                break;
            default:
                break;
        }
    }
    this->_rawString = rawStr.str();
}

void LabelColor::applyColor(cocos2d::Label* label) {
    int currentCharIdx = -1;
    for (int i = 0; i < this->_rawString.length(); i++) {
        const char currentChar = this->_rawString[i];
        // サロゲートペアの始まりか、ASCII 文字に当たったら現在の文字カウントを上げる
        if ((currentChar & 0xC0) == 0xC0 || (currentChar & 0x80) != 0x80) {
            currentCharIdx++;
        }
        bool available = false;
        // 色の位置はバイト数で表しているので i をインデックスに使う
        Color3B color = this->colorAtPosition(i, &available);
        if (!available) {
            continue;
        }
        // Label の文字タグは実際の文字位置なので、currentCharIdx をインデックスに使う
        Sprite* charSprite = label->getLetter(currentCharIdx);
        if (charSprite != nullptr) {
            charSprite->setColor(color);
        }
    }
}

Color3B LabelColor::colorAtPosition(int pos, bool* available) {
    if (available != nullptr) {
        *available = true;
    }
    for (Range range : *this->_colorRanges) {
        if (range.start <= pos && range.start + range.length > pos) {
            return range.color;
        }
    }
    if (available != nullptr) {
        *available = false;
    }
    return Color3B::BLACK;
}

std::string LabelColor::getRawString() {
    return this->_rawString;
}

void LabelColor::applyFormattedString(const std::string& str, Label* label) {
    LabelColor color(str);
    label->setString(color.getRawString());
    color.applyColor(label);
}
