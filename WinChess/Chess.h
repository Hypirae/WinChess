#pragma once

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
#define CHESS_BOARD_X 8
#define CHESS_BOARD_Y 8
#define CHESS_BOARD_AREA (CHESS_BOARD_X * CHESS_BOARD_Y)

namespace Chess
{
	namespace Board
	{
		class Board
		{
		public:
			Board ();
			Board ( const std::string& const fen );

			std::string toFEN ();
			void fromFEN ( const std::string& const fen );
			

		private:
			short _x;
			short _y;

			std::array<std::optional<Chess::Piece::Piece>, CHESS_BOARD_AREA> _board;
		};
	}
}