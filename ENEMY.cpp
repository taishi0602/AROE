#include<cmath>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"SCORE.h"
#include"input.h"
ENEMY_BULLETS* ENEMY::Bullets = 0;
SCORE* ENEMY::Point = 0;
void ENEMY::init(CONTAINER*c) {
	Img[0] = c->enemy1.Img;
	//Img[1] = c->enmey2.Img;�G�l�~�[�Q
	Color = c->enemyColor;//�J���[a�͍ŏ��̓[��
	Speed = c->enemySpeed;

	ImgW = c->enemyWeapon.Img;
	RadW = c->enemyWeponRad;

	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY::updata(PLAYER*target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
	}
	if (Color.a >= 0.1f) {//�J���[�œ���
		Py += Speed;
	}
	if (Py <= -70) {//Py���ȉ��Ŏ~�܂��ĕ\���Ȃ��@�����l��
		Color.a = 0.0f;
		Py = 1144;
	}
	if (Py >= 1150) {
		Color.a = 0.0f;
		Py = -64;
	}
	

	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
	if (TimeCnt%12==5) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear(Px, Py, RadW);
			//Bullets->appear(Px, Py, Rad + CorrectRad);
			//Bullets->appear(Px, Py, Rad - CorrectRad);

		}
	}
	TimeCnt++;
}
void ENEMY::damage() {//�_���[�W���̔���
	Color.a = 0.0f;
	Point->setPoint(100);//�S�|�C���g��SCORE��
}
void ENEMY::draw() {
	drawImage(Img[0], Px, Py, Rad, Color);
	//drawImage(Img[1], Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}
//ENEMY�̓n���Z�b�g
float ENEMY::px() {
	return Px;
}
float ENEMY::py() {
	return Py;
}
