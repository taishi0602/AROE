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
	int num();//Getter�֐�
	ENEMY* enemy(int i);//Getter�֐�
private:
	int Num = 0;//�z��
	ENEMY* Enemy = 0;//�z��
};
