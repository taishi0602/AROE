#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAYER_BULLETS;
class PLAYER {
public:
	void init(CONTAINER* c);
	void updata(int*select);
	void draw();
	
	float px();
	float py();

	void damege();
	bool isAttackable();
	static void setBullets(PLAYER_BULLETS* bullets) { Bullets = bullets; }


private:
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Rad = 0;
	float Speed = 0;
    int TriggerInterval = 0;
	int TriggerCnt = 0;

	int BlinkCnt = 0;
	int BlinkInterval = 0;
	int BlinkNumFrames = 0;

	static PLAYER_BULLETS* Bullets;

	COLOR Color;
};
