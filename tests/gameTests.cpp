#include <gtest/gtest.h>
#include "tictactoe/game.h"

using namespace tictactoe;

// Game Tests
/*
Game testing focuses on testing the overall game logic, 
such as checking win/draw conditions, and ensuring that the game state updates correctly after moves are made.
These tests ensure that the core mechanics of the game are functioning as intended.
*/

// Test that empty cell count decreases after making a move
TEST(GameTest, EmptyCellsDecreaseAfterMove) {
    Game game;
    EXPECT_EQ(game.getEmptyCellsCount(), 9);

    game.makeMove(0,0,CellState::X);

    EXPECT_EQ(game.getEmptyCellsCount(), 8);
}

// Test that undoing a move increases empty cell count
TEST(GameTest, UndoMoveIncreasesEmptyCells) {
    Game game;
    game.makeMove(0,0,CellState::X);
    EXPECT_EQ(game.getEmptyCellsCount(), 8);

    game.undoMove(0,0);
    EXPECT_EQ(game.getEmptyCellsCount(), 9);
}

// Test empty board condition
TEST(GameTest, TestEmptyBoard) {
    Game game;
    EXPECT_EQ(game.getEmptyCellsCount(), 9);
    EXPECT_FALSE(game.checkIfDraw());
    EXPECT_EQ(game.checkIfWin(), CellState::Empty);
}

// Test full board with no winner is a draw
TEST(GameTest, FullBoardNoWinnerIsDraw) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::O);
    game.makeMove(0, 2, CellState::X);
    game.makeMove(1, 0, CellState::X);
    game.makeMove(1, 1, CellState::O);
    game.makeMove(1, 2, CellState::O);
    game.makeMove(2, 0, CellState::O);
    game.makeMove(2, 1, CellState::X);
    game.makeMove(2, 2, CellState::X);

    EXPECT_TRUE(game.checkIfDraw());
    EXPECT_EQ(game.checkIfWin(), CellState::Empty);
}

// Test full board with a winner is not a draw
TEST(GameTest, FullBoardWithWinnerIsNotDraw) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::X);
    game.makeMove(0, 2, CellState::X);
    game.makeMove(1, 0, CellState::O);
    game.makeMove(1, 1, CellState::O);
    game.makeMove(1, 2, CellState::X);
    game.makeMove(2, 0, CellState::O);
    game.makeMove(2, 1, CellState::X);
    game.makeMove(2, 2, CellState::O);

    EXPECT_FALSE(game.checkIfDraw());
    EXPECT_EQ(game.checkIfWin(), CellState::X);
}

// Test that two in a row does not count as a win
TEST(GameTest, TwoInRowIsNotWin) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::X);

    EXPECT_EQ(game.checkIfWin(), CellState::Empty);
}

TEST(GameTest, clearBoardResetsState) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::X);
    game.makeMove(0, 2, CellState::X);
    game.makeMove(1, 1, CellState::O);
    game.clearBoard();

    EXPECT_EQ(game.getEmptyCellsCount(), 9);
    EXPECT_EQ(game.getCell(0, 0), CellState::Empty);
    EXPECT_EQ(game.checkIfWin(), CellState::Empty);
}

// Test draw condition
TEST(GameTest, TestDrawCondition) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::O);
    game.makeMove(0, 2, CellState::X);
    game.makeMove(1, 0, CellState::X);
    game.makeMove(1, 1, CellState::O);
    game.makeMove(1, 2, CellState::O);
    game.makeMove(2, 0, CellState::O);
    game.makeMove(2, 1, CellState::X);
    game.makeMove(2, 2, CellState::X);
    EXPECT_TRUE(game.checkIfDraw());
}

// Test win conditions for X and O in diagonals
TEST(GameTest, XWinDiagonal) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(1, 1, CellState::X);
    game.makeMove(2, 2, CellState::X);
    EXPECT_EQ(game.checkIfWin(), CellState::X);
}
TEST(GameTest, OWinDiagonal) {
    Game game;
    game.makeMove(0, 0, CellState::O);
    game.makeMove(1, 1, CellState::O);
    game.makeMove(2, 2, CellState::O);
    EXPECT_EQ(game.checkIfWin(), CellState::O);
}

// Test win conditions for X and O in columns
TEST(GameTest, XWinColumn) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(1, 0, CellState::X);
    game.makeMove(2, 0, CellState::X);
    EXPECT_EQ(game.checkIfWin(), CellState::X);
}
TEST(GameTest, OWinColumn) {
    Game game;
    game.makeMove(0, 0, CellState::O);
    game.makeMove(1, 0, CellState::O);
    game.makeMove(2, 0, CellState::O);
    EXPECT_EQ(game.checkIfWin(), CellState::O);
}

// Test win conditions for X and O in rows
TEST(GameTest, OWinRow) {
    Game game;
    game.makeMove(0, 0, CellState::O);
    game.makeMove(0, 1, CellState::O);
    game.makeMove(0, 2, CellState::O);
    EXPECT_EQ(game.checkIfWin(), CellState::O);
}
TEST(GameTest, XWinRow) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(0, 1, CellState::X);
    game.makeMove(0, 2, CellState::X);
    EXPECT_EQ(game.checkIfWin(), CellState::X);
}
