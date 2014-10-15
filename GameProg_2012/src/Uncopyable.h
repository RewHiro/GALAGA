#pragma once

//=====================================
//�R�s�[�֎~�N���X
//=====================================

class Uncopyable{
protected:
	Uncopyable() = default;
	~Uncopyable() = default;
private:
	Uncopyable(const Uncopyable &) = delete;
	Uncopyable operator&=(const Uncopyable &) = delete;
};