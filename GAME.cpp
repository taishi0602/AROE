#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAY_BACKs.h"
#include"ENEMIES.h"//敵１達
#include"ENEMY_ENCOUNT.h"//敵の出現
#include"ENEMY_BULLETS.h"
#include"ENEMY_BULLET.h"
#include"PLAYER_BULLETS.h"
#include"PLAYER_BULLET.h"
#include"SCORE.h"
#include"GAME.h"
#include"input.h"
#include"RESULT.h"
#include"windows.h"
enum constitute {//整数上から自動割り当て
	gameMain,
	gameResult,
};
GAME::GAME(){
//MessageBox(0, "始まり", "", 0);
C = new CONTAINER;
Player = new PLAYER;
PlayBacks = new PLAY_BACKs(C);
Enemies = new ENEMIES(C);
EnemyEncount = new ENEMY_ENCOUNT(C);
EnemyBullets = new ENEMY_BULLETS(C);
PlayerBullets = new PLAYER_BULLETS(C);
Score = new SCORE;
Result = new RESULT;
ENEMY::setBullets(EnemyBullets);
ENEMY::setPoint(Score);
ENEMY2::setBullets(EnemyBullets);
ENEMY2::setPoint(Score);
ENEMY_ENCOUNT::setColor(Enemies);//エネミーエンカウントでEnemiesのカラーを手に入れる
PLAYER::setBullets(PlayerBullets);
PLAYER_BULLET::setTargets(Enemies);//自機弾は敵の情報をゲット
ENEMY_BULLET::setTarget(Player);
ENEMY_BULLET2::setTarget(Player);
RESULT::setTarget(Score);
Player->init(C);
PlayBacks->init(C);
Enemies->init(C);
EnemyBullets->init(C);
PlayerBullets->init(C);
Score->init(C);
Result->init(C);
}
GAME::~GAME() {
	//MessageBox(0, "デリート", "", 0);
	delete Player;
	delete PlayBacks;
	delete Enemies;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Score;
	delete Result;
}
void GAME::proc(int*state) {
	//動き
	getInput();
	switch (select) {

	case gameMain:
	Player->updata(state);
	PlayBacks->updata();
	Enemies->updata(Player);
	EnemyEncount->updata();//敵出現
	EnemyBullets->updata();
	PlayerBullets->updata();
	Score->updata();
	//描画
    clearTarget();
    PlayBacks->draw();
	Player->draw();
	EnemyBullets->draw();
	PlayerBullets->draw();
	Enemies->draw();
	Score->draw();
    present();
	break;
	
	case gameResult:
	Result->updata();
	clearTarget();
	Result->draw();
	present();

	}
}