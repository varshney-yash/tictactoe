#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include "../Player.h"
#include <cassert>
#include <utility>

class TestPlayer {
public:
    static void runTests() {
        testConstructor();
        testGetName();
        testGetSymbol();
    }

private:
    static void testConstructor() {
        Player player("Alice", 'X');
        assert(player.getName() == "Alice");
        assert(player.getSymbol() == 'X');
    }

    static void testGetName() {
        Player player("Bob", 'O');
        assert(player.getName() == "Bob");
    }

    static void testGetSymbol() {
        Player player("Charlie", 'X');
        assert(player.getSymbol() == 'X');
    }

};

#endif // TESTPLAYER_H
