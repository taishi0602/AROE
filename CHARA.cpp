#include"CHARA.h"
void CHARA::init() {
	
}
void CHARA::updata() {
	
}
void CHARA::damage() {//�_���[�W���̔���
	
}
void CHARA::draw() {
	drawImage(Img, Px, Py, Rad, Color);
	drawImage(ImgW, Px, Py, RadW, Color);
}
//ENEMY�̓n���Z�b�g
float CHARA::px() {
	return Px;
}
float CHARA::py() {
	return Py;
}