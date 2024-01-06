#ifndef TESTBOARD_H
#define TESTBOARD_H

#include "../Board.h"
#include <cassert>

class TestBoard {
public:
    static void runTests() {
        testReset();
        testMarkCell();
        testHasWinner();
        testIsTie();
        testGetCell();
    }

private:
    static void testReset() {
        Board board;
        board.markCell(0, 0, 'X');
        board.reset();
        assert(board.getCell(0, 0) == ' ');
        assert(board.getCell(1, 1) == ' ');
        assert(board.getCell(2, 2) == ' ');
    }

    static void testMarkCell() {
        Board board;
        assert(board.markCell(0, 0, 'X') == true);
        assert(board.markCell(0, 0, 'O') == false); // Already taken
        assert(board.markCell(3, 3, 'X') == false); // Out of bounds
    }

    static void testHasWinner() {
        Board board;
        board.markCell(0, 0, 'X');
        board.markCell(0, 1, 'X');
        board.markCell(0, 2, 'X');
        assert(board.hasWinner() == true);

        board.reset();
        board.markCell(0, 0, 'O');
        board.markCell(1, 1, 'O');
        board.markCell(2, 2, 'O');
        assert(board.hasWinner() == true);
    }

    static void testIsTie() {
        Board board;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board.markCell(i, j, (i + j) % 2 == 0 ? 'X' : 'O');
            }
        }
        assert(board.isTie() == true);
        board.reset();
        assert(board.isTie() == false);
    }

    static void testGetCell() {
        Board board;
        board.markCell(0, 0, 'X');
        assert(board.getCell(0, 0) == 'X');
        assert(board.getCell(3, 3) == '\0'); // Out of bounds
    }
};

#endif // TESTBOARD_H
