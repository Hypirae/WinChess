#pragma once

namespace Chess
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
		None = 0,
	};

	namespace PieceUtil
	{
		std::string pieceToFEN ( Piece piece );
		Piece FENToPiece ( const char fen );
		Piece FENToPiece ( std::string& fen );
	}
}