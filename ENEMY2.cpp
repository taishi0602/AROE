#include<cmath>
#include<input.h>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"SCORE.h"

ENEMY_BULLETS* ENEMY2::Bullets = 0;
SCORE* ENEMY2::Point = 0;
void ENEMY2::init(CONTAINER* c) {
	Img = c->enemy2.Img;//�G�l�~�[2�摜
	Color = c->enemyColor;//�J���[a
	Speed = c->enemySpeed;//�����X�s�[�h
	ImgW = c->enemyWeapon2.Img;//�G�l�~�[����摜
	RadW = c->enemyWeponRad;//����̌���
	TriggerInterval = c->enemyTriggerInterval2;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY2::updata(PLAYER* target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
	}
	if (Color.a >= 0.1f) {//�J���[�œ���
		Px += Speed;
	}
	if (Px <= -46) {//Py���ȉ��Ŏ~�܂��ĕ\���Ȃ��@�����l��
		Color.a = 0.0f;
		Px = 1366;//�Q�[����ł̉�ʒ[�i�E�j
	}
	if (Px >= 1366) {
		Color.a = 0.0f;
		Px = -45;//�Q�[����ł̉�ʒ[�i���j
	}
	//�G�̒e�̔��ˈʒu�@�p�x�܂ł𒲐���ENEMY_BULLETE���œ���
	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
	if (TimeCnt % 12 == 5) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear2(Px, Py, RadW);
		}
	}
	TimeCnt++;
}
void ENEMY2::damage() {//�_���[�W���̔���
	Color.a = 0.0f;
	Point->setPoint(200);//�|�C���g��SCORE��
}