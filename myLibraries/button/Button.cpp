
#include <SFML/Graphics.hpp>

#include <Button.h>



Button::Button(const sf::String &buttonString, const sf::Font &font)
    : RectangleShape()
    {
        m_buttonText.setCharacterSize(50);
        m_buttonText.setStyle(sf::Text::Bold);

        // initialize the |m_buttonText| variable of the object with given sf::String
        // and setting minimal button size, aka size of displaying text
        m_minimalSizeOfButton = initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromStringAndFont(buttonString, font);
        
        resizeButton(m_minimalSizeOfButton);
    }

sf::Vector2f Button::initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromStringAndFont(const sf::String &buttonString, const sf::Font &font)
{
    m_buttonText.setFont(font);

    return initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromString(buttonString);
}

sf::Vector2f Button::initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromString(const sf::String &buttonString)
    {   
        
        m_buttonText.setString(buttonString);

        sf::FloatRect boundingBoxOfButtonText = m_buttonText.getGlobalBounds();

        // setting position of displayed text to the center of its Origins (tf::Text.setOrigins()),
        // its needed to position displayed text in the center of button -
        // top left corner of bound box is origin, and this point of bound box will be always in center of displayed text
        m_buttonText.setPosition(-boundingBoxOfButtonText.width / 2, -boundingBoxOfButtonText.height + 15);

        sf::Vector2f minimalSizeOfButton;

        // correcting size of displayed text, because 
        // |m_buttonText.getGlobalBounds()| does not give bound box that cover all the text
        minimalSizeOfButton.x = boundingBoxOfButtonText.width + 10;
        minimalSizeOfButton.y = boundingBoxOfButtonText.height * 1.3;

        return minimalSizeOfButton;
    }

void Button::resizeButton(const sf::Vector2f &sizeToSet)
    {
        if (sizeToSet.x <= m_minimalSizeOfButton.x
            ||
            sizeToSet.y <= m_minimalSizeOfButton.y)
        {
            sf::RectangleShape::setSize(m_minimalSizeOfButton);
        }
        else
        {
            sf::RectangleShape::setSize(sizeToSet);
        }

        sf::Vector2f buttonPosition = sf::RectangleShape::getPosition();

        m_buttonText.setOrigin((-sf::RectangleShape::getSize().x / 2.f) - buttonPosition.x,
                               (-sf::RectangleShape::getSize().y / 2.f) - buttonPosition.y);
    }

void Button::swapColorsOfTextAndRectangle()
{
    sf::Color tempColor = sf::RectangleShape::getFillColor();
    sf::RectangleShape::setFillColor(m_buttonText.getFillColor());
    m_buttonText.setFillColor(tempColor);
}

void Button::toggleButtonOutline()
{
    if (m_needChangeOutlineState)
    {
        sf::RectangleShape::setOutlineThickness(2.f);
        m_needChangeOutlineState = !m_needChangeOutlineState;
    }
    else
    {
        sf::RectangleShape::setOutlineThickness(0);
        m_needChangeOutlineState = !m_needChangeOutlineState;
    }
}

void Button::shiftTextPosition(float x, float y)
{
    m_buttonText.move(x, y);
}

void Button::setButtonString(const sf::String &buttonString)
    {
        if (buttonString == m_buttonText.getString())
        {
            return;
        }

        // initialize the |m_buttonText| variable of the object with given sf::String
        // and setting minimal button size, aka size of displaying text
        m_minimalSizeOfButton = initMinimalSizeButtonOutOfTextSizeThatIsCreatedFromString(buttonString);

        resizeButton(m_minimalSizeOfButton);
    }

void Button::setPosition(const sf::Vector2f &position)
    {
        sf::RectangleShape::setPosition(position);

        m_buttonText.setOrigin(-position - sf::RectangleShape::getSize() / 2.f);
    }

void Button::setPosition(float x, float y)
    {
        sf::RectangleShape::setPosition(x, y);

        sf::Vector2f newOrigin;

        newOrigin.x = -x - sf::RectangleShape::getSize().x / 2;
        newOrigin.y = -y - sf::RectangleShape::getSize().y / 2;

        m_buttonText.setOrigin(newOrigin);
    }

void Button::setSize(const sf::Vector2f &size)
    {
        if (size.x <= m_minimalSizeOfButton.x
            ||
            size.y <= m_minimalSizeOfButton.y)
        {
            return;
        }

        resizeButton(size);
    }

void Button::setSize(float x, float y)
    {
        Button::setSize(sf::Vector2f(x, y));
    }
