#include "Board.h"
#include <SFML/Graphics.hpp>
#include "BaseRenderer.h"
#include <fstream>
#include <vector>

class Game {
private:
    Board* _board;
    sf::RenderWindow* window;                            // Window used solely for accepting keyboard inputs.
    BaseRenderer* _baseRenderer;

    int _gameSpeed = 500;
    int _gameLevel = 0;

    const std::string DATA_IN_FILE_PATH = "data/scoreHistory/dataIn.txt";
    const std::string DATA_OUT_FILE_PATH = "data/scoreHistory/dataOut.txt";

    std::ifstream dataIn;
    std::ofstream dataOut;

    std::vector<Player> dataEntries;

    void _initializeStreams();
    void _addEntryToDataFile();
    void _getEntryFromDataFile();
    void _sortDataEntries();
    void _writeDataEntries();
    void _swapEntries(int i, int j);
    void _closeStream(std::fstream file);
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