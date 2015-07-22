#include "BaseRenderer.h"
#include <SFML\Graphics.hpp>

class SFMLRenderer : public BaseRenderer {
private:
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
    SFMLRenderer();
    sf::RenderWindow Window;

    sf::RenderWindow& GetWindow();
    void DrawBoard(int board[20][10]);
};
