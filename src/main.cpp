#include "neuralNetwork.h"
#include "matrix.h"

int main(){
	neuralNetwork nn = neuralNetwork(2, 4, 1);
	nn.print();
	std::vector<std::vector<double>> inputs = { {1,1},{1,0} ,{0,1} ,{0,0} };
	std::vector<std::vector<double>> targets = { {0},{1} ,{1} ,{0} };
	for (int i = 0; i < 100000; i++) {
		nn.train(inputs[i % 4], targets[i % 4], 0.1);
	}

	nn.print();

	std::cout << nn.predict({ 1,0 })[0];
}   