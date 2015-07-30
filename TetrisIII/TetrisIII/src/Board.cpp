#include "Board.h"
#include <iostream>
#include <random>
#include <time.h>

enum TileType{
    backgroundBlack,
    activePivotWhite,
    activeRed,
    activeBlue,
    activeGreen,
    activeYellow,
    activePurple,
    activeTeal,
    activeOrange
};

// Default constructor
Board::Board(Piece* piece) {
    srand(time(NULL));
    _piece = piece;
    _activePosition.resize(2);
    _activeColor = rand() % 7 + 2;
    _initializeBoard();
    _drawPieceAt(0, 0, 0, 4);
}

// Initializes all values of board array to 0.
void Board::_initializeBoard() {
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            _board[i][j] = TileType::backgroundBlack;
        }
    }
}

// Writes a piece to the board at a specific row and column.
void Board::_drawPieceAt(int piece, int rotation, int row, int col) {
    _activePiece = piece;
    _activeRotation = rotation;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int y = row + i - 2;
            int x = col + j - 2;

            if (y < 20 && y >= 0 && x < 10 && x >= 0) {

                if (_piece->matrix[piece][rotation][i][j] == 1) {
                    _board[y][x] = 1;
                }

                else if (_piece->matrix[piece][rotation][i][j] != TileType::backgroundBlack) {
                    _board[y][x] = _activeColor;
                }
            }
            
        }
    }
   
}

// Checks for collisions and handles displacing the piece on the board.
void Board::Move(Direction direction) {
    _storeCurrentPosition();
    _clearBoard();

    switch (direction) {
        case NORTH:
            //Rotate
            if (_canMove(NORTH)) {
                _activeRotation = (_activeRotation == 3) ? -1 : _activeRotation;
                _drawPieceAt(_activePiece, _activeRotation + 1, _activePosition[0], _activePosition[1]);
            }

            else {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1]);
            }
            break;

        case SOUTH:
            //Down
            if (_canMove(SOUTH)) {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0] + 1, _activePosition[1]);
            }

            else {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1]);
                _makePermanent();
                _checkAllRows();
                _getNextPiece();
            }
            break;

        case WEST:
            //Left 
            if (_canMove(WEST)) {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1] - 1);
            }

            else {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1]);
            }
            break;

        case EAST:
            //Right
            if (_canMove(EAST)) {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1] + 1);
            }

            else {
                _drawPieceAt(_activePiece, _activeRotation, _activePosition[0], _activePosition[1]);
            }
            break;

            
        default:
            break;
    }
}


void Board::_drawTile(int i, int j, int tileNum) {
    _board[i][j] = tileNum;
}

// Reinitializes all the values of the board to 0, except for persisting pieces (represented by 3's).
void Board::_clearBoard() {
     
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            if (_board[i][j] <= TileType::backgroundBlack) {
                _drawTile(i, j, _board[i][j]);
            }

            else {
                _drawTile(i, j, TileType::backgroundBlack);
            }
        }
    }
}

// Calls _hasCollided with parameters respective to keyboard input.
bool Board::_canMove(Direction direction) {
    int nextPotentialRotation = (_activeRotation == 3) ? 0 : _activeRotation + 1;

    switch (direction) {
        case NORTH:
            if (!_hasCollided(nextPotentialRotation, 0, 0, 0)) {
                return true;
            }
            break;

        case SOUTH:
            if (!_hasCollided(_activeRotation, 0, 0, 1)) {
                return true;
            }
            break;

        case WEST:
            if (!_hasCollided(_activeRotation, 0, -1, 0)) {
                return true;
            }
            break;

        case EAST:
            if (!_hasCollided(_activeRotation, 1, 0, 0)) {
                return true;
            }
            break;
    }
    
    return false;
}
 
// Checks for collision with board bounds or existing pieces (True: collision occurs || False: collision does not occur).
bool Board::_hasCollided(int rotation, int eastAdj, int westAdj, int southAdj) {
    int row = _activePosition[0];
    int col = _activePosition[1];
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (_piece->matrix[_activePiece][rotation][i][j] != TileType::backgroundBlack) {

                // Check for collision with board boundaries.
                if (i + row + southAdj > 21 || i + row < 0 || j + col + eastAdj > 11 || j + col + westAdj <= 1) {
                    return true;
                }

                else {
                    // Check for collision with existing pieces (negative values persist through clear board).
                    if (_board[i + row - 2 + southAdj][j + col - 2 + westAdj + eastAdj] < 0) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

// Scans game board for pivot piece (1) and calls SetPosition to store it.
void Board::_storeCurrentPosition() {
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            if (_board[i][j] == 1) {
                SetPosition(i , j);
            }
        }
    }
}

// Returns board value at row and column.
int Board::GetValueAt(int row, int col) {
    return _board[row][col];
}

// Stores pivot position's row and col in the _activePosition vector
void Board::SetPosition(int row, int col) {
    _activePosition[0] = row;
    _activePosition[1] = col;
}

// Returns the pivot positon of the piece represented by the value 2.
std::vector<int> Board::GetPosition() const {
    return _activePosition;
}

// Rewrites each piece's values as negative persisting values.
void Board::_makePermanent() {

    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            if (_board[i][j] > 0) {
                _board[i][j] = -_activeColor;
            }
        }
    }
}

// Randomly sets the parameters of the next piece.
void Board::_setNextPieceParameters() {
    _nextPiece = rand() % 7;
    _nextRotation = rand() % 4;
    _nextColor = rand() % 7 + 2;
}

// Implement function! //
void Board::PreviewNextPiece() {
    _setNextPieceParameters();
}

// Creates and draws a random piece of random orientation and sets _activePiece and _activeRotation
void Board::_getNextPiece() {
    _setNextPieceParameters();

    _activePiece = _nextPiece;
    _activeRotation = _nextRotation;
    _activeColor = _nextColor;

    _drawPieceAt(_nextPiece, _nextRotation, 0, 4);
}

// Calls _clearRow on rows not containing blank tiles (0).
bool Board::_checkForCompleteRows() {
    if (_getCompleteRow() >= 0) {
        return true;
    }
    return false;
}

void Board::_clearCompleteRows() {
    _clearRow(_getCompleteRow());
    player.Score += 100;
}

// Checks board for rows not containing a blank tile (0)
int Board::_getCompleteRow() {
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        int k = 0;

        for (int j = 0; j < BOARD_COLS; j++)
        {
            if (_board[i][j] == 0) {
                k++;
            }
        }
        if (k == 0) {
            return i;
        }
    }

    return -1;
}

// Clears row by overwriting it with the row above it, repeating until the top of the board.
void Board::_clearRow(int row) {
    for (int i = row; i > 1; i--)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            _board[i][j] = _board[i - 1][j];
        }
    }
}

void Board::_checkAllRows() {
    while (_checkForCompleteRows()) {
        _clearCompleteRows();
    }
}

void Board::DropTile() {
    while (_canMove(SOUTH)) {
        Move(SOUTH);
    }
}

int Board::GetLowestTile() {
    for (int i = _activePosition[0] + 1; i < BOARD_ROWS - 1; i++)
    {
        if (_board[i + 1][_activePosition[1]] < 0) {
            return i;
        }
    }
}















// Testing Function: Outputs pivot position respective to board.
void Board::_COUT_activePosition() {
    std::cout << "Position:\trow = " << _activePosition[0] << "\tcol = " << _activePosition[1] << std::endl;
}
