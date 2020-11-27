#pragma once
#define STATE_MAIN 0
#define STATE_RESULT 1
class CONTAINER;
class PLAY_BACKs;
class PLAYER;
class ENEMIES;
class ENEMIES1_2;
class ENEMIES1_3;
class ENEMY_BULLETS;
class PLAYER_BULLETS;
class SCORE;
class RESULT;
class GAME {
public:
	GAME();
	~GAME();
	void proc();
private:
	CONTAINER* C = 0;
	PLAYER* Player = 0;
	PLAY_BACKs* PlayBacks = 0;
	ENEMIES* Enemies = 0;
	ENEMIES1_2* Enemies1_2 = 0;
	ENEMIES1_3* Enemies1_3 = 0;
	ENEMY_BULLETS* EnemyBullets = 0;
	PLAYER_BULLETS* PlayerBullets = 0;
	SCORE* Score = 0;

	RESULT* Result = 0;
	int select = STATE_MAIN;
};