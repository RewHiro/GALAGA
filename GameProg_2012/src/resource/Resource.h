#pragma once
#include "../Uncopyable.h"
#include <memory>

//========================================
//���\�[�X�N���X
//========================================

class CResource : private Uncopyable{
public:
	~CResource();

	//�@�C���X�^���X�̎擾
	static CResource &GetInstance(){
		static CResource instatnce;
		return instatnce;
	}

	//========================================
	//�摜
	//========================================
	static int player_graph;
	static int player_bullet;
	//========================================
	//��
	//========================================


private:
	CResource();
};

