#include <vector>
#include <utility>
//#include "Net.h"
//#include "State.h"



//#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//#include <cmath>


#include <PGNGameCollection.h> 
#include <iostream> 
#include <fstream> 
#include "chess.h"

using namespace std;

void create_training_data()
{
	try
	{
        pair < vector< vector<vector<vector<int> > > >, vector < string > > data;
		vector<string>values {"1-0","0-1","1/2-1/2"};
		std::ifstream pgnfile("./ficsgamesdb2016.pgn");
		pgn::GameCollection games;
		pgnfile >> games;
		for(pgn::GameCollection::iterator it=games.begin();it!=games.end();++it) {
			chess current_game;
			std::cout<<"moves: "<<it->moves()<<endl;
			int i=1;
			for(pgn::MoveList::iterator it2=it->moves().begin();it2!=it->moves().end();++it2) {
				data.first.push_back(current_game.serializemove());
				data.second.push_back(it->result());
				data.first.push_back(current_game.serializemove());
				data.second.push_back(it->result());
				++i;
			}
			cout<<"it->result()   "<<it->result()<<endl;
			std::cout<<"----------end of it---------------"<<endl;
			
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}
}

int main() {
    create_training_data();
}


/*
int main(int argc, char *argv[])
{
	try
	{
		//PGN Code
		std::ifstream pgnfile("./pgn/example_1/sample.pgn");
		pgn::GameCollection games;

		// collecting games from file
		pgnfile >> games;
		// now counting and printing the result
		std::cout << std::endl << "The sample.pgn file contains " << games.size() << " games." 
				<< std::endl << std::endl;


		//NN Code
		// {3,2,1}---> 3 input Neurons, 2 hidden layer Neurons, 
		// and 1 output Neuron for the output layer
		std::vector<unsigned> topology;
		topology.push_back(3);
		topology.push_back(2);
		topology.push_back(1);
		Net myNet(topology);

		// read all the inputs
		std::vector<double> inputVals;
		myNet.feedForward(inputVals);

		// train the network against the tragetvals
		std::vector<double> targetVals;
		myNet.backProp(targetVals);

		std::vector<double> resultVals;
		myNet.getResults(resultVals);



	}
	catch (std::exception &e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}


*/
