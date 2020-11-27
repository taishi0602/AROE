#pragma once
#include"COLOR.h"
class CONTAINER;
class SCORE;
class RESULT {
public:
	void init(CONTAINER* c);
	void updata();
	void draw();
	static void setTarget(SCORE* score) { Score = score; }
private:
	int Img = 0;
	int Px = 0;
	int Py = 0;
	COLOR Color;

	static SCORE* Score;

	int numImg[10];
	int numPx = 0;
	int numPy = 0;
	int ResultScore = 0;

	int Cnt = 0;

};