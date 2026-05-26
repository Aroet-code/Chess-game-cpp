#pragma once
#include "Board.h"
#include <vector>
#include "ChessNamespace.h"

using namespace chess;

class MovementHandler
{
private:
	Board* board;
	Pair knightOffsets[8] = {
		Pair(2, 1), Pair(2, -1), Pair(-2, 1), Pair(-2, -1),
		Pair(1, 2), Pair(1, -2), Pair(-1, 2), Pair(-1, -2)
	};
	bool isOutOfBounds(int x, int y) {
		return (x > 8 || x < 1 || y > 8 || y < 1);
	}
public:
	MovementHandler(Board* board) {
		this->board = board;
	}

	std::vector<Pair> getPossibleMoves(int x, int y) {
		std::vector<Pair> result;

		Board board = *this->board;

		char type = board.getPieceOnASquare(x, y);

		int newX = x;
		int newY = y;

		std::vector<Pair> steps;

		switch (type) {
		case '0' || 'p':
			break;
		case '1':
			if (board.getPieceOnASquare(newX, newY + 1) == '0') {
				result.push_back({ newX, newY + 1 });
				if (y == 2) {
					if (board.getPieceOnASquare(newX, newY + 2) == '0') {
						result.push_back({ newX, newY + 2 });
					}
				}
			}
			if (!isOutOfBounds(newX - 1, newY + 1)) {
				if (board.getPieceOnASquare(newX - 1, newY + 1) > '6') {
					result.push_back({ newX - 1, newY + 1 });
				}
			}
			if (!isOutOfBounds(newX + 1, newY + 1)) {
				if (board.getPieceOnASquare(newX + 1, newY + 1) > '6') {
					result.push_back({ newX + 1, newY + 1 });
				}
			}
			[[fallthrough]];
		case '2':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			[[fallthrough]];
		case '3':
			for (auto step : knightOffsets) {
				newX = x;
				newY = y;
				newX += step.x;
				newY += step.y;
				if (!isOutOfBounds(newX, newY)) {
					if (board.getPieceOnASquare(newX, newY) == '0' || board.getPieceOnASquare(newX, newY) > '6') {
						result.push_back({ newX, newY });
					}
				}
			}
			[[fallthrough]];
		case '4':
			steps = { {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			[[fallthrough]];
		case '5':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			[[fallthrough]];
		}

		if (type >= '2' && type <= '5' && type != '3') {
			for (Pair step : steps) {
				newX = x;
				newY = y;
				while (true) {
					if (isOutOfBounds(newX, newY)) {
						result.pop_back();
						break;
					}
					newX += step.x;
					newY += step.y;
					char piece = board.getPieceOnASquare(newX, newY);
					if (piece == '0' || piece == 'p') {
						result.push_back({ newX, newY });
					}
					else if (piece > '6') {
						result.push_back({ newX, newY });
						break;
					}
					else if (piece <= '6') {
						break;
					}
				}
			}
		}
		
		return result;
	}
};

