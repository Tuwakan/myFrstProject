#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::RectangleShape
{
private:

    static sf::Font m_allButtonsFont;

    sf::Vector2f m_minimalSizeOfButton;

    sf::Text m_buttonText;

    bool m_needChangeOutlineState = true;

    sf::Vector2f initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromString(const sf::String &buttonString);

    void resizeButton(const sf::Vector2f &size);

public:

    bool m_outlineToggle;

    sf::Color m_outlineColor;

    Button(const sf::String &buttonName = "N");

    virtual ~Button()
    {
    }

    static void setFontForAllButtons(const sf::Font &font)
    {
        Button::m_allButtonsFont = font;
    }

    void toggleButtonOutline();

    void setButtonString(const sf::String &buttonString);

    const sf::Text& getButtonText()
    {
        return m_buttonText;
    }

    void setTextColor(const sf::Color &color)
    {
        m_buttonText.setFillColor(color);
    }

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void setSize(const sf::Vector2f &size);

    void setSize(float x, float y);
};

#endif // BUTTON_H
