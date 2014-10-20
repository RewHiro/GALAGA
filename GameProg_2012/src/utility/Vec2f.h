#pragma once

//=====================================
//ベクトルクラス
//=====================================

class Vec2f{
public:
	Vec2f() = default;
	Vec2f(const float pos_x, const float pos_y) :
		m_x(pos_x),
		m_y(pos_y){}

	//　+=演算子
	Vec2f &operator+=(const Vec2f &vec){
		m_x += vec.m_x;
		m_y += vec.m_y;
		return *this;
	}

	//　-=演算子
	Vec2f &operator-=(const Vec2f &vec){
		m_x -= vec.m_x;
		m_y -= vec.m_y;
		return *this;
	}

	//　+演算子
	Vec2f operator+(const Vec2f &vec){
		Vec2f add;
		add.m_x = m_x + vec.m_x;
		add.m_y = m_y + vec.m_y;
		return add;
	}

	//　/演算子
	Vec2f operator/(const float div){
		Vec2f add;
		add.m_x = m_x / div;
		add.m_y = m_y / div;
		return add;
	}


	//　座標を取得
	float x(){ return m_x; }
	float y(){ return m_y; }

private:
	float m_x, m_y;			//　座標
};