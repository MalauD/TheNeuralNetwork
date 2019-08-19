#include "neuralNetwork.h"
#include "matrix.h"
#include <random>

int main(){
	neuralNetwork nn = neuralNetwork(2, 4, 1);
	nn.print();
	std::vector<std::vector<float>> inputs = { {1,1},{1,0} ,{0,1} ,{0,0} };
	std::vector<std::vector<float>> targets = { {0},{1} ,{1} ,{0} };
	
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rnd(0, 3);
	
	int iter = 10000;

	for (int i = 0; i < iter; i++) {
		int curRN = rnd(gen);

		if (i % (iter / 10) == 0) {
			std::cout << "Error: " <<nn.train(inputs[curRN], targets[curRN], 0.01) << "\r";
		}
		nn.train(inputs[curRN], targets[curRN], 1.1);
	}

	nn.print();

	std::cout << nn.predict({ 1,1 })[0] << "\n";
	std::cout << nn.predict({ 1,0 })[0] << "\n";
	std::cout << nn.predict({ 0,1 })[0] << "\n";
	std::cout << nn.predict({ 0,0 })[0] << "\n";
}   