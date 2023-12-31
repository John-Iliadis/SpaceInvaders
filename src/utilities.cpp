//
// Created by Gianni on 18/12/2023.
//

#include "../include/utilities.hpp"

float max_text_height(const sf::Text& text)
{
    int char_size = text.getCharacterSize();
    const sf::Font* font = text.getFont();
    std::string text_str = text.getString().toAnsiString();
    bool bold = (text.getStyle() & sf::Text::Bold);

    float max{};

    for (const auto& character : text_str)
    {
        sf::Glyph glyph = font->getGlyph(character, char_size, bold);
        float height = glyph.bounds.height;

        if (height > max)
        {
            max = height;
        }
    }

    return max;
}

static float get_text_max_height(sf::Text& text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    float text_max_height = max_text_height(text);
    float max_height{};

    if (textRect.height >= text_max_height)
    {
        max_height = textRect.height;
    }
    else
    {
        max_height = text_max_height;
    }

    return max_height;
}

void center_text(sf::Text& text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    float max_height = get_text_max_height(text);

    text.setOrigin(int(textRect.left + textRect.width * 0.5f), int(textRect.top + max_height * 0.5f));
}

void set_text_origin_right(sf::Text& text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    float max_height = get_text_max_height(text);

    text.setOrigin(int(textRect.width), int(textRect.top + max_height * 0.5f));
}

void set_text_origin_left(sf::Text& text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    float max_height = get_text_max_height(text);

    text.setOrigin((int)textRect.left, int(textRect.top + max_height * 0.5f));
}

void center_shape(sf::Shape& shape)
{
    auto dimensions = shape.getLocalBounds();
    shape.setOrigin(dimensions.width / 2.f, dimensions.height / 2.f);
}

void center_sprite(sf::Sprite& sprite)
{
    auto dimensions = sprite.getLocalBounds();
    sprite.setOrigin(dimensions.width / 2, dimensions.height / 2);
}

std::string key_to_string(sf::Keyboard::Key key)
{
#define KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

    switch (key)
    {
        KEYTOSTRING_CASE(Unknown)
        KEYTOSTRING_CASE(A)
        KEYTOSTRING_CASE(B)
        KEYTOSTRING_CASE(C)
        KEYTOSTRING_CASE(D)
        KEYTOSTRING_CASE(E)
        KEYTOSTRING_CASE(F)
        KEYTOSTRING_CASE(G)
        KEYTOSTRING_CASE(H)
        KEYTOSTRING_CASE(I)
        KEYTOSTRING_CASE(J)
        KEYTOSTRING_CASE(K)
        KEYTOSTRING_CASE(L)
        KEYTOSTRING_CASE(M)
        KEYTOSTRING_CASE(N)
        KEYTOSTRING_CASE(O)
        KEYTOSTRING_CASE(P)
        KEYTOSTRING_CASE(Q)
        KEYTOSTRING_CASE(R)
        KEYTOSTRING_CASE(S)
        KEYTOSTRING_CASE(T)
        KEYTOSTRING_CASE(U)
        KEYTOSTRING_CASE(V)
        KEYTOSTRING_CASE(W)
        KEYTOSTRING_CASE(X)
        KEYTOSTRING_CASE(Y)
        KEYTOSTRING_CASE(Z)
        KEYTOSTRING_CASE(Num0)
        KEYTOSTRING_CASE(Num1)
        KEYTOSTRING_CASE(Num2)
        KEYTOSTRING_CASE(Num3)
        KEYTOSTRING_CASE(Num4)
        KEYTOSTRING_CASE(Num5)
        KEYTOSTRING_CASE(Num6)
        KEYTOSTRING_CASE(Num7)
        KEYTOSTRING_CASE(Num8)
        KEYTOSTRING_CASE(Num9)
        KEYTOSTRING_CASE(Escape)
        KEYTOSTRING_CASE(LControl)
        KEYTOSTRING_CASE(LShift)
        KEYTOSTRING_CASE(LAlt)
        KEYTOSTRING_CASE(LSystem)
        KEYTOSTRING_CASE(RControl)
        KEYTOSTRING_CASE(RShift)
        KEYTOSTRING_CASE(RAlt)
        KEYTOSTRING_CASE(RSystem)
        KEYTOSTRING_CASE(Menu)
        KEYTOSTRING_CASE(LBracket)
        KEYTOSTRING_CASE(RBracket)
        KEYTOSTRING_CASE(SemiColon)
        KEYTOSTRING_CASE(Comma)
        KEYTOSTRING_CASE(Period)
        KEYTOSTRING_CASE(Quote)
        KEYTOSTRING_CASE(Slash)
        KEYTOSTRING_CASE(BackSlash)
        KEYTOSTRING_CASE(Tilde)
        KEYTOSTRING_CASE(Equal)
        KEYTOSTRING_CASE(Dash)
        KEYTOSTRING_CASE(Space)
        KEYTOSTRING_CASE(Return)
        KEYTOSTRING_CASE(BackSpace)
        KEYTOSTRING_CASE(Tab)
        KEYTOSTRING_CASE(PageUp)
        KEYTOSTRING_CASE(PageDown)
        KEYTOSTRING_CASE(End)
        KEYTOSTRING_CASE(Home)
        KEYTOSTRING_CASE(Insert)
        KEYTOSTRING_CASE(Delete)
        KEYTOSTRING_CASE(Add)
        KEYTOSTRING_CASE(Subtract)
        KEYTOSTRING_CASE(Multiply)
        KEYTOSTRING_CASE(Divide)
        KEYTOSTRING_CASE(Left)
        KEYTOSTRING_CASE(Right)
        KEYTOSTRING_CASE(Up)
        KEYTOSTRING_CASE(Down)
        KEYTOSTRING_CASE(Numpad0)
        KEYTOSTRING_CASE(Numpad1)
        KEYTOSTRING_CASE(Numpad2)
        KEYTOSTRING_CASE(Numpad3)
        KEYTOSTRING_CASE(Numpad4)
        KEYTOSTRING_CASE(Numpad5)
        KEYTOSTRING_CASE(Numpad6)
        KEYTOSTRING_CASE(Numpad7)
        KEYTOSTRING_CASE(Numpad8)
        KEYTOSTRING_CASE(Numpad9)
        KEYTOSTRING_CASE(F1)
        KEYTOSTRING_CASE(F2)
        KEYTOSTRING_CASE(F3)
        KEYTOSTRING_CASE(F4)
        KEYTOSTRING_CASE(F5)
        KEYTOSTRING_CASE(F6)
        KEYTOSTRING_CASE(F7)
        KEYTOSTRING_CASE(F8)
        KEYTOSTRING_CASE(F9)
        KEYTOSTRING_CASE(F10)
        KEYTOSTRING_CASE(F11)
        KEYTOSTRING_CASE(F12)
        KEYTOSTRING_CASE(F13)
        KEYTOSTRING_CASE(F14)
        KEYTOSTRING_CASE(F15)
        KEYTOSTRING_CASE(Pause)
        case sf::Keyboard::KeyCount:
            break;
    }

    throw std::runtime_error("std::string key_to_string - End of function reached");
}