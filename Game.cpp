#include "Game.h"
#include <iostream>

Game::Game() : player1('X'), player2('O'), currentPlayer(nullptr) {
    initializePlayers();
}

Game::~Game() {
    // Destructor, if needed for cleanup
}

void Game::play() {
    displayInstructions();
    while (!isGameOver()) {
        board.displayBoard();
        currentPlayer->makeMove(board);
        updateGameState();
        switchPlayer();
    }
    board.displayBoard();
    if (board.isWin()) {
        declareWinner();
    } else {
        declareTie();
    }
}

bool Game::isGameOver() const {
    return board.isWin() || board.isTie();
}

void Game::switchPlayer() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
    } else {
        currentPlayer = &player1;
    }
}

void Game::initializePlayers() {
    player1.setName("Player 1");
    player2.setName("Player 2");
    currentPlayer = &player1;
}

void Game::displayInstructions() const {
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "Player 1 is X and Player 2 is O." << std::endl;
    std::cout << "Take turns to place your mark on the board." << std::endl;
    std::cout << "The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner." << std::endl;
    std::cout << "When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie." << std::endl << std::endl;
}

void Game::updateGameState() {
}

void Game::declareWinner() const {
    std::cout << currentPlayer->getName() << " wins the game!" << std::endl;
}

void Game::declareTie() const {
    std::cout << "The game is a tie!" << std::endl;
}
