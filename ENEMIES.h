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


	int num();//Getter関数
	int num2();//Getter関数

	ENEMY* enemy(int i);//Getter関数
	ENEMY2* enemy2(int i);//Getter関数

private:
	int Num = 0;//配列
	int Num2 = 0;
	ENEMY* Enemy = 0;//配列
	ENEMY2* Enemy2 = 0;
	int Cnt=0;
	int n = 0;
};
