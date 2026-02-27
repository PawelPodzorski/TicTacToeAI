#pragma once
#include "tictactoe.h"
#include "Models/minimaxReturnModel.h"
#include <cmath>

namespace ai{
    constexpr int WIN_SCORE = 1000;
    constexpr int LOSE_SCORE = -1000;
    constexpr int DRAW_SCORE = 0;

    int scoreMove(tictactoe::Game& tgame, short depth = 9);
    bool isBetter(int eval, int bestEval, bool maximizingPlayer);
    short switchPlayer(short player);
    short matein(tictactoe::Game& tgame, short eval);
    
    MinimaxReturn minimax(tictactoe::Game& tgame, short player, short depth = 9, bool maximizingPlayer = true);
    MinimaxReturn minimaxAlphaBeta(tictactoe::Game& tgame, short player, short depth = 9, bool maximizingPlayer = true, int alpha = INT_MIN, int beta = INT_MAX);
    
    MinimaxReturn evaluateMinimax(tictactoe::Game& tgame, short player, short depth, bool maximizingPlayer);
    MinimaxReturn evaluateMinimaxAlphaBeta(tictactoe::Game& tgame, short player, short depth, bool maximizingPlayer);
    
    template<typename Func = decltype(evaluateMinimaxAlphaBeta)>
    MinimaxReturn evaluate(tictactoe::Game& tgame, short player, short depth = 9, bool maximizingPlayer = true, Func minimaxFunc = evaluateMinimaxAlphaBeta){
        return minimaxFunc(tgame, player, depth, maximizingPlayer);
    }
}