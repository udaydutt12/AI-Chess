#include "State.h"
#include <vector>

State::State(int[8][8][5] board_in = NULL) {
    
}

std::vector<std::vector<std::vector<int> > > serialize();
std::vector<int> edges();

State::std::vector<std::vector<std::vector<int> > >serialize() {

}


int State::key() {
    // change the return type in a bit
    return 0;
}

/*
        serialize:
        input= board state's current FEN

        take a board at its current state and fill in a board[64]
        
        lowercase = WHITE , uppercase = BLACK
        1 = p , 2 = r , 3 = k , 4 = b, 5=q,6=k, 7 = castled king white,
        8=square with en passant available
        9= P , 10 = R , 11= K , 12 = B, 13=Q,14=K, 15=castled king black 

        now board[64] has values from 1-16. each of these numbers are 4 bits.

        this means we can expand this vector into a 8x8x4 bitvector.

        actually we need to store whether black or white plays next. So the last column will be all 1's if white, and all 0's if black.

        therefore, the output of the serialize function is a bitvector of size 8x8x5

*/
