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
		
		bool isWhite = false;

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
			break;
		case '2':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			isWhite = true;
			break;
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
			break;
		case '4':
			steps = { {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			isWhite = true;
			break;
		case '5':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			isWhite = true;
			break;
		case '6':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			for (auto step : steps) {
				if (!isOutOfBounds(newX, newY)) {
					if (board.getPieceOnASquare(newX, newY) == '0' || board.getPieceOnASquare(newX, newY) > '6') {
						result.push_back({ newX, newY });
					}
				}
			}
			break;
		case '7':
			if (board.getPieceOnASquare(newX, newY - 1) == '0') {
				result.push_back({ newX, newY - 1 });
				if (y == 7) {
					if (board.getPieceOnASquare(newX, newY - 2) == '0') {
						result.push_back({ newX, newY - 2 });
					}
				}
			}
			if (!isOutOfBounds(newX - 1, newY - 1)) {
				if (board.getPieceOnASquare(newX - 1, newY - 1) <= '6' && board.getPieceOnASquare(newX - 1, newY - 1) != '0') {
					result.push_back({ newX - 1, newY - 1 });
				}
			}
			if (!isOutOfBounds(newX + 1, newY - 1)) {
				if (board.getPieceOnASquare(newX + 1, newY - 1) <= '6' && board.getPieceOnASquare(newX + 1, newY - 1) != '0') {
					result.push_back({ newX + 1, newY - 1 });
				}
			}
			break;
		case '8':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			isWhite = false;
			break;
		case '9':
			for (auto step : knightOffsets) {
				newX = x;
				newY = y;
				newX += step.x;
				newY += step.y;
				if (!isOutOfBounds(newX, newY)) {
					if (board.getPieceOnASquare(newX, newY) == '0' || board.getPieceOnASquare(newX, newY) <= '6') {
						result.push_back({ newX, newY });
					}
				}
			}
			break;
		case 'a':
			steps = { {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			isWhite = false;
			break;
		case 'b':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			isWhite = false;
			break;
		case 'c':
			steps = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
			for (auto step : steps) {
				if (!isOutOfBounds(newX, newY)) {
					if (board.getPieceOnASquare(newX, newY) == '0' || board.getPieceOnASquare(newX, newY) <= '6') {
						result.push_back({ newX, newY });
					}
				}
			}
			break;
		}

		if ((type >= '2' && type <= '5' && type != '3') || (type >= '8' && type <= 'b' && type != 'a')) {
			for (Pair step : steps) {
				newX = x;
				newY = y;
				while (true) {
					newX += step.x;
					newY += step.y;
					if (isOutOfBounds(newX, newY)) {
						break;
					}
					char piece = board.getPieceOnASquare(newX, newY);
					if (piece == '0' || piece == 'p' || piece == -'p') {
						result.push_back({ newX, newY });
					}
					else {
						if (isWhite) {
							if (piece > '6') {
								result.push_back({ newX, newY });
								break;
							}
							else if (piece <= '6') {
								break;
							}
						}
						else {
							if (piece <= '6') {
								result.push_back({ newX, newY });
								break;
							}
							else {
								break;
							}
						}
					}
				}
			}
		}
		
		return result;
	}
};

