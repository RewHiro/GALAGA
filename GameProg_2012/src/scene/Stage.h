#pragma once
#include "SceneManager.h"
#include "../object/Object.h"
#include <array>

//=====================================
//ステージクラス
//=====================================

class CStage : public CScene{
public:
	CStage();
	~CStage();

	//　更新
	void Update();

	//　描画
	void Draw();

private:
	std::unique_ptr<Object>m_player;
	std::array<std::unique_ptr<Object>, 150>m_star;
	
	int c_x;
	int c_y;
	int one_point;
	int ten_points;
	int cregit;
	bool c_zero;

	//　星の更新
	void StarUpdate();

	//　星の描画
	void StarDraw();

	//　クレジットの操作
	void CregitControl();

	//　1桁目のクレジットの描画
	void OnePointDraw();
	//　2桁目のクレジットの描画
	void TenPointDraw();

};

