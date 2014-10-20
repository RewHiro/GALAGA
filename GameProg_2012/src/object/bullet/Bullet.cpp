#include "Bullet.h"
#include "../../resource/Resource.h"
#include "../../../DxLib/DxLib.h"

CBullet::CBullet():
SPEED_VAL(15)
{
	m_size = Vec2f(16,16);
	m_state = State::NONE;
}

//　更新
void CBullet::Update(){
	if (m_state != State::LIVE)return;
	m_pos -= Vec2f(0,SPEED_VAL);
	if (m_pos.y() <= 0){
		m_state = State::NONE;
	}
}

//　描画
void CBullet::Draw(){
	if (m_state != State::LIVE)return;
	DrawExtendGraphF(m_pos.x(), m_pos.y(),
		m_pos.x() + m_size.x(), m_pos.y() + m_size.y(),
		CResource::player_bullet, true);
}

//　生成
void CBullet::Create(const Vec2f &pos){
	if (m_state != State::NONE)return;
	m_pos = pos;
	m_state = State::LIVE;
}