//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

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