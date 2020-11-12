#include<cmath>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"input.h"
ENEMY_BULLETS* ENEMY::Bullets = 0;
int ENEMY::Idx = 1;
void ENEMY::init(CONTAINER*c) {
	Img = c->enemyImg;
	Px = c->enemyPx+Idx;
	Py = c->enemyPy;
	Rad = c->enemyRad;
	Color = c->enemyColor;
	Speed = c->enemySpeed;
	Idx += 110;

	ImgW = c->enemyWeponImg;
	RadW = c->enemyWeponRad;

	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY::updata(PLAYER*target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
		Cnt++;
	}
	if (Cnt == 10) {
		Cnt = 0;
		Color.a = 1.0f;
	}
	if (Color.a == 1.0f) {
		Py -= Speed;
	}
	if (Py <= 0) {
		Color.a = 0.0f;
		Py = 1080+50;
	}
	TimeCnt++;

	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
	if (TimeCnt%10==6) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear(Px, Py, RadW);
			//Bullets->appear(Px, Py, Rad + CorrectRad);
			//Bullets->appear(Px, Py, Rad - CorrectRad);

		}
	}
	
}
void ENEMY::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);

}