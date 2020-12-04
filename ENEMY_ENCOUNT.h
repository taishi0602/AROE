#pragma once
class CONTAINER;
class ENEMIES;
class ENEMY_ENCOUNT {
public:
	void updata();
	static void setColor(ENEMIES* enemies) { Enemies = enemies; }
private:
	int gameCnt = 0;
	int encountTime = 0;
	static ENEMIES* Enemies;
};
