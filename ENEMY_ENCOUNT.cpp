#include"ENEMY_ENCOUNT.h"
#include"ENEMIES.h"
ENEMIES* ENEMY_ENCOUNT::Enemies = 0;
ENEMY_ENCOUNT::ENEMY_ENCOUNT(CONTAINER*c) {
	c->loadData("DATA.txt");
	encount[0].enemyWave = c->iData("enemyWave0");
	encount[0].encountTime = c->iData("encountTime0");
	encount[1].enemyWave = c->iData("enemyWave1");
	encount[1].encountTime = c->iData("encountTime1");
	encount[2].enemyWave = c->iData("enemyWave2");
	encount[2].encountTime = c->iData("encountTime2");
	encount[3].enemyWave = c->iData("enemyWave3");
	encount[3].encountTime = c->iData("encountTime3");
	encount[4].enemyWave = c->iData("enemyWave4");
	encount[4].encountTime = c->iData("encountTime4");
	encount[5].enemyWave = c->iData("enemyWave5");
	encount[5].encountTime = c->iData("encountTime5");
	encountMax = c->iData("encountMax");
}
void ENEMY_ENCOUNT::updata() {
	if (gameCnt==60) {
		encountTime++;
		gameCnt = 0;
	}
	if (gameCnt == 0) {
		for (int i = 0; i < encountMax; i++) {
			if (encount[i].encountTime == encountTime) {
				Enemies->Encount(encount[i].enemyWave);//Ží—Þ‚ð“n‚µ‚Ä‚ ‚Á‚¿‚ÅŽd•ª‚¯‚³‚¹‚é
			}
		}
	}
		gameCnt++;
}