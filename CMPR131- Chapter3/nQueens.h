#pragma once

#include <vector>

class NQueens {
public:
    NQueens();
    void initializeAndSolveInteractive();

private:
    bool isSafe(int row, int col);
    bool isOccupied(int row, int col);
    void printBoard();
    void solveInteractive();

    int size;
    std::vector<std::vector<int>> board;
};
