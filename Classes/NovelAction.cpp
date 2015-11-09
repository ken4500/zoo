//
//  NovelAction.cpp
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#include "NovelAction.h"

NovelAction::Type NovelAction::getType() {
    return this->_type;
}

NovelAction::Target NovelAction::getTarget() {
    return this->_target;
}

NovelAction::Balloon NovelAction::getBalloon() {
    return this->_balloon;
}

std::string NovelAction::getValue() {
    return this->_value;
}

std::string NovelAction::getValue2() {
    return this->_value2;
}

std::string NovelAction::getValue3() {
    return this->_value3;
}

bool NovelAction::getFullscreen() {
    return this->_type == Type::Speak && this->_target == Target::None &&
    (this->_balloon == Balloon::FullOverlay || this->_balloon == Balloon::LightOverlay);
}

NovelAction* NovelAction::createFromJson(rapidjson::Value& json) {
    auto result = new NovelAction();
    
    auto type = string(json["type"].GetString());
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    if (type == "set") {
        result->_type = Type::Set;
    } else if (type == "name") {
        result->_type = Type::Name;
    } else if (type == "speak") {
        result->_type = Type::Speak;
    } else if (type == "narration") {
        result->_type = Type::Narration;
    } else if (type == "music") {
        result->_type = Type::Music;
    } else if (type == "effect") {
        result->_type = Type::Effect;
    } else if (type == "delay") {
        result->_type = Type::Delay;
    } else if (type == "shake") {
        result->_type = Type::Shake;
    } else if (type == "wait") {
        result->_type = Type::Wait;
    } else if (type == "clear") {
        result->_type = Type::Clear;
    } else if (type == "show_image") {
        result->_type = Type::ShowImage;
    } else if (type == "show_image_instant") {
        result->_type = Type::ShowImageInstant;
    } else if (type == "hide_image") {
        result->_type = Type::HideImage;
    } else if (type == "hide_image_instant") {
        result->_type = Type::HideImageInstant;
    }
    
    if (result->_type == Type::Set || result->_type == Type::Speak || result->_type == Type::Name || result->_type == Type::Narration) {
        auto target = string(json["target"].GetString());
        std::transform(target.begin(), target.end(), target.begin(), ::tolower);
        if (target == "left") {
            result->_target = Target::Left;
        } else if (target == "right") {
            result->_target = Target::Right;
        } else if (target == "narration") {
            result->_target  = Target::Narration;
        } else if (target == "background") {
            result->_target  = Target::Background;
        } else if (target == "none") {
            result->_target  = Target::None;
        }
    } else {
        result->_target  = Target::None;
    }
    
    if (result->_type == Type::Set) {
    } else if (result->_type == Type::Speak) {
        auto balloon = string(json["balloon"].GetString());
        std::transform(balloon.begin(), balloon.end(), balloon.begin(), ::tolower);
        if (balloon == "normal") {
            result->_balloon = Balloon::Normal;
        } else if (balloon == "shout") {
            result->_balloon = Balloon::Shout;
        } else if (balloon == "modal") {
            result->_balloon = Balloon::Modal;
        } else if (balloon == "thought") {
            result->_balloon = Balloon::Thought;
        } else if (balloon == "battle_shout") {
            result->_balloon = Balloon::Battle_Shout;
        } else if (balloon == "battle_thought") {
            result->_balloon = Balloon::Battle_Thought;
        } else if (balloon == "light_overlay") {
            result->_balloon = Balloon::LightOverlay;
        } else if (balloon == "full_overlay") {
            result->_balloon = Balloon::FullOverlay;
        } else if (balloon == "battle") {
            result->_balloon = Balloon::Battle;
        }
    }
    
    std::string lowerValue;
    if (json["value"].IsNull() == false) {
        result->_value = string(json["value"].GetString());
        lowerValue = result->_value;
        std::transform(lowerValue.begin(), lowerValue.end(), lowerValue.begin(), ::tolower);
    } else {
        result->_value = "";
    }

    if (json["value2"].IsNull() == false) {
        result->_value2 = string(json["value2"].GetString());
        lowerValue = result->_value2;
        std::transform(lowerValue.begin(), lowerValue.end(), lowerValue.begin(), ::tolower);
    } else {
        result->_value2 = "";
    }

    if (json["value3"].IsNull() == false) {
        result->_value3 = string(json["value3"].GetString());
        lowerValue = result->_value3;
        std::transform(lowerValue.begin(), lowerValue.end(), lowerValue.begin(), ::tolower);
    } else {
        result->_value3 = "";
    }
    
    return result;
}