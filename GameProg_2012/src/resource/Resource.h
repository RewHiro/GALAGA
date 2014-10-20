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

	static int usagi;
	static int usagi2;
	static int up1up;
	static int game_over;
	static int high_score;
	static int pcregit;
	static int c0;
	static int c1;
	static int c2;
	static int c3;
	static int c4;
	static int c5;
	static int c6;
	static int c7;
	static int c8;
	static int c9;
	static int c10;
	static int c20;
	static int c30;
	static int c40;
	static int c50;
	static int c60;
	static int c70;
	static int c80;
	static int c90;



	//========================================
	//音
	//========================================


private:
	CResource();
};

