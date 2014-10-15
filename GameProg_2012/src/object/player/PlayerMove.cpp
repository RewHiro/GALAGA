#include "PlayerMove.h"
#include "Player.h"
#include "../../../DxLib/DxLib.h"

CPlayerMove::CPlayerMove():
m_velocity(0),
SPEED_VAL(5)
{
}

//�@�X�V
void CPlayerMove::Update(){
	Left();
	Right();
	Stop();
}

//�@���ɓ�������
void CPlayerMove::Left(){
	if (!CheckHitKey(KEY_INPUT_LEFT))return;
	m_velocity = -SPEED_VAL;
}

//�@�E�ɓ�������
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
	m_velocity = SPEED_VAL;
}

//�@�����Ȃ��Ƃ��̏���
void CPlayerMove::Stop(){
	if (CheckHitKeyAll())return;
	m_velocity = 0;
}