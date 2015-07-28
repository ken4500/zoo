//
//  CoinTreeReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#include "CoinTreeReader.h"
#include "CoinTree.h"

using namespace cocos2d;

static CoinTreeReader* _instanceCoinTreeReader = nullptr;

CoinTreeReader* CoinTreeReader::getInstance() {
    if (!_instanceCoinTreeReader) {
        _instanceCoinTreeReader = new CoinTreeReader();
    }
    return _instanceCoinTreeReader;
}

void CoinTreeReader::purge() {
    CC_SAFE_DELETE(_instanceCoinTreeReader);
}

Node* CoinTreeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    CoinTree* node = CoinTree::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
