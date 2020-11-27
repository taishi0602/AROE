#include"CONTAINER.h"
#include"SCORE.h"
#include"ENEMY.h"
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
	int score = Point;//ENEMYからスコアが返ってくる
	int truss = 10000;//truss(桁)でわっていく
	for (int i = 0; i < 5;i++) {
	    int num = score / truss;
		drawImage(Img[num], Px+i*60, Py, Color);
		score %= truss;
		truss /= 10;
	}
}
void SCORE::setPoint(int point) {//ENEMYでダメージ時に１００がかえってきて＋される
	Point += point;
}
int SCORE::point() {
	return Point;
}