#include "BaseRenderer.h"
#include <SFML\Graphics.hpp>

class SFMLRenderer : public BaseRenderer {
private:
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 800;
    sf::Vector2f _boardPos;
    sf::Vector2f _headerPos;
    sf::Vector2f _tileSize;
    sf::RectangleShape _tile;
    sf::RectangleShape _getTileOfType(int parameter);
    static sf::Font _font;
    static sf::Text _header;

    void _createWindow();
    void _initializeTile();
    void _setTilePos(int x, int y);
    void _drawTile(int type);
    void _initializeHeader();
    void _initializeGUI();
    void _loadFont();

public:
    SFMLRenderer();
    sf::RenderWindow Window;

    sf::RenderWindow& GetWindow();
    void DrawBoard(int board[20][10]);
};
