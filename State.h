
#include <vector>

#ifndef STATE_H
#define STATE_H

class State {
    State::State(int[8][8][5] board_in = NULL);
    std::vector<std::vector<std::vector<int> > > serialize();
    int key();
    std::vector<int> edges();

};

#endif