#include "Render.h"
#include "Board.h"

Render::Render(Board* board) {
    _board = board;
    _createWindow();
    _initializeTile();
}

void Render::_createWindow() {
    Window.create(sf::VideoMode(300, 500), "Tetris - by John Spielvogel");
}

void Render::DrawBoard() {
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 20; j++)
        {
            _setPixelPos(20 * i + 20, 20 * j + 20);
            if (_board->boardSpace[i][j] == 0) {
                Window.draw(_getTileOfType(0));
            }
            else if (_board->boardSpace[i][j] == 1) {
                Window.draw(_getTileOfType(1));
            }
            else if (_board->boardSpace[i][j] == 2) {
                Window.draw(_getTileOfType(2));
            }
            else if (_board->boardSpace[i][j] == 3) {
                Window.draw(_getTileOfType(3));
            }
            else {
                Window.draw(_getTileOfType(0));
            }
        }
        _setPixelPos(20 * i + 20, 20);
    }
}

sf::RectangleShape Render::_getTileOfType(int parameter) {
    switch (parameter) {
    case 1:
        _tile.setFillColor(sf::Color::Green);
        break;
    case 2:
        _tile.setFillColor(sf::Color::Red);
        break;
    case 3:
        _tile.setFillColor(sf::Color::Blue);
        break;
    default:
        _tile.setFillColor(sf::Color::Transparent);
        break;
    }

    return _tile;
}

void Render::_initializeTile() {
    _tileSize.x = 20;
    _tileSize.y = 20;
    _pixelPos.x = 0;
    _pixelPos.y = 0;

    _tile.setFillColor(sf::Color::Transparent);
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness((double)0.55);
    _tile.setSize(_tileSize);
    _tile.setPosition(_pixelPos);
}

void Render::_setPixelPos(int x, int y) {
    _pixelPos.x = (float)x;
    _pixelPos.y = (float)y;

    _tile.setPosition(_pixelPos);
}