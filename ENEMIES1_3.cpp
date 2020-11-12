#include"ENEMIES1_3.h"
#include"CONTAINER.h"
ENEMIES1_3::ENEMIES1_3(CONTAINER* c) {
	Num = c->enemies1_3Num;//”z—ñ
	Enemy = new ENEMY1_3[Num];//”z—ñ
}
ENEMIES1_3::~ENEMIES1_3() {
	delete[]Enemy;
}
void ENEMIES1_3::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].init(c);
	}
}
void ENEMIES1_3::updata(PLAYER* target) {
	for (int i = 0; i < Num; i++) {
		Enemy[i].updata(target);
	}
}
void ENEMIES1_3::draw() {
	for (int i = 0; i < Num; i++) {
		Enemy[i].draw();
	}
}