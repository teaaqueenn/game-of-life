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

private:
    int rows, cols;
    std::vector<std::vector<bool>> grid;

    int countLiveNeighbors(int row, int col) const;
};

#endif