#pragma once
#include "Board.h"
#include <vector>
class MovementHandler
{
private:
	Board board;
	Pair knightOffsets[8] = {
		Pair(2, 1), Pair(2, -1), Pair(-2, 1), Pair(-2, -1),
		Pair(1, 2), Pair(1, -2), Pair(-1, 2), Pair(-1, -2)
	};
public:
	std::vector<Pair> getPossibleMoves(int x, int y) {
		std::vector<Pair> resutl;

		char type = board.getPieceOnASquare(x, y);

		switch (type) {
		case '0':
			break;
		}

		return result;
	}
};

