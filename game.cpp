#include "game.h"
#include <cstdlib>

GameOfLife::GameOfLife(int rows, int cols)
    : rows(rows), cols(cols), grid(rows, std::vector<bool>(cols)) {}

void GameOfLife::initializeRandom() {
    for (int y = 0; y < rows; ++y)
        for (int x = 0; x < cols; ++x)
            grid[y][x] = std::rand() % 2;
}

int GameOfLife::countLiveNeighbors(int row, int col) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int ny = row + dy, nx = col + dx;
            if (ny >= 0 && ny < rows && nx >= 0 && nx < cols)
                count += grid[ny][nx];
        }
    }
    return count;
}

void GameOfLife::update() {
    std::vector<std::vector<bool>> newGrid = grid;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            int neighbors = countLiveNeighbors(y, x);
            if (grid[y][x])
                newGrid[y][x] = (neighbors == 2 || neighbors == 3);
            else
                newGrid[y][x] = (neighbors == 3);
        }
    }
    grid = newGrid;
}

bool GameOfLife::isAlive(int row, int col) const {
    return grid[row][col];
}