#include "Resource.h"
#include "../../DxLib/DxLib.h"

int CResource::player_graph;
int CResource::player_bullet;

CResource::CResource(){
	player_graph = LoadGraph("res/‰æ‘œ/player/ship.png");
	player_bullet = LoadGraph("res/‰æ‘œ/player/bullet.png");
}

CResource::~CResource(){
	InitGraph();
}