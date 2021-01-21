#include"BULLET.h"
#include<cmath>

void BULLET::init() {
	
}
void BULLET::appear(float px, float py, float rad) {
	Color.a = 1.0f;
	Px = px;
	Py = py;
	Rad = rad;
	Dx = -sin(rad);
	Dy = -cos(rad);
}
void BULLET::updata() {
	
}
void BULLET::draw() {
	drawImage(Img, Px, Py, Rad, Color);
}