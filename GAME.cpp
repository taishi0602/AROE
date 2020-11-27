#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAY_BACKs.h"
#include"ENEMIES.h"
#include"ENEMIES1_2.h"
#include"ENEMIES1_3.h"
#include"ENEMY_BULLETS.h"
#include"ENEMY_BULLET.h"
#include"PLAYER_BULLETS.h"
#include"PLAYER_BULLET.h"
#include"SCORE.h"
#include"GAME.h"
#include"input.h"
#include"RESULT.h"
#include"windows.h"
#define STATE_MAIN 0
#define STATE_RESULT 1
GAME::GAME(){
MessageBox(0, "‚â‚ ", "", 0);
C = new CONTAINER;
Player = new PLAYER;
PlayBacks = new PLAY_BACKs(C);
Enemies = new ENEMIES(C);
Enemies1_2 = new ENEMIES1_2(C);
Enemies1_3 = new ENEMIES1_3(C);
EnemyBullets = new ENEMY_BULLETS(C);
PlayerBullets = new PLAYER_BULLETS(C);
Score = new SCORE;
Result = new RESULT;
ENEMY::setBullets(EnemyBullets);
ENEMY::setPoint(Score);
ENEMY1_2::setBullets(EnemyBullets);
ENEMY1_3::setBullets(EnemyBullets);
PLAYER::setBullets(PlayerBullets);
PLAYER_BULLET::setTargets(Enemies);//©‹@’e‚Í“G‚Ìî•ñ‚ğƒQƒbƒg
ENEMY_BULLET::setTarget(Player);
RESULT::setTarget(Score);
Player->init(C);
PlayBacks->init(C);
Enemies->init(C);
Enemies1_2->init(C);
Enemies1_3->init(C);
EnemyBullets->init(C);
PlayerBullets->init(C);
Score->init(C);
Result->init(C);
}
GAME::~GAME() {
	MessageBox(0, "‚Ğ‚ñ", "", 0);
	delete Player;
	delete PlayBacks;
	delete Enemies;
	delete Enemies1_2;
	delete Enemies1_3;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Score;
	delete Result;
}
void GAME::proc() {
	//“®‚«
	getInput();
	switch (select) {
	case STATE_MAIN:
	Player->updata(&select);
	PlayBacks->updata();
	Enemies->updata(Player);
	Enemies1_2->updata(Player);
	Enemies1_3->updata(Player);
	EnemyBullets->updata();
	PlayerBullets->updata();
	Score->updata();
	//•`‰æ
    clearTarget();
    PlayBacks->draw();
	Player->draw();
	EnemyBullets->draw();
	PlayerBullets->draw();
	Enemies->draw();
	Enemies1_2->draw();
	Enemies1_3->draw();
	Score->draw();
    present();
	break;
	case STATE_RESULT:
	Result->updata();
	clearTarget();
	Result->draw();
	present();

	}
}