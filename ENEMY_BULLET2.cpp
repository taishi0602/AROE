#include<cmath>
#include"CONTAINER.h"
#include"ENEMY_BULLET.h"
#include"PLAYER.h"

PLAYER* ENEMY_BULLET2::Target = 0;//“–‚½‚è”»’èŒn

void ENEMY_BULLET2::init(CONTAINER* c) {
	Img = c->enemyBullet2.Img;
	Color = c->enemyBulletColor;
	AdvSpeed = c->enemyBulletAdvSpeed;
	WindowWidth = (float)c->windowWidth;
	WindowHeight = (float)c->windowHeight;

	AlphaDecayVal = c->enemyBulletAlphaDecayVal;
}
void ENEMY_BULLET2::updata() {
	if (Color.a < 1.0f) {
		Color.a -= AlphaDecayVal;
		return;
	}
	Px += Dx * AdvSpeed;
	Py += Dy * AdvSpeed;
	if (Px<0 || Px>WindowWidth ||
		Py<0 || Py>WindowHeight) {
		Color.a = 0.0f;
		return;
	}
	if (Target->isAttackable()) {
		float RightX = Target->px() + 30;
		float LeftX = Target->px() - 30;
		float TopY = Target->py() - 30;
		float BottomY = Target->py() + 30;
		if (RightX >= Px && LeftX <= Px && TopY <= Py && BottomY >= Py) {
			Color.a -= AlphaDecayVal;
			Target->damege();
		}
	}
}