#pragma once
#include <string>

namespace tictactoe {
    enum class CellState : short { Empty = 0, O = 1, X = 2 };

    std::string toString(tictactoe::CellState state);

    class Game {
        private:
        CellState board[3][3];

        // Enable ANSI escape codes on Windows for colored output
        #ifdef _WIN32
            void enableANSI();
        #endif

        public:
        Game();
        void clearBoard();
        void printBoard() const;
        bool makeMove(short row, short col, short player);
        void undoMove(short row, short col);
        short checkIfWin() const;
        bool checkIfDraw() const;
        short getCell(short row, short col) const;
        short getEmptyCellsCount() const;
    };
}