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
        _baseRenderer->RenderGUI(_board->_board, _board->GetLowestTile());                       // Outputs visualization
        _baseRenderer->DrawScore(_board->player.Score, 120, 230);
        _baseRenderer->DrawLevel(_gameLevel, 178, 152);
        _baseRenderer->DrawNextPiece(_board->_nextPieceMatrix, 213, -265);
        _baseRenderer->DrawHoldPiece(_board->_holdPieceMatrix, 213, -81);

        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    _board->GameOverFillBoard();
    _baseRenderer->RenderGUI(_board->_board, _board->GetLowestTile());
    _baseRenderer->DrawGameOver(400, 400);
    window->display();


    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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
            if (event.key.code == sf::Keyboard::Key::Pause) {
                _pauseGame(event);
            }
            if (event.key.code == sf::Keyboard::RControl || event.key.code == sf::Keyboard::LControl) {
                if (_board->IsHoldingPiece()) {
                    _board->SetNextPieceToHold();
                }
                else {
                    _board->HoldPiece();
                }
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
    int score = _board->player.Score;
    
    _gameLevel = score / 500;
    _gameSpeed = 500 - _gameLevel * 50;
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

void Game::_pauseGame(sf::Event event) {
    while (event.key.code == sf::Keyboard::Key::Pause) {
            std::this_thread::sleep_for(std::chrono::microseconds(1));
            window->pollEvent(event);
    }
}