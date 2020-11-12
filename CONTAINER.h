#pragma once
#include"COLOR.h"
#include"framework.h"
#include"graphic.h"

class CONTAINER {
public:
	CONTAINER() {
		//èâä˙âª
		initialize("Game", 1320, 1080);
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
	//é©ã@
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