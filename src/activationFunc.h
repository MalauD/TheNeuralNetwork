#include <functional>
#include <math.h>

static struct activationFunc {
	static std::function<float(float, uint16_t, uint16_t)> sigmoid;

	static std::function<float(float, uint16_t, uint16_t)> dsigmoid; 
};
