//
//  AnimalReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "AnimalReader.h"
#include "Animal.h"

using namespace cocos2d;

static AnimalReader* _instanceAnimalReader = nullptr;

AnimalReader* AnimalReader::getInstance() {
    if (!_instanceAnimalReader) {
        _instanceAnimalReader = new AnimalReader();
    }
    return _instanceAnimalReader;
}

void AnimalReader::purge() {
    CC_SAFE_DELETE(_instanceAnimalReader);
}

Node* AnimalReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Animal* node = Animal::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
