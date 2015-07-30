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
    sf::Text _level; 
    sf::Image imageH;
    sf::Image imageL;
    sf::Image imageR;
    sf::Image imageB;
    sf::Image imageBg;
    sf::Texture textureH;
    sf::Texture textureB;
    sf::Texture textureL;
    sf::Texture textureR;
    sf::Texture textureBg;
    sf::Sprite _header;
    sf::Sprite _leftHUD;
    sf::Sprite _rightHUD;
    sf::Sprite _footerHUD;
    sf::Sprite _background;

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
    void DrawScore(int score);
    void DrawLevel(int level);
};
