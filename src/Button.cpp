#include "Button.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Button::Button(const sf::Text &buttonText)
    : RectangleShape()
    {
        setButtonText(buttonText);

        sf::RectangleShape::setFillColor(m_baseButtonColor);
    }

Button::Button(const sf::String &buttonName)
    : RectangleShape()
    {
        sf::Font *m_font = new sf::Font();

        if (!m_font->loadFromFile("D:\\resources\\consolab.ttf"))
        {
            std::cout << "!m_font.loadFromFile(\"arial.ttf\")" << std::endl;
        }

        m_buttonText.setFont(*m_font);
        m_buttonText.setString(buttonName);
        m_buttonText.setCharacterSize(10);
        m_buttonText.setFillColor(sf::Color::Red);

        initSizeOfButtonText();

        resizeButton(m_sizeOfText);

        delete m_font;
        m_font = nullptr;
    }

bool Button::isInBoundOfButton(const sf::Vector2f &position)
    {
        if (position.x > sf::RectangleShape::getPosition().x
            &&
            position.y > sf::RectangleShape::getPosition().y
            &&
            position.x < sf::RectangleShape::getPosition().x + sf::RectangleShape::getSize().x
            &&
            position.y < sf::RectangleShape::getPosition().y + sf::RectangleShape::getSize().y)
        {
            return true;
        }

        return false;
    }

void Button::initSizeOfButtonText()
    {
        sf::FloatRect boundingBoxOfButtonText = m_buttonText.getGlobalBounds();

        m_buttonText.setPosition(-boundingBoxOfButtonText.width / 2, -boundingBoxOfButtonText.height);

        m_sizeOfText.x = boundingBoxOfButtonText.width * 1.3;
        m_sizeOfText.y = boundingBoxOfButtonText.height * 1.3;
    }

void Button::resizeButton(const sf::Vector2f &size)
    {
        const sf::Vector2f buttonSize = sf::RectangleShape::getSize();

        if (buttonSize.x < m_sizeOfText.x
            &&
            buttonSize.y < m_sizeOfText.y)
        {
            sf::RectangleShape::setSize(m_sizeOfText);
        }
        else
        {
            sf::RectangleShape::setSize(size);
        }

        sf::Vector2f buttonPosition = sf::RectangleShape::getPosition();

        m_buttonText.setOrigin((-sf::RectangleShape::getSize().x / 2.f) - buttonPosition.x,
                               (-sf::RectangleShape::getSize().y / 2.f) - buttonPosition.y);
    }

void Button::setButtonText(const sf::Text &text)
    {
        if (text.getString() == m_buttonText.getString())
        {
            return;
        }

        m_buttonText = text;

        initSizeOfButtonText();

        resizeButton(m_sizeOfText);
    }

void Button::setPosition(const sf::Vector2f &position)
    {
        sf::RectangleShape::setPosition(position);

        m_buttonText.setOrigin(-position - sf::RectangleShape::getSize() / 2.f);
    }

void Button::setSize(const sf::Vector2f &size)
    {
        if (size.x <= m_sizeOfText.x
            &&
            size.y <= m_sizeOfText.y)
        {
            return;
        }

        resizeButton(size);
    }

