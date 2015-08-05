#pragma once
#include "Player.h"
#include "Direction.h"
#include "Piece.h"
#include <vector>
#include "BaseRenderer.h"

class Board {
public:
    const static int BOARD_COLS = 10;                                                         // Board dimension.
    const static int BOARD_ROWS = 20;                                                         // Board dimension.

    int _board[BOARD_ROWS][BOARD_COLS];                                                       // 20 x 10 game board.
    int _nextPieceMatrix[5][5];
    int _holdPieceMatrix[5][5];
    
    Player player;
    Board(Piece* piece);                                                                      // Default constructor.
    int GetNextPiece();
    void Move(Direction direction);                                                           // Moves active piece by one tile in chosen direction.
    void DropTile();
    void HoldPiece();
    void SetNextPieceToHold();
    bool IsHoldingPiece();
    void GameOverFillBoard();
    int GetValueAt(int row, int col);                                                         // Returns board[row][col] value.
    void SetPosition(int row, int col);                                                       // Sets pivot position respective to board ( _activePosition[0] = row and _activePosition[1] = col ).
    std::vector<int> GetPosition() const;                                                     // Returns pivot position respective to board.
    int GetLowestTile();
    
    void _COUT_activePosition();                                                              // Test: Outputs current _activePosition vector values to console window.

private:   
    Piece* _piece;
    std::vector<int> _activePosition;                                                         // activePiece's pivot positon respective to game board.
    int _activePiece;                                                                         // Current active Piece reference value.        
    int _activeRotation;                                                                      // activePiece's current rotation reference value.
    int _activeColor;
    int _previewPiece;
    int _nextPiece;
    int _nextRotation;
    int _nextColor;
    int _holdPiece;
    int _holdRotation;
    int _holdColor;

    void _initializeBoard();                                                                  // initializes _board array members to 0.
    void _clearBoard();                                                                       // Board values get reinitialized to 0 unless they are 3's (permanent persisting value).
    bool _canMove(Direction direction);                                                       // Calls _hasCollided respective to input
    bool _hasCollided(int rotation, int eastAdj, int westAdj, int southAdj);                  // Collision detection (Checks bounds of board + surrounding tiles).
    void _drawPieceOnBoardAt(int piece, int rotation, int row, int col);                             // Adds full piece to board at row and col in a specific rotation.
    void _storeCurrentPosition();                                                             // Stores pivot position respective to game board.
    void _makePermanent();                                                                    // Converts values on board (1's and 2's) to 3's in order to make these tiles persistent throughout the game.
    void _getNextPiece();                                                                     // Gets random next piece, sets starting position, and draws piece to board.
    void _storePieceToHold();
    void _clearHoldPiece();
    void _clearNextPiece();
    void _drawTile(int i, int j, int tileNum);
    void _initializeNextPiece();
    
    void _setNextPieceParameters();
    void _checkAllRows();
    bool _checkForCompleteRows();                                                              // Finds and deletes complete row.
    void _clearCompleteRows();
    int _getCompleteRow();                                                                    // Returns row which requires deleting.
    void _clearRow(int row);                                                                  // Clears row and drops above rows down by one.
    //enum class TileType;
};