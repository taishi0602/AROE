#pragma once
#include"COLOR.h"
#include"framework.h"
#include"graphic.h"

class CONTAINER {
	class DATA* Data = 0;
	int NumData = 0;
public:
	CONTAINER();
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
	
	//CONTAINER
	const int windowWidth = 1320;//ÉvÉåÉCâÊñ Ç≈ÇÃí[Ç‹Ç≈Ç…Ç†ÇΩÇÈ
	const int windowHeight = 1080;//âÊñ ècÇÃí∑Ç≥
	const float windowCenterX = windowWidth / 2.0f;//ÉvÉåÉCâÊñ íÜâõÇ≈Ç†ÇÈ
	const float windowCenterY = windowHeight / 2.0f;//ècâÊñ ÇÃíÜâõ
	const int windowTop = 0;
	const int windowBottom = windowHeight;
	//é©ã@
	const COLOR playerColor = COLOR(1.0f,1.0f,1.0f,1.0f);
	const int playerBlinkInterval = 5;
	const int playerBlinkNumFrames = 60;

	//é©ã@íe
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
	//ìGíe
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
	//ÉXÉRÉAä÷òA
	int numberImg = 0;//ÇOÅ`ÇXÇÃÇ∑Ç◊ÇƒÇä‹ÇÒÇæâÊëú
	const COLOR numColor = COLOR(0.0f, 1.0f, 0.0f, 1.0f);
	const float numPx = 1400.0f;
	const float numPy = 250.0f;

	const float v2numPx = 780;
	const float v2numPy = 600;

	const int back = 3;
};