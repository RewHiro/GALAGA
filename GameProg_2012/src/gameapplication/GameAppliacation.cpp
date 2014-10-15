#include "GameAppliacation.h"
#include "../scene/SceneManager.h"
#include "DxLib.h"

CGameAppliacation::CGameAppliacation():
m_scene_mgr(CSceneManager::GetInstacnce()),
m_resource(CResource::GetInstance())
{

}


CGameAppliacation::~CGameAppliacation(){
	DxLib_End();    // DXƒ‰ƒCƒuƒ‰ƒŠI—¹ˆ—
}

void CGameAppliacation::Update(){
	m_scene_mgr.Update();
	m_scene_mgr.Draw();
}