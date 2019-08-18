#include <stdint.h>
#include "matrix.h"
#include "activationFunc.h"

class neuralNetwork {
		uint16_t inputNodes, hiddenNodes, outputNodes;
		matrix *weightsIH, *weightsHO, *biasH, *biasO;
	public:
		neuralNetwork(uint16_t nodesIN, uint16_t nodesHI, uint16_t nodesOU);
		~neuralNetwork();

		std::vector<double> predict(std::vector<double> input);

		void train(std::vector<double> input, std::vector<double> target, double learningRate);
		void print();
};