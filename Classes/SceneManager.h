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
#include "NetworkManagerDelegate.h"
#include "NetworkingWrapper.h"
class MainScene;
class MultiBattleScene;
class TitleScene;

class SceneManager : NetworkingDelegate {
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
    void showPeerList();
    void receiveMultiplayerInvitations();
    void sendData(const void* data, unsigned long length);


    
private:
    std::unique_ptr<NetworkingWrapper> networkingWrapper;
    Scene* _scene;
    bool _isNetwork;
    void receivedData(const void* data, unsigned long length);
    void stateChanged(ConnectionState state);
    
    SceneManager();
    ~SceneManager();
};

#endif /* defined(__Tetrominos__SceneManager__) */
