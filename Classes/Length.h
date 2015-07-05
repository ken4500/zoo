//
//  Length.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#ifndef __Zoo__Length__
#define __Zoo__Length__

#include "CommonInclude.h"

class Length {
public:
    Length(UnitOfLength unit, float length);

    UnitOfLength getUnit();
    float getLength();
    float getMmLength();
    float getLength(UnitOfLength unit);

private:
    float _mm;
};

#endif /* defined(__Zoo__Length__) */
