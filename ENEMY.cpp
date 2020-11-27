#include<cmath>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"SCORE.h"
#include"input.h"
ENEMY_BULLETS* ENEMY::Bullets = 0;
SCORE* ENEMY::Point = 0;
int ENEMY::Idx = 0;
void ENEMY::init(CONTAINER*c) {
	Img = c->enemy1_1.Img;
	Px = c->enemy1_1.Px+Idx;
	Py = c->enemy1_1.Py;
	Rad = c->enemy1_1.Rad;
	Color = c->enemyColor;
	Speed = c->enemySpeed;
	Idx += 110;

	ImgW = c->enemyWeapon.Img;
	RadW = c->enemyWeponRad;

	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;

	//BlinkNumFrames = c->enemyBlinkNumFrames;
	//BlinkInterval = c->enemyBlinkInterval;
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
	if (Color.a >= 0.1f) {
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
void ENEMY::damage() {//ダメージ時の反応
	Color.a = 0.0f;
	Py = 1080 + 50;
	Point->setPoint(100);//百ポイントをSCOREへ
}
void ENEMY::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}
//ENEMYの渡すセット
float ENEMY::px() {
	return Px;
}
float ENEMY::py() {
	return Py;
}
