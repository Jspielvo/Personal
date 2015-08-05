#include "Board.h"
#include <SFML/Graphics.hpp>
#include "BaseRenderer.h"


class Game {
private:
    Board* _board;
    sf::RenderWindow* window;                            // Window used solely for accepting keyboard inputs.
    BaseRenderer* _baseRenderer;

    int _gameSpeed = 500;
    int _gameLevel = 0;

    void _initializeGame();                             // Initializes main game loop.
    void _handleEvents();                               // Handles keyboard inputs.
    bool _gameOver();                                   // Returns true if top row of board contains a permanent tile (represented by 3).
    void _increaseSpeed(int speed);
    void _increaseDifficulty();
    void _pauseGame(sf::Event event);

public:
    Game(Board* board, BaseRenderer* baseRenderer);
    Game(Board* board, BaseRenderer* baseRenderer, sf::RenderWindow* window);                                 // Default constructor.
};