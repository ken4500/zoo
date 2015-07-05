//
//  AbstractSpecies.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#ifndef __Zoo__AbstractSpecies__
#define __Zoo__AbstractSpecies__

#include "CommonInclude.h"

class AbstractSpecies {
public:
    AbstractSpecies();
    Length getMaxHeight();
    Length getMinHeight();
    Length getSpeed();
    std::string getImageName();
    std::string getMoveCsbName();

protected:
    Length _maxHeight;
    Length _minHeight;
    Length _speed;
    std::string _imageName;
    std::string _moveCsbName;
};


#endif /* defined(__Zoo__AbstractSpecies__) */
