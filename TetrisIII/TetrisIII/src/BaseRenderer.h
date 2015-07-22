#pragma once

class BaseRenderer {
public:
    BaseRenderer();
    virtual void DrawBoard(int board[20][10]);
};