#pragma once
#include"COLOR.h"
class CONTAINER;
class ENEMIES;//“–‚½‚è”»’èŒn‚Å
class ENEMIES1_2;
class PLAYER_BULLET {
public:
	void init(CONTAINER* c);
	void appear(float px, float py, float rad);
	void updata();
	void draw();
	static void setTargets(ENEMIES* targets) { Targets = targets; }
	static void setTargets(ENEMIES1_2* targets2) { Targets2 = targets2; }

private:
	friend class PLAYER_BULLETS;
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

	float SqDistance = 0;
	static ENEMIES* Targets;
	static ENEMIES1_2* Targets2;
};