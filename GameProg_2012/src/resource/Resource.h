#pragma once
#include "../Uncopyable.h"
#include <memory>

//========================================
//リソースクラス
//========================================

class CResource : private Uncopyable{
public:
	~CResource();

	//　インスタンスの取得
	static CResource &GetInstance(){
		static CResource instatnce;
		return instatnce;
	}

	//========================================
	//画像
	//========================================
	static int player_graph;
	static int player_bullet;
	//========================================
	//音
	//========================================


private:
	CResource();
};

