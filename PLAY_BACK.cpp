#include<cmath>
#include"CONTAINER.h"
#include"PLAY_BACK.h"
#include"input.h"
void PLAY_BACK::init(CONTAINER* c) {
	ImgB = c->desertBack.Img;
	ImgB2 = c->ruinsBack.Img;
	ImgB3 = c->bossBack.Img;
	ImgS = c->scoreBack.Img;
	PyB = c->desertBack.Py;
	PxB = c->desertBack.Px;
	PyB2 = c->ruinsBack.Py;
	PxB2 = c->ruinsBack.Px;
	PyB3 = c->bossBack.Py;
	PxB3 = c->bossBack.Px;

}
void PLAY_BACK::updata() {
	timeCnt+=5;
	PyB += 2.5f;
	if (PyB >= 1620 && timeCnt / 60 <= 58) {//ゲーム内1分までスクロール
		PyB = 540;
	}
	PyB2 += 2.5f;
	if (PyB2 >= 1620 && (timeCnt / 60 >= 60 && timeCnt / 60 <= 118)) {//ゲーム内1分から2分までスクロール
		PyB2 = 540;
	}
	if (timeCnt / 60 >= 120 && timeCnt / 60 <= 121) {//ゲーム内2分からスクロールして止まる
		PyB3 += 9.0f;
	}
}
void PLAY_BACK::draw() {
	if (timeCnt >= 0 && timeCnt / 60 <= 62) {
		drawImage(ImgB, PxB, PyB, 0.0f);
		drawImage(ImgB, PxB, PyB - 1080, 0.0f);
	}
	if (timeCnt / 60 >= 60 && timeCnt / 60 <= 122) {
		drawImage(ImgB2, PxB2, PyB2, 0.0f);
		drawImage(ImgB2, PxB2, PyB2 - 1080, 0.0f);
	}
	if (timeCnt / 60 >= 120) {
		drawImage(ImgB3, PxB3, PyB3, 0.0f);
		drawImage(ImgB3, PxB3, PyB3 - 1080, 0.0f);
	}
	drawImage(ImgS, 1650, 540, 0.0f);
}