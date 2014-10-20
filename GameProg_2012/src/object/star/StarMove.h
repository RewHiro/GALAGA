#pragma once
#include "../../utility/Vec2f.h"

class CStarMove{
public:
	CStarMove();

	//�@�X�V
	void Update();

	//�@�X�s�[�h�̎擾
	Vec2f GetSpeed(){ return m_velocity; }

private:
	const float SPEED_VAL;		//�@���x�̒l
	Vec2f m_velocity;		//�@���x
};

