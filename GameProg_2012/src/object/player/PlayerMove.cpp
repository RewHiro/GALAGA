#include "PlayerMove.h"
#include "Player.h"
#include "../../../DxLib/DxLib.h"

CPlayerMove::CPlayerMove():
m_velocity(0),
SPEED_VAL(5)
{
}

//　更新
void CPlayerMove::Update(){
	Left();
	Right();
	Stop();
}

//　左に動く処理
void CPlayerMove::Left(){
	if (!CheckHitKey(KEY_INPUT_LEFT))return;
	m_velocity = -SPEED_VAL;
}

//　右に動く処理
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
	m_velocity = SPEED_VAL;
}

//　動かないときの処理
void CPlayerMove::Stop(){
	if (CheckHitKeyAll())return;
	m_velocity = 0;
}