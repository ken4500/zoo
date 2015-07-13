//
//  WorldMapReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#include "WorldMapReader.h"
#include "WorldMap.h"

using namespace cocos2d;

static WorldMapReader* _instanceWorldMapReader = nullptr;

WorldMapReader* WorldMapReader::getInstance() {
    if (!_instanceWorldMapReader) {
        _instanceWorldMapReader = new WorldMapReader();
    }
    return _instanceWorldMapReader;
}

void WorldMapReader::purge() {
    CC_SAFE_DELETE(_instanceWorldMapReader);
}

Node* WorldMapReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    WorldMap* node = WorldMap::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
