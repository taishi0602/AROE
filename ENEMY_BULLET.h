#pragma once
#include"COLOR.h"
class CONTAINER;
class ENEMY_BULLET {
public:
	void init(CONTAINER* c);
	void appear(float px,float py,float rad);
	void updata();
	void draw();
private:
	friend class ENEMY_BULLETS;
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	COLOR Color;
	float Dx = 0;
	float Dy = 0;
	float AdvSpeed = 0;
	float WindowWidth = 0;
	float WindowHeight = 0;
};
