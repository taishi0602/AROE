#pragma once
#include"COLOR.h"
#include"framework.h"
#include"graphic.h"

class CONTAINER {
public:
	struct DATA {
		int Img = 0;
	    float Px = 0;
		float Py = 0;
		float Rad = 0;
	};
	DATA start;
	DATA startBotton;
	DATA startArow;

	DATA desertBack;
	DATA ruinsBack;
	DATA bossBack;
	DATA scoreBack;
	DATA num[10];


	DATA player;
	DATA playerBullet;
	DATA enemy1_1;
	DATA enemy1_2;
	DATA enemy1_3;
	DATA enemyBullet;
	DATA enemyWeapon;
	CONTAINER() {//GAMEとSTARTで2回呼び出してしまっているので修正予定
		//初期化
		//initialize("Game", 1980, 1080);
		//画像データ
		start.Img = loadImage("start.png");
		startBotton.Img = loadImage("start_buttom.png");
		startArow.Img = loadImage("yazirusi.png");

		desertBack.Img = loadImage("backGround.jpg");
		ruinsBack.Img = loadImage("backGround2.jpg");
		bossBack.Img = loadImage("BossStage.jpg");
		scoreBack.Img = loadImage("play_score.png");

		player.Img = loadImage("heart.png");
		playerBullet.Img = loadImage("heartSmall.png");
		enemy1_1.Img=loadImage("zako_1.png");
		enemyWeapon.Img = loadImage("weapon_1.png");
		enemyBullet.Img = loadImage("zakodann1.png");

		numberImg = loadImage("number0_9.png");//後で
		num[0].Img = divideImage(numberImg, 0, 0, 100, 100);
		num[1].Img = divideImage(numberImg, 100, 0, 200, 100);
		num[2].Img = divideImage(numberImg, 200, 0, 300, 100);
		num[3].Img = divideImage(numberImg, 300, 0, 400, 100);
		num[4].Img = divideImage(numberImg, 400, 0, 500, 100);
		num[5].Img = divideImage(numberImg, 500, 0, 600, 100);
		num[6].Img = divideImage(numberImg, 600, 0, 700, 100);
		num[7].Img = divideImage(numberImg, 700, 0, 800, 100);
		num[8].Img = divideImage(numberImg, 800, 0, 900, 100);
		num[9].Img = divideImage(numberImg, 900, 0, 1000, 100);

		//座標　角度　データ
        start.Px = 960;
		start.Py = 540;
        startBotton.Px=960.0f;
		startBotton.Py=900.0f;
		startArow.Px = 810.0f;
		startArow.Py = 800.0f;

		desertBack.Py = 540.0f;
		desertBack.Px = 660.0f;
		ruinsBack.Py = 540.0f;
		ruinsBack.Px = 660.0f;
		bossBack.Py = 540.0f;
		bossBack.Px = 660.0f;

		player.Px = 660.0f;
		player.Py = 900.0f;
		enemy1_1.Px = windowCenterX - 110;
		enemy1_1.Py = 1145;
        enemy1_1.Rad = 0;
		enemy1_2.Px = 100;
		enemy1_2.Py = -50;
		enemy1_2.Rad = 3.141592f / 180.0 * -120.0f;
		enemy1_3.Px = 1220;
		enemy1_3.Rad = 3.141592 / 180.0f * 120.0f;
	}
	//CONTAINER
	const int windowWidth = 1320;
	const int windowHeight = 1080;
	const float windowCenterX = windowWidth / 2.0f;
	const float windowCenterY = windowHeight / 2.0f;
	const int windowTop = 0;
	const int windowBottom = windowHeight;
	//スタートイメージ
	//int startImg = 0;//スタート画面背景
	
	//int start2Img = 0;//スタート画面Startロゴ
	
	//int start3Img = 0;//スタート画面矢印画像
	
	//プレイ中背景画像

	//自機
	const COLOR playerColor = COLOR(1.0f,0.0f,0.0f,1.0f);
	const int playerBlinkInterval = 5;
	const int playerBlinkNumFrames = 60;

	//自機弾
	const COLOR playerBulletColor = COLOR(1.0f, 1.0f, 1.0f, 0.0f);
	const float playerBulletAdvSpeed = 20.0f;
	const int playerBulletsNum = 30;
	const int playerTriggerInterval = 10;
	const float playerCorrectRad = 0.5;

	//enemy1_1
	const float enemySpeed = 3;
	const COLOR enemyColor = COLOR(0.4f, 0.8f, 1.0f, 0.0f);

	//enemy1_2
	const float enemy1_2Speed = 3;
	const COLOR enemy1_2Color = COLOR(0.4f, 0.8f, 1.0f, 0.0f);
	//enemy1_3

	//enemies
	int enemiesNum = 3;
	int enemies1_2Num = 3;
	int enemies1_3Num = 3;
	//敵弾
	//int enemyBulletImg = 0;
	const COLOR enemyBulletColor = COLOR(1.0f, 0.7f, 0.7f, 0.0f);
	const float enemyBulletAdvSpeed = 20.0f;
	const int enemyBulletsNum = 30;
	const int enemyTriggerInterval = 10;
	const float enemyCorrectRad = 0.5;
	const float enemyBulletAlphaDecayVal = 1.0f / 10;
	//enemyWepon
	//int enemyWeponImg = 0;
	const float enemyWeponRad = 0;
	const float enemyWeponSpeed = 3;
	const COLOR enemyWeponColor = COLOR(0.4f, 0.8f, 1.0f, 1.0f);
	//スコア関連
	int numberImg = 0;//０～９のすべてを含んだ画像
	const COLOR numColor = COLOR(0.0f, 1.0f, 0.0f, 1.0f);
	const float numPx = 1400.0f;
	const float numPy = 250.0f;
};