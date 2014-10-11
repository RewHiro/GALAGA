#include "Player.h"
#include "../../resource/Resource.h"
#include "../../utility/Vec2f.h"
#include "../../scene/SceneManager.h"
#include "PlayerMove.h"
#include "../../../DxLib/DxLib.h"
//#define Debug

CPlayer::CPlayer():
m_move(std::unique_ptr<CPlayerMove>())
{
	m_size = Vec2f(64, 64);
	m_pos = Vec2f(CSceneManager::WIDTH / 2 - m_size.GetPosX() / 2,
		CSceneManager::HEIGHT - m_size.GetPosY());
}

//�@�X�V
void CPlayer::Update(){
	m_move->Update();
}

//�@�`��
void CPlayer::Draw(){
	LiveDraw();
}

//�@�����Ă�Ƃ��̕`�揈��
void CPlayer::LiveDraw(){

	if (m_state != State::LIVE){ return; }
	DrawExtendGraphF(m_pos.GetPosX(), m_pos.GetPosY(), 
		m_pos.GetPosX()+m_size.GetPosX(), m_pos.GetPosY() + m_size.GetPosY(), 
		CResource::player_graph, true);

//�@�����蔻��e�X�g
#ifdef Debug
	DrawBox(300, 400, 300+64, 400+64, GetColor(255, 0, 0), false);
#endif
}