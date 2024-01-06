#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name, char symbol);
    ~Player();

    // Returns the player's name
    std::string getName() const;

    // Returns the player's symbol
    char getSymbol() const;

    // Prompts the player to make a move and returns the chosen cell as a pair of row and column
    std::pair<int, int> makeMove() const;

private:
    std::string name;
    char symbol;
};

#endif // PLAYER_H
