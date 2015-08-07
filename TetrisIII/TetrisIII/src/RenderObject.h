#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;

class RenderObject {
private:


public:
    Vector2f _position;
    RectangleShape _tile;
    Font _font;
    Text _text;
    Image _image;
    Texture _texture;
    Sprite _sprite;
    RenderObject();

    void SetPosition(Vector2f pos);
    void SetTile(RectangleShape tile);
    void SetFont(std::string fontPath);
    void SetText(Text text);
    void SetImage(std::string imagePath);
    void SetTexture(Image image);
    void SetSprite();
    void SetSpriteSize(int width, int height);

    Vector2f GetPosition();
    RectangleShape GetTile();
    Font GetFont();
    Text GetText();
    Image GetImage();
    Texture GetTexture();
    Sprite GetSprite();

};