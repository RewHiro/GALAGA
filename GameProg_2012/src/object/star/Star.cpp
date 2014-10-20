#include "Star.h"
#include "../../utility/Random.h"
#include "../../scene/SceneManager.h"
#include "../../effect/Blink.h"
#include "../../../DxLib/DxLib.h"
#include <limits>

CStar::CStar():
SIZE(Vec2f(static_cast<float>(Random::Uniform(2, 3)), static_cast<float>(Random::Uniform(1, 2)))),
SPEED_VAL(3),
BLINK_TIME(30),
BLINK_COUNT(Random::Select({ 0, 4, 8, 12, 15, 18, 21, 24 })),
TRANSPARENCY_STOP_TIME(5),
m_red(Random::Uniform(0,255)),
m_green(Random::Uniform(0, 255)),
m_blue(Random::Uniform(0, 255)),
m_velocity(0,SPEED_VAL),
m_blink(std::make_unique<CBlink>(m_state, BLINK_TIME, BLINK_COUNT, TRANSPARENCY_STOP_TIME))
{
	m_state = State::LIVE;
	m_pos = Vec2f(static_cast<float>(Random::Uniform(0, CSceneManager::WIDTH)),
		static_cast<float>(Random::Uniform(0, CSceneManager::HEIGHT)));
	m_size = SIZE;
}

//　更新
void CStar::Update(){
	Move();
	m_blink->Update();
	Reset();
}

//　描画
void CStar::Draw(){
	if (m_state != State::LIVE)return;
	DrawBox(static_cast<int>(m_pos.x()), static_cast<int>(m_pos.y()),
		static_cast<int>(m_pos.x() + m_size.x()), static_cast<int>(m_pos.y() + m_size.y()),
		GetColor(m_red, m_green, m_blue), true);
}

//　リセット
void CStar::Reset(){
	if (m_state != State::NONE)return;
	m_state = State::LIVE;
	m_pos = Vec2f(m_pos.x(), -50);
}

//　移動処理
void CStar::Move(){
	if (m_state == State::NONE)return;
	m_pos += m_velocity;
	LimitLine();
}

//　動ける限界ライン
void CStar::LimitLine(){
	if (m_pos.y() < CSceneManager::HEIGHT)return;
	m_state = State::NONE;
}