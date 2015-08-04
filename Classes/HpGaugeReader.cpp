//
//  HpGaugeReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/04.
//
//

#include "HpGaugeReader.h"
#include "HpGauge.h"

using namespace cocos2d;

static HpGaugeReader* _instanceHpGaugeReader = nullptr;

HpGaugeReader* HpGaugeReader::getInstance() {
    if (!_instanceHpGaugeReader) {
        _instanceHpGaugeReader = new HpGaugeReader();
    }
    return _instanceHpGaugeReader;
}

void HpGaugeReader::purge() {
    CC_SAFE_DELETE(_instanceHpGaugeReader);
}

Node* HpGaugeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    HpGauge* node = HpGauge::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
