#include "chess.h"
#include <vector>
//#include <PGNGameCollection.h> 
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

chess::chess(std::string pgn) {
    chess::file = pgn;
}

void chess::serializemove (std::string player,std::string move_number) {
    std::string fout = ".\\out.fen";
    std::string s=".\\pgn2fen "+chess::file+" "+move_number+" "+player+ " "+fout;
    system(s.c_str());
    std::ifstream datin(fout);
    std::vector<std::vector<int> > board(8,std::vector<int>(8));
    int i=0;
    int j=0;
    std::string x;
    datin>>x;
    std::cout<<"x= "<<x<<std::endl; 
}

int main() {
    std::string pgn = "./sample.pgn";
    chess c(pgn);
    c.serializemove("w","1");
    c.serializemove("b","1");
}