#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAYER {
public:
	void init(CONTAINER* c);
	void updata();
	void draw();
	void damege();
	void setPx(float px);
	void setPy(float py);
	float px();
	float py();
	bool isAttackable();
private:
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	float Speed = 0;
	int BlinkCnt = 0;
	int BlinkNumFrames = 0;

	COLOR Color;
};
