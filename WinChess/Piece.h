#pragma once

namespace Chess
{
	namespace Piece
	{
		enum class Piece
		{
			WhiteKing = 75,
			WhiteQueen = 81,
			WhiteBishop = 66,
			WhiteKnight = 78,
			WhiteRook = 82,
			WhitePawn = 80,
			BlackKing = 107,
			BlackQueen = 113,
			BlackBishop = 98,
			BlackKnight = 110,
			BlackRook = 114,
			BlackPawn = 112,
		};

		const std::string& const pieceToFEN ( Chess::Piece::Piece piece );
		Chess::Piece::Piece FENToPiece ( const char fen );
		Chess::Piece::Piece FENToPiece ( const std::string& const fen );
	}
}