#pragma once
enum select {
	Main
};
class CONTAINER;
class PLAY_BACKs;
class PLAYER;
class ENEMIES;
class ENEMY_ENCOUNT;
class ENEMY_BULLETS;
class PLAYER_BULLETS;
class SCORE;
class RESULT;
class GAME {
public:
	GAME();
	~GAME();
	void proc(int*state);
private:
	CONTAINER* C = 0;
	PLAYER* Player = 0;
	PLAY_BACKs* PlayBacks = 0;
	ENEMIES* Enemies = 0;
	ENEMY_ENCOUNT* EnemyEncount = 0;
	ENEMY_BULLETS* EnemyBullets = 0;
	PLAYER_BULLETS* PlayerBullets = 0;
	SCORE* Score = 0;

	RESULT* Result = 0;
	int select = Main;
};