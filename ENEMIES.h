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
	int num();//Getter関数
	ENEMY* enemy(int i);//Getter関数
private:
	int Num = 0;//配列
	ENEMY* Enemy = 0;//配列
	int Cnt=0;
};
