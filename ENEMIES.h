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
	void setColor1(float color);
	void setColor2(float color);
	void setColor3(float color);
	int num();//Getterä÷êî
	ENEMY* enemy(int i);//Getterä÷êî
private:
	int Num = 0;//îzóÒ
	ENEMY* Enemy = 0;//îzóÒ
	int Cnt=0;
};
