//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

struct Connection
{
	double weight,deltaWeight;
};

typedef vector<Neuron> Layer; 

Net::Net(const vector<unsigned> &topology)
{
	unsigned numLayers= topology.size();
	for(unsigned layerNum=0;layerNum<numLayers;++layerNum) {
		m_layers.push_back(Layer());
		unsigned numOutputs = (layerNum == topology.size() - 1) ? 0 : topology[layerNum+1];
		//fill this new layer with neurons, and also one bias neuron
		for(unsigned neuronNum=0;neuronNum<=topology[layerNum];++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs));
			cout<<"Added the "<<neuronNum<<"th neuron for the "<<layerNum<<"th layer"<<endl;
		}
	}
}

void Net::feedForward(const vector<unsigned>& inputVals) 
{
	assert(inputVals.size()==m_layers[0].size()-1);
	
	// Assign (latch) the input values into the input neurons
	for(unsigned i=0;i<inputVals.size();++i) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	// Forward Propagate
	for(unsigned layerNum = 1; layerNum < m_layers.size();++layerNum) {
		Layer& prevLayer = m_layers[layerNum-1];
		for(unsigned n = 0; n<m_layers[layerNum].size()-1;++n) {
			m_layers[layerNum][n].feedForward(prevLayer);
		}
		
	}
}

void Net::backProp()
{
	//Calculate the overall error (RMS of output neuron errors)
	Layer &outputLayer=m_layers.back();
	m_error = 0.0;
	for (unsigned n=0;n<outputLater.size()-1;++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta*delta;
	}
	m_error =sqrt(m_error/(outputLayer.size()-1));
	
	// Implement a recent average
	m_recentAverageError = 
		(m_recentAverageError * m_recentAverageSmoothingFactor
		 / (m_recentAverageSmoothingFactor+1.0);

	//Calculate output layer gradients
	
	for (unsigned n=0;n<outputLayer.size()-1;++n) {
		outputLayer[n].calcOutputGradients(targetVales[n]);
	}

	//Calculate gradients on hidden layers
	for (unsigned layerNum = m_layers.size()-2;--layerNum) {
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum+1];
		for (unsigned n = 0; n<hiddenLayer.size();++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}
	//FOr all layers from outputs to first hidden layer, 
	//update connection weights
	
	for (unsigned layerNum = m_layers.size()-1;l>0;--l) {
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer= m_layers[layerNum-1];
		for (unsigned n = 0; n<layer.size();++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}
}

void Net::getResults()
{

}


int main()
{
	// {3,2,1}---> 3 input Neurons, 2 hidden layer Neurons, 1 output Neuron
	vector<unsigned> topology; 
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

}

