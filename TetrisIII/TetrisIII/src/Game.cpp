#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Default constructor
Game::Game(Board* board) {
    _board = board;
    _initializeGame();
    
}

// Initializes game loop
void Game::_initializeGame() {                                               
    window.create(sf::VideoMode(0, 0), "Input");                // Window solely for input handling                     

    while (!_gameOver()) {                                      // Continue looping until top row has a tile
        sf::Clock clock;                                        // Clock to control framerate
        int start = clock.getElapsedTime().asMilliseconds();    // Start timer
        
        system("cls");                                          // Clears console window
        _handleEvents();                                        // Handles window input
        
        _board->DrawBoard();                                    // Outputs 0's, 1's, 2's, and 3's to console
        _board->CheckForCompleteRows();                         // Finds and deletes complete rows

        int end = clock.getElapsedTime().asMilliseconds();      // End timer
        while (end - start < 300) {                             // Controls loop speed
            end = clock.getElapsedTime().asMilliseconds();
        }
    }

    std::cout << "\t\GAME OVER!" << std::endl;
}

// Handles input
void Game::_handleEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Up:
                _board->Move(NORTH);
                break;

            case sf::Keyboard::Down:
                _board->Move(SOUTH);
                break;

            case sf::Keyboard::Left:
                _board->Move(WEST);
                break;

            case sf::Keyboard::Right:
                _board->Move(EAST);
                break;

            case sf::Keyboard::Escape:
                window.close();
                break;
            }
        }
    }

    _board->Move(SOUTH);
}

// Returns false if top row of board contains a permanent piece.
bool Game::_gameOver() {
    for (int i = 0; i < 10; i++)
    {
        if (_board->GetValueAt(0, i) == 3) {
            return true;
        }
    }
    return false;
}