#include"CHARA.h"
void CHARA::init() {
	
}
void CHARA::updata() {
	
}
void CHARA::damage() {//ダメージ時の反応
	
}
void CHARA::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}
//ENEMYの渡すセット
float CHARA::px() {
	return Px;
}
float CHARA::py() {
	return Py;
}