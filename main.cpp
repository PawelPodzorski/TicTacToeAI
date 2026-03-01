#include <iostream>
#include <cmath>
#include "tictactoe/game.h"

int main() {
    playTTTGame();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard leftover input
    std::cout << "Press Enter to exit...";
    std::cin.get(); // Wait for user input before exiting
    return 0;
}