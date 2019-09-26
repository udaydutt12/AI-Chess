#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
#include "Net.h"
#include "Layer.h"
#include "Neuron.h"'

Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers= topology.size();
	for(unsigned layerNum=0;layerNum<numLayers;++layerNum) {
		m_layers.push_back(Layer());
		unsigned numOutputs = (layerNum == topology.size() - 1) ? 0 : topology[layerNum+1];
		//fill this new layer with neurons, and also one bias neuron
		for(unsigned neuronNum=0;neuronNum<=topology[layerNum];++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs,neuronNum));
			std::cout<<"Added the "<<neuronNum<<"th neuron for the "<<layerNum<<"th layer"<<std::endl;
		}
	}
}

void Net::feedForward(const std::vector<double>& inputVals) 
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

void Net::backProp(const std::vector<double> &targetVals)
{
	//Calculate the overall error (RMS of output neuron errors)
	Layer &outputLayer=m_layers.back();
	m_error = 0.0;
	for (unsigned n=0;n<outputLayer.size()-1;++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta*delta;
	}
	m_error =sqrt(m_error/(outputLayer.size()-1));
	
	// Implement a recent average
	m_recentAverageError = 
		m_recentAverageError * m_recentAverageSmoothingFactor
		 / (m_recentAverageSmoothingFactor+1.0);

	//Calculate output layer gradients
	
	for (unsigned n=0;n<outputLayer.size()-1;++n) {
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}

	//Calculate gradients on hidden layers
	for (unsigned layerNum = m_layers.size()-2;;--layerNum) {
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum+1];
		for (unsigned n = 0; n<hiddenLayer.size();++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}
	//FOr all layers from outputs to first hidden layer, 
	//update connection weights
	
	for (unsigned layerNum = m_layers.size()-1;layerNum>0;--layerNum) {
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer= m_layers[layerNum-1];
		for (unsigned n = 0; n<layer.size();++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}
}

void Net::getResults(std::vector<double> &resultVals) const
{
	resultVals.clear();
	for(unsigned n = 0; n<m_layers.back().size();++n) {
		resultVals.push_back(m_layers.back()[n].getOutputVal());
	}
}
