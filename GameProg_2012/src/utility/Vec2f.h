#pragma once

//=====================================
//ベクトルクラス
//=====================================

class Vec2f{
public:
	Vec2f() = default;
	Vec2f(const float pos_x, const float pos_y);

	//　x座標を取得
	float GetPosX(){ return m_x; }

	//　y座標を取得
	float GetPosY(){ return m_y; }

private:
	float m_x, m_y;
};

