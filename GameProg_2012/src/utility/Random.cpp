#include "Random.h"

std::mt19937 Random::engine = std::mt19937( std::random_device()() );

Random::Random(const unsigned long seed){
	my_engine.seed(seed);
}

//　シードの設定
void Random::SetSeed(const unsigned long seed){
	engine.seed(seed);
}

//　一様分布のランダム(実数)
double Random::Uniform(const double min, const double max){
	std::uniform_real_distribution<double>random(min, max);
	double result = random(engine);
	return result;
}

//　一様分布のランダム(実数)
float Random::Uniform(const float min, const float max){
	std::uniform_real_distribution<float>random(min, max);
	float result = random(engine);
	return result;
}

//　一様分布のランダム(整数)
int Random::Uniform(const int min, const int max){
	std::uniform_int_distribution<int>random(min, max);
	int result = random(engine);
	return result;
}

//　ベルヌーイ分布(指定した確率でtrueが出現、0.00~1.00)
bool Random::Bernulli(const float probability){
	std::bernoulli_distribution random(probability);
	bool result = random(engine);
	return result;
}

//　正規分布
//　exexpectation：期待値
//　error：標準偏差(誤差)
double Random::Gaussian(const double expectation, const double error){
	std::normal_distribution<double>random(expectation, error);
	double result = random(engine);
	return result;
}

int Random::Gaussian(const int expectation, const int error){
	std::normal_distribution<double>random(expectation, error);
	int result = random(engine);
	return result;
}