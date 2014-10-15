#pragma once
#include "SceneManager.h"
#include "../object/Object.h"

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
};

