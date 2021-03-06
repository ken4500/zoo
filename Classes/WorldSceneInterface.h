//
//  WorldSceneInterface.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef Zoo_WorldSceneInterface_h
#define Zoo_WorldSceneInterface_h

class WorldMap;

class WorldSceneInterface
{
public:
    virtual void updateCoinLabel() = 0;
    virtual void showNoticeView(std::string message, float delay, std::function<void ()> closeCallback) = 0;
    virtual void levelUpEffect(std::function<void()> callback) = 0;
    virtual void transitionMap(WorldMap* newMap) = 0;
    virtual void updateWeightLabel(Weight weight) = 0;
};


#endif
