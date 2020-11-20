#include<cmath>
#include"CONTAINER.h"
#include"ENEMY1_3.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
ENEMY_BULLETS* ENEMY1_3::Bullets = 0;
int ENEMY1_3::Idx = 1;
void ENEMY1_3::init(CONTAINER* c) {
	Img = c->enemy1_1.Img;
	Px = c->enemy1_3.Px;
	Py = c->enemy1_2.Py - Idx;
	PyD = Py;
	Rad = c->enemy1_3.Rad;
	Speed = c->enemy1_2Speed;
	Color = c->enemy1_2Color;
	Idx += 110;

	ImgW = c->enemyWeapon.Img;
	RadW = c->enemyWeponRad;
	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY1_3::updata(PLAYER* target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
		Cnt++;
	}
	if (Cnt == 13) {
		Cnt = 0;
		Color.a = 1.0f;
	}
	if (Color.a == 1.0f) {
		Py += Speed;
	}
	if (Py >= 1080) {
		Color.a = 0.0f;
		Py =  PyD;
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
void ENEMY1_3::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}