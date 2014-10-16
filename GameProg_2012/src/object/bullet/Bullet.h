#pragma once
#include "../Object.h"

//=====================================
//�e�N���X
//=====================================

class CBullet :public Object{
public:
	CBullet();
	~CBullet() = default;

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@����
	void Create(Vec2f &);
private:
	//�@�ړ�����
	void Move();

	const float SPEED_VAL;
};