#include "Board.h"
#include <iostream>

Board::Board() {
    reset();
}

Board::~Board() {
    // Destructor, if needed for cleanup
}

void Board::reset() {
    for (auto &row : grid) {
        row.fill(' ');
    }
}

bool Board::markCell(int row, int col, char symbol) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false; // Out of bounds
    }
    if (grid[row][col] != ' ') {
        return false; // Cell already taken
    }
    grid[row][col] = symbol;
    return true;
}

bool Board::hasWinner() const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((grid[i][0] != ' ' && checkLine(grid[i][0], i, 0, 0, 1)) ||
            (grid[0][i] != ' ' && checkLine(grid[0][i], 0, i, 1, 0))) {
            return true;
        }
    }
    // Check diagonals
    return (grid[1][1] != ' ' &&
           (checkLine(grid[1][1], 0, 0, 1, 1) || checkLine(grid[1][1], 0, 2, 1, -1)));
}

bool Board::isTie() const {
    for (const auto &row : grid) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there's an empty cell, it's not a tie
            }
        }
    }
    return !hasWinner(); // It's a tie if there's no winner
}

void Board::display() const {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << ' ';
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j];
            if (j < 2) std::cout << '|';
        }
        std::cout << '\n';
        if (i < 2) std::cout << "  -----\n";
    }
}

char Board::getCell(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return '\0'; // Out of bounds
    }
    return grid[row][col];
}

bool Board::checkLine(char symbol, int startRow, int startCol, int deltaRow, int deltaCol) const {
    for (int i = 0; i < 3; ++i) {
        if (grid[startRow + i * deltaRow][startCol + i * deltaCol] != symbol) {
            return false;
        }
    }
    return true;
}
