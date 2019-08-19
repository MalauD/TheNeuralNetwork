#include "activationFunc.h"

std::function<float(float, uint16_t, uint16_t)> activationFunc::sigmoid = [](float val, uint16_t rows, uint16_t cols) {
	return 1 / (1 + exp(-val)); 
};

std::function<float(float, uint16_t, uint16_t)> activationFunc::dsigmoid = [](float val, uint16_t rows, uint16_t cols) {
	return val * (1 - val);
};