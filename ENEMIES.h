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
	int num();//Getter�֐�
	ENEMY* enemy(int i);//Getter�֐�
private:
	int Num = 0;//�z��
	ENEMY* Enemy = 0;//�z��
	int Cnt=0;
};
