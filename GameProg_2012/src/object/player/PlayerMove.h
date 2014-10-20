#pragma once
#include "../../utility/Vec2f.h"
#include <memory>

class CPlayer;

class CPlayerMove{
public:
	CPlayerMove(Vec2f &pos);

	//�@�X�V
	void Update();

	//�@�X�s�[�h�̎擾
	Vec2f GetSpeed(){ return m_velocity; }

private:

	//�@���ɓ�������
	void Left();

	//�@�E�ɓ�������
	void Right();

	//�@�����Ȃ��Ƃ��̏���
	void Stop();

	//�@���͈̔͂𒴂����Ƃ��̏���
	void LimitLeft();

	//�@�E�͈̔͂𒴂����Ƃ��̏���
	void LimitRight();

	Vec2f &m_pos;					//�@�|�W�V���������锠
	Vec2f m_velocity;				//�@���x

	const float SPEED_VAL;		//�@���x�̒l
	const float LIMIT_LINE;		//�@���E�̍��W
	const int LIMIT_LEFT;		//�@���ɓ�����͈�
	const int LIMIT_RIGHT;		//�@�E�ɓ�����͈�
};

