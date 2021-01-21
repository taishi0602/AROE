#pragma once
#include"COLOR.h"
#include"CHARA.h"
class CONTAINER;
class PLAYER;
class ENEMY_BULLETS;
class SCORE;
class ENEMY:public CHARA{
public:
	void init(CONTAINER* c);
	void updata(PLAYER*target);
	void damage();
	static void setBullets(ENEMY_BULLETS* bullets) { Bullets = bullets; }
	static void setPoint(SCORE* point) { Point = point; }
	static ENEMY_BULLETS* Bullets;
	static SCORE* Point;
};
class ENEMY2 :public CHARA {
public:
	void init(CONTAINER* c);
	void updata(PLAYER* target);
	void damage();
	static void setBullets(ENEMY_BULLETS* bullets) { Bullets = bullets; }
	static void setPoint(SCORE* point) { Point = point; }
	static ENEMY_BULLETS* Bullets;
	static SCORE* Point;
};

