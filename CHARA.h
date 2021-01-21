#pragma once
#include"CONTAINER.h"
#include"ENEMY_BULLETS.h"
#include"SCORE.h"
class CHARA {
public:
	virtual void init();
	virtual void updata();
	virtual void draw();
	virtual void damage();
	virtual float px();
	virtual float py();
protected:
	friend class ENEMIES;//ENEMIESÇ≈ïœçXâ¬î\Ç…ÇµÇƒÇ®Ç≠
	int Img;
	float Px;
	float Py;
	float Rad;
	float Speed;

	int Cnt = 0;
	int TimeCnt = 0;
	COLOR Color;

	int ImgW;
	float RadW;
	int TriggerCnt;
	int TriggerInterval;
	float CorrectRad;
};