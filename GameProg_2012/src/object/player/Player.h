#pragma once
#include "../Object.h"
#include <memory>
#include <array>

class CPlayerMove;
class CBullet;

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

	//　弾の更新
	void BulletUpdate();

	//　弾の描画
	void BulletDraw();

	//　弾の生成
	void CreateBullet();

	//　弾の発射
	void Shot();

	std::unique_ptr<CPlayerMove>m_move;
	std::array<std::unique_ptr<CBullet>, 2>m_bullet;
};

