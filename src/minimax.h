#pragma once
#include "tictactoe.h"
#include "Models/minimaxReturnModel.h"

namespace ai{
    constexpr int WIN_SCORE = 1000;
    constexpr int LOSE_SCORE = -1000;
    constexpr int DRAW_SCORE = 0;

    MinimaxReturn minimax(tictactoe::Game& tgame, short player, short depth = 9, bool maximizingPlayer = true);
    int scoreMove(tictactoe::Game& tgame, short depth = 9);
    bool isBetter(int eval, int bestEval, bool maximizingPlayer);
    short switchPlayer(short player);
    short matein(tictactoe::Game& tgame, short eval);

    MinimaxReturn evaluateMinimax(tictactoe::Game& tgame, short player, short depth, bool maximizingPlayer);
}