#include <iostream>
#include "SFMLRenderer.h"
#include <random>

sf::Font SFMLRenderer::_font;
sf::Text SFMLRenderer::_header;


SFMLRenderer::SFMLRenderer() {
    _createWindow();
    _initializeGUI();
    srand(time(NULL));
}

void SFMLRenderer::_createWindow() {
    Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris - by John Spielvogel");
}

void SFMLRenderer::_initializeGUI() {
    _boardPos.x = WINDOW_WIDTH * 0.5;
    _boardPos.y = WINDOW_HEIGHT * 0.5;

    _initializeHeader();
    _initializeTile();
}

sf::RenderWindow& SFMLRenderer::GetWindow() {
    sf::RenderWindow &tempWindow = Window;
    return tempWindow;
}
void SFMLRenderer::_drawTile(int type) {
    Window.draw(_getTileOfType(type));
}
void SFMLRenderer::DrawBoard(int board[20][10]) {
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            _setTilePos(_tileSize.y * (j - 5) , _tileSize.x * (i - 10));
            _drawTile(board[i][j]);
        }
        _setTilePos(_tileSize.y * i + _tileSize.y, 0);
    }
    Window.draw(_header);
    Window.display();
}

void SFMLRenderer::_loadFont() {
    if (!_font.loadFromFile("data/Stencil.ttf")) {
        std::cout << "Error opening font file." << std::endl;
        exit(1);
    }
}

void SFMLRenderer::_initializeHeader() {
   _loadFont();

    _header.setString("TETRIS");
    _header.setFont(_font);
    _header.setCharacterSize(50);
    _header.setColor(sf::Color::Green);
    _header.setOrigin(_header.getLocalBounds().width / 2, _header.getLocalBounds().height / 2);
    _headerPos.x = WINDOW_WIDTH / 2;
    _headerPos.y = _boardPos.y * 0.125 + -_header.getLocalBounds().height / 2;
    _header.setPosition(_headerPos);
    
}

sf::RectangleShape SFMLRenderer::_getTileOfType(int parameter) {
    switch (parameter) {

        case 0:
            // Empty Black
            _tile.setFillColor(sf::Color::Black);
            break;

        case -1:
        case 1:
            // Pivot Grey
            _tile.setFillColor(sf::Color::Color(155, 155, 155));
            break;

        case -2:
        case 2:
            _tile.setFillColor(sf::Color::Red);
            break;

        case -3:
        case 3:
            _tile.setFillColor(sf::Color::Blue);
            break;

        case -4:
        case 4:
            // Green
            _tile.setFillColor(sf::Color::Color(53, 168, 49));
            break;

        case -5:
        case 5:
            // Yellow
            _tile.setFillColor(sf::Color::Color(209, 214, 51));
            break;

        case -6:
        case 6:
            // Light blue
            _tile.setFillColor(sf::Color::Color(41, 128, 185));
            break;

        case -7:
        case 7:
            // Purple
            _tile.setFillColor(sf::Color::Color(103, 10, 173));
            break;

        case -8:
        case 8:
            // Orange
            _tile.setFillColor(sf::Color::Color(214, 91, 43));
            break;

        default:
            _tile.setFillColor(sf::Color::Black);
            break;
    }

    return _tile;
}

void SFMLRenderer::_initializeTile() {
    _tileSize.x = WINDOW_WIDTH * 0.0375;
    _tileSize.y = WINDOW_HEIGHT * 0.0375;
   
    //_tileSize.x = 30;
    //_tileSize.y = 30;


    _tile.setFillColor(sf::Color::Transparent);
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness((double)0.6);
    _tile.setSize(_tileSize);
    _tile.setPosition(_boardPos);
}

void SFMLRenderer::_setTilePos(int x, int y) {
    _tile.setPosition(x + _boardPos.x, y + _boardPos.y);
}