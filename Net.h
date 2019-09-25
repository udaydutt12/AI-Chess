#include <vector>
#include "Layer.h"

#ifndef NET_H
#define NET_H

class Net
{
	public:
		Net(const std::vector<unsigned> &topology);
		void feedForward(const std::vector<double> &inputVals);
		void backProp(const std::vector<double>& targetVals);
		void getResults(std::vector<double> &resultVals) const;
	private:
		std::vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
		double m_error;
		double m_recentAverageError;
		double m_recentAverageSmoothingFactor;
};

#endif