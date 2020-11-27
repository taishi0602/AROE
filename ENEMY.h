#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAYER;
class ENEMY_BULLETS;
class SCORE;
class ENEMY {
public:
	void init(CONTAINER* c);
	void updata(PLAYER*target);
	void draw();
	static void setBullets(ENEMY_BULLETS* bullets) { Bullets = bullets; }
	static void setPoint(SCORE* point) { Point = point; }
	
	float px();
	float py();

	void damage();
private:
	static int Idx;
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	float Speed = 0;
	int Cnt = 0;
	int TimeCnt = 0;
	COLOR Color;
	static ENEMY_BULLETS* Bullets;
	static SCORE* Point;

	int ImgW = 0;
	float RadW;
	int TriggerCnt = 0;
	int TriggerInterval = 0;
	float CorrectRad = 0;

};
