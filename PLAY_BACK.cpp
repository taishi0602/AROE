#include<cmath>
#include"CONTAINER.h"
#include"PLAY_BACK.h"
#include"input.h"
int PLAY_BACK::idx = 0;
void PLAY_BACK::init(CONTAINER* c) {
	Img[0] = c->desertBack.Img;
	Img[1] =  c->DR_Back.Img;
	Img[2] =c->ruinsBack.Img;
	Img[3] = c->bossBack.Img;
	ImgS = c->scoreBack.Img;
	Py = c->desertBack.Py+idx;
	Px = c->desertBack.Px;
	//Color = c->backColor;
	idx -= 1080;
	//PyB2 = c->ruinsBack.Py;
	//PxB2 = c->ruinsBack.Px;
	//PyB3 = c->bossBack.Py;
	//PxB3 = c->bossBack.Px;

}
void PLAY_BACK::updata() {
	if (timeCnt >= 55&&Py==-540) {
		i = 1;
	}
	if (timeCnt >= 60 && Py == -540) {
		i = 2;
	}
	if (timeCnt >= 120 && Py == -540) {
		i = 3;
	}
	Py += 2.5f;
	if (Py >= 1620) {
		Py = -540;
	}
	roopCnt += 1;
	if (roopCnt >= 60) {
		timeCnt++;
		roopCnt = 0;
	}
}
void PLAY_BACK::draw() {
	drawImage(Img[i], Px, Py, 0.0f);

	drawImage(ImgS, 1650, 540, 0.0f);
}