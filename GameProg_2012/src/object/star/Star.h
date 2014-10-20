#pragma once
#include "../Object.h"
#include <memory>

//=====================================
//星クラス
//=====================================

class CBlink;

class CStar : public Object{
public:
	CStar();

	//　更新
	void Update();

	//　描画
	void Draw();

private:

	const Vec2f SIZE;		// サイズ
	const float SPEED_VAL;	//　速さ
	const int BLINK_TIME;		//　点滅する時間
	const unsigned long BLINK_COUNT;			//　カウント
	const int TRANSPARENCY_STOP_TIME;			//　透明になってる時間

	int m_red;				//　赤(RGB値0～255)
	int m_green;			//　緑(RGB値0～255)
	int m_blue;				//　青(RGB値0～255)

	Vec2f m_velocity;		//　速度

	std::unique_ptr<CBlink>m_blink;

	//　リセット
	void Reset();

	//　移動処理
	void Move();

	//　動ける限界ライン
	void LimitLine();
};

