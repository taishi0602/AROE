#include "window.h"
#include"GAME.h"
//�Q�[�������G���g���[�|�C���g------------------------------------------------------------------
void gmain(){
    GAME* game = new GAME;
    while( msgProc() ){
        game->proc();
    }
    delete game;
}
