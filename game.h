#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>

class Game {
public:
    Game(int rows, int cols);
    void initializeRandom();
    void update();
    bool isAlive(int row, int col) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    const std::vector<std::pair<int, int>>& getUpdatedCells() const;
    void clearUpdatedCells();
    void printGrid() const;

private:
    int rows, cols;
    std::vector<std::vector<bool>> grid;
    std::vector<std::pair<int, int>> updatedCells;
    std::vector<std::vector<bool>> prevGrid;  // Track previous grid for comparison

    int countLiveNeighbors(int row, int col) const;
};

#endif