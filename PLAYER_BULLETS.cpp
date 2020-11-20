#include"CONTAINER.h"
#include"PLAYER_BULLET.h"
#include"PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(CONTAINER* c) {
	Num = c->playerBulletsNum;
	Bullet = new PLAYER_BULLET[Num];
}
PLAYER_BULLETS::~PLAYER_BULLETS() {
	delete[]Bullet;
}
void PLAYER_BULLETS::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Bullet[i].init(c);
	}
}
void PLAYER_BULLETS::appear(float px, float py, float rad) {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a <= 0.0f) {
			Bullet[i].appear(px, py, rad);
			break;
		}
	}
}
void PLAYER_BULLETS::updata() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].updata();
		}
	}
}
void PLAYER_BULLETS::draw() {
	for (int i = 0; i < Num; i++) {
		if (Bullet[i].Color.a > 0.0f) {
			Bullet[i].draw();
		}
	}
}