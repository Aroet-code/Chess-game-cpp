#pragma once
#include <cstdint>
#include <iostream>
class Board
{
private:
	void initiateDefaultStartPosition() {
		reset();
		uint64_t temp = 1;
		white_rooks = white_rooks ^ temp;
		temp = temp << 1;
		white_knights = white_knights ^ temp;
		temp = temp << 1;
		white_bishops = white_bishops ^ temp;
		temp = temp << 1;
		white_kings = white_kings ^ temp;
		temp = temp << 1;
		white_queens = white_queens ^ temp;
		temp = temp << 1;
		white_bishops = white_bishops ^ temp;
		temp = temp << 1;
		white_knights = white_knights ^ temp;
		temp = temp << 1;
		white_rooks = white_rooks ^ temp;
		for (int i = 0; i < 8; i++) {
			temp = temp << 1;
			white_pawns = white_pawns ^ temp;
		}
		temp = temp << 32;
		for (int i = 0; i < 8; i++) {
			temp = temp << 1;
			black_pawns = black_pawns ^ temp;
		}
		temp = temp << 1;
		black_rooks = black_rooks ^ temp;
		temp = temp << 1;
		black_knights = black_knights ^ temp;
		temp = temp << 1;
		black_bishops = black_bishops ^ temp;
		temp = temp << 1;
		black_kings = black_kings ^ temp;
		temp = temp << 1;
		black_queens = black_queens ^ temp;
		temp = temp << 1;
		black_bishops = black_bishops ^ temp;
		temp = temp << 1;
		black_knights = black_knights ^ temp;
		temp = temp << 1;
		black_rooks = black_rooks ^ temp;
	}
	void reset() {
		white_pawns = 0;
		white_rooks = 0;
		white_knights = 0;
		white_bishops = 0;
		white_queens = 0;
		white_kings = 0;

		black_pawns = 0;
		black_rooks = 0;
		black_knights = 0;
		black_bishops = 0;
		black_queens = 0;
		black_kings = 0;
	}
public:
	Board(bool initialize) {
		if (initialize) {
			initiateDefaultStartPosition();
		}
	}

	char getPieceOnASquare(int x, int y) {
		uint64_t temp = 1;
		temp = temp << ((y - 1) * 8);
		temp = temp << (x - 1);
		if (temp & white_pawns) {
			return '1';
		}
		if (temp & white_rooks) {
			return '2';
		}
		if (temp & white_knights) {
			return '3';
		}
		if (temp & white_bishops) {
			return '4';
		}
		if (temp & white_queens) {
			return '5';
		}
		if (temp & white_kings) {
			return '6';
		}
		if (temp & black_pawns) {
			return '7';
		}
		if (temp & black_rooks) {
			return '8';
		}
		if (temp & black_knights) {
			return '9';
		}
		if (temp & black_bishops) {
			return 'a';
		}
		if (temp & black_queens) {
			return 'b';
		}
		if (temp & black_kings) {
			return 'c';
		}
		return '0';
	}

	void logBoard() {
		uint64_t temp = 1;
		temp = temp << 63;
		std::cout << "Logging the board:" << std::endl;
		for (int i = 0; i < 64; i++) {
			if (i != 0) {
				temp = temp >> 1;
			}
			if (i % 8 == 0) {
				std::cout << std::endl;
			}
			if (temp & white_pawns) {
				std::cout << "1";
				continue;
			}
			if (temp & white_rooks) {
				std::cout << "2";
				continue;
			}
			if (temp & white_knights) {
				std::cout << "3";
				continue;
			}
			if (temp & white_bishops) {
				std::cout << "4";
				continue;
			}
			if (temp & white_queens) {
				std::cout << "5";
				continue;
			}
			if (temp & white_kings) {
				std::cout << "6";
				continue;
			}
			if (temp & black_pawns) {
				std::cout << "7";
				continue;
			}
			if (temp & black_rooks) {
				std::cout << "8";
				continue;
			}
			if (temp & black_knights) {
				std::cout << "9";
				continue;
			}
			if (temp & black_bishops) {
				std::cout << "a";
				continue;
			}
			if (temp & black_queens) {
				std::cout << "b";
				continue;
			}
			if (temp & black_kings) {
				std::cout << "c";
				continue;
			}
			std::cout << 0;
		}
		std::cout << std::endl << std::endl;
		std::cout << "Finished logging the board." << std::endl;
	}

	uint64_t white_pawns = 0;
	uint64_t white_rooks = 0;
	uint64_t white_knights = 0;
	uint64_t white_bishops = 0;
	uint64_t white_queens = 0;
	uint64_t white_kings = 0;

	uint64_t black_pawns = 0;
	uint64_t black_rooks = 0;
	uint64_t black_knights = 0;
	uint64_t black_bishops = 0;
	uint64_t black_queens = 0;
	uint64_t black_kings = 0;

};

struct Pair {
	int x;
	int y;

	Pair(int x, int y) {
		this->x = x;
		this->y = y;
	}
};