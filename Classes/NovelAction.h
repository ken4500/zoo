//
//  NovelAction.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#ifndef __ninjya__NovelAction__
#define __ninjya__NovelAction__

#include <iostream>
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

using namespace std;

class NovelAction {
public:
    enum class Type {
        Set,
        Name,
        Speak,
        Music,
        Effect,
        Introduction,
        Narration,
        Location,
        Delay,
        LWF,
        Flash,
        Shake,
        Wait,
        Clear,
        ShowImage,
        ShowImageInstant,
        HideImage,
        HideImageInstant
    };
    enum class Target {
        None,
        Left,
        Right,
        Background,
        Narration,
    };
    enum class Balloon {
        None,
        Normal,
        Shout,
        Thought,
        Modal,
        Battle,
        Battle_Shout,
        Battle_Thought,
        LightOverlay,
        FullOverlay
    };
    static NovelAction* createFromJson(rapidjson::Value& json);
    Type getType();
    Target getTarget();
    Balloon getBalloon();
    std::string getValue();
    std::string getValue2();
    std::string getValue3();
    bool getFullscreen();
private:
    Type _type = Type::Set;
    Target _target = Target::None;
    Balloon _balloon = Balloon::None;
    std::string _value;
    std::string _value2;
    std::string _value3;
};


#endif /* defined(__ninjya__NovelAction__) */
