#include"CONTAINER.h"
#include"START1_1.h"
#include"START.h"
#include"input.h"
START::START() {
	C = new CONTAINER;
	Start = new START1_1;
	Start->init(C);
}
START::~START() {
	delete C;
	delete Start;
}
void START::proc(int* state) {
	getInput();
	Start->updata(state);
	clearTarget();
	Start->draw();

	present();
}