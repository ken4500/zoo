//
//  ShopReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#include "ShopReader.h"
#include "Shop.h"

using namespace cocos2d;

static ShopReader* _instanceShopReader = nullptr;

ShopReader* ShopReader::getInstance() {
    if (!_instanceShopReader) {
        _instanceShopReader = new ShopReader();
    }
    return _instanceShopReader;
}

void ShopReader::purge() {
    CC_SAFE_DELETE(_instanceShopReader);
}

Node* ShopReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Shop* node = Shop::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
