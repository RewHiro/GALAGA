#pragma once
#include "../Object.h"
#include"math.h"

enum TYPE{
	NONE = 0,
	YELLOW,
	RED,
	BLUE,
	GREEN
};

int enemy[5][10] = {
		{ 0, 0, 0, 4, 4, 4, 4, 0, 0, 0 },
		{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
		{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};



//=====================================
//“GƒNƒ‰ƒX
//=====================================


class CEnemy : public Object{
public:


	int move0_x = 600 / 2;
	int move0_y = 780 - 700;

	float d = 0;



	CEnemy();
	~CEnemy();
};

