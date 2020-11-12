#pragma once
#include"ENEMY1_3.h"
class CONTAINER;
class ENEMIES1_3 {
public:
	ENEMIES1_3(CONTAINER* c);
	~ENEMIES1_3();
	void init(CONTAINER* c);
	void updata(PLAYER* target);
	void draw();
private:
	int Num = 0;//”z—ñ
	ENEMY1_3* Enemy = 0;//”z—ñ
};