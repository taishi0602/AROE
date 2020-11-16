#pragma once
class CONTAINER;
class START1_1 {
public:
	void init(CONTAINER*c);
	void updata(int*state);
	void draw();
private:
	int Img = 0;
    int Px = 0;
    int Py = 0;
	int Img2 = 0;
	int Px2 = 0;
	int Py2 = 0;
	int Img3 = 0;
	int Px3 = 0;
	int Py3 = 0;

	int BlinkStart = 0;
	int BlinkCnt = 120;
};