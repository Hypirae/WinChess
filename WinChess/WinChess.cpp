#include "stdafx.h"

int main()
{
    using ChessBoard = Chess::Board::Board;
    using ChessPiece = Chess::Piece::Piece;

#ifdef _DEBUG
    const char t_p = 'p';
    const char t_K = 'K';

    ChessPiece tt_p = Chess::Piece::FENToPiece ( t_p );
    ChessPiece tt_K = Chess::Piece::FENToPiece ( t_K );

    assert ( ( tt_p == ChessPiece::BlackPawn ) );
    assert ( ( tt_K == ChessPiece::WhiteKing ) );

    std::string c_fen{ "2k5/4p2b/Pp6/1p4n1/5R1p/1qp1BP2/1b2K1P1/8" };
    ChessBoard t_board_d{};
    ChessBoard t_board_c{ c_fen };

    auto t_board_df = t_board_d.toFEN ();
    auto t_board_cf = t_board_c.toFEN ();

    assert ( ( t_board_df == STARTING_FEN ) );
    assert ( ( t_board_cf == c_fen ) );
#endif // _DEBUG

    return 0;
}
