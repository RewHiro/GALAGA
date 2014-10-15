#include "DxLib\DxLib.h"
#include "src\gameapplication\GameAppliacation.h"

//=====================================
//ÉÅÉCÉì
//=====================================

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

	CGameAppliacation &app = CGameAppliacation::GetInstance();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE)){
		app.Update();
	}
	return 0;
}