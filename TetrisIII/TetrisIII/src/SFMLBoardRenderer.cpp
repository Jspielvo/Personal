#include <iostream>
#include "SFMLRenderer.h"
#include <random>

sf::Font SFMLRenderer::_font;
sf::Text SFMLRenderer::_headerText;


SFMLRenderer::SFMLRenderer() {
    _createWindow();
    _initializeGUI();
    srand(time(NULL));
}

void SFMLRenderer::_createWindow() {
    Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris - by John Spielvogel", sf::Style::Titlebar | sf::Style::Close);
}

void SFMLRenderer::_initializeGUI() {
    _boardPos.x = WINDOW_WIDTH * 0.5;
    _boardPos.y = WINDOW_HEIGHT * 0.5;

    _initializeBackground();
    _initializeHeader();
    _initializeFooter();
    _initializeLeftHUD();
    _initializeRightHUD();
    _initializeTile();
}

sf::RenderWindow& SFMLRenderer::GetWindow() {
    sf::RenderWindow &tempWindow = Window;
    return tempWindow;
}

void SFMLRenderer::_drawTile(int type) {
    Window.draw(_getTileOfType(type));
}

void SFMLRenderer::RenderGUI(int board[20][10], int lowPos) {
    Window.draw(_background);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            _setTilePos(_tileSize.y * (j - 5) , _tileSize.x * (i - 10));
            _drawTile(board[i][j]);
        }
        _setTilePos(_tileSize.y * i + _tileSize.y, 0);
    }

    _drawGUI();
    Window.display();
}

void SFMLRenderer::_drawGUI() {
    Window.draw(_score);
    Window.draw(_level);
    Window.draw(_headerText);
    //Window.draw(_header);
    //Window.draw(_footerHUD);
    //Window.draw(_leftHUD);
    //Window.draw(_rightHUD);
}

void SFMLRenderer::DrawScore(int score) {
    _score.setFont(_font);
    _score.setString(std::to_string(score));
    _score.setCharacterSize(30);
    _score.setColor(sf::Color::White);

    _drawLeadingZeroes(score);

    _score.setOrigin(_score.getLocalBounds().width / 2, _score.getLocalBounds().height / 2);
    _score.setPosition(WINDOW_WIDTH * 0.15, WINDOW_HEIGHT * 0.2875);

}

void SFMLRenderer::DrawLevel(int level) {
    _level.setFont(_font);
    _level.setString(std::to_string(level));
    _level.setCharacterSize(30);
    _level.setColor(sf::Color::White);
    _level.setOrigin(_level.getLocalBounds().width / 2, _level.getLocalBounds().height / 2);
    _level.setPosition(WINDOW_WIDTH * 0.2225, WINDOW_HEIGHT * 0.190);
}

void SFMLRenderer::_drawLeadingZeroes(int score) {
    if (_getLengthOfInt(score, 10) == 3) {
        _score.setString("00000" + std::to_string(score));
    }
    else if (_getLengthOfInt(score, 10) == 4) {
        _score.setString("0000" + std::to_string(score));
    }
    else if (_getLengthOfInt(score, 10) == 5) {
        _score.setString("0000" + std::to_string(score));
    }
    else if (_getLengthOfInt(score, 10) == 6) {
        _score.setString("000" + std::to_string(score));
    }
    else if (_getLengthOfInt(score, 10) == 7) {
        _score.setString("00" + std::to_string(score));
    }
    else if (_getLengthOfInt(score, 10) == 8) {
        _score.setString("0" + std::to_string(score));
    }
    else {
        _score.setString("00000000");
    }
}

int SFMLRenderer::_getLengthOfInt(int value, int base) {
    int numberOfDigits = 0;

    do {
        numberOfDigits++;
        value /= base;
    } while (value);

    return numberOfDigits;
}

void SFMLRenderer::_loadFont() {
    if (!_font.loadFromFile("data/Bauhs93.ttf")) {
        std::cout << "Error opening font file." << std::endl;
        exit(1);
    }
}


void SFMLRenderer::_initializeHeader() {
   _loadFont();

   if (!imageH.loadFromFile("data/header.png")) {
       std::cout << "Error loading header.png" << std::endl;
       exit(1);
   }

   textureH.loadFromImage(imageH);
   _header.setTexture(textureH);
   _header.setPosition(249, 0);

    _headerText.setString("TETRIS");
    _headerText.Bold;
    _headerText.setFont(_font);
    _headerText.setCharacterSize(50);
    _headerText.setColor(sf::Color::White);
    _headerText.setOrigin(_headerText.getLocalBounds().width / 2, _headerText.getLocalBounds().height / 2);
    _headerTextPos.x = WINDOW_WIDTH / 2;
    _headerTextPos.y = _boardPos.y * 0.125 + -_headerText.getLocalBounds().height / 2;
    _headerText.setPosition(_headerTextPos);
    
}


void SFMLRenderer::_initializeFooter() {
    if (!imageB.loadFromFile("data/footerHUD.png")) {
        std::cout << "Error loading footerHUD.png" << std::endl;
        exit(1);
    }
    
    textureB.loadFromImage(imageB);
    _footerHUD.setTexture(textureB);
    _footerHUD.setPosition(249, 700);
}

void SFMLRenderer::_initializeBackground() {
    if (!imageBg.loadFromFile("data/bg.png")) {
        std::cout << "Error loading bg.png." << std::endl;
        exit(1);
    }
    textureBg.loadFromImage(imageBg);
    _background.setTexture(textureBg);
}

void SFMLRenderer::_initializeLeftHUD() {
    
    if (!imageL.loadFromFile("data/leftHUD.png")) {
        std::cout << "Error loading leftHUD.png." << std::endl;
        exit(1);
    }
    textureL.loadFromImage(imageL);    
    _leftHUD.setTexture(textureL);
    
}

void SFMLRenderer::_initializeRightHUD() {
    if (!imageR.loadFromFile("data/rightHUD.png")) {
        std::cout << "Error loading rightHUD.png." << std::endl;
        exit(1);
    }

    textureR.loadFromImage(imageR);
    _rightHUD.setTexture(textureR);
    _rightHUD.setPosition(550, 0);
}

void SFMLRenderer::_initializeTile() {
    _tileSize.x = WINDOW_WIDTH * 0.0375;
    _tileSize.y = WINDOW_HEIGHT * 0.0375;

    _tile.setFillColor(sf::Color::Transparent);
    _tile.setOutlineColor(sf::Color::Color(255, 255, 255, 100));
    _tile.setOutlineThickness((double)0.51);
    _tile.setSize(_tileSize);
    _tile.setPosition(_boardPos);
}

void SFMLRenderer::_setTilePos(int x, int y) {
    _tile.setPosition(x + _boardPos.x, y + _boardPos.y);
}

sf::RectangleShape SFMLRenderer::_getTileOfType(int parameter) {
    switch (parameter) {

        case 0:
            // Empty Black
            _tile.setFillColor(sf::Color::Color(0,0,0,100));
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

