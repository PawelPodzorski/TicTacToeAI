#pragma once

namespace tictactoe {
    class Game {
        private:
        short board[3][3];

        public:
        Game();
        void clearBoard();
        void printBoard();
        bool makeMove(short row, short col, short player);
        void undoMove(short row, short col);
        short checkIfWin();
        bool checkIfDraw();
    };
}