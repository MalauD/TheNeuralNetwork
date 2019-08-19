#include "neuralNetwork.h"
#include "matrix.h"
#include <random>

int main(){
	neuralNetwork nn = neuralNetwork(2, 2, 1);
	nn.print();
	std::vector<std::vector<double>> inputs = { {1,1},{1,0} ,{0,1} ,{0,0} };
	std::vector<std::vector<double>> targets = { {0},{1} ,{1} ,{0} };
	
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rnd(0, 3);
	
	for (int i = 0; i < 100000; i++) {
		int curRN = rnd(gen);

		nn.train(inputs[curRN], targets[curRN], 1);
	}

	nn.print();

	std::cout << nn.predict({ 1,1 })[0] << "\n";
	std::cout << nn.predict({ 1,0 })[0] << "\n";
	std::cout << nn.predict({ 0,1 })[0] << "\n";
	std::cout << nn.predict({ 0,0 })[0] << "\n";
}   