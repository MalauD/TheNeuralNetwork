#include <functional>
#include <math.h>

static struct activationFunc {
	static std::function<double(double, uint16_t, uint16_t)> sigmoid;

	static std::function<double(double, uint16_t, uint16_t)> dsigmoid; 
};
