#pragma once
class CONTAINER;
class ENEMIES;
class ENEMY_ENCOUNT {
public:
	ENEMY_ENCOUNT();
	void updata();
	static void setColor(ENEMIES* enemies) { Enemies = enemies; }
private:
	struct ENCOUNTDATA {
		int enemyWave;
		int encountTime;
	};
	ENCOUNTDATA encount[6];//敵のパターン数
	int gameCnt = 0;
	int encountTime = 0;
	int encountMax = 0;
	static ENEMIES* Enemies;
};
