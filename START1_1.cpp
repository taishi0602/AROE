#include<iostream>
#include"START1_1.h"
#include"CONTAINER.h"
#include"input.h"
#define STATE_PLAY 1
void START1_1::init(CONTAINER*c) {
	c->loadData("DATA.txt");
	startScreen.Img = c->start.Img;
	startScreen.Px = c->iData("startScreenPx");
	startScreen.Py = c->iData("startScreenPy");
	startBotton.Img = c->startBotton.Img;
	startBotton.Px = c->iData("startBottonPx");
	startBotton.Py = c->iData("startBottonPy");
	startArow.Img = c->startArow.Img;
	startArow.Px = c->iData("startArowPx");
	startArow.Py= c->iData("startArowPy");

	BlinkStart = 0;
	BlinkCnt = 120;
}
void START1_1::updata(int*state) {
	if(isTrigger(KEY_Z)&&BlinkStart==0){
		BlinkStart = 1;
		startArow.Px += 3.0f;
		startArow.Py += 3.0f;
	}
	if (BlinkCnt==100) {
		startArow.Px -= 3.0f;
		startArow.Py -= 3.0f;
	}
	if (BlinkStart == 1) {
		BlinkCnt--;
	}
	if (BlinkCnt <= 0) {
		*state = STATE_PLAY;
		BlinkStart=0;
		BlinkCnt = 120;
	}

}
void START1_1::draw() {
	drawImage(startScreen.Img, startScreen.Px, startScreen.Py, 0.0f);
	if (BlinkCnt / 10 % 2 == 0) {
		drawImage(startBotton.Img, startBotton.Px, startBotton.Py, 0.0f);
	}
	drawImage(startArow.Img, startArow.Px, startArow.Py, 0.0f);
}