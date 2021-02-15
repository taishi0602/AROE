#pragma once
class CONTAINER;
class START1_1 {
public:
	void init(CONTAINER*c);
	void updata(int*state);
	void draw();
private:
	struct sDATA {
	int Img = 0;
    float Px = 0;
    float Py = 0;
	};
	sDATA startScreen;
	sDATA startBotton;
	sDATA startArow;

	int BlinkStart = 0;
	int BlinkCnt = 120;
};