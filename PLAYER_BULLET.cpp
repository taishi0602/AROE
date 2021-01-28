#include<cmath>
#include"CONTAINER.h"
#include"PLAYER_BULLET.h"
#include"ENEMIES.h"

ENEMIES* PLAYER_BULLET::Targets = 0;//�����蔻��n

void PLAYER_BULLET::init(CONTAINER* c) {
	Img = c->playerBullet.Img;
	Color = c->playerBulletColor;
	AdvSpeed = c->playerBulletAdvSpeed;
	WindowWidth = (float)c->windowWidth;
	WindowHeight = (float)c->windowHeight;

	SqDistance = pow(c->playerBulletDistance, 2);//���
}
void PLAYER_BULLET::appear(float px, float py, float rad) {
	Color.a = 1.0f;
	Px = px;
	Py = py;
	Rad = rad;
	Dx = -sin(rad);
	Dy = -cos(rad);
}
void PLAYER_BULLET::updata() {
	//�e�@����
	Px += Dx * AdvSpeed;
	Py += Dy * AdvSpeed;
	if (Px<0 || Px>WindowWidth ||
		Py<0 || Py>WindowHeight) {
		Color.a = 0.0f;
		return;
	}
	//�^�[�Q�b�g�Ɠ����������̓���
	int num = Targets->num();
	for (int i = 0; i < num; i++) {
		ENEMY* target = Targets->enemy(i); //��̕�����肾���Ă���
		float x = target->px() - Px;
		float y = target->py() - Py;
		if (x * x + y * y <= SqDistance) {//�����蔻��
			target->damage();//ENEMY��
			break;
		}
	}
	int num2 = Targets->num2();
	for (int i = 0; i < num2; i++) {
		ENEMY2* target = Targets->enemy2(i); //��̕�����肾���Ă���
		float x = target->px() - Px;
		float y = target->py() - Py;
		if (x * x + y * y <= SqDistance) {//�����蔻��
			target->damage();//ENEMY��
			break;
		}
	}
}
void PLAYER_BULLET::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}