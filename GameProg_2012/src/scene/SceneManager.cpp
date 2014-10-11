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
	DxLib_Init();   // DX���C�u��������������
}

CSceneManager::~CSceneManager(){
}

//�@�X�V
void CSceneManager::Update(){
	Transition();
	if (m_state == State::UPDATE){
		m_scene->Update();
		InitializeTheState();
	}
}

//�@�`��
void CSceneManager::Draw(){
	// ��ʂ�������
	ClearDrawScreen();
	if (m_state == State::UPDATE){
		m_scene->Draw();
	}
	// ����ʂ̓��e��\��ʂɉf��
	ScreenFlip();
}

//�@�J�ڏ���
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

//�@�J�ڂ������V�[����n���֐�
void CSceneManager::SelectScene(Scene next_scene){
	m_now_scene = next_scene;
}

//�@��Ԃ�����������
void CSceneManager::InitializeTheState(){
	if (m_now_scene == m_old_scene){ return; }
	m_state = State::INIT;
}