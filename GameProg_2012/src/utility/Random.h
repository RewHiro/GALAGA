#pragma once
#include <random>

//=====================================
//ランダムクラス
//=====================================

class Random{
public:

	Random() = default;

	Random(const unsigned long seed);

	//　シードの設定
	static void SetSeed(const unsigned long seed);

	//　一様分布のランダム(実数)
	static double Uniform(const double min, const double max);

	//　一様分布のランダム(実数)
	static float Uniform(const float min, const float max);

	//　一様分布のランダム(整数)
	static int Uniform(const int min, const int max);

	//　ベルヌーイ分布(指定した確率でtrueが出現、0.00~1.00)
	static bool Bernulli(const float probability);

	//　正規分布
	//　exexpectation：期待値
	//　error：標準偏差(誤差)
	static double Gaussian(const double expectation, const double error);

	static int Gaussian(const int expectation, const int error);

private:
	static std::mt19937 engine;
	std::mt19937 my_engine;
};