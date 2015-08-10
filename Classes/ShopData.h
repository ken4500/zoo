//
//  ShopData.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/10.
//
//

#ifndef __Zoo__ShopData__
#define __Zoo__ShopData__

#include "CommonInclude.h"

enum class ShopLineup {
    OFFESE_UP = 0,
    ANIMAL_NUM,
    GET_COIN,
    SPAWN_NUM,
    EMERGE_ENEMY,
    COUNT
};

class ShopData {
public:
    static ShopData* getInstance();
    static std::string toString(ShopLineup lineup);
    static ShopLineup toType(std::string str);
    static std::vector<ShopLineup> getAllType();
    
    int getMaxLevel(ShopLineup lineup);
    int getPrice(ShopLineup lineup, int level);
    float getValue(ShopLineup lineup, int level);
    
private:
    static std::map<ShopLineup, std::string> toStringMap;
    static std::map<std::string, ShopLineup> toTypeMap;
    
    ShopData();
    ~ShopData();
    int _maxLevelList[(int)ShopLineup::COUNT];
    std::vector<int> _priceList[(int)ShopLineup::COUNT];
    std::vector<float> _valueList[(int)ShopLineup::COUNT];

};


#endif /* defined(__Zoo__ShopData__) */
