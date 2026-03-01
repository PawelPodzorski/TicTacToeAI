#include <iostream>
#include "tictactoe.h"

using std::cout;

namespace tictactoe {

// Enable ANSI escape codes on Windows for colored output
// Copied from intenet
#ifdef _WIN32
#include <windows.h>
void Game::enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif
//

// Convert CellState to string for printing
std::string toString(tictactoe::CellState state){
    switch(state){
        case CellState::Empty:
            return " ";
        case CellState::O:
            return "O";
        case CellState::X:
            return "X";
    }
    return "?";
}


Game::Game() {
    clearBoard();
}

void Game::clearBoard(){
    // set all values in board to 0
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            board[i][j] = CellState::Empty;
        }
    }
}

void Game::printBoard() const {
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            // print X in red and O in blue
            switch (board[i][j]) {
                case CellState::X:
                    std::cout << "\033[31m" << toString(board[i][j]) << "\033[0m"; // red
                    break;
                case CellState::O:
                    std::cout << "\033[34m" << toString(board[i][j]) << "\033[0m"; // blue
                    break;
                case CellState::Empty:
                    std::cout << " ";
                    break;
            }

            if(j < 2) cout << " | ";
        }
        cout << "\n" << (i < 2 ? "--+---+--\n" : "");
    }
}

// returns true if move was successful
bool Game::makeMove(short row, short col, short player) {
    // Check if valid move
    if(row < 0 || row > 2 || col < 0 || col > 2){ // out of bounds
        return false;
    }
    if(board[row][col] != CellState::Empty){ // cell already occupied
        return false;
    }

    // make move
    board[row][col] = static_cast<CellState>(player);
    return true;
}

void Game::undoMove(short row, short col){
    if(row < 0 || row > 2 || col < 0 || col > 2){
        return;
    }
    board[row][col] = CellState::Empty;
}

short Game::checkIfWin() const {
    // Check rows
    for(short i = 0; i < 3; i++){
        if(board[i][0] != CellState::Empty && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return static_cast<short>(board[i][0]);
        }
    }

    // Check columns
    for(short j = 0; j < 3; j++){
        if(board[0][j] != CellState::Empty && board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            return static_cast<short>(board[0][j]);
        }
    }

    // Check diagonals
    if(board[0][0] != CellState::Empty && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return static_cast<short>(board[0][0]);
    }
    if(board[0][2] != CellState::Empty && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return static_cast<short>(board[0][2]);
    }

    // No winner
    return 0;
}

bool Game::checkIfDraw() const {
    // check if any empty spaces
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            if(board[i][j] == CellState::Empty){
                return false;
            }
        }
    }

    return !checkIfWin(); // check if win before declaring draw
}

short Game::getCell(short row, short col) const {
    if(row < 0 || row > 2 || col < 0 || col > 2){
        return -1; // invalid cell
    }
    return static_cast<short>(board[row][col]);
}

short Game::getEmptyCellsCount() const {
    short count = 0;
    for(short i = 0; i < 3; i++){
        for(short j = 0; j < 3; j++){
            if(board[i][j] == CellState::Empty){
                count++;
            }
        }
    }
    return count;
};

}