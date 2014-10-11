#pragma once
class CPlayerMove
{
public:
	CPlayerMove();

	//　更新
	void Update();

private:

	//　左に動く処理
	void Left();

	//　右に動く処理
	void Right();

	//　動かないときの処理
	void Stop();

	float m_velocity;				//　速度
};

