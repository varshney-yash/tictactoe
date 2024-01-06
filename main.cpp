#include "Game.h"
#include <iostream>

int main() {
    try {
        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

        Game game;

        game.displayInstructions();

        game.play();

    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown exception occurred." << std::endl;
        return 2;
    }

    return 0;
}
