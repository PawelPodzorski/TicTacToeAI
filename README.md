# Tic-Tac-Toe AI

![](https://img.shields.io/badge/C%2B%2B-11+-blue.svg)
![LICENSE](https://img.shields.io/badge/License-MIT-orange.svg)

A classic Tic-Tac-Toe game implemented in C++ where you can play against another human or an AI opponent. The AI uses the Minimax algorithm with alpha-beta pruning to determine the optimal move, making the "Impossible" difficulty level unbeatable.

## Features

-   **Player vs Player:** Play a game of Tic-Tac-Toe with a friend on the same machine.
-   **Player vs AI:** Challenge an AI with varying levels of difficulty.
-   **Multiple AI Difficulties:**
    -   **Easy:** The AI makes completely random moves.
    -   **Medium:** The AI will make a winning move or block a losing move if one is available. Otherwise, it plays randomly.
    -   **Impossible:** The AI uses the Minimax algorithm with alpha-beta pruning to play a perfect game every time. It will never lose.

## Getting Started

### Prerequisites

You will need a C++ compiler (like g++) installed on your system.

### Compilation and Execution

1.  Clone the repository:
    ```sh
    git clone https://github.com/pawelpodzorski/TicTacToeAI.git
    cd TicTacToeAI
    ```

2.  Compile the source files using your C++ compiler. For example, with g++:
    ```sh
    g++ src/*.cpp -o tttai.exe
    ```

3.  Run the executable:
    ```sh
    ./tttai.exe
    ```

## How to Play

1.  When the game starts, you will be prompted to choose an opponent: `AI` or `Human`.
2.  If you choose `AI`, you will then select a difficulty: `Easy`, `Medium`, or `Impossible`.
3.  The game board is represented by a 3x3 grid. `0` indicates an empty cell, `1` is for Player 1 (O), and `2` is for Player 2 (X).
4.  To make a move, enter the row and column numbers (from 0 to 2), separated by a space. For example, to place your mark in the top-left corner, enter `0 0`.

```
Do you want to play against AI or Human?
AI
Choose AI difficulty: [Easy | Medium | Impossible]
Impossible
-----------------------
0 0 0
0 0 0
0 0 0
Player 1, enter row and column (0-2) for your move
0 0
-----------------------
1 0 0
0 2 0
0 0 0
Player 1, enter row and column (0-2) for your move
...
```

## Code Structure

-   `main.cpp`: The entry point for the application.
-   `game.h` / `game.cpp`: Manages the main game loop, user input, and different game modes (Human vs. Human, Human vs. AI).
-   `tictactoe.h` / `tictactoe.cpp`: Contains the `Game` class, which handles the board state, move validation, and checking for win/draw conditions.
-   `minimax.h` / `minimax.cpp`: Implements the AI logic using the Minimax algorithm with alpha-beta pruning to find the optimal move.
-   `Models/minimaxReturnModel.h`: Defines the `MinimaxReturn` struct used to return the evaluation score and the best move from the AI algorithm.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
