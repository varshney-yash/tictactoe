# TicTacToe Game in C++

This project is a simple implementation of the classic TicTacToe game using C++. It adheres to the principles of Object-Oriented Programming (OOP) and follows the SOLID principles to ensure a maintainable and scalable codebase. The game is played in the console and allows two players to compete against each other.

## Features

- Object-Oriented Design
- Adherence to SOLID principles
- Console-based user interface
- Two-player gameplay
- Automated tests for core components

## Prerequisites

To build and run this game, you will need:

- A C++ compiler (e.g., GCC, Clang)
- Make (for using the provided Makefile)

## Getting Started

To get started with the game, clone this repository to your local machine using the following command:

```
git clone https://github.com/your-username/tictactoe-cpp.git
```

Navigate to the project directory:

```
cd tictactoe-cpp
```

Build the project using the Makefile:

```
make all
```

Run the game:

```
./tictactoe
```

## Running Tests

To run the automated tests for the game components, execute the following command:

```
make test
```

## Project Structure

The project is structured as follows:

- `README.md`: This file, containing information about the project.
- `Game.h/cpp`: The Game class responsible for managing the game flow.
- `Board.h/cpp`: The Board class responsible for the game board state and display.
- `Player.h/cpp`: The Player class representing each player in the game.
- `main.cpp`: The entry point of the application.
- `tests/`: This directory contains all the test cases for the game components.
  - `TestBoard.h/cpp`: Tests for the Board class.
  - `TestPlayer.h/cpp`: Tests for the Player class.
  - `TestGame.h/cpp`: Tests for the Game class.
- `Makefile`: A Makefile to automate the build and test processes.

## Contributing

Contributions to this project are welcome. Please adhere to the project's coding standards and provide tests for any new features or bug fixes.

## License

This project is open-sourced under the MIT license. See the LICENSE file for more details.

## Acknowledgments

- Thanks to all the contributors who have helped to improve this project.
- Special thanks to the C++ community for providing valuable resources and support.

Enjoy playing TicTacToe!
