#include "Resource.h"
#include "../../DxLib/DxLib.h"

int CResource::player_graph;
int CResource::player_bullet;

int CResource::usagi;
int CResource::usagi2;
int CResource::up1up;
int CResource::game_over;
int CResource::high_score;
int CResource::pcregit;
int CResource::c0;
int CResource::c1;
int CResource::c2;
int CResource::c3;
int CResource::c4;
int CResource::c5;
int CResource::c6;
int CResource::c7;
int CResource::c8;
int CResource::c9;
int CResource::c10;
int CResource::c20;
int CResource::c30;
int CResource::c40;
int CResource::c50;
int CResource::c60;
int CResource::c70;
int CResource::c80;
int CResource::c90;



CResource::CResource(){
	player_graph = LoadGraph("res/‰æ‘œ/player/ship.png");
	player_bullet = LoadGraph("res/‰æ‘œ/player/bullet.png");

	usagi = LoadGraph("res/‰æ‘œ/‚Ò[‚¾‚¤‚³‚¬.png");
	usagi2 = LoadGraph("res/‰æ‘œ/‚¤‚³‚¬2.png");
	up1up = LoadGraph("res/‰æ‘œ/1up.png");
	game_over = LoadGraph("res/‰æ‘œ/game_over.png");
	high_score = LoadGraph("res/‰æ‘œ/high_score.png");

	pcregit = LoadGraph("res/‰æ‘œ/cregit/cregit.png");
	c0 = LoadGraph("res/‰æ‘œ/cregit/0.png");
	c1 = LoadGraph("res/‰æ‘œ/cregit/1.png");
	c2 = LoadGraph("res/‰æ‘œ/cregit/2.png");
	c3 = LoadGraph("res/‰æ‘œ/cregit/3.png");
	c4 = LoadGraph("res/‰æ‘œ/cregit/4.png");
	c5 = LoadGraph("res/‰æ‘œ/cregit/5.png");
	c6 = LoadGraph("res/‰æ‘œ/cregit/6.png");
	c7 = LoadGraph("res/‰æ‘œ/cregit/7.png");
	c8 = LoadGraph("res/‰æ‘œ/cregit/8.png");
	c9 = LoadGraph("res/‰æ‘œ/cregit/9.png");
	c10 = LoadGraph("res/‰æ‘œ/cregit/10.png");
	c20 = LoadGraph("res/‰æ‘œ/cregit/20.png");
	c30 = LoadGraph("res/‰æ‘œ/cregit/30.png");
	c40 = LoadGraph("res/‰æ‘œ/cregit/40.png");
	c50 = LoadGraph("res/‰æ‘œ/cregit/50.png");
	c60 = LoadGraph("res/‰æ‘œ/cregit/60.png");
	c70 = LoadGraph("res/‰æ‘œ/cregit/70.png");
	c80 = LoadGraph("res/‰æ‘œ/cregit/80.png");
	c90 = LoadGraph("res/‰æ‘œ/cregit/90.png");
}

CResource::~CResource(){
	InitGraph();
}