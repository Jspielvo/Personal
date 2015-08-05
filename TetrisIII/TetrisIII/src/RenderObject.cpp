#include "RenderObject.h"

RenderObject::RenderObject() {

}

void RenderObject::SetPosition(Vector2f pos) {
    _sprite.setPosition(pos);
}

void RenderObject::SetTile(RectangleShape tile) {
    _tile = tile;
}

void RenderObject::SetFont(std::string fontPath) {
    if (!_font.loadFromFile(fontPath)) {
        std::cout << "Error loading " << fontPath  << "." << std::endl;
        exit(1);
    }
}

void RenderObject::SetText(Text text) {
    _text = text;
}

void RenderObject::SetImage(std::string imagePath) {
    if (!_image.loadFromFile(imagePath)) {
        std::cout << "Error loading " << imagePath << "." << std::endl;
        exit(1);
    }
}

void RenderObject::SetTexture(Image image) {
    if (!_texture.loadFromImage(image)) { 
        std::cout << "Error loading image. Can not set texture." << std::endl;
        exit(1);
    }
}

void RenderObject::SetSprite() {
    _sprite.setTexture(_texture);
    _sprite.setPosition(_position);
}

Vector2f RenderObject::GetPosition() {
    return _position;
}

RectangleShape RenderObject::GetTile() {
    return _tile;
}

Font RenderObject::GetFont() {
    return _font;
}

Text RenderObject::GetText() {
    return _text;
}

Image RenderObject::GetImage() {
    return _image;
}

Texture RenderObject::GetTexture() {
    return _texture;
}

Sprite RenderObject::GetSprite() {
    return _sprite;
}
