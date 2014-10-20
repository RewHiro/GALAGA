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

//�@�X�V
void CPlayerMove::Update(){
	Left();
	Right();
	Stop();
	m_pos += m_velocity;
}

//�@���ɓ�������
void CPlayerMove::Left(){
	if (!CheckHitKey(KEY_INPUT_LEFT))return;
	m_velocity = Vec2f(-SPEED_VAL,0);
	LimitLeft();
}

//�@�E�ɓ�������
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
	m_velocity = Vec2f(SPEED_VAL,0);
	LimitRight();
}

//�@�����Ȃ��Ƃ��̏���
void CPlayerMove::Stop(){
	if (CheckHitKeyAll())return;
	m_velocity = Vec2f(0,0);
}

//�@��������E
void CPlayerMove::LimitLeft(){
	if (m_pos.x() > LIMIT_LEFT)return;
	m_velocity = Vec2f(0, 0);
}

//�@��������E
void CPlayerMove::LimitRight(){
	if (m_pos.x() < LIMIT_RIGHT - 64)return;
	m_velocity = Vec2f(0, 0);
}