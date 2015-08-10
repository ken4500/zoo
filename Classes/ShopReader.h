//
//  ShopReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#ifndef __Zoo__ShopReader__
#define __Zoo__ShopReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ShopReader : public cocostudio::NodeReader {
public:
    static ShopReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__Shop__) */
