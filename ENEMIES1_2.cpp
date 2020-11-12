#include"ENEMIES1_2.h"
#include"CONTAINER.h"
ENEMIES1_2::ENEMIES1_2(CONTAINER* c) {
	Num = c->enemies1_2Num;//”z—ñ
	Enemy = new ENEMY1_2[Num];//”z—ñ
}
ENEMIES1_2::~ENEMIES1_2() {
	delete[]Enemy;
}
void ENEMIES1_2::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].init(c);
	}
}
void ENEMIES1_2::updata(PLAYER*target) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].updata(target);
	}
}
void ENEMIES1_2::draw() {
	for (int i = 0; i < Num; i++) {
		Enemy[i].draw();
	}
}