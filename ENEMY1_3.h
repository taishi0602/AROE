#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAYER;
class ENEMY_BULLETS;
class ENEMY1_3 {
public:
	void init(CONTAINER* c);
	void updata(PLAYER* target);
	void draw();
	static void setBullets(ENEMY_BULLETS* bullets) { Bullets = bullets; }

private:
	static int Idx;
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float PyD = 0;
	float Rad = 0;
	float Speed = 0;
	int Cnt = 0;
	int TimeCnt = 0;
	COLOR Color;
	static ENEMY_BULLETS* Bullets;


	int ImgW = 0;
	float RadW = 0;
	int TriggerCnt = 0;
	int TriggerInterval = 0;
	float CorrectRad = 0;

};
