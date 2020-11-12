#include<cmath>
#include"CONTAINER.h"
#include"ENEMY1_2.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
ENEMY_BULLETS* ENEMY1_2::Bullets = 0;
int ENEMY1_2::Idx = 0;
void ENEMY1_2::init(CONTAINER* c) {
	Img = c->enemyImg;
	Px = c->enemy1_2Px;
	Py = c->enemy1_2Py-Idx;
	PyD = Py;
	Rad = c->enemy1_2Rad;
	Speed = c->enemy1_2Speed;
	Color =c->enemy1_2Color;
	Idx += 110;

	ImgW = c->enemyWeponImg;
	RadW = c->enemyWeponRad;
	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY1_2::updata(PLAYER*target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
		Cnt++;
	}
	if (Cnt == 13) {
		Cnt = 0;
		Color.a = 1.0f;
	}
	if (Color.a==1.0f) {
		Py += Speed;
	}
	if (Py >= 1080) {
		Color.a = 0.0f;
		Py = PyD;
	}
	TimeCnt++;
	if (TimeCnt % 10 == 6) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear(Px, Py, RadW);
			//Bullets->appear(Px, Py, Rad + CorrectRad);
			//Bullets->appear(Px, Py, Rad - CorrectRad);

		}
	}
	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
}
void ENEMY1_2::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}