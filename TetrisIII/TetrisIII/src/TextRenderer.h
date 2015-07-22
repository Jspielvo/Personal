#include "BaseRenderer.h"
#include <iostream>

class TextRenderer : public BaseRenderer {
public:
    void DrawBoard(int board[20][10]);
};