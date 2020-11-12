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
		Py--;
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
