#include "TestGame.h"
#include <iostream>

int main() {
    TestGame::runTests();
    std::cout << "All Game tests passed!" << std::endl;
    return 0;
}

// TestGame.h
#ifndef TESTGAME_H
#define TESTGAME_H

#include "../Game.h"
#include <cassert>

class TestGame {
public:
    static void runTests() {
        testGameFlow();
        testSwitchPlayer();
        testGameOver();
    }

private:
    static void testGameFlow() {
        Game game;
        game.play();
        assert(game.isGameOver() && "Game should be over after a win or a tie");
    }

    static void testSwitchPlayer() {
        Game game;
        Player* initialPlayer = game.getCurrentPlayer();
        game.switchPlayer();
        assert(game.getCurrentPlayer() != initialPlayer && "Current player should switch after calling switchPlayer()");
    }

    static void testGameOver() {
        Game game;
        game.play();
        assert(game.isGameOver() && "Game should be over when all cells are marked or there's a winner");
    }
};

#endif // TESTGAME_H

// TestGame.cpp
#include "TestGame.h"

int main() {
    TestGame::runTests();
    std::cout << "All Game tests passed!" << std::endl;
    return 0;
}
