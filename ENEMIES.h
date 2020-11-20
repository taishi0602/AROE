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
	int num();//Getterä÷êî
	ENEMY* enemy(int i);//Getterä÷êî
private:
	int Num = 0;//îzóÒ
	ENEMY* Enemy = 0;//îzóÒ
};
