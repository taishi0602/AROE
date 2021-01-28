#include<cmath>
#include"CONTAINER.h"
#include"PLAYER_BULLET.h"
#include"ENEMIES.h"

ENEMIES* PLAYER_BULLET::Targets = 0;//当たり判定系

void PLAYER_BULLET::init(CONTAINER* c) {
	Img = c->playerBullet.Img;
	Color = c->playerBulletColor;
	AdvSpeed = c->playerBulletAdvSpeed;
	WindowWidth = (float)c->windowWidth;
	WindowHeight = (float)c->windowHeight;

	SqDistance = pow(c->playerBulletDistance, 2);//二乗
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
	//弾　動き
	Px += Dx * AdvSpeed;
	Py += Dy * AdvSpeed;
	if (Px<0 || Px>WindowWidth ||
		Py<0 || Py>WindowHeight) {
		Color.a = 0.0f;
		return;
	}
	//ターゲットと当たった時の動き
	int num = Targets->num();
	for (int i = 0; i < num; i++) {
		ENEMY* target = Targets->enemy(i); //一体分を取りだしている
		float x = target->px() - Px;
		float y = target->py() - Py;
		if (x * x + y * y <= SqDistance) {//当たり判定
			target->damage();//ENEMYへ
			break;
		}
	}
	int num2 = Targets->num2();
	for (int i = 0; i < num2; i++) {
		ENEMY2* target = Targets->enemy2(i); //一体分を取りだしている
		float x = target->px() - Px;
		float y = target->py() - Py;
		if (x * x + y * y <= SqDistance) {//当たり判定
			target->damage();//ENEMYへ
			break;
		}
	}
}
void PLAYER_BULLET::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}