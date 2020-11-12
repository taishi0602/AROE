#pragma once
class CONTAINER;
class PLAYER;
class ENEMIES;
class ENEMIES1_2;
class ENEMIES1_3;
class ENEMY_BULLETS;
class GAME {
public:
	GAME();
	~GAME();
	void proc();
private:
	CONTAINER* C = 0;
	PLAYER* Player = 0;
	ENEMIES* Enemies = 0;
	ENEMIES1_2* Enemies1_2 = 0;
	ENEMIES1_3* Enemies1_3 = 0;
	ENEMY_BULLETS* EnemyBullets = 0;
};