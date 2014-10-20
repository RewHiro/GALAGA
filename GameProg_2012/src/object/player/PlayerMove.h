#pragma once
#include "../../utility/Vec2f.h"
#include <memory>

class CPlayer;

class CPlayerMove{
public:
	CPlayerMove(Vec2f &pos);

	//　更新
	void Update();

	//　スピードの取得
	Vec2f GetSpeed(){ return m_velocity; }

private:

	//　左に動く処理
	void Left();

	//　右に動く処理
	void Right();

	//　動かないときの処理
	void Stop();

	//　左の範囲を超えたときの処理
	void LimitLeft();

	//　右の範囲を超えたときの処理
	void LimitRight();

	Vec2f &m_pos;					//　ポジションを入れる箱
	Vec2f m_velocity;				//　速度

	const float SPEED_VAL;		//　速度の値
	const float LIMIT_LINE;		//　限界の座標
	const int LIMIT_LEFT;		//　左に動ける範囲
	const int LIMIT_RIGHT;		//　右に動ける範囲
};

