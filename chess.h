#include <vector>
#include <string>

#ifndef CHESS_H
#define CHESS_H

class chess {
    public:
        chess(std::string file);
        void serializemove (std::string player,std::string move_number);
        std::vector< std::vector<int> > Board;
        std::string file;
};

#endif


/*
        in state.cpp, we take the current board state as a fen string. This chess class holds the current chess game in the form of 
        a fen string and needs to be able to take the next move as an input

        todo: change main.cpp so that we take a pgn and input the next move into the chess game.


*/

