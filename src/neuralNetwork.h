#include <stdint.h>
#include "matrix.h"
#include "activationFunc.h"
#include <cmath>

class neuralNetwork {
		uint16_t inputNodes, hiddenNodes, outputNodes;
		matrix *weightsIH, *weightsHO, *biasH, *biasO;
	public:
		neuralNetwork(uint16_t nodesIN, uint16_t nodesHI, uint16_t nodesOU);
		~neuralNetwork();

		std::vector<float> predict(std::vector<float> input);

		float train(std::vector<float> input, std::vector<float> target, float learningRate);
		void print();
};