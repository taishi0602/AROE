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
	int num();//Getter関数
	ENEMY* enemy(int i);//Getter関数
private:
	int Num = 0;//配列
	ENEMY* Enemy = 0;//配列
};
