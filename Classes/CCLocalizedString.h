//
//  CCLocalizedString.h
//  SkeletonX
//
//  Created by 小苏 on 11-12-1.
//  Copyright (c) 2011年 GeekStudio. All rights reserved.
//

#ifndef _CCLocalizedString_h
#define _CCLocalizedString_h

#include "CocosGUI.h"
#include "cocos2d.h"

/**get the localized string by the key, if can't get the value then return mComment
 support for file name below:
 "Localized_en";//english
 "Localized_zh";//chinese
 "Localized_fr";//french
 "Localized_it";//italian
 "Localized_ge";//german
 "Localized_sp";//spanish
 "Localized_ru";//russian
 "Localized_ko";//korean
 "Localized_jp";//japanese
 "Localized_hu";//hungarian
 */
const char * CCLocalizedStringAndFont(const char * mKey,const char * mComment,cocos2d::ui::TextBMFont* label = nullptr);
const char * CCLocalizedStringAndFont(const char * mKey,const char * mComment,cocos2d::ui::Text* label = nullptr);
const char * CCLocalizedString(const char * mKey,const char * mCommnet);

/**purge localize string cached
 */
void PurgeCCLocalizedStringCached();

#endif
