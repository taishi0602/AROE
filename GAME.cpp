#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAY_BACK.h"
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
GAME::GAME(){
C = new CONTAINER;
Player = new PLAYER;
PlayBack = new PLAY_BACK;
Enemies = new ENEMIES(C);
Enemies1_2 = new ENEMIES1_2(C);
Enemies1_3 = new ENEMIES1_3(C);
EnemyBullets = new ENEMY_BULLETS(C);
PlayerBullets = new PLAYER_BULLETS(C);
//Score = new SCORE;
ENEMY::setBullets(EnemyBullets);
ENEMY1_2::setBullets(EnemyBullets);
ENEMY1_3::setBullets(EnemyBullets);
PLAYER::setBullets(PlayerBullets);
PLAYER_BULLET::setTargets(Enemies);//©‹@’e‚Í“G‚Ìî•ñ‚ğƒQƒbƒg
ENEMY_BULLET::setTarget(Player);
Player->init(C);
PlayBack->init(C);
Enemies->init(C);
Enemies1_2->init(C);
Enemies1_3->init(C);
EnemyBullets->init(C);
PlayerBullets->init(C);
//Score->init(C);
}
GAME::~GAME() {
	delete Player;
	delete PlayBack;
	delete Enemies;
	delete Enemies1_2;
	delete Enemies1_3;
	delete EnemyBullets;
	delete PlayerBullets;
	//delete Score;
}
void GAME::proc() {
	getInput();
	Player->updata();
	PlayBack->updata();
	Enemies->updata(Player);
	Enemies1_2->updata(Player);
	Enemies1_3->updata(Player);
	EnemyBullets->updata();
	PlayerBullets->updata();
	//Score->updata();

	clearTarget();
	PlayBack->draw();
	Player->draw();
	EnemyBullets->draw();
	PlayerBullets->draw();
	Enemies->draw();
	Enemies1_2->draw();
	Enemies1_3->draw();
	//Score->draw();
	present();
}