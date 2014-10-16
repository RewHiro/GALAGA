#pragma once
#include "../Object.h"
#include <memory>
#include <array>

class CPlayerMove;
class CBullet;

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

	//�@�e�̍X�V
	void BulletUpdate();

	//�@�e�̕`��
	void BulletDraw();

	//�@�e�̐���
	void CreateBullet();

	//�@�e�̔���
	void Shot();

	std::unique_ptr<CPlayerMove>m_move;
	std::array<std::unique_ptr<CBullet>, 2>m_bullet;
};

