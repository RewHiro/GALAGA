#pragma once
#include "SceneManager.h"
#include "../object/Object.h"

//=====================================
//ステージクラス
//=====================================

class CStage : public CScene{
public:
	CStage();
	~CStage();

	//　更新
	void Update();

	//　描画
	void Draw();

private:
	std::unique_ptr<Object>m_player;
};

