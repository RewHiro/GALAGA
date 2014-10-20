#pragma once
#include "../object/Object.h"

//=====================================
//点滅クラス(エフェクト)
//=====================================

//-------------------------------------
//【注意】
//・オブジェクトで継承したものしか使用できない
//-------------------------------------

class CBlink{
public:
	//　state:オブジェクトの状態を入れる
	//　blink_time:点滅する時間
	//　start_count:スタートの時間
	//　transparency_stop_time:透明化終了時間
	CBlink(Object::State &state, const int blink_time, const unsigned long start_count, const int transparency_count);

	//　更新
	void Update();

private:
	const int BLINK_TIME;		//　点滅する時間
	const int TRANSPARENCY_STOP_TIME;	//　透明化終了時間
	Object::State &m_state;			//　状態を入れる箱
	unsigned long m_count;			//　カウント
	int m_transparency_count;		//　透明カウント

	//　カウントリセット
	void CountReset();

	//　状態の遷移
	void TransitionOfState();

	//　透明になる処理
	void ChanegeOfTransparent();

	//　状態を戻す
	void ReturnState();

	//　透明時の処理
	void Transparent();
};

