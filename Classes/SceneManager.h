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

class MainScene;
class TitleScene;

class SceneManager {
public:
    static SceneManager* getInstance();
    void enterMainScene();
    void resetMainScene();
    MainScene* getMainScene();
    
private:
    Scene* _mainScene;
    
    SceneManager();
    ~SceneManager();
};

#endif /* defined(__Tetrominos__SceneManager__) */
