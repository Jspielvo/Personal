#include <SFML/Graphics.hpp>
#include "Board.h"
#pragma once

class Render {
private:
    Board* _board;

    const static int WINDOW_WIDTH = 400;
    const static int WINDOW_HEIGHT = 200;

    void _createWindow();
    void _initializeTile();
    void _setPixelPos(int x, int y);
    sf::RectangleShape _tile;
    sf::RectangleShape _getTileOfType(int parameter);
    sf::Vector2f _pixelPos;
    sf::Vector2f _tileSize;

public:
    Render(Board* board);
    sf::RenderWindow Window;
    void DrawBoard();
};