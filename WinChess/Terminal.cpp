#include "stdafx.h"

wincon::console_bg_colors getBgColor ( int i )
{
	const wincon::console_bg_colors b = wincon::console_bg_colors::black;
	const wincon::console_bg_colors w = wincon::console_bg_colors::white;

	const std::array<wincon::console_bg_colors, CHESS_BOARD_AREA> cl{
		w, b, w, b, w, b, w, b,
		b, w, b, w, b, w, b, w,
		w, b, w, b, w, b, w, b,
		b, w, b, w, b, w, b, w,
		w, b, w, b, w, b, w, b,
		b, w, b, w, b, w, b, w,
		w, b, w, b, w, b, w, b,
		b, w, b, w, b, w, b, w
	};

	return cl[ i ];
}

wincon::console_text_colors getPieceColor ( Chess::Piece piece )
{
	switch ( piece )
	{
		case Chess::Piece::WhiteKing:
		case Chess::Piece::WhiteQueen:
		case Chess::Piece::WhiteBishop:
		case Chess::Piece::WhiteKnight:
		case Chess::Piece::WhiteRook:
		case Chess::Piece::WhitePawn:
			return wincon::console_text_colors::white;
			break;
		case Chess::Piece::BlackKing:
		case Chess::Piece::BlackQueen:
		case Chess::Piece::BlackBishop:
		case Chess::Piece::BlackKnight:
		case Chess::Piece::BlackRook:
		case Chess::Piece::BlackPawn:
			return wincon::console_text_colors::black;
			break;
		default:
			return wincon::console_text_colors::black;
	}
}

wincon::console_text_colors getFgColor ( int i, Chess::Piece piece )
{
	auto bc = getBgColor ( i );
	auto pc = getPieceColor ( piece );

	if ( bc == wincon::console_bg_colors::black && pc == wincon::console_text_colors::black )
	{
		return wincon::console_text_colors::white;
	}

	if ( bc == wincon::console_bg_colors::white && pc == wincon::console_text_colors::white )
	{
		return wincon::console_text_colors::black;
	}

	return pc;
}

Chess::Terminal::Terminal ()
{
	term = wincon::console_out{ _octx };
}

void Chess::Terminal::drawBoard ( Board board )
{
	int i = 0;
	short x = 0, y = 0;
	std::array<std::optional<Piece>, CHESS_BOARD_AREA> boardArray = board.getBoard ();

	// set position of the board
	term.setpos ( 0, 0 );

	std::for_each ( boardArray.begin (), boardArray.end (), [this, &i, &x, &y] ( std::optional<Piece> piece )
					{
						if ( x == 8 )
						{
							x = 0;
							y++;
						}

						// set the position and bg of the board for this character
						term.setpos ( x, y );
						term.setbgcolor ( getBgColor ( i ) );

						if ( piece.has_value () )
						{
							std::string fen = PieceUtil::pieceToFEN ( piece.value () );

							if ( fen == "\0" )
							{
								std::cout << " ";
							}
							else
							{
								term.settextcolor ( getFgColor ( i, piece.value () ) );
								std::cout << fen;
							}
						}
						else
						{
							std::cout << " ";
						}

						i++;
						x++;
					} );
}