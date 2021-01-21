#pragma once
#include<cmath>
#include"COLOR.h"
#include"BULLET.h"
class CONTAINER;
class PLAYER;

class ENEMY_BULLET:public BULLET {
public:
	void init(CONTAINER* c);
	void updata();

	static void setTarget(PLAYER* target) {
		Target = target;
	}
	static PLAYER* Target;

};
class ENEMY_BULLET2 :public BULLET {
public:
	void init(CONTAINER* c);
	void updata();
	static void setTarget(PLAYER* target) {
		Target = target;
	}
	static PLAYER* Target;

};
