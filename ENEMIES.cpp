#include"ENEMIES.h"
#include"CONTAINER.h"
ENEMIES::ENEMIES(CONTAINER* c) {
	Num = c->enemiesNum;//”z—ñ
	Enemy = new ENEMY[Num];//”z—ñ
}
ENEMIES::~ENEMIES() {
	delete[]Enemy;
}
void ENEMIES::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].init(c);
	}
}
void ENEMIES::updata(PLAYER*target) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].updata(target);
	}
}
void ENEMIES::draw() {
	for (int i = 0; i < Num; i++) {
		Enemy[i].draw();
	}
}
int ENEMIES::num() {
	return Num;
}
ENEMY* ENEMIES::enemy(int i) {
	return Enemy + i;
}