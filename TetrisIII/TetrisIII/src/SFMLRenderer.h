#include "BaseRenderer.h"
#include "RenderObject.h"
#include <SFML\Graphics.hpp>

class SFMLRenderer : public BaseRenderer {
private:
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 800;
    sf::Vector2f _boardPos;
    sf::Vector2f _headerTextPos;
    sf::Vector2f _tileSize;
    sf::RectangleShape _tile;
    sf::RectangleShape _previewTile;
    sf::RectangleShape _getTileOfType(int parameter);
    static sf::Font _font;
    static sf::Text _headerText;
    sf::Text _gameOver;
    sf::Text _score;
    sf::Text _level; 
    sf::Image imageH;
    sf::Image imageL;
    sf::Image imageR;
    sf::Image imageB;
    sf::Texture textureH;
    sf::Texture textureB;
    sf::Texture textureL;
    sf::Texture textureR;
    sf::Sprite _header;
    //sf::Sprite _leftHUD;
    //sf::Sprite _rightHUD;
    //sf::Sprite _footerHUD;

    RenderObject _background;

    void _createWindow();
    void _initializeTile();
    void _setTilePos(int x, int y);
    void _drawTile(int type);
    void _initializeBackground();
    void _initializeHeader();
    void _initializeFooter();
    void _initializeLeftHUD();
    void _initializeRightHUD();
    void _initializeGUI();
    void _drawGUI();
    void _loadFont(); 
    void _drawLeadingZeroes(int score);
    int _getLengthOfInt(int value, int base);

public:
    SFMLRenderer();
    sf::RenderWindow Window;

    sf::RenderWindow& GetWindow();
    void RenderGUI(int board[20][10], int lowPos);
    void DrawHoldPiece(int holdPiece[5][5], int x, int y);
    void DrawNextPiece(int nextPiece[5][5], int x, int y);
    void DrawScore(int score, int x, int y);
    void DrawLevel(int level, int x, int y);
    void DrawGameOver(int x, int y);
    void DrawStartMenu();
    void DrawInGameMenu(int x, int y);
    void DrawClearRowAnimation(int level, int x, int y);
};
