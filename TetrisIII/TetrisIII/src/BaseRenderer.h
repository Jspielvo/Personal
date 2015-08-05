#pragma once
#include "RenderObject.h"

class BaseRenderer {
public:
    BaseRenderer();
    virtual void RenderGUI(int board[20][10], int lowPos);
    virtual void DrawNextPiece(int nextPiece[5][5], int x, int y);
    virtual void DrawHoldPiece(int holdPiece[5][5], int x, int y);
    virtual void DrawScore(int score, int x, int y);
    virtual void DrawLevel(int level, int x, int y);
    virtual void DrawGameOver(int x, int y);
    virtual void DrawStartMenu();
    virtual void DrawInGameMenu(int x, int y);
    virtual void DrawClearRowAnimation(int level, int x, int y);

};