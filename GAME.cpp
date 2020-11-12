#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"ENEMIES1_2.h"
#include"ENEMIES1_3.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"input.h"
GAME::GAME(){
C = new CONTAINER;
Player = new PLAYER;
Enemies = new ENEMIES(C);
Enemies1_2 = new ENEMIES1_2(C);
Enemies1_3 = new ENEMIES1_3(C);
EnemyBullets = new ENEMY_BULLETS(C);
ENEMY::setBullets(EnemyBullets);
ENEMY1_2::setBullets(EnemyBullets);
ENEMY1_3::setBullets(EnemyBullets);
Player->init(C);
Enemies->init(C);
Enemies1_2->init(C);
Enemies1_3->init(C);
EnemyBullets->init(C);
}
GAME::~GAME() {
	delete Player;
	delete Enemies;
	delete Enemies1_2;
	delete Enemies1_3;
	delete EnemyBullets;
}
void GAME::proc() {
	getInput();
	Player->updata();
	Enemies->updata(Player);
	Enemies1_2->updata(Player);
	Enemies1_3->updata(Player);
	EnemyBullets->updata();

	clearTarget();
	Player->draw();
	EnemyBullets->draw();
	Enemies->draw();
	Enemies1_2->draw();
	Enemies1_3->draw();
	present();
}