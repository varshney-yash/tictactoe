#ifndef TESTGAME_H
#define TESTGAME_H

#include "../Game.h"
#include <gtest/gtest.h>

class TestGame : public ::testing::Test {
protected:
    Game game;

    TestGame() {
    }

    virtual ~TestGame() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};

// Test initialization of the game
TEST_F(TestGame, GameInitialization) {
    EXPECT_FALSE(game.isGameOver());
}

// Test switching players
TEST_F(TestGame, SwitchPlayer) {
    char initialSymbol = game.getCurrentPlayer()->getSymbol();
    game.switchPlayer();
    EXPECT_NE(initialSymbol, game.getCurrentPlayer()->getSymbol());
}

// Test game over conditions
TEST_F(TestGame, GameOverConditions) {
    game.getBoard().markCell(0, 0, 'X');
    game.getBoard().markCell(0, 1, 'X');
    game.getBoard().markCell(0, 2, 'X');
    game.updateGameState();
    EXPECT_TRUE(game.isGameOver());
}

// Test tie condition
TEST_F(TestGame, TieCondition) {
    game.getBoard().markCell(0, 0, 'X');
    game.getBoard().markCell(0, 1, 'O');
    game.getBoard().markCell(0, 2, 'X');
    game.getBoard().markCell(1, 0, 'X');
    game.getBoard().markCell(1, 1, 'X');
    game.getBoard().markCell(1, 2, 'O');
    game.getBoard().markCell(2, 0, 'O');
    game.getBoard().markCell(2, 1, 'X');
    game.getBoard().markCell(2, 2, 'O');
    game.updateGameState();
    EXPECT_TRUE(game.isTie());
}

#endif // TESTGAME_H
