#include "Stage.h"
#include "SceneManager.h"
#include "../object/player/Player.h"
#include "../object/star/Star.h"
#include "../resource/Resource.h"
#include "../utility/Key.h"
#include "../../DxLib/DxLib.h"

CStage::CStage():
m_player(std::make_unique<CPlayer>()),
c_x(105),
c_y(780),
one_point(0),
ten_points(0),
cregit(0),
c_zero(false)
{
	for (auto &star : m_star){
		star = std::make_unique<CStar>();
	}
}

CStage::~CStage(){
}

//　更新
void CStage::Update(){
	CregitControl();
	m_player->Update();
	StarUpdate();
}

//　描画
void CStage::Draw(){
	StarDraw();

	//　1UP
	DrawRotaGraph(105, 50, 0.8, 0.0, CResource::up1up, TRUE);
	//　ハイスコア
	DrawRotaGraph(300, 50, 0.8, 0.0, CResource::high_score, TRUE); 

	//　クレジット
	DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::pcregit, TRUE);

	OnePointDraw();
	TenPointDraw();

	m_player->Draw();
}

//　星の更新
void CStage::StarUpdate(){
	for (auto &star : m_star){
		star->Update();
	}
}

//　星の描画
void CStage::StarDraw(){
	for (auto &star : m_star){
		star->Draw();
	}
}

//　クレジットの操作
void CStage::CregitControl(){
	one_point = cregit % 10;
	ten_points = cregit / 10;
	if (GetKey(KEY_INPUT_C) == 1){
		cregit += 1;
		c_zero = true; 
	}
}

//　1桁目のクレジットの描画
void CStage::OnePointDraw(){
	if (c_zero == false){ DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c0, TRUE); }
	if (one_point == 0){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c0, TRUE);
	}
	if (one_point == 1){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c1, TRUE);
	}
	if (one_point == 2){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c2, TRUE);
	}
	if (one_point == 3){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c3, TRUE);
	}
	if (one_point == 4){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c4, TRUE);
	}
	if (one_point == 5){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c5, TRUE);
	}
	if (one_point == 6){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c6, TRUE);
	}
	if (one_point == 7){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c7, TRUE);
	}
	if (one_point == 8){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c8, TRUE);
	}
	if (one_point == 9){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c9, TRUE);
	}
}
//　2桁目のクレジットの描画
void CStage::TenPointDraw(){
	if (ten_points == 1){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c10, TRUE);
	}
	if (ten_points == 2){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c20, TRUE);
	}
	if (ten_points == 3){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c30, TRUE);
	}
	if (ten_points == 4){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c40, TRUE);
	}
	if (ten_points == 5){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c50, TRUE);
	}
	if (ten_points == 6){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c60, TRUE);
	}
	if (ten_points == 7){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c70, TRUE);
	}
	if (ten_points == 8){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c80, TRUE);
	}
	if (ten_points == 9){
		DrawRotaGraph(c_x, c_y, 0.8, 0.0, CResource::c90, TRUE);
	}
}