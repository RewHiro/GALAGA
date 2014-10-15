#pragma once
#include "../Object.h"
#include <memory>

class CPlayerMove;

//=====================================
//���@�N���X
//=====================================

class CPlayer : public Object{
public:
	CPlayer();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:
	//�@�����Ă�Ƃ��̕`�揈��
	void LiveDraw();

	//�@�ړ�����
	void MoveUpdate();

	std::unique_ptr<CPlayerMove>m_move;
};

