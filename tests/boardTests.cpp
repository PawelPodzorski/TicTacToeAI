#include <gtest/gtest.h>
#include "tictactoe/game.h"

using namespace tictactoe;

// Board Tests
/*
Board testing is focused on testing the Game class methods related to the game board,
such as making moves, undoing moves and getting cell states. 
These tests ensure that managing the board state is functioning correctly.
*/

// Test making valid moves
TEST(BoardTest, TestValidMoves) {
    Game game;
    EXPECT_TRUE(game.makeMove(0, 0, CellState::X));
    EXPECT_TRUE(game.makeMove(1, 1, CellState::O));
}

// Test making invalid moves
TEST(BoardTest, TestInvalidMoves) {
    Game game;
    EXPECT_TRUE(game.makeMove(0, 0, CellState::X));
    EXPECT_FALSE(game.makeMove(0, 0, CellState::O)); // cell already occupied
    EXPECT_FALSE(game.makeMove(-1, 0, CellState::X)); // out of bounds
    EXPECT_FALSE(game.makeMove(0, 3, CellState::O)); // out of bounds
}

// Test getCell method for valid and invalid coordinates
TEST(BoardTest, GetCellTest) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    game.makeMove(1, 1, CellState::O);
    EXPECT_EQ(game.getCell(0, 0), CellState::X);
    EXPECT_EQ(game.getCell(1, 1), CellState::O);
    EXPECT_EQ(game.getCell(2, 2), CellState::Empty);
    EXPECT_EQ(game.getCell(-1, 0), CellState::Empty); // out of bounds
    EXPECT_EQ(game.getCell(0, 3), CellState::Empty); // out of bounds
}

// Test undoing moves
TEST(BoardTest, UndoMoveTest) {
    Game game;
    game.makeMove(0, 0, CellState::X);
    EXPECT_EQ(game.getCell(0, 0), CellState::X);

    game.undoMove(0, 0);
    EXPECT_EQ(game.getCell(0, 0), CellState::Empty);

    game.undoMove(-1, 0); // out of bounds, should do nothing
    EXPECT_EQ(game.getCell(0, 0), CellState::Empty);
}
