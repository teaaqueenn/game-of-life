#include "game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

const int ROWS = 26;
const int COLS = 50;
const int STEPS = 100;
const int DELAY_MS = 150;

void printGrid(const Game & game) {
    for (int y = 0; y < game.getRows(); ++y) {
        for (int x = 0; x < game.getCols(); ++x) {
            std::cout << (game.isAlive(y, x) ? "⬜" : "⬛");
        }
        std::cout << '\n';
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::system("chcp 65001 > nul"); 

    Game game(ROWS, COLS);
    game.initializeRandom();

    for (int step = 0; step < STEPS; ++step) {
        system("cls");  // use "cls" on Windows
        std::cout << "Step: " << step << "\n\n";
        printGrid(game);
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));
    }

    return 0;
}