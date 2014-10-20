#include "Blink.h"
#include "../utility/Random.h"
#include <limits>


//　MEMO
//　コンストラクタ
//　引数にStateというenumclassを宣言し、const修飾子を付けるとエラる

//　state:オブジェクトの状態を入れる
//　blink_time:点滅する時間
//　start_count:スタートの時間
//　transparency_stop_time:透明化終了時間
CBlink::CBlink(Object::State &state, const int blink_time, const unsigned long start_count, const int transparency_stop_time) :
BLINK_TIME(blink_time),
TRANSPARENCY_STOP_TIME(transparency_stop_time),
m_state(state),
m_count(start_count),
m_transparency_count(0)
{
}

//　更新
void CBlink::Update(){
	if (m_state == Object::State::NONE)return;
	m_count++;
	TransitionOfState();
	CountReset();
}

//　カウントをリセット
void CBlink::CountReset(){
	if ((std::numeric_limits<unsigned long>::max)() - 10 > m_count)return;
	m_count = 0;
}

//　状態の遷移
void CBlink::TransitionOfState(){
	Transparent();
	ChanegeOfTransparent();
}

//　透明になる処理
void CBlink::ChanegeOfTransparent(){
	if (m_state != Object::State::LIVE)return;
	if (m_count % BLINK_TIME == 0){
		m_state = Object::State::TRANSPARENCY;
	}
}

//　状態を戻す
void CBlink::ReturnState(){
	if (m_transparency_count != TRANSPARENCY_STOP_TIME)return;
	m_state = Object::State::LIVE;
	m_transparency_count = 0;
}

//　透明時の処理
void CBlink::Transparent(){
	if (m_state != Object::State::TRANSPARENCY)return;
	m_transparency_count++;
	ReturnState();
}