//
//  HpGaugeReader.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/04.
//
//

#ifndef __Zoo__HpGaugeReader__
#define __Zoo__HpGaugeReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class HpGaugeReader : public cocostudio::NodeReader {
public:
    static HpGaugeReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__Zoo__HpGauge__) */
