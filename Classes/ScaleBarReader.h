//
//  ScaleBarReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#ifndef __Zoo__ScaleBarReader__
#define __Zoo__ScaleBarReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ScaleBarReader : public cocostudio::NodeReader {
public:
    static ScaleBarReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__ScaleBar__) */
