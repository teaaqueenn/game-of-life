#include "game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

const int ROWS = 26;
const int COLS = 50;
const int STEPS = 100;
const int DELAY_MS = 150;

void moveCursorToTop() {
    std::cout << "\033[H";  // ANSI escape code
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::system("chcp 65001 > nul");

    Game game(ROWS, COLS);
    game.initializeRandom();

    for (int step = 0; step <= STEPS; ++step) {
        moveCursorToTop();
        std::cout << "Step: " << step << "\n\n";

        // Update the game
        game.update();

        // If there are updated cells, print the grid
        const auto& updatedCells = game.getUpdatedCells();
        if (!updatedCells.empty()) {
            game.printGrid();
            game.clearUpdatedCells();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));
    }

    return 0;
}