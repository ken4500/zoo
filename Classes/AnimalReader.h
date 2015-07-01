//
//  AnimalReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#ifndef __Zoo__AnimalReader__
#define __Zoo__AnimalReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class AnimalReader : public cocostudio::NodeReader {
public:
    static AnimalReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__Animal__) */
