//
//  CCLocalizedString.cpp
//  SkeletonX
//
//  Created by mac on 11-12-1.
//  Copyright (c) 2011年 GeekStudio. All rights reserved.
//


#include "cocos2d.h"
#include "CCLocalizedString.h"
#include "UserDataManager.h"
#include "CocosGUI.h"

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
USING_NS_CC;


static map<std::string,std::string> localizedStrings;

void PurgeCCLocalizedStringCached()
{
    localizedStrings.clear();
}


const char * CCLocalizedString(const char * mKey,const char * mCommnet)
{
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    const char * fileName;
    switch (curLanguage) {
        case LanguageType::ENGLISH:
            fileName = "Localized_en";
            break;
        case LanguageType::CHINESE:
            fileName = "Localized_zh";
            break;
        case LanguageType::FRENCH:
            fileName = "Localized_fr";
            break;
        case LanguageType::ITALIAN:
            fileName = "Localized_it";
            break;
        case LanguageType::GERMAN:
            fileName = "Localized_ge";
            break;
        case LanguageType::SPANISH:
            fileName = "Localized_sp";
            break;
        case LanguageType::RUSSIAN:
            fileName = "Localized_ru";
            break;
        case LanguageType::KOREAN:
            fileName = "Localized_ko";
            break;
        case LanguageType::JAPANESE:
            fileName = "Localized_jp";
            break;
        case LanguageType::HUNGARIAN:
            fileName = "Localized_hu";
            break;
            /**
             case for more localize
             */
        default:
            fileName = "Localized_en";
            break;
    }
    
    std::string resultStr;
    
    if (localizedStrings.empty())
    {
        // Initialize variables needed
        string line, fullPath, contents;
        
        // Get absolute path of file
        fullPath = FileUtils::getInstance()->fullPathForFilename(fileName);
        
        // Get data of file
        contents = FileUtils::getInstance()->getStringFromFile(fullPath);
        if(contents == "")
        {
            //            fileName = "Localized_en";
            //            fullPath = FileUtils::getInstance()->fullPathForFilename( fileName );
            //            contents = FileUtils::getInstance()->getStringFromFile(fullPath).c_str();
        }
        if(contents == "")
        {
            return " ";
        }
        
        // Create a string stream so that we can use getline( ) on it
        istringstream fileStringStream( contents );
        
        // Get file contents line by line
        while ( std::getline( fileStringStream, line ) )
        {
            //            debug_Printf("line :%s",line.c_str());
            if (line.find("/*",0) == string::npos && line.find("//",0) == string::npos) //filter the valid string of one line
            {
                //                debug_Printf("find the line not start with \" /* \"");
                std::string::size_type validPos= line.find('=',0);
                if ( validPos != string::npos)
                {
                    //                    debug_Printf("fimd the line contain \" = \"");
                    std::string keyStr = line.substr(0,validPos);
                    std::string subStr = line.substr(validPos+1,line.size()-1); // get valid string
                    
                    //trim space
                    keyStr.erase(0, keyStr.find_first_not_of(" \t")); // 去掉头部空格
                    keyStr.erase(keyStr.find_last_not_of(" \t") + 1); // 去掉尾部空格
                    
                    subStr.erase(0, subStr.find_first_not_of(" \t")); // 去掉头部空格
                    subStr.erase(subStr.find_last_not_of(" \t") + 1); // 去掉尾部空格
                    
                    //trim \"
                    keyStr.erase(0, keyStr.find_first_not_of("\""));
                    keyStr.erase(keyStr.find_last_not_of("\"") + 1);
                    
                    subStr.erase(0, subStr.find_first_not_of("\""));
                    
                    
                    //trim ; character and last \" character
                    subStr.erase(subStr.find_last_not_of(";") + 1);
                    subStr.erase(subStr.find_last_not_of("\"") + 1);
                    
                    
                    //replace line feed with \n
                    string::size_type pos(0);
                    string old_value("\\n");
                    if((pos=subStr.find(old_value))!=string::npos)
                    {
                        for(; pos!=string::npos; pos+=1)
                        {
                            if((pos=subStr.find(old_value,pos))!=string::npos)
                            {
                                subStr.erase(pos, 2);
                                subStr.insert(pos, 1, '\n');
                            }
                            else
                                break;
                        }
                    }
                    
                    localizedStrings.insert(std::pair<std::string, std::string>(keyStr,subStr));
                    
                    const char * keyChars = keyStr.c_str();
                    
                    if (strcmp(keyChars,mKey) == 0) {
                        resultStr = subStr;
                    }
                }
            }
        }
        
        //return valid value
        if (resultStr.length() > 0){
            return (string(resultStr)).c_str();
        }
        return mKey;
    }
    else
    {
        std::map<std::string,std::string>::iterator itr = localizedStrings.find(std::string(mKey));
        if (itr != localizedStrings.end()) {
            resultStr = itr->second;
            if (resultStr.length() > 0)
            {
                return (itr->second).c_str();
            }
        }
    }
    return mKey;
}

/* default label is nullptr */
const char * CCLocalizedStringAndFont(const char * mKey,const char * mComment,cocos2d::ui::Text* label)
{
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    if (curLanguage == LanguageType::CHINESE) {
        label->setFontName("font/simiyo.ttf");
    }
    return CCLocalizedString(mKey, mComment);
}

/* default label is nullptr */
const char * CCLocalizedStringAndFont(const char * mKey,const char * mComment,cocos2d::ui::TextBMFont* label)
{
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    if (curLanguage == LanguageType::CHINESE) {
        label->setFntFile("font/zoo_font2_zh.fnt");
    }
    return CCLocalizedString(mKey, mComment);
 }
