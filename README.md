# Tic-Tac-Toe AI

![](https://img.shields.io/badge/C%2B%2B-17+-blue.svg)
[![LICENSE](https://img.shields.io/badge/License-MIT-orange.svg)](https://opensource.org/licenses/MIT)
[![CI testing](https://github.com/PawelPodzorski/TicTacToeAI/actions/workflows/ci.yml/badge.svg)](https://github.com/PawelPodzorski/TicTacToeAI/actions/workflows/ci.yml)

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

To compile and run this project, you will need a C++ compiler that supports C++17, such as g++.

### Compilation and Execution

1.  Clone the repository:
    ```sh
    git clone https://github.com/pawelpodzorski/TicTacToeAI.git
    cd TicTacToeAI
    ```

2.  Compile the source files using your C++ compiler. For example, with g++:
    ```sh
    g++ -std=c++17 src/*.cpp main.cpp -Iinclude -o tictactoeai.exe
    ```

3.  Run the executable:
    ```sh
    ./tictactoeai.exe
    ```

## How to Play

1.  When the game starts, you will be prompted to choose an opponent: `AI` or `Human`.
2.  If you choose `AI`, you will then select a difficulty: `Easy`, `Medium`, or `Impossible`.
3.  The game board is displayed in the console. Player 1 is 'O' (blue) and Player 2 is 'X' (red).
4.  To make a move, enter the row and column numbers (from 0 to 2), separated by a space. For example, to place your mark in the top-left corner, enter `0 0`.

```
Do you want to play against AI or Human?
ai
Choose AI difficulty: [Easy | Medium | Impossible]
medium
-----------------------
  |   |
--+---+--
  |   |
--+---+--
  |   |
Player 1, enter row and column (0-2) for your move
0 0
-----------------------
O |   |
--+---+--
  |   |
--+---+--
  |   |
-----------------------
O |   |
--+---+--
X |   |
--+---+--
  |   |
Player 1, enter row and column (0-2) for your move
...
```

## AI Implementation

The core of the AI is the **Minimax algorithm**, a decision-making algorithm used in two-player games. It works by recursively exploring the game tree to find the optimal move.

-   **Evaluation Function:** A scoring function evaluates terminal states (win, loss, draw). Wins are given a high positive score, losses a high negative score, and draws a neutral score. The score is adjusted by depth to prefer faster wins and slower losses.
-   **Alpha-Beta Pruning:** To optimize the Minimax search, alpha-beta pruning is implemented. This technique safely prunes large parts of the game tree that cannot influence the final decision, significantly speeding up the AI's move calculation.

## Testing

The project includes a suite of unit tests built with the GoogleTest framework to ensure the core game logic is working correctly.

1.  **Install GoogleTest:**
    On Debian-based systems (like Ubuntu), you can install it via `apt`.
    ```sh
    sudo apt-get update
    sudo apt-get install -y libgtest-dev cmake
    ```
    Then, build and install the libraries:
    ```sh
    cd /usr/src/gtest
    sudo cmake .
    sudo make
    sudo cp lib/*.a /usr/lib
    ```

2.  **Compile and Run Tests:**
    Compile the test suite using the following command:
    ```sh
    g++ -std=c++17 src/*.cpp tests/*.cpp -Iinclude -lgtest -lgtest_main -pthread -o gtest.exe
    ```
    Execute the tests:
    ```sh
    ./gtest.exe
    ```
    
## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
