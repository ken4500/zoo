//
//  TransmigrationReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#ifndef __Zoo__TransmigrationReader__
#define __Zoo__TransmigrationReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class TransmigrationReader : public cocostudio::NodeReader {
public:
    static TransmigrationReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__Transmigration__) */
