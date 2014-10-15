#include "SceneManager.h"
#include "Stage.h"
#include "DxLib.h"

CSceneManager::Scene CSceneManager::m_now_scene = CSceneManager::Scene::STAGE;
CSceneManager::CSceneManager():
m_state(State::INIT)
{
	ChangeWindowMode(true);
	SetGraphMode(CSceneManager::WIDTH, CSceneManager::HEIGHT, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();   // DXライブラリ初期化処理
}

CSceneManager::~CSceneManager(){
}

//　更新
void CSceneManager::Update(){
	Transition();
	if (m_state == State::UPDATE){
		m_scene->Update();
		InitializeTheState();
	}
}

//　描画
void CSceneManager::Draw(){
	// 画面を初期化
	ClearDrawScreen();
	if (m_state == State::UPDATE){
		m_scene->Draw();
	}
	// 裏画面の内容を表画面に映す
	ScreenFlip();
}

//　遷移処理
void CSceneManager::Transition(){
	if (m_state != State::INIT){ return; }
	m_scene.reset();
	switch (m_now_scene){
	case Scene::TITLE:
		break;
	case Scene::STAGE:
		m_scene = std::make_unique<CStage>();
		break;
	case Scene::RESULT:
		break;
	}
	m_now_scene = m_old_scene;
	m_state = State::UPDATE;
}

//　遷移したいシーンを渡す関数
void CSceneManager::SelectScene(Scene next_scene){
	m_now_scene = next_scene;
}

//　状態を初期化する
void CSceneManager::InitializeTheState(){
	if (m_now_scene == m_old_scene){ return; }
	m_state = State::INIT;
}