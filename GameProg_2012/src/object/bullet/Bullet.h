#pragma once
#include "../Object.h"

//=====================================
//弾クラス
//=====================================

class CBullet :public Object{
public:
	CBullet();
	~CBullet() = default;

	//　更新
	void Update();

	//　描画
	void Draw();

	//　生成
	void Create(Vec2f &);
private:
	//　移動処理
	void Move();

	const float SPEED_VAL;
};