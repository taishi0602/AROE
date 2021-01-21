#include"CONTAINER.h"
#include"ENEMY_BULLET.h"
#include"ENEMY_BULLETS.h"
ENEMY_BULLETS::ENEMY_BULLETS(CONTAINER* c) {
	Num = c->enemyBulletsNum;
	Bullet = new ENEMY_BULLET[Num];
	Bullet2 = new ENEMY_BULLET2[Num];
}
ENEMY_BULLETS::~ENEMY_BULLETS() {
	delete[]Bullet;
	delete[]Bullet2;
}
void ENEMY_BULLETS::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Bullet[i].init(c);
		Bullet2[i].init(c);
	}
}
void ENEMY_BULLETS::appear(float px, float py, float rad) {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a <= 0.0f) {
			Bullet[i].appear(px, py, rad);
			break;
		}
	}
}
void ENEMY_BULLETS::appear2(float px, float py, float rad) {
	for (int i = 0; i < Num; i++) {
		if (Bullet2[i].Color.a <= 0.0f) {
			Bullet2[i].appear(px, py, rad);
			break;
		}
	}
}
void ENEMY_BULLETS::updata() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].updata();
		}
		if (Bullet2[i].Color.a > 0.0f) {
			Bullet2[i].updata();
		}
	}
}
void ENEMY_BULLETS::draw() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].draw();
		}
		if (Bullet2[i].Color.a > 0.0f) {
			Bullet2[i].draw();
		}
	}
}