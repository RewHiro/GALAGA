#include "Stage.h"
#include "SceneManager.h"
#include "../object/player/Player.h"
#include "../../DxLib/DxLib.h"

CStage::CStage():
m_player(std::make_unique<CPlayer>())
{
}


CStage::~CStage(){
}

//　更新
void CStage::Update(){
	m_player->Update();
}

//　描画
void CStage::Draw(){
	//DrawCircle(CSceneManager::WIDTH / 2, CSceneManager::HEIGHT / 2, 10, GetColor(255, 0, 0), true);
	m_player->Draw();
}