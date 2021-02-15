#include<cassert>
#include<stdio.h>
#include"DATA.h"
#include"CONTAINER.h"
CONTAINER::CONTAINER() {
	//画像データ
	start.Img = loadImage("start.png");
	startBotton.Img = loadImage("start_buttom.png");
	startArow.Img = loadImage("yazirusi.png");
	desertBack.Img = loadImage("backGround.png");
	DR_Back.Img = loadImage("backGround1,5.jpg");
	ruinsBack.Img = loadImage("backGround2.jpg");
	bossBack.Img = loadImage("BossStage.jpg");
	scoreBack.Img = loadImage("play_score.png");
	player.Img = loadImage("jiki.png");
	playerBullet.Img = loadImage("jiki_tama.png");
	enemy1.Img = loadImage("zako_1.png");
	enemy2.Img = loadImage("zako_2.png");
	enemyWeapon.Img = loadImage("weapon_1.png");
	enemyWeapon2.Img = loadImage("weapon_2.png");
	enemyBullet.Img = loadImage("zakodann1.png");
	enemyBullet2.Img = loadImage("zakodann2.png");
	numberImg = loadImage("number0_9.png");//後で
	num[0].Img = divideImage(numberImg, 0, 0, 100, 100);
	num[1].Img = divideImage(numberImg, 100, 0, 100, 100);
	num[2].Img = divideImage(numberImg, 200, 0, 100, 100);
	num[3].Img = divideImage(numberImg, 300, 0, 100, 100);
	num[4].Img = divideImage(numberImg, 400, 0, 100, 100);
	num[5].Img = divideImage(numberImg, 500, 0, 100, 100);
	num[6].Img = divideImage(numberImg, 600, 0, 100, 100);
	num[7].Img = divideImage(numberImg, 700, 0, 100, 100);
	num[8].Img = divideImage(numberImg, 800, 0, 100, 100);
	num[9].Img = divideImage(numberImg, 900, 0, 100, 100);
	result.Img = loadImage("resultBack.png");
}
int CONTAINER::loadData(const char* filename) {
	FILE* fp = 0;
	fopen_s(&fp, filename, "r");
	assert(fp != 0);
	//dataファイルの一行目はdata数でなければならない
	fscanf_s(fp, "%d", &NumData);
	//Dataを確保
	Data = new DATA[NumData];//DATA.h DATA.cppはこのためにある
	//読み込む
	char name[256];
	float value;
	for (int i = 0; i < NumData; i++) {
		//すべてfloat値で読み込む
		fscanf_s(fp, "%s %f", name, 256, &value);
		Data[i].setName(name);
		Data[i].setValue(value);
	}
	fclose(fp);
	return 0;
}
CONTAINER::~CONTAINER() {
	if (Data) {
		delete[] Data;
		Data = 0;
	}
}
float CONTAINER::fData(const char* name) {
	int i;
	for (i = 0; i < NumData; i++) {
		if (Data[i].name() == name) {
			return Data[i].value();
		}
	}
	assert(i < Numdata);
	return 0;
}
int CONTAINER::iData(const char* name) {
	int i;
	for (i = 0; i < NumData; i++) {
		if (Data[i].name() == name) {
			return (int)Data[i].value();
		}
	}
	assert(i < NumData);
	return 0;
}

