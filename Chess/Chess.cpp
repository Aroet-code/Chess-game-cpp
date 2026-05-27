#include <iostream>
#include "Board.h"
#include "MovementHandler.h"
#include "ChessNamespace.h"

using namespace chess;

int main()
{
    std::cout << "Hello World!\n";
    Board* board = new Board(true);
    MovementHandler* mh = new MovementHandler(board);

    board->white_rooks ^= ((Bitboard)8388608 << 12);

    board->black_pawns ^= ((Bitboard)1 << 51);
    board->black_pawns ^= ((Bitboard)1 << 52);

    board->white_pawns ^= ((Bitboard)1 << 11);
    board->white_pawns ^= ((Bitboard)1 << 12);
    
    board->logBoard();


    std::cout << board->getPieceOnASquare(1, 1) << std::endl;

    for (auto a : mh->getPossibleMoves(5, 1)) {
        std::cout << "x: " << a.x << " y: " << a.y << std::endl;
    }

    delete board;
}