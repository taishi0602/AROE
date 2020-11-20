#include"framework.h"
#include "window.h"
#include"START.h"
#include"GAME.h"
#define STATE_TITLE 0
#define STATE_PLAY 1

//ゲーム処理エントリーポイント------------------------------------------------------------------
void gmain(){
    initialize("Game", 1980, 1080);
    START* start = new START;
    GAME* game = new GAME;
    int state=STATE_TITLE;

    while( msgProc() ){
        switch (state) {
        case STATE_TITLE://スタート画面
            start->proc(&state);
            break;
        case STATE_PLAY://本編
            game->proc();
            break;
        }
    }
    delete start;
    //delete game;
}
