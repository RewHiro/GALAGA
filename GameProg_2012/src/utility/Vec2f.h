#pragma once

//=====================================
//�x�N�g���N���X
//=====================================

class Vec2f{
public:
	Vec2f() = default;
	Vec2f(const float pos_x, const float pos_y);

	//�@x���W���擾
	float GetPosX(){ return m_x; }

	//�@y���W���擾
	float GetPosY(){ return m_y; }

private:
	float m_x, m_y;
};

