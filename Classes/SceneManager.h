//
//  SceneManager.h
//  Tetrominos
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#ifndef __Tetrominos__SceneManager__
#define __Tetrominos__SceneManager__

#include "CommonInclude.h"
#include "WorldSceneInterface.h"
class MainScene;
class MultiBattleScene;
class TitleScene;

class SceneManager {
public:
    static SceneManager* getInstance();
    void enterMainScene();
    void resetMainScene();
    MainScene* getMainScene();
    MultiBattleScene* getMultiBattleScene();
    WorldSceneInterface* getWorldScene();
    void enterMultiBattleScene();
    void backMainScene();
    
    bool isNetwork();
    
private:
    Scene* _scene;
    bool _isNetwork;
    
    SceneManager();
    ~SceneManager();
};

#endif /* defined(__Tetrominos__SceneManager__) */
