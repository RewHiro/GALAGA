#include "PlayerMove.h"
#include "Player.h"
#include "../../scene/SceneManager.h"
#include "../../../DxLib/DxLib.h"

CPlayerMove::CPlayerMove(Vec2f &pos) :
m_pos(pos),
m_velocity(0,0),
SPEED_VAL(3),
LIMIT_LINE(0),
LIMIT_LEFT(0),
LIMIT_RIGHT(CSceneManager::WIDTH)
{
}

//　更新
void CPlayerMove::Update(){
	Left();
	Right();
	Stop();
	m_pos += m_velocity;
}

//　左に動く処理
void CPlayerMove::Left(){
	if (!CheckHitKey(KEY_INPUT_LEFT))return;
	m_velocity = Vec2f(-SPEED_VAL,0);
	LimitLeft();
}

//　右に動く処理
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
	m_velocity = Vec2f(SPEED_VAL,0);
	LimitRight();
}

//　動かないときの処理
void CPlayerMove::Stop(){
	if (CheckHitKeyAll())return;
	m_velocity = Vec2f(0,0);
}

//　動ける限界
void CPlayerMove::LimitLeft(){
	if (m_pos.x() > LIMIT_LEFT)return;
	m_velocity = Vec2f(0, 0);
}

//　動ける限界
void CPlayerMove::LimitRight(){
	if (m_pos.x() < LIMIT_RIGHT - 64)return;
	m_velocity = Vec2f(0, 0);
}