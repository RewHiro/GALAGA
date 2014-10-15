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

	float m_velocity;				//　速度
	const float SPEED_VAL;		//　速度の値
};

