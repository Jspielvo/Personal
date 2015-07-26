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

    while (!_gameOver()) {                                                                       // Continue looping until top row has a tile
        window->clear();

        if (clock.getElapsedTime().asMilliseconds() > _gameSpeed) {
            _board->Move(SOUTH);
            clock.restart();
        }
        
        _handleEvents();                                                                         // Handles window input
        _increaseDifficulty();
        _baseRenderer->DrawBoard(_board->_board, _board->GetLowestTile());                       // Outputs visualization
        _baseRenderer->DrawScore(_board->player.Score);

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
            exit(0);
            break;
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Up) {
                _board->Move(NORTH);
            }
            if (event.key.code == sf::Keyboard::Key::Space) {
                _board->DropTile();
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        _board->Move(SOUTH);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        _board->Move(WEST);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        _board->Move(EAST);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        window->close();
        exit(0);
    }  
}

void Game::_increaseDifficulty() {
    if (_board->player.Score % 400 == 1) {
        _increaseSpeed(_gameSpeed - 50);
        _gameLevel++;
        std::cout << _gameLevel << std::endl;
    }
}

void Game::_increaseSpeed(int speed) {
    _gameSpeed = speed;
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