#include <vector>
#include "Net.h"
//#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//#include <cmath>

int main()
{
	// {3,2,1}---> 3 input Neurons, 2 hidden layer Neurons, 1 output Neuron
	std::vector<unsigned> topology; 
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);

	std::vector<double> targetVals;
	myNet.backProp(targetVals);

	std::vector<double> resultVals;
	myNet.getResults(resultVals);

}