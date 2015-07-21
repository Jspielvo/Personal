#include "Board.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    Board* _board;
    sf::RenderWindow window;                            // Window used solely for accepting keyboard inputs.

    void _initializeGame();                             // Initializes main game loop.
    void _handleEvents();                               // Handles keyboard inputs.
    bool _gameOver();                                   // Returns true if top row of board contains a permanent tile (represented by 3).

public:
    Game(Board* board);                                 // Default constructor.
};