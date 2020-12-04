#include"ENEMY_ENCOUNT.h"
#include"ENEMIES.h"
ENEMIES* ENEMY_ENCOUNT::Enemies = 0;
void ENEMY_ENCOUNT::updata() {
	if (gameCnt==60) {
		encountTime++;
		gameCnt = 0;
	}
	if (encountTime == 5&&gameCnt==0) {
		Enemies->setColor1(1.0f);//スイッチ
		
	}
	if (encountTime == 10&&gameCnt==0) {
		Enemies->setColor2(1.0f);
		Enemies->setColor3(1.0f);
	}
	if (encountTime == 20 && gameCnt == 0) {
		Enemies->setColor1(1.0f);
		Enemies->setColor2(1.0f);
		Enemies->setColor3(1.0f);
	}
	if (encountTime == 30 && gameCnt == 0) {
		Enemies->setColor1(1.0f);
		Enemies->setColor2(1.0f);
		Enemies->setColor3(1.0f);
	}
	if (encountTime == 40 && gameCnt == 0) {
		
	}
	if (encountTime == 50 && gameCnt == 0) {
		
	}
	if (encountTime == 60 && gameCnt == 0) {
		
	}
	if (encountTime == 70 && gameCnt == 0) {
		
	}
	if (encountTime == 80 && gameCnt == 0) {
		
	}
	if (encountTime == 90 && gameCnt == 0) {
		
	}
	if (encountTime == 100 && gameCnt == 0) {
		
	}
	if (encountTime == 120 && gameCnt == 0) {
		
	}

		gameCnt++;
}