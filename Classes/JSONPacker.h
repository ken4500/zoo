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
    double time;
    std::vector<int> intDataList;
    std::vector<float> numberDataList;
    std::vector<std::string> stringDataList;
};

std::vector<CommandData> unpackCommandDataJSON(std::string json);
std::string packCommandData(CommandData commandData);
std::string packCommandData(std::vector<CommandData> commandList);

}

#endif /* defined(__Zoo__JSONPacker__) */
