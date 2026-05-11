#include <iostream>
#include "Board.h"

int main()
{
    std::cout << "Hello World!\n";
    Board* board = new Board(true);
    
    board->logBoard();

    std::cout << board->getPieceOnASquare(1, 1);

    delete board;
}