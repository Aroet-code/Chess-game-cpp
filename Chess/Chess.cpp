#include <iostream>
#include "Board.h"
#include "MovementHandler.h"

int main()
{
    std::cout << "Hello World!\n";
    Board* board = new Board(true);
    MovementHandler* mh = new MovementHandler(board);

    board->white_rooks += ((uint64_t)8388608 << 12);
    
    board->logBoard();


    std::cout << board->getPieceOnASquare(1, 1) << std::endl;

    for (auto a : mh->getPossibleMoves(2, 1)) {
        std::cout << "x: " << a.x << " y: " << a.y << std::endl;
    }

    delete board;
}