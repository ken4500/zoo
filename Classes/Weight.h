//
//  Weight.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/31.
//
//

#ifndef __Zoo__Weight__
#define __Zoo__Weight__

#include "Constants.h"
#include "Length.h"

#endif /* defined(__Zoo__Weight__) */

class Weight {
public:
    Weight(float Weight);
    Weight(UnitOfWeight unit, float Weight);
    Weight(Length length, float density);
    static std::string toString(UnitOfWeight unit);
    static UnitOfWeight toUnit(std::string str);

    UnitOfWeight getUnit();
    std::string getUnitStr();
    float getWeight();
    float getMgWeight();
    float getWeight(UnitOfWeight unit);
    float getDisplayWeight();
    
    Weight operator+(Weight a) const
    {
        return Weight(_mg + a.getMgWeight());
    }
    Weight operator-(Weight a) const
    {
        return Weight(_mg - a.getMgWeight());
    }
    Weight operator*(float scale) const
    {
        return Weight(_mg * scale);
    }
    Weight operator/(float scale) const
    {
        return Weight(_mg / scale);
    }
    bool operator>(Weight b) const
    {
        return _mg > b.getMgWeight();
    }
    bool operator<(Weight b) const
    {
        return _mg < b.getMgWeight();
    }
    bool operator>=(Weight b) const
    {
        return _mg >= b.getMgWeight();
    }
    bool operator<=(Weight b) const
    {
        return _mg <= b.getMgWeight();
    }

private:
    static std::map<std::string, UnitOfWeight> toUnitMap;
    static std::map<UnitOfWeight, std::string> toStringMap;
    static std::map<UnitOfWeight, float> toValueMap;

    float _mg;
};
