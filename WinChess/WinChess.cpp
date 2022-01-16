#include "stdafx.h"

int main()
{

    Chess::Board board{};
    Chess::Terminal term{};

    term.drawBoard ( board );

#ifdef _DEBUG
    int pause = 0;
    std::cin >> pause;
#endif // _DEBUG

    return 0;
}
