#include"ENEMY_ENCOUNT.h"
#include"ENEMIES.h"
ENEMIES* ENEMY_ENCOUNT::Enemies = 0;
ENEMY_ENCOUNT::ENEMY_ENCOUNT() {
	encount[0].enemyWave = 1;
	encount[0].encountTime = 5;
	encount[1].enemyWave = 2;
	encount[1].encountTime = 10;
	encount[2].enemyWave = 3;
	encount[2].encountTime = 15;
	encount[3].enemyWave = 4;
	encount[3].encountTime = 30;
	encount[4].enemyWave = 5;
	encount[4].encountTime = 30;
	encount[5].enemyWave = 6;
	encount[5].encountTime = 30;
	encountMax = 10;
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