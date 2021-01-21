#pragma once
#include"PLAYER.h"
#include"CONTAINER.h"
class BULLET {
public:
	virtual void init();
	virtual void appear(float px, float py, float rad);
	virtual void updata();
	virtual void draw();
	
protected:
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

	float AlphaDecayVal = 0;
};