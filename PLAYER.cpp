#include<iostream>
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"input.h"
enum a {
	Title
};
PLAYER_BULLETS* PLAYER::Bullets = 0;
void PLAYER::init(CONTAINER*c) {
	c->loadData("DATA.txt");
	Px = c->fData("playerPx");
	Py = c->fData("playerPy");
	Rad = c->fData("playerRad");
	Speed = c->fData("playerSpeed");
    BlinkNumFrames = c->iData("playerBlinkNumFrames");
	BlinkInterval = c->iData("playerBlinkInterval");
	TriggerCnt = c->iData("playerTriggerCnt");
	TriggerInterval = c->iData("playerTriggerInterval");
	Img = c->player.Img;
	Color = c->playerColor;
}
void PLAYER::updata(int*state) {
	if (isTrigger(KEY_C)) {
		*state = Title;
	}
	if (BlinkCnt <= 0 || BlinkCnt-- / BlinkInterval % 2) {//点滅
		Color.a = 1.0f;
	}
	else {
		Color.a = 0.1f;
	}
	if (isPress(KEY_UP)) {
		Py -= Speed;
	}
	if (isPress(KEY_DOWN)) {
		Py += Speed;
	}
	if (isPress(KEY_LEFT)) {
		Px -= Speed;
	}
	if (isPress(KEY_RIGHT)) {
		Px +=Speed;
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
float PLAYER::px() {
	return Px;
}
float PLAYER::py() {
	return Py;
}
