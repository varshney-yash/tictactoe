#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();

    void play();
    bool isGameOver() const;
    void switchPlayer();

private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;

    void initializePlayers();
    void displayInstructions() const;
    void updateGameState();
    void declareWinner() const;
    void declareTie() const;
};

#endif // GAME_H
