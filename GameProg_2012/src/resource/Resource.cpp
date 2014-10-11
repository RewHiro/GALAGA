#include "Resource.h"
#include "../../DxLib/DxLib.h"

int CResource::player_graph;

CResource::CResource(){
	player_graph = LoadGraph("res/‰æ‘œ/player/ship.png");
}

CResource::~CResource(){
	InitGraph();
}