#pragma once

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
#define CHESS_BOARD_X 8
#define CHESS_BOARD_Y 8
#define CHESS_BOARD_AREA (CHESS_BOARD_X * CHESS_BOARD_Y)

namespace Chess
{
	static std::string StartingFEN = STARTING_FEN;

	class Board
	{
	public:
		Board ();
		Board ( std::string& fen );

		std::string toFEN ();
		void fromFEN ( std::string& fen );
		std::array<std::optional<Piece>, CHESS_BOARD_AREA>& getBoard ();

	private:
		short _x;
		short _y;

		std::array<std::optional<Piece>, CHESS_BOARD_AREA> _board;
	};
}