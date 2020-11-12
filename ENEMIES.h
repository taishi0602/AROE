#pragma once
#include"ENEMY.h"
class CONTAINER;
class ENEMIES {
public:
	ENEMIES(CONTAINER* c);
	~ENEMIES();
	void init(CONTAINER* c);
	void updata(PLAYER*target);
	void draw();
private:
	int Num = 0;//”z—ñ
	ENEMY* Enemy = 0;//”z—ñ
};
