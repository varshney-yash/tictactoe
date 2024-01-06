#ifndef BOARD_H
#define BOARD_H

#include <array>

class Board {
public:
    Board();
    ~Board();

    void reset();

    bool markCell(int row, int col, char symbol);

    bool hasWinner() const;

    bool isTie() const;

    void display() const;

    char getCell(int row, int col) const;

private:
    std::array<std::array<char, 3>, 3> grid;

    bool checkLine(char symbol, int startRow, int startCol, int deltaRow, int deltaCol) const;
};

#endif // BOARD_H
