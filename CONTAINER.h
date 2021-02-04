#pragma once
#include"COLOR.h"
#include"framework.h"
#include"graphic.h"

class CONTAINER {
	class DATA* Data = 0;
	int NumData = 0;
public:
	~CONTAINER();
	int loadData(const char* filename);
	float fData(const char* name);
	int iData(const char* name);

	struct DATA2 {
		int Img = 0;
		COLOR color;
	};
	DATA2 start;
	DATA2 startBotton;
	DATA2 startArow;

	DATA2 desertBack;
	DATA2 ruinsBack;
	DATA2 DR_Back;
	DATA2 bossBack;
	DATA2 scoreBack;
	DATA2 num[10];


	DATA2 player;
	DATA2 playerBullet;
	DATA2 enemy1;
	DATA2 enemy2;
	DATA2 enemyBullet;
	DATA2 enemyBullet2;
	DATA2 enemyWeapon;
	DATA2 enemyWeapon2;


	DATA2 result;
	CONTAINER() {
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
		enemy1.Img=loadImage("zako_1.png");
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

		//座標　角度　データ
        start.Px = 960.0f;
		start.Py = 540.0f;
        startBotton.Px=960.0f;
		startBotton.Py=900.0f;
		startArow.Px = 810.0f;
		startArow.Py = 800.0f;

		desertBack.Py = 540.0f;
		desertBack.Px = 660.0f;

		result.Px = 960.0f;
		result.Py = 540.0f;
	}
	//CONTAINER
	const int windowWidth = 1320;//プレイ画面での端までにあたる
	const int windowHeight = 1080;//画面縦の長さ
	const float windowCenterX = windowWidth / 2.0f;//プレイ画面中央である
	const float windowCenterY = windowHeight / 2.0f;//縦画面の中央
	const int windowTop = 0;
	const int windowBottom = windowHeight;
	//自機
	const COLOR playerColor = COLOR(1.0f,1.0f,1.0f,1.0f);
	const int playerBlinkInterval = 5;
	const int playerBlinkNumFrames = 60;

	//自機弾
	const COLOR playerBulletColor = COLOR(1.0f, 1.0f, 1.0f, 0.0f);
	const float playerBulletAdvSpeed = 20.0f;
	const int playerBulletsNum = 30;
	const int playerTriggerInterval = 10;
	const float playerCorrectRad = 0.5;
	const float playerBulletDistance = 45.0f;
	//enemy1
	const float enemySpeed = 3;
	const COLOR enemyColor = COLOR(0.4f, 0.8f, 1.0f, 0.0f);
	const COLOR enemyColor2 = COLOR(1.0f, 1.0f, 1.0f, 0.0f);
	//enemies
	int enemiesNum = 9;
	int enemiesNum2 = 3;
	//敵弾
	//int enemyBulletImg = 0;
	const COLOR enemyBulletColor = COLOR(1.0f, 0.7f, 0.7f, 0.0f);
	const float enemyBulletAdvSpeed = 17.0f;
	const int enemyBulletsNum = 30;
	const int enemyTriggerInterval = 10;
	const int enemyTriggerInterval2 = 5;
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

	const float v2numPx = 780;
	const float v2numPy = 600;

	const int back = 3;
};