#include <vector>
//#include "Layer.h"
//#include "Connection.h"
#ifndef NEURON_H
#define NEURON_H

class Neuron;
struct Connection;
typedef std::vector<Neuron> Layer;

class Neuron
{
	public:
		Neuron(unsigned numOutputs,unsigned myIndex);
		void setOutputVal(double val);
		double getOutputVal(void) const;
		void feedForward(const Layer &prevLayer);
		void calcOutputGradients(double targetVal);
		void calcHiddenGradients(const Layer &nextLayer);
		void updateInputWeights(Layer &prevLayer);
	private:
		static double transferFunction(double x);
		static double transferFunctionDerivative(double x);
		double sumDOW(const Layer &nextLayer) const;
		double m_outputVal;
		std::vector<Connection> m_outputWeights;
		static double randomWeight(void);
		static double eta;  //[0.0..1.0] overall net training rate
		static double alpha; //[0.0..n] multiplier of last weight (momentum)
		unsigned m_myIndex;
		double m_gradient;
};

#endif