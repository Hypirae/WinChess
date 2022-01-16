#include "stdafx.h"

const std::string& const Chess::Piece::pieceToFEN(Chess::Piece::Piece piece)
{
	return std::string{ static_cast< char >( piece ) };
}

Chess::Piece::Piece Chess::Piece::FENToPiece ( const char fen )
{
	switch ( fen )
	{
		case 'p':
		case 'P':
			return ( fen == 'P' ) ? Chess::Piece::Piece::WhitePawn : Chess::Piece::Piece::BlackPawn;
			break;
		case 'r':
		case 'R':
			return ( fen == 'R' ) ? Chess::Piece::Piece::WhiteRook : Chess::Piece::Piece::BlackRook;
			break;
		case 'n':
		case 'N':
			return ( fen == 'N' ) ? Chess::Piece::Piece::WhiteKnight : Chess::Piece::Piece::BlackKnight;
			break;
		case 'b':
		case 'B':
			return ( fen == 'B' ) ? Chess::Piece::Piece::WhiteBishop : Chess::Piece::Piece::BlackBishop;
			break;
		case 'q':
		case 'Q':
			return ( fen == 'Q' ) ? Chess::Piece::Piece::WhiteQueen : Chess::Piece::Piece::BlackQueen;
			break;
		case 'k':
		case 'K':
			return ( fen == 'K' ) ? Chess::Piece::Piece::WhiteKing : Chess::Piece::Piece::BlackKing;
			break;
	}
}

Chess::Piece::Piece Chess::Piece::FENToPiece ( const std::string& const fen )
{
	char fenc = static_cast< char >( fen[ 0 ] );

	return Chess::Piece::FENToPiece ( fenc );
}
