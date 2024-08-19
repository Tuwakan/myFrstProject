#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::RectangleShape
{
private:

    sf::Vector2f m_sizeOfText;

    sf::Text m_buttonText;

    void initSizeOfButtonText();

    void resizeButton(const sf::Vector2f &size);

public:

    sf::Color m_baseButtonColor = sf::Color(255, 255, 255, 128);

    Button(const sf::Text &buttonText);

    Button(const sf::String &buttonName = "NONE");

    virtual ~Button()
    {
    }

    bool isInBoundOfButton(const sf::Vector2f &position);

    void move(float offsetX, float offsetY);

    void setButtonText(const sf::Text &text);

    sf::Text& getButtonText()
    {
        return m_buttonText;
    }

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void setSize(const sf::Vector2f &size);
};

#endif // BUTTON_H
