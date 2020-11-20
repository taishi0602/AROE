#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAY_BACK {
public:
	void init(CONTAINER* c);
	void updata();
	void draw();
private:
	int ImgS = 0;
	int ImgB2 = 0;
	int ImgB3 = 0;
	int ImgB = 0;
	float PyB = 0;
	float PxB = 0;
	float PyB2 = 0;
	float PxB2 = 0;
	float PyB3 = 0;
	float PxB3 = 0;
	int timeCnt = 0;
};
