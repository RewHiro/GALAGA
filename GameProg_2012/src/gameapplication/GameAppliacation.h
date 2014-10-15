#pragma once
#include "../Uncopyable.h"
#include "../scene/SceneManager.h"
#include "../resource/Resource.h"
#include <memory>

//=====================================
//アプリケーションクラス
//=====================================

class CGameAppliacation : private Uncopyable{
public:

	~CGameAppliacation();

	//　インスタンスの取得
	static CGameAppliacation &GetInstance(){
		static CGameAppliacation instance;
		return instance;
	}

	//　更新
	void Update();

private:
	CGameAppliacation();
	CSceneManager &m_scene_mgr;
	CResource &m_resource;
};