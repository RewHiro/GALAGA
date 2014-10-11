#include "PlayerMove.h"
#include "../../../DxLib/DxLib.h"

CPlayerMove::CPlayerMove(){
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
}

//　右に動く処理
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
}

//　動かないときの処理
void CPlayerMove::Stop(){
	if (!CheckHitKeyAll())return;
}