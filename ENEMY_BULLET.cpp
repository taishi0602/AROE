#include<cmath>
#include"CONTAINER.h"
#include"ENEMY_BULLET.h"

void ENEMY_BULLET::init(CONTAINER* c) {
	Img = c->enemyBulletImg;
	Color = c->enemyBulletColor;
	AdvSpeed = c->enemyBulletAdvSpeed;
	WindowWidth = (float)c->windowWidth;
	WindowHeight = (float)c->windowHeight;
}
void ENEMY_BULLET::appear(float px, float py, float rad) {
	Color.a = 1.0f;
	Px = px;
	Py = py;
	Rad = rad;
	Dx = -sin(rad);
	Dy = -cos(rad);
}
void ENEMY_BULLET::updata() {
	Px += Dx * AdvSpeed;
	Py += Dy * AdvSpeed;
	if (Px<0 || Px>WindowWidth ||
		Py<0 || Py>WindowHeight) {
		Color.a = 0.0f;
	}
}
void ENEMY_BULLET::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}