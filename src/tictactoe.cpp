#include <iostream>
#include "tictactoe.h"

using std::cout;

namespace tictactoe {

Game::Game() {
    clearBoard();
}

void Game::clearBoard(){
    // set all values in board to 0
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            board[i][j] = 0;
        }
    }
}

void Game::printBoard() const {
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// returns true if move was successful
bool Game::makeMove(short row, short col, short player) {
    // Check if valid move
    if(row < 0 || row > 2 || col < 0 || col > 2){
        //cout << "Invalid move. Row and column must be between 0 and 2\n";
        return false;
    }
    if(board[row][col] != 0){
        //cout << "Invalid move. Already occupied\n";
        return false;
    }

    // make move
    board[row][col] = player;
    return true;
}

void Game::undoMove(short row, short col){
    if(row < 0 || row > 2 || col < 0 || col > 2){
        return;
    }
    board[row][col] = 0;
}

short Game::checkIfWin() const {
    // Check rows
    for(short i = 0; i < 3; i++){
        if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
    }

    // Check columns
    for(short j = 0; j < 3; j++){
        if(board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            return board[0][j];
        }
    }

    // Check diagonals
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }

    // No winner
    return 0;
}

bool Game::checkIfDraw() const {
    // check if any empty spaces
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            if(board[i][j] == 0){
                return false;
            }
        }
    }

    return !checkIfWin(); // check if win before declaring draw
}

short Game::getEmptyCellsCount() const {
    short count = 0;
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            if(board[i][j] == 0){
                count++;
            }
        }
    }
    return count;
};

}