#pragma once
#include"ENEMY1_2.h"
class CONTAINER;
class ENEMIES1_2 {
public:
	ENEMIES1_2(CONTAINER* c);
	~ENEMIES1_2();
	void init(CONTAINER* c);
	void updata(PLAYER*target);
	void draw();
private:
	int Num = 0;//”z—ñ
	ENEMY1_2* Enemy = 0;//”z—ñ
};

