#pragma once
#include "../object/Object.h"

//=====================================
//�_�ŃN���X(�G�t�F�N�g)
//=====================================

//-------------------------------------
//�y���Ӂz
//�E�I�u�W�F�N�g�Ōp���������̂����g�p�ł��Ȃ�
//-------------------------------------

class CBlink{
public:
	//�@state:�I�u�W�F�N�g�̏�Ԃ�����
	//�@blink_time:�_�ł��鎞��
	//�@start_count:�X�^�[�g�̎���
	//�@transparency_stop_time:�������I������
	CBlink(Object::State &state, const int blink_time, const unsigned long start_count, const int transparency_count);

	//�@�X�V
	void Update();

private:
	const int BLINK_TIME;		//�@�_�ł��鎞��
	const int TRANSPARENCY_STOP_TIME;	//�@�������I������
	Object::State &m_state;			//�@��Ԃ����锠
	unsigned long m_count;			//�@�J�E���g
	int m_transparency_count;		//�@�����J�E���g

	//�@�J�E���g���Z�b�g
	void CountReset();

	//�@��Ԃ̑J��
	void TransitionOfState();

	//�@�����ɂȂ鏈��
	void ChanegeOfTransparent();

	//�@��Ԃ�߂�
	void ReturnState();

	//�@�������̏���
	void Transparent();
};

