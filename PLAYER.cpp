#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"input.h"
PLAYER_BULLETS* PLAYER::Bullets = 0;
void PLAYER::init(CONTAINER*c) {
	Img = c->player.Img;
	Px = c->player.Px;
	Py = c->player.Py;
	Color = c->playerColor;
	TriggerInterval = c->playerTriggerInterval;

	BlinkNumFrames = c->playerBlinkNumFrames;
	BlinkInterval = c->playerBlinkInterval;
}
void PLAYER::updata() {
	if (BlinkCnt <= 0 || BlinkCnt-- / BlinkInterval % 2) {//点滅
		Color.a = 1.0f;
	}
	else {
		Color.a = 0.1f;
	}
	if (isPress(KEY_UP)) {
		Py -= 4.0f;
	}
	if (isPress(KEY_DOWN)) {
		Py += 4.0f;
	}
	if (isPress(KEY_LEFT)) {
		Px -= 4.0f;
	}
	if (isPress(KEY_RIGHT)) {
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
	if (isPress(KEY_Z)) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear(Px, Py, Rad);
			//Bullets->appear(Px, Py, Rad + CorrectRad);
			//Bullets->appear(Px, Py, Rad - CorrectRad);

		}
	}
}
bool PLAYER::isAttackable() {//ダメージくらうかどうかの判定　ENEMY_BULLETにあり
	if (BlinkCnt <= 0) {
		return true;
	}
	else {
		return false;
	}
}
void PLAYER::damege() {
	BlinkCnt = BlinkNumFrames;//点滅開始 ダメージ食らったときBlinkCntに60が入って上のアタックえーぶるがFALSEになる
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
