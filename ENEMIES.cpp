#include"ENEMIES.h"
#include"CONTAINER.h"
ENEMIES::ENEMIES(CONTAINER* c) {
	Num = c->enemiesNum;//配列
	Enemy = new ENEMY[Num];//配列 エネミー
}
ENEMIES::~ENEMIES() {
	delete[]Enemy;
}
void ENEMIES::init(CONTAINER* c) {
	for (int i = 0; i < 3; i++) {
		Enemy[i].init(c);
		Enemy[i].Px = 550+Cnt;
		Enemy[i].Py = 1144;
		Enemy[i].Rad = 0;
		Enemy[i].Speed = -3.0f;
		Enemy[i].Color.a = 0;//カラーaで動いたりするようになっているのでENEMY_ENCOUNTでカラーの値を変更する
		Cnt += 110;
	}
	Cnt = 0;
	for (int i = 3; i < 6; i++) {
		Enemy[i].init(c);
		Enemy[i].Px = 100+Cnt;
		Enemy[i].Py = -64;
		Enemy[i].Rad = 3.141592f / 180.0 * -150.0f;
		Enemy[i].Speed = 2.5f;
		Enemy[i].Color.a = 0;
		Cnt += 110;
	}
	Cnt = 0;
	for (int i = 6; i < 9; i++) {
		Enemy[i].init(c);
		Enemy[i].Px = 1000 + Cnt;
		Enemy[i].Py = -64;
		Enemy[i].Rad = 3.141592f / 180.0 * -210.0f;
		Enemy[i].Speed = 2.5f;
		Enemy[i].Color.a = 0;
		Cnt += 110;
	}
}
void ENEMIES::updata(PLAYER*target) {
	for (int i = 0; i < 9; i++) {
		Enemy[i].updata(target);
		if (Enemy[i].Color.a == 0) {//撃たれた後の初期値帰り
			if (i < 3) {
				Enemy[i].Py = 1144;
			}
			else if (i >= 3 && i < 9) {
				Enemy[i].Py = -64;
			}
		}
	}
}
void ENEMIES::draw() {
	for (int i = 0; i < 9; i++) {
		Enemy[i].draw();
	}
}
int ENEMIES::num() {
	return Num;
}
ENEMY* ENEMIES::enemy(int i) {
	return Enemy + i;
}
void ENEMIES::setColor1(float color) {
	for (int i = 0; i < 3; i++) {
		Enemy[i].Color.a = color;
	}
}
void ENEMIES::setColor2(float color) {
	for (int i = 3; i < 6; i++) {
		Enemy[i].Color.a = color;
	}
}
void ENEMIES::setColor3(float color) {
	for (int i = 6; i < 9; i++) {
		Enemy[i].Color.a = color;
	}
}

