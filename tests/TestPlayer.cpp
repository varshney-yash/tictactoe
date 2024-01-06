#include "TestPlayer.h"

void TestPlayer::runTests() {
    testConstructor();
    testGetName();
    testGetSymbol();
}

void TestPlayer::testConstructor() {
    Player player("Alice", 'X');
    assert(player.getName() == "Alice");
    assert(player.getSymbol() == 'X');
}

void TestPlayer::testGetName() {
    Player player("Bob", 'O');
    assert(player.getName() == "Bob");
}

void TestPlayer::testGetSymbol() {
    Player player("Charlie", 'X');
    assert(player.getSymbol() == 'X');
}


int main() {
    TestPlayer::runTests();
    return 0;
}
