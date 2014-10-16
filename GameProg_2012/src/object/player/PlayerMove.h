#pragma once
#include <memory>

class CPlayer;

class CPlayerMove{
public:
	CPlayerMove();

	//　更新
	void Update();

	//　スピードの取得
	float GetSpeed(){ return m_velocity; }

private:

	//　左に動く処理
	void Left();

	//　右に動く処理
	void Right();

	//　動かないときの処理
	void Stop();

	//　動ける限界
	void Limit(float x);

	float m_velocity;				//　速度

	const float SPEED_VAL;		//　速度の値
	const float LIMIT_LINE;		//　限界の座標
};

