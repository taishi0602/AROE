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
	void Encount(int enemyWave);


	int num();//Getterä÷êî
	int num2();//Getterä÷êî

	ENEMY* enemy(int i);//Getterä÷êî
	ENEMY2* enemy2(int i);//Getterä÷êî

private:
	int Num = 0;//îzóÒ
	int Num2 = 0;
	ENEMY* Enemy = 0;//îzóÒ
	ENEMY2* Enemy2 = 0;
	int Cnt=0;
	int n = 0;
};
