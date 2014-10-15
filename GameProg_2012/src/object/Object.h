#pragma once
#include "../utility/Vec2f.h"

//=====================================
//�I�u�W�F�N�g�N���X(���N���X)
//=====================================

class Object{
public:
	Object():
		m_hp(10),
		m_power_val(10),
		m_state(State::LIVE){}
	virtual ~Object() = default;

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	enum class State;
	int m_hp;							//�@hp
	int m_power_val;					//�@�U����
	State m_state;						//�@���݂̏��
	Vec2f m_pos;						//�@�|�W�V����
	Vec2f m_size;						//�@�I�u�W�F�N�g�̑傫��

	//�@��Ԃ̎��
	enum class State{
		NONE,
		LIVE
	};
};

