#include<cmath>
#include<input.h>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"SCORE.h"

ENEMY_BULLETS* ENEMY2::Bullets = 0;
SCORE* ENEMY2::Point = 0;
void ENEMY2::init(CONTAINER* c) {
	Img = c->enemy2.Img;//エネミー2画像
	Color = c->enemyColor;//カラーa
	Speed = c->enemySpeed;//動くスピード
	ImgW = c->enemyWeapon2.Img;//エネミー武器画像
	RadW = c->enemyWeponRad;//武器の向き
	TriggerInterval = c->enemyTriggerInterval2;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY2::updata(PLAYER* target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
	}
	if (Color.a >= 0.1f) {//カラーで動く
		Px += Speed;
	}
	if (Px <= -46) {//Pyが以下で止まって表示なし　初期値へ
		Color.a = 0.0f;
		Px = 1366;//ゲーム上での画面端（右）
	}
	if (Px >= 1366) {
		Color.a = 0.0f;
		Px = -45;//ゲーム上での画面端（左）
	}
	//敵の弾の発射位置　角度までを調整→ENEMY_BULLETE等で動く
	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
	if (TimeCnt % 12 == 5) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear2(Px, Py, RadW);
		}
	}
	TimeCnt++;
}
void ENEMY2::damage() {//ダメージ時の反応
	Color.a = 0.0f;
	Point->setPoint(200);//ポイントをSCOREへ
}