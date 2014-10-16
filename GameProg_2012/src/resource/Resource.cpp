#include "Resource.h"
#include "../../DxLib/DxLib.h"

int CResource::player_graph;
int CResource::player_bullet;

CResource::CResource(){
	player_graph = LoadGraph("res/�摜/player/ship.png");
	player_bullet = LoadGraph("res/�摜/player/bullet.png");
}

CResource::~CResource(){
	InitGraph();
}