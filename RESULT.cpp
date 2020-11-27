#include"RESULT.h"
#include"SCORE.h"
#include"CONTAINER.h"
SCORE* RESULT::Score = 0;
void RESULT::init(CONTAINER* c) {
	Img = c->result.Img;
	Px = c->result.Px;
	Py = c->result.Py;

	numImg[0] = c->num[0].Img;
	numImg[1] = c->num[1].Img;
	numImg[2] = c->num[2].Img;
	numImg[3] = c->num[3].Img;
	numImg[4] = c->num[4].Img;
	numImg[5] = c->num[5].Img;
	numImg[6] = c->num[6].Img;
	numImg[7] = c->num[7].Img;
	numImg[8] = c->num[8].Img;
	numImg[9] = c->num[9].Img;

	numPx = c->v2numPx;
	numPy = c->v2numPy;
	Color = c->numColor;
}


void RESULT::updata() {
}
void RESULT::draw() {
	drawImage(Img, Px, Py, 0.0f);
	int score = Score->point();//SCOREから最終的なスコアが返ってくる
	int truss = 10000;//truss(桁)でわっていく
	for (int i = 0; i < 5;i++) {
	    int num = score / truss;
		drawImage(numImg[num], numPx+i*60, numPy, Color);
		score %= truss;
		truss /= 10;
	}
}

