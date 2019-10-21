#include <vector>
#include <pair>
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
        std::pair < std::vector< int[8][8][5] >, std::vector < std::string > > data;
		std::ifstream pgnfile("./pgn/example_2/sample.pgn");
		pgn::GameCollection games;
		pgnfile >> games;
		for(pgn::GameCollection::iterator it=games.begin();it!=games.end();++it) {
			chess current_game;
			for(pgn::MoveList::iterator it2=it->moves().begin();it2!=it->moves().end();++it2) {
				//State s;
				//s.move(it2->black);
				std::cout<<"	----------start of it2---------------"<<endl;
				cout<<"it2->black  "<< (it2->black()).hdata->str() << endl;
				cout<<"it2->isCheckMate  "<<it2->isCheckMate() <<endl;
				cout<<"it2->white  "<<it2->white() <<endl;
				std::cout<<"	----------	end of it2---------------"<<endl;
               // it2->white.
				//current_game.move(it2->white());
				//current_game.move(it2->black());
			}
			cout<<"it->result()   "<<it->result()<<endl;
			std::cout<<"----------end of it---------------"<<endl;
			
		}
	//	while (s.board.is_game_over()) {
		//	computer_move(s, v);
	//		print(s.board);
	//	}
	//	print(s.board.result());
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

		// write down the name of the players extracting infos from the_game object
		game_header_printout(the_game);

		// the customary MoveList object
		pgn::MoveList movelist = the_game.moves();
		// and the new Position object, by default initialized with the initial piece arrangement
		pgn::Position p;

		// now get each move from the game and 
		// 1. fill it up
		// 2. print it out
		for (pgn::MoveList::iterator itr = movelist.begin(); itr != movelist.end(); itr++)
		{
			std::cout << p.moveNumber() << ".";

			// get the white ply, feed it to the position, get it back completed and print it.
			pgn::Ply ply;
			ply = itr->white();
			// Position::update() method has a double purpose:
			// 1. updates the position object
			// 2. complete the 'from square' ply as a side effect
			p.update(ply);
			// this converts from pgn to algebrical notation and print
			move_printout(ply);

			// same stuff for black move
			ply = itr->black();
			if (!ply.valid()) break; // in case the game ends with a white move (not in this game)
			p.update(ply);
			move_printout(ply);
			
			// six moves for every line, please
			if ((p.moveNumber()-1) % 6 == 0) 
				std::cout << std::endl;
		}
		// who won?
		std::cout << the_game.result() << std::endl << std::endl;
	}

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
		*/


    /*

#!/usr/bin/env python3
import os
import chess.pgn
import numpy as np
from state import State

def get_dataset(num_samples=None):
  X,Y = [], []
  gn = 0
  values = {'1/2-1/2':0, '0-1':-1, '1-0':1}
  # pgn files in the data folder
  for fn in os.listdir("data"):
    pgn = open(os.path.join("data", fn))
    while 1:
      game = chess.pgn.read_game(pgn)
      if game is None:
        break
      res = game.headers['Result']
      if res not in values:
        continue
      value = values[res]
      board = game.board()
      for i, move in enumerate(game.main_line()):
        board.push(move)
        ser = State(board).serialize()
        X.append(ser)
        Y.append(value)
      print("parsing game %d, got %d examples" % (gn, len(X)))
      if num_samples is not None and len(X) > num_samples:
        return X,Y
      gn += 1
  X = np.array(X)
  Y = np.array(Y)
  return X,Y

if __name__ == "__main__":
  X,Y = get_dataset(25000000)
  np.savez("processed/dataset_25M.npz", X, Y)



    */