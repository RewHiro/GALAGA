#pragma once
#include "../Object.h"
#include <memory>

//=====================================
//���N���X
//=====================================

class CBlink;

class CStar : public Object{
public:
	CStar();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:

	const Vec2f SIZE;		// �T�C�Y
	const float SPEED_VAL;	//�@����
	const int BLINK_TIME;		//�@�_�ł��鎞��
	const unsigned long BLINK_COUNT;			//�@�J�E���g
	const int TRANSPARENCY_STOP_TIME;			//�@�����ɂȂ��Ă鎞��

	int m_red;				//�@��(RGB�l0�`255)
	int m_green;			//�@��(RGB�l0�`255)
	int m_blue;				//�@��(RGB�l0�`255)

	Vec2f m_velocity;		//�@���x

	std::unique_ptr<CBlink>m_blink;

	//�@���Z�b�g
	void Reset();

	//�@�ړ�����
	void Move();

	//�@��������E���C��
	void LimitLine();
};

