#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAY_BACKs.h"
#include"ENEMIES.h"//“G‚P’B
#include"ENEMY_ENCOUNT.h"//“G‚ÌoŒ»
#include"ENEMY_BULLETS.h"
#include"ENEMY_BULLET.h"
#include"PLAYER_BULLETS.h"
#include"PLAYER_BULLET.h"
#include"SCORE.h"
#include"GAME.h"
#include"input.h"
#include"RESULT.h"
#include"windows.h"
enum constitute {//®”ã‚©‚ç©“®Š„‚è“–‚Ä
	gameMain,
	gameResult,
};
GAME::GAME(){
//MessageBox(0, "n‚Ü‚è", "", 0);
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
ENEMY_ENCOUNT::setColor(Enemies);//ƒGƒlƒ~[ƒGƒ“ƒJƒEƒ“ƒg‚ÅEnemies‚ÌƒJƒ‰[‚ğè‚É“ü‚ê‚é
PLAYER::setBullets(PlayerBullets);
PLAYER_BULLET::setTargets(Enemies);//©‹@’e‚Í“G‚Ìî•ñ‚ğƒQƒbƒg
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
	//MessageBox(0, "ƒfƒŠ[ƒg", "", 0);
	delete Player;
	delete PlayBacks;
	delete Enemies;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Score;
	delete Result;
}
void GAME::proc(int*state) {
	//“®‚«
	getInput();
	switch (select) {

	case gameMain:
	Player->updata(state);
	PlayBacks->updata();
	Enemies->updata(Player);
	EnemyEncount->updata();//“GoŒ»
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