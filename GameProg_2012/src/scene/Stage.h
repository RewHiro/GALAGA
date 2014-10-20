#pragma once
#include "SceneManager.h"
#include "../object/Object.h"
#include <array>

//=====================================
//�X�e�[�W�N���X
//=====================================

class CStage : public CScene{
public:
	CStage();
	~CStage();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:
	std::unique_ptr<Object>m_player;
	std::array<std::unique_ptr<Object>, 150>m_star;
	
	int c_x;
	int c_y;
	int one_point;
	int ten_points;
	int cregit;
	bool c_zero;

	//�@���̍X�V
	void StarUpdate();

	//�@���̕`��
	void StarDraw();

	//�@�N���W�b�g�̑���
	void CregitControl();

	//�@1���ڂ̃N���W�b�g�̕`��
	void OnePointDraw();
	//�@2���ڂ̃N���W�b�g�̕`��
	void TenPointDraw();

};

