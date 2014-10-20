#include "Player.h"
#include "../../resource/Resource.h"
#include "../../utility/Vec2f.h"
#include "../../scene/SceneManager.h"
#include "PlayerMove.h"
#include "../bullet/Bullet.h"
#include "../../utility/Key.h"
#include "../../../DxLib/DxLib.h"
//#define Debug

CPlayer::CPlayer():
m_move(std::make_unique<CPlayerMove>(m_pos))
{
	m_size = Vec2f(64, 64);
	m_pos = Vec2f(CSceneManager::WIDTH / 2 - m_size.x() / 2,
		CSceneManager::HEIGHT - m_size.y());
	for (auto &bullet : m_bullet){
		bullet = std::make_unique<CBullet>();
	}
}

//　更新
void CPlayer::Update(){
	gpUpdateKey();
	MoveUpdate();
	Shot();
	BulletUpdate();
}

//　描画
void CPlayer::Draw(){
	BulletDraw();
	LiveDraw();
}

//　生きてるときの描画処理
void CPlayer::LiveDraw(){
	if (m_state != State::LIVE)return;
	DrawExtendGraphF(m_pos.x(), m_pos.y(), 
		m_pos.x()+m_size.x(), m_pos.y() + m_size.y(), 
		CResource::player_graph, true);

//　当たり判定テスト
#ifdef Debug
	DrawBox(300, 400, 300+64, 400+64, GetColor(255, 0, 0), false);
#endif
}

//　移動処理
void CPlayer::MoveUpdate(){
	if (m_state != State::LIVE)return;
	m_move->Update();
}

//　弾の更新
void CPlayer::BulletUpdate(){
	for (auto &bullet : m_bullet){
		bullet->Update();
	}
}

//　弾の描画
void CPlayer::BulletDraw(){
	for (auto &bullet : m_bullet){
		bullet->Draw();
	}
}

//　弾の生成
void CPlayer::CreateBullet(){
	for (auto &bullet : m_bullet){
		if (bullet->GetState() == State::NONE){
			bullet->Create(Vec2f(m_pos.x() + m_size.x() / 2 - 6, m_pos.y() + m_size.y() / 2));
			break;
		}
	}
}

//　発射
void CPlayer::Shot(){
	if (GetKey(KEY_INPUT_LCONTROL) == 0 || GetKey(KEY_INPUT_LCONTROL) > 1)return;
	CreateBullet();
}