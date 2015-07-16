//
//  NovelLayer.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#ifndef __ninjya__NovelLayer__
#define __ninjya__NovelLayer__

#include "cocos2d.h"
#include "Constants.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "NovelAction.h"
#include "NovelPlayer.h"
#include "NovelBalloon.h"
#include "NovelTouchHandler.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

using namespace ui;
using namespace cocostudio;

USING_NS_CC;
using namespace std;

class NovelLayer : public LayerColor
{
    
public:
    NovelLayer();
    virtual ~NovelLayer();
    CREATE_FUNC(NovelLayer);
    virtual bool init();
    static NovelLayer* create(rapidjson::Value& json, GLubyte opacity, bool fade, std::function<void ()> callback, std::function<void ()> callback2 = NULL);
    // ノベル再生を開始する_
    void playNovel();
    void removeSkipButton();
    //! シーン終了処理
    void endScene();

protected:
    
private:
    Sprite* _leftNameImage = NULL;
    Sprite* _rightNameImage = NULL;
    Node* _leftNode = NULL;
    Node* _rightNode = NULL;
    Sprite* _backGroundImage = NULL;
    Sprite* _leftChara =  NULL;
    Sprite* _rightChara = NULL;
    int _debugSkip;
    std::shared_ptr<NovelPlayer> _player = nullptr;
    //! 再生が始まっているかフラグ
    bool _isPlaying = false;
    //! シーン切り替え中フラグ
    bool _isSceneBreak = true;
    //! 背景透明度
    GLubyte _targetOpacity = 255;
    //! 再生が終わったときに呼ばれるコールバック
    std::function<void ()> _endCallback;
    //! 再生が終わったときに呼ばれるコールバック2
    std::function<void ()> _endCallback2;
    //! ノベル開始時・終了時にフェード効果を再生するかどうか
    bool _playFade = false;
    //! フェードアウトに使う画像
    cocos2d::Sprite* _fadeOutOverlaySprite = nullptr;
    int _balloonIdx = 0;
    //! 現在の会話バルーン
    NovelBalloon* _leftBalloon = nullptr;
    //! 現在の会話バルーン
    NovelBalloon* _rightBalloon = nullptr;
    //! デフォルトバルーン（会話以外で使うもの）
    NovelBalloon* _defaultBalloon = nullptr;
    //! タッチ処理するバルーン
    NovelTouchHandler* _touchAbsorber = nullptr;
    //! タッチハンドラ
    cocos2d::EventListenerTouchOneByOne* _touchHandler = nullptr;
    //! 画像表示
    cocos2d::Sprite* _item = nullptr;
    //! アクションインデックス
    int _actionIdx = 0;
    //! 実行中並列アクション
    std::set<int> _inProgressActions;
    // データ読み込みが完了している
    bool _preloadFinished = false;
    
    //! 次のアクションをプレーヤーから取得して再生する
    void playNext();
    //! 次のシーン再生を始める
    void beginScene();
    //! 非同期アクション実行API。すべてのアクションが終わったら playNext が呼ばれる。
    int beginAction();
    void completeAction(int actionIdx);
    
    void clearBalloons();
    void updateSpeechBalloon(std::shared_ptr<NovelAction> action);
    void playDelay(std::shared_ptr<NovelAction> action);
    void showItem(std::shared_ptr<NovelAction> action, const bool fade);
    void hideItem(bool fade);
    void playWait();
    void setImage(std::shared_ptr<NovelAction> action);
    void setNameImage(std::shared_ptr<NovelAction> action);
    void _pushedSkipButton(Ref* sender);
};

#endif /* defined(__ninjya__NovelLayer__) */
