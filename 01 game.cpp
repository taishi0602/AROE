#include"framework.h"
#include "window.h"
#include"CONTAINER.h"
#include"START.h"
#include"GAME.h"
enum constitute {
    Title,
    Play
};

//�Q�[�������G���g���[�|�C���g------------------------------------------------------------------
void gmain(){
    initialize("Game", 1980, 1080);
    START* start = new START;
    GAME* game = new GAME;
    int state = Title;
    while( msgProc() ){
        switch (state) {
        case Title://�X�^�[�g���
            start->proc(&state);
            break;
        case Play://�{��
            game->proc();
            break;
        }
    }
    delete start;
    delete game;
}
