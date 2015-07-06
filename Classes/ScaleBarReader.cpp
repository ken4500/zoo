//
//  ScaleBarReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "ScaleBarReader.h"
#include "ScaleBar.h"

using namespace cocos2d;

static ScaleBarReader* _instanceScaleBarReader = nullptr;

ScaleBarReader* ScaleBarReader::getInstance() {
    if (!_instanceScaleBarReader) {
        _instanceScaleBarReader = new ScaleBarReader();
    }
    return _instanceScaleBarReader;
}

void ScaleBarReader::purge() {
    CC_SAFE_DELETE(_instanceScaleBarReader);
}

Node* ScaleBarReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    ScaleBar* node = ScaleBar::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
