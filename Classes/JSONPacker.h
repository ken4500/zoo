//
//  JSONPacker.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/28.
//
//

#ifndef __Zoo__JSONPacker__
#define __Zoo__JSONPacker__

namespace JSONPacker
{

struct CommandData
{
    std::string commandName;
    float time;
    std::vector<float> numberDataList;
    std::vector<std::string> stringDataList;
};

CommandData unpackCommandDataJSON(std::string json);
std::string packCommandData(CommandData commandData);

}

#endif /* defined(__Zoo__JSONPacker__) */
