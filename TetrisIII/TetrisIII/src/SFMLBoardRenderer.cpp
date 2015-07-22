#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer() {
    _createWindow();
    _initializeTile();
}

void SFMLRenderer::_createWindow() {
    Window.create(sf::VideoMode(300, 500), "Tetris - by John Spielvogel");
}

sf::RenderWindow& SFMLRenderer::GetWindow() {
    sf::RenderWindow &tempWindow = Window;
    return tempWindow;
}

void SFMLRenderer::DrawBoard(int board[20][10]) {
    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            _setPixelPos(20 * j + 20, 20 * i + 20);
            if (board[i][j] == 0) {
                Window.draw(_getTileOfType(0));
            }
            else if (board[i][j] == 1) {
                Window.draw(_getTileOfType(1));
            }
            else if (board[i][j] == 2) {
                Window.draw(_getTileOfType(2));
            }
            else if (board[i][j] == 3) {
                Window.draw(_getTileOfType(3));
            }
            else {
                Window.draw(_getTileOfType(0));
            }
        }
        _setPixelPos(20 * i + 20, 20);
    }
    //Window.display();
}

sf::RectangleShape SFMLRenderer::_getTileOfType(int parameter) {
    switch (parameter) {
    case 0:
        _tile.setFillColor(sf::Color::Black);
        break;
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

void SFMLRenderer::_initializeTile() {
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

void SFMLRenderer::_setPixelPos(int x, int y) {
    _pixelPos.x = (float)x;
    _pixelPos.y = (float)y;

    _tile.setPosition(_pixelPos);
}