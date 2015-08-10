//
//  TransmigrationReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#include "TransmigrationReader.h"
#include "Transmigration.h"

using namespace cocos2d;

static TransmigrationReader* _instanceTransmigrationReader = nullptr;

TransmigrationReader* TransmigrationReader::getInstance() {
    if (!_instanceTransmigrationReader) {
        _instanceTransmigrationReader = new TransmigrationReader();
    }
    return _instanceTransmigrationReader;
}

void TransmigrationReader::purge() {
    CC_SAFE_DELETE(_instanceTransmigrationReader);
}

Node* TransmigrationReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Transmigration* node = Transmigration::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
