#include "neuralNetwork.h"

neuralNetwork::neuralNetwork(uint16_t nodesIN, uint16_t nodesHI, uint16_t nodesOU)
{
	inputNodes = nodesIN;
	hiddenNodes = nodesHI;
	outputNodes = nodesOU;

	weightsIH = new matrix(hiddenNodes, inputNodes);
	weightsHO = new matrix(outputNodes, hiddenNodes);
	matrix::randomize(weightsIH);
	matrix::randomize(weightsHO);

	biasH = new matrix(hiddenNodes, 1);
	biasO = new matrix(outputNodes, 1);
	matrix::randomize(biasH);
	matrix::randomize(biasO);
}

neuralNetwork::~neuralNetwork()
{
}

std::vector<double> neuralNetwork::predict(std::vector<double> input)
{
	matrix inputs = *matrix::fromArray(input);

 	matrix hidden = *matrix::dotProduct(weightsIH,&inputs);

	hidden = hidden + (*biasH);
	hidden.map(activationFunc::sigmoid);

	matrix output = *matrix::dotProduct(weightsHO, &hidden);
	
	output = output + (*biasO);
	output.map(activationFunc::sigmoid);

	return matrix::toArray(&output);
}

void neuralNetwork::train(std::vector<double> input, std::vector<double> target, double learningRate)
{
	matrix* inputs = matrix::fromArray(input);
	matrix hiddens = *matrix::dotProduct(weightsIH, inputs);
	hiddens = hiddens + (*biasH);

	hiddens.map(activationFunc::sigmoid);

	matrix outputs = *matrix::dotProduct(weightsHO, &hiddens);

	outputs = outputs + (*biasO);
	outputs.map(activationFunc::sigmoid);

	matrix targets = *matrix::fromArray(target);

	matrix outputError = targets - outputs;

	matrix gradient = *matrix::map(&outputs, activationFunc::dsigmoid);
	gradient = gradient * outputError * learningRate;

	matrix hiddenT = *matrix::transpose(&hiddens);


	matrix weightHODelta = *matrix::dotProduct(&gradient,&hiddenT);

	*weightsHO = *weightsHO + weightHODelta;
	*biasO = *biasO + gradient;


	matrix whoT = *matrix::transpose(weightsHO);
	matrix hiddenError = *matrix::dotProduct(&whoT,&outputError);


	matrix hiddenGradient = *matrix::map(&hiddens, activationFunc::dsigmoid);
	hiddenGradient = hiddenGradient * hiddenError * learningRate;


	matrix inputT = *matrix::transpose(inputs);
	matrix weightIHDelta = *matrix::dotProduct(&hiddenGradient, &inputT);


	*weightsIH = *weightsIH + weightIHDelta;
	*biasH = *biasH + hiddenGradient;

	
}

void neuralNetwork::print()
{
	std::cout << "=== IN: " << inputNodes << " HI: " << hiddenNodes << " OU: " << outputNodes << " ===\n \n";
	
	std::cout << "---- Weights ---- \n \n";

	std::cout << "Input -> Hidden \n \n";
	weightsIH->print();
	std::cout << "Hidden -> Output \n \n";
	weightsHO->print();

	std::cout << "---- Bias ---- \n \n";

	std::cout << "Hidden \n \n";
	biasH->print();
	std::cout << "Output \n \n";
	biasO->print();
	std::cout << "======================= \n";
}
