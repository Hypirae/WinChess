#include "stdafx.h"

Chess::Board::Board::Board ()
{
	_x = CHESS_BOARD_X;
	_y = CHESS_BOARD_Y;
	_board = std::array<std::optional<Chess::Piece::Piece>, CHESS_BOARD_AREA>{};

	fromFEN ( STARTING_FEN );
}

Chess::Board::Board::Board ( const std::string& const fen )
{
	_x = CHESS_BOARD_X;
	_y = CHESS_BOARD_Y;
	_board = std::array<std::optional<Chess::Piece::Piece>, CHESS_BOARD_AREA>{};

	fromFEN ( fen );
}

std::string Chess::Board::Board::toFEN ()
{
	std::string fen{};
	int squares = 0;
	int empties = 0;

	std::for_each ( _board.begin (), _board.end (), [this, &fen, &squares, &empties] ( std::optional<Chess::Piece::Piece> square )
					{
						if ( squares == 8 )
						{
							if ( empties > 0 )
							{
								fen.append ( std::to_string ( empties ) );
								empties = 0;
							}

							squares = 0;
							fen.append ( "/" );
						}

						if ( square.has_value () )
						{
							if ( empties > 0 )
							{
								fen.append ( std::to_string ( empties ) );
								empties = 0;
							}

							Chess::Piece::Piece p = square.value ();
							const char c = static_cast< char >( p );

							fen.append ( std::string{ c } );
						}
						else
						{
							empties++;
						}

						squares++;
					} );

	if ( empties > 0 )
		fen.append ( std::to_string ( empties ) );

	return fen;
}

void Chess::Board::Board::fromFEN ( const std::string& const fen )
{
	std::array<std::optional<Chess::Piece::Piece>, 64> board{};
	int i = 0;

	std::for_each ( fen.begin (), fen.end (), [&board, &i] ( const char& c )
					{
						switch ( c )
						{
							case 'p':
							case 'P':
							case 'r':
							case 'R':
							case 'n':
							case 'N':
							case 'b':
							case 'B':
							case 'q':
							case 'Q':
							case 'k':
							case 'K':
								board[ i ] = Chess::Piece::FENToPiece ( c );
								break;
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
								{
									int t = std::stoi ( std::string{ c } );
									i = i + ( t - 1 );
									break;
								}
							default:
								i--;
								break;
						}

						i++;
					} );

	_board = board;
}