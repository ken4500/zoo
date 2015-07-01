//
//  GachaReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#ifndef __Zoo__GachaReader__
#define __Zoo__GachaReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class GachaReader : public cocostudio::NodeReader {
public:
    static GachaReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__Gacha__) */
