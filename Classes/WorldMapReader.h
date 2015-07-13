//
//  WorldMapReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#ifndef __Zoo__WorldMapReader__
#define __Zoo__WorldMapReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class WorldMapReader : public cocostudio::NodeReader {
public:
    static WorldMapReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__WorldMap__) */
