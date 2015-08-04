//
//  Species.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#ifndef __Zoo__AbstractSpecies__
#define __Zoo__AbstractSpecies__

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "Constants.h"
#include "Length.h"
class Weight;

class Species {
public:
    Species(std::string name, rapidjson::Value& json);
    Species(std::string name);
    std::string getName();
    Length getMaxHeight();
    Length getAverageHeight();
    Length getMinHeight();
    Weight getMaxWeight();
    Weight getAverageWeight();
    Weight getMinWeight();
    SizeRank getMaxHeightRank(Length getMaxHeight);
    SizeRank getMinHeightRank(Length getMinHeight);
    Length getSpeed();
    Length getDashSpeed();
    float getDensity();
    std::string getImageName();
    std::string getBackImageName();
    std::string getMoveCsbName();
    bool isMove();
    Length getRandomHeight();
    
    static std::vector<Species*> getAllSpecies();
    static rapidjson::Document document;
    static bool hasJson;

protected:
    std::string _name;
    Length _maxHeight;
    Length _minHeight;
    Length _speed;
    Length _dashSpeed;
    std::string _imageName;
    std::string _moveCsbName;
    float _density;
    bool _move;
    
    void init(std::string name, rapidjson::Value& json);
    double _getStandardDeviation();
};


#endif /* defined(__Zoo__AbstractSpecies__) */
