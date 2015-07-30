#include "TextRenderer.h"

void TextRenderer::RenderGUI(int board[20][10]) {
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] == 3) {
                std::cout << " * ";
            }
            else if (board[i][j] == 2) {
                std::cout << " + ";
            }
            else if (board[i][j] == 1) {
                std::cout << " * ";
            }
            else {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}