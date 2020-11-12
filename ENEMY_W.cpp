//#include<cmath>
//#include"ENEMY_W.h"
//#include"CONTAINER.h"
//#include"PLAYER.h"
//void ENEMY_W::init(CONTAINER* c) {
//	Img = c->enemyWeponImg;
//	Px = c->enemyWeponPx;
//	Py = c->enemyWeponPy;
//	Rad = c->enemyWeponRad;
//	Color = c->enemyWeponColor;
//}
//void ENEMY_W::updata(PLAYER* target) {
//	float dx = target->px() - Px;
//	float dy = target->py() - Py;
//	Rad = atan2(-dx, -dy);
//}
//void ENEMY_W::draw() {
//	drawImage(Img, Px, Py, Rad, Color);
//}