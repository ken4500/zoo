//
//  Length.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#ifndef __Zoo__Length__
#define __Zoo__Length__

#include "Constants.h"

class Length {
public:
    Length(float length);
    Length(UnitOfLength unit, float length);
    static Length createWithDisplayLength(float displayLength);
    static std::string toString(UnitOfLength unit);
    static UnitOfLength toUnit(std::string str);

    UnitOfLength getUnit();
    std::string getUnitStr();
    float getLength();
    float getMmLength();
    float getLength(UnitOfLength unit);
    float getDisplayLength();
    
    Length add(Length l);
    Length scale(float scale);
    
    static Length add(Length l1, Length l2);
    static Length scale(Length l, float scale);
    Length operator*(float scale) const
    {
        return Length(_mm * scale);
    }
    Length operator/(float scale) const
    {
        return Length(_mm / scale);
    }
    bool operator>(Length b) const
    {
        return _mm > b.getMmLength();
    }
    bool operator<(Length b) const
    {
        return _mm < b.getMmLength();
    }
    bool operator>=(Length b) const
    {
        return _mm >= b.getMmLength();
    }
    bool operator<=(Length b) const
    {
        return _mm <= b.getMmLength();
    }

private:
    static std::map<std::string, UnitOfLength> toUnitMap;
    static std::map<UnitOfLength, std::string> toStringMap;
    float _mm;
};

#endif /* defined(__Zoo__Length__) */

