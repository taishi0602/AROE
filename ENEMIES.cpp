#include"ENEMIES.h"
#include"CONTAINER.h"
ENEMIES::ENEMIES(CONTAINER* c) {
	Num = c->enemiesNum;//配列
	Num2 = c->enemiesNum2;
	Enemy = new ENEMY[Num];//配列 エネミー
	Enemy2 = new ENEMY2[Num2];
}
ENEMIES::~ENEMIES() {
	delete[]Enemy;
	delete[]Enemy2;

}
void ENEMIES::init(CONTAINER* c) {
	for (int i = 0; i < 3; i++) {
		Enemy[i].init(c);
		Enemy[i].Px = 550+Cnt;
		Enemy[i].Py = 1144;
		Enemy[i].Rad = 0;
		Enemy[i].Speed = -2.5f;
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
		Enemy[i].Rad = 3.141592f / 180.0f * -210.0f;
		Enemy[i].Speed = 2.5f;
		Enemy[i].Color.a = 0;
		Cnt += 110;
	}
	Cnt = 0;
	for (int i = 0; i < 3; i++) {
		Enemy2[i].init(c);
		Enemy2[i].Color.a = 0;//カラーaで動いたりするようになっているのでENEMY_ENCOUNTでカラーの値を変更する
	}
	Enemy2[0].Px =-45;
	Enemy2[0].Py = 80;
	Enemy2[0].Rad = 3.141592/180.0f*90.0f;
	Enemy2[0].Speed = 3.0f;
	Enemy2[1].Px = 1365;
	Enemy2[1].Py = 240;
	Enemy2[1].Rad = 3.141592 / 180.0f * -90.0f;
	Enemy2[1].Speed = -3.0f;
	Enemy2[2].Px = -45;
	Enemy2[2].Py = 480;
	Enemy2[2].Rad = 3.141592 / 180.0f * 90.0f;
	Enemy2[2].Speed = 3.0f;
}
void ENEMIES::updata(PLAYER*target) {
	for (int i = 0; i < 9; i++) {
		Enemy[i].updata(target);
		if (Enemy[i].Color.a == 0) {//撃たれた後の初期値帰り
			if (i < 3) {
				Enemy[i].Py = 1144;
			}
			else if (i >= 3) {
				Enemy[i].Py = -64;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		Enemy2[i].updata(target);
		if (Enemy2[i].Color.a == 0) {//撃たれた後の初期値帰り
			if (i == 0||i==2) {
				Enemy2[i].Px = -45;
			}
			else if (i == 1) {
				Enemy2[i].Px = 1365;
			}
		}
	}
}
void ENEMIES::draw() {
	for (int i = 0; i < 9; i++) {
		Enemy[i].draw();
	}
	for (int i = 0; i < 3; i++) {
		Enemy2[i].draw();
	}
}
int ENEMIES::num() {//PLAYER_BULLETEへおくっている
	return Num;
}
int ENEMIES::num2() {
	return Num2;
}
ENEMY* ENEMIES::enemy(int i) {
	return Enemy + i;
}
ENEMY2* ENEMIES::enemy2(int i) {
	return Enemy2 + i;
}
void ENEMIES::Encount(int enemy) {//種類を渡される
	if (enemy == 1) {//Wave1
		for (int i = 3; i < 9; i++) {
			Enemy[i].Color.a = 1.0f;
		}
	}
	if (enemy == 2) {
		for (int i = 0; i < 3; i++) {
			Enemy[i].Color.a = 1.0f;
		}
		Enemy2[0].Color.a = 1.0f;
		Enemy2[2].Color.a = 1.0f;
	}
	if (enemy == 3) {
		for (int i = 0; i < 3; i++) {
			Enemy[i].Color.a = 1.0f;
		}
		Enemy2[0].Color.a = 1.0f;
		Enemy2[1].Color.a = 1.0f;
	}
	if (enemy == 4) {
		Enemy2[0].Color.a = 1.0f;
	}
	if (enemy == 4) {
		Enemy2[1].Color.a = 1.0f;
	}
	if (enemy == 4) {
		Enemy2[2].Color.a = 1.0f;
	}
}

