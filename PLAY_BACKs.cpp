#include"CONTAINER.h"
#include"PLAY_BACKs.h"
#include"PLAY_BACK.h"
PLAY_BACKs::PLAY_BACKs(CONTAINER* c) {
	Num = c->back;
	Back = new PLAY_BACK[Num];
}
PLAY_BACKs::~PLAY_BACKs() {
	delete[]Back;
}
void PLAY_BACKs::init(CONTAINER* c) {
	for (int i = 0; i < Num; i++) {
		Back[i].init(c);
	}
}
void PLAY_BACKs::updata() {
	for (int i = 0; i < Num; i++) {
		if (Back[i].Color.a > 0.0f) {
			Back[i].updata();
		}
	}
}
void PLAY_BACKs::draw() {
	for (int i = 0; i < Num; i++) {
		if (Back[i].Color.a > 0.0f) {
			Back[i].draw();
		}
	}
}