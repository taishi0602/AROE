#include"CONTAINER.h"
#include"SCORE.h"
void SCORE::init(CONTAINER* c) {
	Img[0] = c->num[0].Img;
	Img[1] = c->num[1].Img;
	Img[2] = c->num[2].Img;
	Img[3] = c->num[3].Img;
	Img[4] = c->num[4].Img;
	Img[5] = c->num[5].Img;
	Img[6] = c->num[6].Img;
	Img[7] = c->num[7].Img;
	Img[8] = c->num[8].Img;
	Img[9] = c->num[9].Img;

	Px =c->numPx;
	Py =c->numPy;
	Color = c->numColor;
}
void SCORE::updata() {
	
}
void SCORE::draw() {
	int num = 0;
	int truss = 10000;//Œ…‚Å‚í‚Á‚Ä‚¢‚­
	for (int i = 0; i < 5;i++) {

		drawImage(Img[num], Px+i*30, Py, Color);
		truss /= 10;
	}
}