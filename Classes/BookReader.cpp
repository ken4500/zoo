//
//  BookReader.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#include "BookReader.h"
#include "Book.h"

using namespace cocos2d;

static BookReader* _instanceBookReader = nullptr;

BookReader* BookReader::getInstance() {
    if (!_instanceBookReader) {
        _instanceBookReader = new BookReader();
    }
    return _instanceBookReader;
}

void BookReader::purge() {
    CC_SAFE_DELETE(_instanceBookReader);
}

Node* BookReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Book* node = Book::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
