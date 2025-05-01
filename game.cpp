#include "game.h"
#include <cstdlib>
#include <vector>
#include <iostream>

Game::Game(int rows, int cols)
    : rows(rows), cols(cols), grid(rows, std::vector<bool>(cols)), prevGrid(rows, std::vector<bool>(cols)) {}

void Game::initializeRandom() {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            grid[y][x] = std::rand() % 2;
        }
    }
    prevGrid = grid; // Initial grid is saved to prevGrid
}

int Game::countLiveNeighbors(int row, int col) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int ny = row + dy, nx = col + dx;
            if (ny >= 0 && ny < rows && nx >= 0 && nx < cols) {
                count += grid[ny][nx];
            }
        }
    }
    return count;
}

void Game::update() {
    std::vector<std::vector<bool>> newGrid = grid;

    // Perform the Game of Life rules
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            int neighbors = countLiveNeighbors(y, x);
            if (grid[y][x]) {
                newGrid[y][x] = (neighbors == 2 || neighbors == 3);  // Cell survives
            } else {
                newGrid[y][x] = (neighbors == 3);  // Cell is born
            }
        }
    }

    // Save the new grid as the current state
    grid = newGrid;

    // Track updated cells
    updatedCells.clear();
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (grid[y][x] != prevGrid[y][x]) {
                updatedCells.push_back({y, x});
            }
        }
    }

    // Update the previous grid
    prevGrid = grid;
}

bool Game::isAlive(int row, int col) const {
    return grid[row][col];
}

const std::vector<std::pair<int, int>>& Game::getUpdatedCells() const {
    return updatedCells;
}

void Game::clearUpdatedCells() {
    updatedCells.clear();
}

void Game::printGrid() const {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            std::cout << (isAlive(y, x) ? "⬜" : "⬛");
        }
        std::cout << '\n';
    }
}