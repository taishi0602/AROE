#include<cmath>
#include"CONTAINER.h"
#include"PLAYER_BULLET.h"
#include"ENEMIES.h"

ENEMIES* PLAYER_BULLET::Targets = 0;//ìñÇΩÇËîªíËån

void PLAYER_BULLET::init(CONTAINER* c) {
	Img = c->playerBullet.Img;
	Color = c->playerBulletColor;
	AdvSpeed = c->playerBulletAdvSpeed;
	WindowWidth = (float)c->windowWidth;
	WindowHeight = (float)c->windowHeight;

	//AlphaDecayVal = c->playerBulletAlphaDecayVal;
	//SqDistance = pow(c->playerBulletCollisionDistance, 2);
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
	//íeÅ@ìÆÇ´
	Px += Dx * AdvSpeed;
	Py += Dy * AdvSpeed;
	if (Px<0 || Px>WindowWidth ||
		Py<0 || Py>WindowHeight) {
		Color.a = 0.0f;
		return;
	}
	//É^Å[ÉQÉbÉgÇ∆ìñÇΩÇ¡ÇΩéûÇÃìÆÇ´
	int num = Targets->num();
	for (int i = 0; i < num; i++) {
		ENEMY* target = Targets->enemy(i); //àÍëÃï™ÇéÊÇËÇæÇµÇƒÇ¢ÇÈ
		float RightX = target->px() + 45;
		float LeftX = target->px() - 45;
		float TopY = target->py() - 64;
		float BottomY = target->py() + 64;
		if (RightX >= Px && LeftX <= Px && TopY <= Py && BottomY >= Py) {//ìñÇΩÇËîªíË
			target->damage();//ENEMYÇ÷
			break;
		}
	}
}
void PLAYER_BULLET::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}