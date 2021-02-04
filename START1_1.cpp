#include<iostream>
#include"START1_1.h"
#include"CONTAINER.h"
#include"input.h"
#define STATE_PLAY 1
void START1_1::init(CONTAINER*c) {
	Img = c->start.Img;
	Px = c->iData("startPx");
	Py = c->iData("startPy");

	Img2 = c->startBotton.Img;
	Px2 = c->startBotton.Px;
	Py2 = c->startBotton.Py;
	Img3 = c->startArow.Img;
	Px3 = c->startArow.Px;
	Py3 = c->startArow.Py;

	BlinkStart = 0;
	BlinkCnt = 120;
}
void START1_1::updata(int*state) {
	if(isTrigger(KEY_Z)&&BlinkStart==0){
		BlinkStart = 1;
		Px3 += 3.0f;
		Py3 += 3.0f;
	}
	if (BlinkCnt==100) {
		Px3 -= 3.0f;
		Py3 -= 3.0f;
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
	drawImage(Img, Px, Py, 0.0f);
	if (BlinkCnt / 10 % 2 == 0) {
		drawImage(Img2, Px2, Py2, 0.0f);
	}
	drawImage(Img3, Px3, Py3, 0.0f);
}