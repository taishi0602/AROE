#include "window.h"
#include"GAME.h"
//ゲーム処理エントリーポイント------------------------------------------------------------------
void gmain(){
    GAME* game = new GAME;
    while( msgProc() ){
        game->proc();
    }
    delete game;
}
