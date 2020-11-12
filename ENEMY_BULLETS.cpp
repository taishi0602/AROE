#include"CONTAINER.h"
#include"ENEMY_BULLET.h"
#include"ENEMY_BULLETS.h"
ENEMY_BULLETS::ENEMY_BULLETS(CONTAINER* c) {
	Num = c->enemyBulletsNum;
	Bullet = new ENEMY_BULLET[Num];
}
ENEMY_BULLETS::~ENEMY_BULLETS() {
	delete[]Bullet;
}
void ENEMY_BULLETS::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Bullet[i].init(c);
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
void ENEMY_BULLETS::updata() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].updata();
		}
	}
}
void ENEMY_BULLETS::draw() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].draw();
		}
	}
}