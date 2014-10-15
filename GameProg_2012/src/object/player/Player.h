#pragma once
#include "../Object.h"
#include <memory>

class CPlayerMove;

//=====================================
//自機クラス
//=====================================

class CPlayer : public Object{
public:
	CPlayer();

	//　更新
	void Update();

	//　描画
	void Draw();

private:
	//　生きてるときの描画処理
	void LiveDraw();

	//　移動処理
	void MoveUpdate();

	std::unique_ptr<CPlayerMove>m_move;
};

