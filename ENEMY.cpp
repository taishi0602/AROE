#include<cmath>
#include<input.h>
#include"CONTAINER.h"
#include"ENEMY.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"SCORE.h"

ENEMY_BULLETS* ENEMY::Bullets = 0;
SCORE* ENEMY::Point = 0;
void ENEMY::init(CONTAINER*c) {
	Img = c->enemy1.Img;//エネミー１画像
	Color = c->enemyColor;//カラーa
	Speed = c->enemySpeed;//動くスピード
	ImgW = c->enemyWeapon.Img;//エネミー武器画像
	RadW = c->enemyWeponRad;//武器の向き
	TriggerInterval = c->enemyTriggerInterval;
	CorrectRad = c->enemyCorrectRad;
}
void ENEMY::updata(PLAYER*target) {
	if (TimeCnt == 60) {
		TimeCnt = 0;
	}
	if (Color.a >= 0.1f) {//カラーで動く
		Py += Speed;
	}
	if (Py <= -70) {//Pyが以下で止まって表示なし　初期値へ
		Color.a = 0.0f;
		Py = 1144;//ゲーム上での画面端（下）
	}
	if (Py >= 1150) {
		Color.a = 0.0f;
		Py = -64;//ゲーム上での画面端（上）
	}
	//敵の弾の発射位置　角度までを調整→ENEMY_BULLETE等で動く
	float dx = target->px() - Px;
	float dy = target->py() - Py;
	RadW = atan2(-dx, -dy);
	if (TimeCnt%12==5) {
		if (TriggerCnt++ % TriggerInterval == 0) {
			Bullets->appear(Px, Py, RadW);
		}
	}
	TimeCnt++;
}
void ENEMY::damage() {//ダメージ時の反応
	Color.a = 0.0f;
	Point->setPoint(100);//百ポイントをSCOREへ
}

