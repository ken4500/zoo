//
//  LackLifeReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/11.
//
//

#include "LackLifeReader.h"
#include "LackLife.h"

using namespace cocos2d;

static LackLifeReader* _instanceLackLifeReader = nullptr;

LackLifeReader* LackLifeReader::getInstance() {
    if (!_instanceLackLifeReader) {
        _instanceLackLifeReader = new LackLifeReader();
    }
    return _instanceLackLifeReader;
}

void LackLifeReader::purge() {
    CC_SAFE_DELETE(_instanceLackLifeReader);
}

Node* LackLifeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    LackLife* node = LackLife::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
