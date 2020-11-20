#pragma once
class CONTAINER;
class PLAYER_BULLET;
class PLAYER_BULLETS {
public:
	PLAYER_BULLETS(CONTAINER* c);
	~PLAYER_BULLETS();
	void init(CONTAINER* c);
	void appear(float px, float py, float rad);
	void updata();
	void draw();
private:
	int Num = 0;
	PLAYER_BULLET* Bullet = 0;
};
