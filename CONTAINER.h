#pragma once
#include"COLOR.h"
#include"framework.h"
#include"graphic.h"

class CONTAINER {
public:
	CONTAINER() {
		//初期化
		initialize("Game", 1980, 1080);
		startImg = loadImage("start.png");
		start2Img = loadImage("start_buttom.png");
		start3Img = loadImage("yazirusi.png");
		playerImg = loadImage("heart.png");
		enemyImg=loadImage("zako_1.png");
		enemyWeponImg = loadImage("weapon_1.png");
		enemyBulletImg = loadImage("heartSmall.png");
	}
	//CONTAINER
	const int windowWidth = 1320;
	const int windowHeight = 1080;
	const float windowCenterX = windowWidth / 2.0f;
	const float windowCenterY = windowHeight / 2.0f;
	const int windowTop = 0;
	const int windowBottom = windowHeight;
	//スタートイメージ
	int startImg = 0;//スタート画面背景
	const int startPx = 960;
	const int startPy = 540;
	int start2Img = 0;//スタート画面Startロゴ
	const float start2Px=960.0f;
	const float start2Py=900.0f;
	int start3Img = 0;//スタート画面矢印画像
	const float start3Px = 810.0f;
    float start3Py = 800.0f;
	int State = 0;
	//自機
	int playerImg = 0;
	float playerPx = 500;
	float playerPy = 500;
	//enemy1_1
    int enemyImg = 0;
	float enemyPx = windowCenterX - 110;
    float enemyPy = 1145;
	const float enemyRad = 0;
	const float enemySpeed = 3;
	const COLOR enemyColor = COLOR(0.4f, 0.8f, 1.0f, 0.0f);
	//enemy1_2
	const float enemy1_2Px = 100;
	float enemy1_2Py = -50;
	const float enemy1_2Rad = 3.141592f/180.0*-120.0f;
	const float enemy1_2Speed = 3;
	const COLOR enemy1_2Color = COLOR(0.4f, 0.8f, 1.0f, 0.0f);
	//enemy1_3
	float enemy1_3Px = 1220;
	const float enemy1_3Rad = 3.141592 / 180.0f * 120.0f;
	//enemies
	int enemiesNum = 3;
	int enemies1_2Num = 3;
	int enemies1_3Num = 3;
	//enemyBullet
	int enemyBulletImg = 0;
	const COLOR enemyBulletColor = COLOR(1.0f, 0.7f, 0.7f, 0.0f);
	const float enemyBulletAdvSpeed = 20.0f;
	const int enemyBulletsNum = 30;
	const int enemyTriggerInterval = 10;
	const float enemyCorrectRad = 0.5;
	//enemyWepon
	int enemyWeponImg = 0;
	const float enemyWeponRad = 0;
	const float enemyWeponSpeed = 3;
	const COLOR enemyWeponColor = COLOR(0.4f, 0.8f, 1.0f, 1.0f);
	
};