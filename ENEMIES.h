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
	void setColor4(float color);
	void setColor5(float color);
	void setColor6(float color);


	int num();//Getter�֐�
	int num2();//Getter�֐�

	ENEMY* enemy(int i);//Getter�֐�
	ENEMY2* enemy2(int i);//Getter�֐�

private:
	int Num = 0;//�z��
	int Num2 = 0;
	ENEMY* Enemy = 0;//�z��
	ENEMY2* Enemy2 = 0;
	int Cnt=0;
};
