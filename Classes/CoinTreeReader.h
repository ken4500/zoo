//
//  CoinTreeReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef __Zoo__CoinTreeReader__
#define __Zoo__CoinTreeReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class CoinTreeReader : public cocostudio::NodeReader {
public:
    static CoinTreeReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__CoinTree__) */
