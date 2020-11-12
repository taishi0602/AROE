#pragma once
class CONTAINER;
class ENEMY_BULLET;
class ENEMY_BULLETS {
public:
	ENEMY_BULLETS(CONTAINER* c);
	~ENEMY_BULLETS();
	void init(CONTAINER* c);
	void appear(float px, float py, float rad);
	void updata();
	void draw();
private:
	int Num = 0;
	ENEMY_BULLET* Bullet = 0;
};
