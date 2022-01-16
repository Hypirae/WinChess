#include "stdafx.h"

std::string Chess::PieceUtil::pieceToFEN(Piece piece)
{
	auto fen = std::string{ static_cast< char >( piece ) };
	return fen;
}

Chess::Piece Chess::PieceUtil::FENToPiece ( const char fen )
{
	switch ( fen )
	{
		case 'p':
		case 'P':
			return ( fen == 'P' ) ? Piece::WhitePawn : Piece::BlackPawn;
			break;
		case 'r':
		case 'R':
			return ( fen == 'R' ) ? Piece::WhiteRook : Piece::BlackRook;
			break;
		case 'n':
		case 'N':
			return ( fen == 'N' ) ? Piece::WhiteKnight : Piece::BlackKnight;
			break;
		case 'b':
		case 'B':
			return ( fen == 'B' ) ? Piece::WhiteBishop : Piece::BlackBishop;
			break;
		case 'q':
		case 'Q':
			return ( fen == 'Q' ) ? Piece::WhiteQueen : Piece::BlackQueen;
			break;
		case 'k':
		case 'K':
			return ( fen == 'K' ) ? Piece::WhiteKing : Piece::BlackKing;
			break;
		default:
			return Piece::None;
	}
}

Chess::Piece Chess::PieceUtil::FENToPiece ( std::string& fen )
{
	char fenc = static_cast< char >( fen[ 0 ] );

	return Chess::PieceUtil::FENToPiece ( fenc );
}
