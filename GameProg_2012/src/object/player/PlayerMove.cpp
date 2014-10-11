#include "PlayerMove.h"
#include "../../../DxLib/DxLib.h"

CPlayerMove::CPlayerMove(){
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
}

//�@�E�ɓ�������
void CPlayerMove::Right(){
	if (!CheckHitKey(KEY_INPUT_RIGHT))return;
}

//�@�����Ȃ��Ƃ��̏���
void CPlayerMove::Stop(){
	if (!CheckHitKeyAll())return;
}