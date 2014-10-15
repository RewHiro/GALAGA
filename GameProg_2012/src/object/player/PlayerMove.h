#pragma once
#include <memory>

class CPlayer;

class CPlayerMove{
public:
	CPlayerMove();

	//�@�X�V
	void Update();

	//�@�X�s�[�h�̎擾
	float GetSpeed(){ return m_velocity; }

private:

	//�@���ɓ�������
	void Left();

	//�@�E�ɓ�������
	void Right();

	//�@�����Ȃ��Ƃ��̏���
	void Stop();

	float m_velocity;				//�@���x
	const float SPEED_VAL;		//�@���x�̒l
};

