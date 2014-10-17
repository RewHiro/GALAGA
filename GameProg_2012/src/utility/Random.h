#pragma once
#include <random>

//=====================================
//�����_���N���X
//=====================================

class Random{
public:

	Random() = default;

	Random(const unsigned long seed);

	//�@�V�[�h�̐ݒ�
	static void SetSeed(const unsigned long seed);

	//�@��l���z�̃����_��(����)
	static double Uniform(const double min, const double max);

	//�@��l���z�̃����_��(����)
	static float Uniform(const float min, const float max);

	//�@��l���z�̃����_��(����)
	static int Uniform(const int min, const int max);

	//�@�x���k�[�C���z(�w�肵���m����true���o���A0.00~1.00)
	static bool Bernulli(const float probability);

	//�@���K���z
	//�@exexpectation�F���Ғl
	//�@error�F�W���΍�(�덷)
	static double Gaussian(const double expectation, const double error);

	static int Gaussian(const int expectation, const int error);

private:
	static std::mt19937 engine;
	std::mt19937 my_engine;
};