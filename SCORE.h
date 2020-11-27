#pragma once
#include"COLOR.h"
class CONTAINER;
class SCORE {
public:
	void init(CONTAINER* c);
	void updata();
	void draw();
	void setPoint(int point);
	int point();
private:
	friend class RESULT;
	int Img[10];
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	COLOR Color;

	int Point = 0;


};