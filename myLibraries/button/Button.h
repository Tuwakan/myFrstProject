#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

class Button : public sf::RectangleShape
{
private:

    sf::Vector2f m_minimalSizeOfButton;

    sf::Text m_buttonText;

    bool m_needChangeOutlineState = true;

    sf::Vector2f initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromString(const sf::String &buttonString);
    sf::Vector2f initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromStringAndFont(const sf::String &buttonString, const sf::Font &font);


    void resizeButton(const sf::Vector2f &size);

public:

    bool m_outlineToggle = false;

    sf::Color m_outlineColor;

    bool m_isButtonInAnimation {false};
    std::chrono::duration<long long, std::milli> m_durationOfButtonAnimation = std::chrono::milliseconds(200);
    std::chrono::duration<long long, std::milli> m_sequenceDurationOfButtonAnimation = std::chrono::milliseconds(1000);
    std::chrono::time_point<std::chrono::steady_clock> m_timePointForAnimation;

    Button(const sf::String &buttonString, const sf::Font &font);

    virtual ~Button()
    {
    }

    void swapColorsOfTextAndRectangle();

    void toggleButtonOutline();

    void shiftTextPosition(float x, float y);

    void setButtonString(const sf::String &buttonString);

    const sf::Text& getButtonText()
    {
        return m_buttonText;
    }

    void setButtonFont(const sf::Font &font)
    {
        m_buttonText.setFont(font);
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
