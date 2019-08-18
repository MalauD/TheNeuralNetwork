#include "activationFunc.h"

std::function<double(double, uint16_t, uint16_t)> activationFunc::sigmoid = [](double val, uint16_t rows, uint16_t cols) {
	return 1 / (1 + exp(val)); 
};

std::function<double(double, uint16_t, uint16_t)> activationFunc::dsigmoid = [](double val, uint16_t rows, uint16_t cols) {
	return val * (1 - val);
};