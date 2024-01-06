CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g
LDFLAGS := 
BUILD_DIR := ./build
SRC_DIR := ./tests
TESTS := $(BUILD_DIR)/TestBoard.o $(BUILD_DIR)/TestPlayer.o $(BUILD_DIR)/TestGame.o

.PHONY: all clean test

all: $(BUILD_DIR)/tictactoe

$(BUILD_DIR)/tictactoe: $(BUILD_DIR)/main.o $(BUILD_DIR)/Game.o $(BUILD_DIR)/Board.o $(BUILD_DIR)/Player.o
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TESTS)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/test $^
	$(BUILD_DIR)/test

$(BUILD_DIR)/TestBoard.o: $(SRC_DIR)/TestBoard.cpp $(SRC_DIR)/TestBoard.h
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(BUILD_DIR)/TestPlayer.o: $(SRC_DIR)/TestPlayer.cpp $(SRC_DIR)/TestPlayer.h
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(BUILD_DIR)/TestGame.o: $(SRC_DIR)/TestGame.cpp $(SRC_DIR)/TestGame.h
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/tictactoe $(BUILD_DIR)/test
