#include "Neuron.h"
#include "Layer.h"
#include <cmath>



void Neuron::updateInputWeights(Layer &prevLayer) 
{
	//The weights to be update are in the Connection container
	//in the neurons in the preceding layer
	for (unsigned n=0;n<prevLayer.size();++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
		double newDeltaWeight = 
			//Individual input, magnified by the gradient and train rate:
			eta
			* neuron.getOutputVal()
			* m_gradient
			//Also add momentum = a fraction of the previous delta weight
			+alpha
			* oldDeltaWeight;
		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}	

double Neuron::sumDOW(const Layer &nextLayer) const
{
	double sum = 0.0;
	// Sum our contributions of the errors at the nodes we feed
	for (unsigned n=0;n<nextLayer.size()-1;++n) {
		sum+=m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}
}

Neuron::Neuron(unsigned numOutputs)
{
	for (unsigned c=0; c<numOutputs;++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}

Neuron::feedForward(const Layer &prevLayer)
{
	double sum =0;

	//sum the prev layer's outputs (which are the inputs)
	//Include the biaas node from the previous layer.
	for (unsigned n=0; n<prevLayer.size();++n) {
		sum+= prevLayer[n].getOutputVal() *
			prevLayer[n].n_outputWeights[m_myIndex].weight;
	}

	m_outputVal= Neuron::transferFunction(sum);
}

double Neuron::transferFunction(double x)
{
	return tanh(x);
}

double Neuron::transferFunctionDerivate(double x)
{
	return 1.0-x*x;
}

void Neuron::calcOutputGradients(double targetVal) 
{
	double delta = targetVal-m_outputVal;
	m_gradient = delta* Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::calcHiddenGradients(const Layer &nextLayer) 
{
	double dow = sumDOW(nextLayer);
	mgradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::setOutputVal(double val) 
{
    m_outputVal = val;
}

double Neuron::getOutputVal() 
{
    return m_outputVal;
}

double Neuron::randomWeight() 
{
    return rand()/double(RAND_MAX);
}
