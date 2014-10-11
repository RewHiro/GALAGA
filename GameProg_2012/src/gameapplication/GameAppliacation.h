#pragma once
#include "../Uncopyable.h"
#include "../scene/SceneManager.h"
#include "../resource/Resource.h"
#include <memory>

//=====================================
//�A�v���P�[�V�����N���X
//=====================================

class CGameAppliacation : private Uncopyable{
public:

	~CGameAppliacation();

	//�@�C���X�^���X�̎擾
	static CGameAppliacation &GetInstance(){
		static CGameAppliacation instance;
		return instance;
	}

	//�@�X�V
	void Update();

private:
	CGameAppliacation();
	CSceneManager &m_scene_mgr;
	CResource &m_resource;
};