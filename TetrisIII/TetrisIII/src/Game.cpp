#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

// Default constructor
Game::Game(Board* board, BaseRenderer* baseRenderer) {
    _board = board;
    _baseRenderer = baseRenderer;
    _initializeGame();
    
}

// 
Game::Game(Board* board, BaseRenderer* baseRenderer, sf::RenderWindow* window) {
    this->window = window;

    _board = board;
    _baseRenderer = baseRenderer;
    _initializeGame();
}

// Initializes game loop
void Game::_initializeGame() {        
    sf::Clock clock;

    while (!_gameOver()) {                                      // Continue looping until top row has a tile
        if (clock.getElapsedTime().asMilliseconds() > _gameSpeed) {
            _board->Move(SOUTH);
            clock.restart();
        }
        
        _handleEvents();                                        // Handles window input
        _baseRenderer->DrawBoard(_board->_board);               // Outputs visualization
        _board->CheckForCompleteRows();                         // Finds and deletes complete rows
        
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    std::cout << "\t\GAME OVER!" << std::endl;
}

// Handles input
void Game::_handleEvents() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
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
                window->close();
                break;
            }
        }
    }
}

// Returns false if top row of board contains a permanent piece.
bool Game::_gameOver() {
    for (int i = 0; i < 10; i++)
    {
        if (_board->GetValueAt(0, i) < 0) {
            return true;
        }
    }
    return false;
}