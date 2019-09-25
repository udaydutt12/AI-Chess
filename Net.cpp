//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Connection
{
	double weight,deltaWeight;
}

class Neuron {
	public:
		Neuron(unsigned numOutputs);
	private:
		double m_outputVal;
		vector<Connection> m_outputWeights;
		static double randomWeight(void) {return rand()/double(RAND_MAX);}
};

Neuron::Neuron(unsigned numOutputs)
{
	for (unsigned c=0; c<numOutputs;++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
}

typedef vector<Neuron> Layer; 

class Net
{
	public:
		Net(const vector<unsigned> &topology);
		void feedForward(const vector<double> &inputVals);
		void backProp(const vector<double>& targetVals);
		void getResults(vector<double> &resultVals) const;
	private:
		vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
};

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

void Net::feedForward() 
{
	
}

void Net::backProp()
{
 
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

