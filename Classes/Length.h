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
    Length(float length);
    Length(UnitOfLength unit, float length);
    static std::string toString(UnitOfLength unit);
    static UnitOfLength toUnit(std::string str);

    UnitOfLength getUnit();
    std::string getUnitStr();
    float getLength();
    float getMmLength();
    float getLength(UnitOfLength unit);
    
    void add(Length* l);
    void scale(float scale);
    
    static Length* add(Length* l1, Length* l2);
    static Length* scale(Length* l, float scale);

private:
    static std::map<std::string, UnitOfLength> toUnitMap;
    static std::map<UnitOfLength, std::string> toStringMap;
    float _mm;
};

#endif /* defined(__Zoo__Length__) */

