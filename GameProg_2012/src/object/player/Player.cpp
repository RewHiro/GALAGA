#include "Player.h"
#include "../../resource/Resource.h"
#include "../../utility/Vec2f.h"
#include "../../scene/SceneManager.h"
#include "PlayerMove.h"
#include "../bullet/Bullet.h"
#include "../../../DxLib/DxLib.h"
//#define Debug

CPlayer::CPlayer():
m_move(std::make_unique<CPlayerMove>())
{
	m_size = Vec2f(64, 64);
	m_pos = Vec2f(CSceneManager::WIDTH / 2 - m_size.x() / 2,
		CSceneManager::HEIGHT - m_size.y());
	for (auto &bullet : m_bullet){
		bullet = std::make_unique<CBullet>();
	}
}

//�@�X�V
void CPlayer::Update(){
	MoveUpdate();
	Shot();
	BulletUpdate();
}

//�@�`��
void CPlayer::Draw(){
	LiveDraw();
	BulletDraw();
}

//�@�����Ă�Ƃ��̕`�揈��
void CPlayer::LiveDraw(){
	if (m_state != State::LIVE)return;
	DrawExtendGraphF(m_pos.x(), m_pos.y(), 
		m_pos.x()+m_size.x(), m_pos.y() + m_size.y(), 
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

//�@�e�̍X�V
void CPlayer::BulletUpdate(){
	for (auto &bullet : m_bullet){
		bullet->Update();
	}
}

//�@�e�̕`��
void CPlayer::BulletDraw(){
	for (auto &bullet : m_bullet){
		bullet->Draw();
	}
}

//�@�e�̐���
void CPlayer::CreateBullet(){
	for (auto &bullet : m_bullet){
		if (bullet->GetState() == State::NONE){
			bullet->Create(m_pos);
			break;
		}
	}
}

//�@����
void CPlayer::Shot(){
	if (!CheckHitKey(KEY_INPUT_LCONTROL))return;
	CreateBullet();
}