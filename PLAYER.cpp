#include"CONTAINER.h"
#include"PLAYER.h"
#include"input.h"
void PLAYER::init(CONTAINER*c) {
	Img = c->playerImg;
	Px = c->playerPx;
	Py = c->playerPy;
}
void PLAYER::updata() {
	if (isPress(KEY_UP)) {
		Py -= 4.0f;
	}
	if (isPress(KEY_DOWN)) {
		Py += 4.0f;
	}
	if (isPress(KEY_LEFT)) {
		Px -= 4.0f;
	}
	else if (isPress(KEY_RIGHT)) {
		Px += 4.0f;
	}
	if (Px <= 65.0f) {
		Px = 65.0f;
	}
	if (Px >= 1255.0f) {
		Px = 1255.0f;
	}
	if (Py <= 90.0f) {
		Py = 90.0f;
	}
	if (Py >= 990.0f) {
		Py = 990.0f;
	}
}
bool PLAYER::isAttackable() {
	if (BlinkCnt <= 0) {
		return true;
	}
	else {
		return false;
	}
}
void PLAYER::damege() {
	BlinkCnt = BlinkNumFrames;
}
void PLAYER::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}
void PLAYER::setPx(float px) {
	Px = px;
}
void PLAYER::setPy(float py) {
	Py = py;
}
float PLAYER::px() {
	return Px;
}
float PLAYER::py() {
	return Py;
}
