To create a Neural Network
* We are trying to model a machine that takes in the current chess game state.
-> From this, we know that input layer will be an 8x8 matrix
* The output must be in the form "Rb4", which means "Rook to B4".
-> There are  6 different pieces that can move (king, queen, rook,bishop,knight, pawn). Thus, the max number of output nodes = 6*64=384.
* obviously, not all of these 384 are possible each turn. So then how should we model the output layer?
