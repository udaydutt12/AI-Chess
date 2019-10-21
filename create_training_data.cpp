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

