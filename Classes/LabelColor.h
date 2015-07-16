//
//  LabelColor.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/25.
//
//

#ifndef __ninjya__LabelColor__
#define __ninjya__LabelColor__

#include <stdio.h>
#include "cocos2d.h"

class LabelColor {
private:
    struct Range {
        int start;
        int length;
        cocos2d::Color3B color;
    };
    
    std::shared_ptr<std::vector<Range> > _colorRanges = nullptr;
    cocos2d::Color3B _defaultColor;
    std::string _rawString = "";
    
    cocos2d::Color3B colorFromString(const std::string& str);
    
    bool _hasColorTag = false;
    
public:
    // フォーマット例
    // [c=red]日本語[/c]も[c=blue]対応[/c]しています
    LabelColor(const std::string& str);
    cocos2d::Color3B colorAtPosition(int pos, bool* available);
    std::string getRawString();
    void applyColor(cocos2d::Label* label);
    
    static void applyFormattedString(const std::string& str, cocos2d::Label* label);
    
    inline bool hasColorTag() { return _hasColorTag; };
    
#define LABEL_COLOR(x, y, r, g, b) static cocos2d::Color3B get##y##Color() { return cocos2d::Color3B(r, g, b); }
#include "LabelColorDefinition.h"
#undef LABEL_COLOR
};


#endif /* defined(__ninjya__LabelColor__) */
