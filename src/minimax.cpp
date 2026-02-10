#include "minimax.h"
#include <cmath>

namespace ai{

int minimax(tictactoe::Game& tgame, short depth, short player, bool maximizingPlayer){
    short winner = tgame.checkIfWin();
    if(winner != 0 || tgame.checkIfDraw() || depth == 0){
        return scoreMove(tgame);
    }

    int eval = maximizingPlayer ? INT_MIN : INT_MAX;

    for(short row = 0; row < 3; row++){
        for(short col = 0; col < 3; col++){
            if(tgame.makeMove(row, col, player)){
                int result = minimax(tgame, depth - 1, switchPlayer(player), !maximizingPlayer);
                tgame.undoMove(row,col);
                
                if(maximizingPlayer){
                    eval = std::max(eval, result);
                } else {
                    eval = std::min(eval, result);
                }
            }
        }
    }
    return eval;
}

int scoreMove(tictactoe::Game& tgame){
    short winner = tgame.checkIfWin();
    if(winner == 1) return WIN_SCORE;
    if(winner == 2) return LOSE_SCORE;
    if(tgame.checkIfDraw()) return DRAW_SCORE;
    return 0;
}

short switchPlayer(short player){
    return (player == 1) ? 2 : 1;
}

}