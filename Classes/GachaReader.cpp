//
//  GachaReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "GachaReader.h"
#include "Gacha.h"

using namespace cocos2d;

static GachaReader* _instanceGachaReader = nullptr;

GachaReader* GachaReader::getInstance() {
    if (!_instanceGachaReader) {
        _instanceGachaReader = new GachaReader();
    }
    return _instanceGachaReader;
}

void GachaReader::purge() {
    CC_SAFE_DELETE(_instanceGachaReader);
}

Node* GachaReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Gacha* node = Gacha::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
