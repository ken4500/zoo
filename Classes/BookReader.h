//
//  BookReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#ifndef __Zoo__BookReader__
#define __Zoo__BookReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class BookReader : public cocostudio::NodeReader {
public:
    static BookReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__Book__) */
