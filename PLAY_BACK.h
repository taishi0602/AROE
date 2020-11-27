#pragma once
#include"COLOR.h"
class CONTAINER;
class PLAY_BACK {
public:
	void init(CONTAINER* c);
	void updata();
	void draw();
private:
	friend class PLAY_BACKs;
	static int idx;
	int ImgS = 0;
	int Img[4];
	float Py = 0;
	float Px = 0;
	int timeCnt = 0;
	int roopCnt = 0;
	int i = 0;
	COLOR Color;
};
