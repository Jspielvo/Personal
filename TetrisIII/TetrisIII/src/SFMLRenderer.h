#include "BaseRenderer.h"
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
    sf::Text _score;
    sf::RectangleShape _header;
    sf::Image imageL;
    sf::Image imageR;
    sf::Texture textureL;
    sf::Texture textureR;
    sf::Sprite _leftHUD;
    sf::Sprite _rightHUD;
    sf::RectangleShape _footer;

    void _createWindow();
    void _initializeTile();
    void _setTilePos(int x, int y);
    void _drawTile(int type);
    void _initializeHeader();
    void _initializeFooter();
    void _initializeLeftHUD();
    void _initializeRightHUD();
    void _initializeGUI();
    void _loadFont(); 

public:
    SFMLRenderer();
    sf::RenderWindow Window;

    sf::RenderWindow& GetWindow();
    void DrawBoard(int board[20][10], int lowPos);
    void DrawScore(int score);
};
