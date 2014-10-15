#pragma once

//=====================================
//�x�N�g���N���X
//=====================================

class Vec2f{
public:
	Vec2f() = default;
	Vec2f(const float pos_x, const float pos_y);

	Vec2f &operator+=(const Vec2f &vec){
		m_x += vec.m_x;
		m_y += vec.m_y;
		return *this;
	}

	//�@���W���擾
	float x(){ return m_x; }
	float y(){ return m_y; }
	float m_x, m_y;			//�@���W
private:

};