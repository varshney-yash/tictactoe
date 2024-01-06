#include "Player.h"
#include <iostream>
#include <utility>

Player::Player(const std::string& name, char symbol) : name(name), symbol(symbol) {}

Player::~Player() {}

std::string Player::getName() const {
    return name;
}

char Player::getSymbol() const {
    return symbol;
}

std::pair<int, int> Player::makeMove() const {
    int row, col;
    std::cout << name << " (" << symbol << "), enter your move (row and column): ";
    std::cin >> row >> col;
    return std::make_pair(row, col);
}
