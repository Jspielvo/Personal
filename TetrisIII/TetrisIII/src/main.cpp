#include "Game.h"
#include "SFMLRenderer.h"
#include "TextRenderer.h"

int main()
{
    TextRenderer textRenderer;
    SFMLRenderer sfmlRenderer;

    Piece piece;
    Board board(&piece);
    Game game(&board, &sfmlRenderer, &sfmlRenderer.GetWindow());
    //Game game(&board, &textRenderer);

    return 0;
}