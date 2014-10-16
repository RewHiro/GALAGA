#include "Bullet.h"
#include "../../resource/Resource.h"
#include "../../../DxLib/DxLib.h"

CBullet::CBullet():
SPEED_VAL(10)
{
	m_size = Vec2f(16,16);
	m_state = State::NONE;
}

void CBullet::Update(){
	if (m_state != State::LIVE)return;
	m_pos.m_y -= SPEED_VAL;
}

void CBullet::Draw(){
	if (m_state != State::LIVE)return;
	DrawExtendGraphF(m_pos.x(), m_pos.y(),
		m_pos.x() + m_size.x(), m_pos.y() + m_size.y(),
		CResource::player_bullet, true);
}

void CBullet::Create(Vec2f &pos){
	if (m_state != State::NONE)return;
	m_pos = pos;
	m_state = State::LIVE;
}