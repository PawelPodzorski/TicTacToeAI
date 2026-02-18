#pragma once

namespace tictactoe {
    class Game {
        private:
        short board[3][3];

        public:
        Game();
        void clearBoard();
        void printBoard() const;
        bool makeMove(short row, short col, short player);
        void undoMove(short row, short col);
        short checkIfWin() const;
        bool checkIfDraw() const;
        short getCell(short row, short col) const { return board[row][col]; }
        short getEmptyCellsCount() const;
    };
}