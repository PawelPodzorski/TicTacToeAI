#include "minimax.h"
#include <cmath>

namespace ai{

MinimaxReturn evaluateMinimax(tictactoe::Game& tgame, short player, short depth, bool maximizingPlayer){
    MinimaxReturn result = minimax(tgame, player, depth, maximizingPlayer);
    return MinimaxReturn{result.eval, {result.move[0], result.move[1]}};
}

MinimaxReturn minimax(tictactoe::Game& tgame, short player, short depth, bool maximizingPlayer){
    short winner = tgame.checkIfWin();
    if(winner != 0 || tgame.checkIfDraw() || depth == 0){
        return MinimaxReturn{scoreMove(tgame, depth), {0,0}};
    }

    int eval = maximizingPlayer ? INT_MIN : INT_MAX;
    int bestMove[2] = {0, 0};

    for(short row = 0; row < 3; row++){
        for(short col = 0; col < 3; col++){
            if(tgame.makeMove(row, col, player)){
                MinimaxReturn result = minimax(tgame, switchPlayer(player), depth - 1, !maximizingPlayer);
                tgame.undoMove(row,col);
                
                if(isBetter(result.eval, eval, maximizingPlayer)){
                    eval = result.eval;
                    bestMove[0] = row;
                    bestMove[1] = col;
                }
            }
        }
    }
    return MinimaxReturn{eval, {bestMove[0], bestMove[1]}};
}

int scoreMove(tictactoe::Game& tgame, short depth){
    short winner = tgame.checkIfWin();
    if(winner == 1) return WIN_SCORE+depth; // add depth to prefer faster wins
    if(winner == 2) return LOSE_SCORE-depth; // subtract depth to prefer slower losses
    if(tgame.checkIfDraw()) return DRAW_SCORE;
    return 0;
}

bool isBetter(int eval, int bestEval, bool maximizingPlayer){
    return (maximizingPlayer) ? (eval > bestEval) : (eval < bestEval);
}

short switchPlayer(short player){
    return (player == 1) ? 2 : 1;
}

short matein(tictactoe::Game& tgame, short eval){
    if(eval > 0){
        short numberOfLegalMoves = tgame.getEmptyCellsCount();
        return numberOfLegalMoves + WIN_SCORE - eval;
    } else if(eval < 0){
        short numberOfLegalMoves = tgame.getEmptyCellsCount();
        return -(-numberOfLegalMoves + LOSE_SCORE - eval);
    } else {
        return 0; // draw
    }
}

}