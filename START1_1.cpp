#include"START1_1.h"
#include"CONTAINER.h"
#include"input.h"
#define STATE_PLAY 1
void START1_1::init(CONTAINER*c) {
	Img = c->startImg;
	Px = c->startPx;
	Py = c->startPy;
	Img2 = c->start2Img;
	Px2 = c->start2Px;
	Py2 = c->start2Py;
	Img3 = c->start3Img;
	Px3 = c->start3Px;
	Py3 = c->start3Py;
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
	}

}
void START1_1::draw() {
	drawImage(Img, Px, Py, 0.0f);
	if (BlinkCnt / 10 % 2 == 0) {
		drawImage(Img2, Px2, Py2, 0.0f);
	}
	drawImage(Img3, Px3, Py3, 0.0f);
}