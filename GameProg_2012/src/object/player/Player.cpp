#include "Player.h"
#include "../../resource/Resource.h"
#include "../../utility/Vec2f.h"
#include "../../scene/SceneManager.h"
#include "PlayerMove.h"
#include "../../../DxLib/DxLib.h"
//#define Debug

CPlayer::CPlayer():
m_move(std::make_unique<CPlayerMove>())
{
	m_size = Vec2f(64, 64);
	m_pos = Vec2f(CSceneManager::WIDTH / 2 - m_size.m_x / 2,
		CSceneManager::HEIGHT - m_size.m_y);
}

//�@�X�V
void CPlayer::Update(){
	MoveUpdate();
}

//�@�`��
void CPlayer::Draw(){
	LiveDraw();
}

//�@�����Ă�Ƃ��̕`�揈��
void CPlayer::LiveDraw(){
	if (m_state != State::LIVE)return;
	DrawExtendGraphF(m_pos.m_x, m_pos.m_y, 
		m_pos.m_x+m_size.m_x, m_pos.m_y + m_size.m_y, 
		CResource::player_graph, true);

//�@�����蔻��e�X�g
#ifdef Debug
	DrawBox(300, 400, 300+64, 400+64, GetColor(255, 0, 0), false);
#endif
}

//�@�ړ�����
void CPlayer::MoveUpdate(){
	if (m_state != State::LIVE)return;
	m_move->Update();
	m_pos.m_x += m_move->GetSpeed();
}