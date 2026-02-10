#pragma once
#include "tictactoe.h"

namespace ai{
    constexpr int WIN_SCORE = 1000;
    constexpr int LOSE_SCORE = -1000;
    constexpr int DRAW_SCORE = 0;

    int minimax(tictactoe::Game& tgame, short depth, short player, bool maximizingPlayer = true);
    int scoreMove(tictactoe::Game& tgame);
    short switchPlayer(short player);
}