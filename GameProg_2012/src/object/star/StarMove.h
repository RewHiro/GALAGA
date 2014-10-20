#pragma once
#include "../../utility/Vec2f.h"

class CStarMove{
public:
	CStarMove();

	//　更新
	void Update();

	//　スピードの取得
	Vec2f GetSpeed(){ return m_velocity; }

private:
	const float SPEED_VAL;		//　速度の値
	Vec2f m_velocity;		//　速度
};

