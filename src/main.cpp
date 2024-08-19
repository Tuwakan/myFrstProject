#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <vector>
//#include <thread>
//#include <mutex>

#include <Button.h>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("D:\\resources\\msgothic.ttc"))
    {
        std::cout << "!font.loadFromFile(\"msgothic.ttc\")" << std::endl;
    }

    sf::Text prideSymbol;
    sf::Text greedSymbol;
    sf::Text envySymbol;
    sf::Text wrathSymbol;
    sf::Text lustSymbol;
    sf::Text gluttonySymbol;
    sf::Text slothSymbol;
    sf::Text evilSymbol;

    prideSymbol       .setFont(font);
    greedSymbol       .setFont(font);
    envySymbol        .setFont(font);
    wrathSymbol       .setFont(font);
    lustSymbol        .setFont(font);
    gluttonySymbol    .setFont(font);
    slothSymbol       .setFont(font);
    evilSymbol        .setFont(font);

    prideSymbol       .setString(L"慢");
    greedSymbol       .setString(L"欲");
    envySymbol        .setString(L"妬");
    wrathSymbol       .setString(L"怒");
    lustSymbol        .setString(L"情");
    gluttonySymbol    .setString(L"飢");
    slothSymbol       .setString(L"怠");
    evilSymbol        .setString(L"悪");

    prideSymbol       .setCharacterSize(50);
    greedSymbol       .setCharacterSize(50);
    envySymbol        .setCharacterSize(50);
    wrathSymbol       .setCharacterSize(50);
    lustSymbol        .setCharacterSize(50);
    gluttonySymbol    .setCharacterSize(50);
    slothSymbol       .setCharacterSize(50);
    evilSymbol        .setCharacterSize(50);

    prideSymbol       .setFillColor(sf::Color(128, 255, 0));   // inverted Violet
    greedSymbol       .setFillColor(sf::Color(0, 0, 255));     // inverted Yellow
    envySymbol        .setFillColor(sf::Color(255, 0, 255));   // inverted Green
    wrathSymbol       .setFillColor(sf::Color(0, 255, 255));   // inverted Red
    lustSymbol        .setFillColor(sf::Color(255, 255, 0));   // inverted Blue
    gluttonySymbol    .setFillColor(sf::Color(0, 90, 255));    // inverted Orange
    slothSymbol       .setFillColor(sf::Color(82, 39, 25));    // inverted Light Blue
    evilSymbol        .setFillColor(sf::Color(255, 255, 255)); // inverted Black

    prideSymbol       .setStyle(sf::Text::Bold);
    greedSymbol       .setStyle(sf::Text::Bold);
    envySymbol        .setStyle(sf::Text::Bold);
    wrathSymbol       .setStyle(sf::Text::Bold);
    lustSymbol        .setStyle(sf::Text::Bold);
    gluttonySymbol    .setStyle(sf::Text::Bold);
    slothSymbol       .setStyle(sf::Text::Bold);
    evilSymbol        .setStyle(sf::Text::Bold);


    Button evilButton     (evilSymbol);
    Button prideButton    (prideSymbol);
    Button wrathButton    (wrathSymbol);
    Button greedButton    (greedSymbol);
    Button lustButton     (lustSymbol);
    Button envyButton     (envySymbol);
    Button gluttonyButton (gluttonySymbol);
    Button slothButton    (slothSymbol);

    evilButton     .setFillColor((sf::Color::Black));
    prideButton    .setFillColor(sf::Color(127, 0, 255)); // Violet
    wrathButton    .setFillColor(sf::Color::Red);
    greedButton    .setFillColor(sf::Color::Yellow);
    lustButton     .setFillColor(sf::Color::Blue);
    envyButton     .setFillColor(sf::Color::Green);
    gluttonyButton .setFillColor(sf::Color(255, 165, 0)); // Orange
    slothButton    .setFillColor(sf::Color(173, 216, 230)); // Light Blue

    float sizeOfButtons = 100.f;

    evilButton      .setSize(sizeOfButtons, sizeOfButtons);
    prideButton     .setSize(sizeOfButtons, sizeOfButtons);
    wrathButton     .setSize(sizeOfButtons, sizeOfButtons);
    greedButton     .setSize(sizeOfButtons, sizeOfButtons);
    lustButton      .setSize(sizeOfButtons, sizeOfButtons);
    envyButton      .setSize(sizeOfButtons, sizeOfButtons);
    gluttonyButton  .setSize(sizeOfButtons, sizeOfButtons);
    slothButton     .setSize(sizeOfButtons, sizeOfButtons);

    sf::Vector2f startPositionOfButtons {250.f, 250.f};

    float gapBetweenButtons = 50.f;

    prideButton     .setPosition(startPositionOfButtons.x, 
                                 startPositionOfButtons.y);

    evilButton      .setPosition(sizeOfButtons + gapBetweenButtons + startPositionOfButtons.x,
                                 startPositionOfButtons.y);

    wrathButton     .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                 startPositionOfButtons.y);


    greedButton     .setPosition(startPositionOfButtons.x,
                                 sizeOfButtons + gapBetweenButtons + startPositionOfButtons.y);

    lustButton      .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                 sizeOfButtons + gapBetweenButtons + startPositionOfButtons.y);


    envyButton      .setPosition(startPositionOfButtons.x,
                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);

    slothButton     .setPosition(sizeOfButtons + gapBetweenButtons + startPositionOfButtons.x,
                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);

    gluttonyButton  .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);


    sf::RenderWindow window(sf::VideoMode(900, 900), "My window");

    window.setVerticalSyncEnabled(true);

    /*

    sf::FloatRect boundingBox = text.getGlobalBounds();
    const sf::Vector2f textPosition = text.getPosition();

    std::cout << "textPosition.x : " << textPosition.x << std::endl;
    std::cout << "textPosition.y : " << textPosition.y << std::endl;

    std::cout << "boundingBox.width : " << boundingBox.width << std::endl;
    std::cout << "boundingBox.height : " << boundingBox.height << std::endl;

    text.setOrigin(0, boundingBox.height / 2);

    text.move(100.f, 100.f);

    const sf::Vector2f textPosition2 = text.getPosition();

    std::cout << "textPosition2.x : " << textPosition2.x << std::endl;
    std::cout << "textPosition2.y : " << textPosition2.y << std::endl;

    sf::RectangleShape rectangle(sf::Vector2f(boundingBox.width + 4, boundingBox.height + 3));
    rectangle.setFillColor(sf::Color(255, 255, 255, 128));
    //rectangle.setOrigin(-100.f, -100.f);
    rectangle.move(textPosition2.x, textPosition2.y);

    const sf::Vector2f textCharPosition = text.findCharacterPos(2);

    sf::RectangleShape rectangle2(sf::Vector2f(textCharPosition.x, textCharPosition.y + boundingBox.height));
    rectangle2.setFillColor(sf::Color(255, 255, 255, 128));

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    //text.setOrigin(sf::Vector2f(38.f, 15.f));
    //text.move(sf::Vector2f(250.f, 250.f));
    */

    //Button button(sf::Vector2f(30.f, 20.f));

    sf::Vector2f localCursorPosition{};

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseMoved:

                    localCursorPosition.x = sf::Mouse::getPosition(window).x;
                    localCursorPosition.y = sf::Mouse::getPosition(window).y;

                    if (evilButton.getGlobalBounds().contains(localCursorPosition))
                    {
                        if (evilButton.getFillColor() == evilButton.m_baseButtonColor)
                        {
                            
                        }
                    }
                    else
                    {
                        if (evilButton.getFillColor() != evilButton.m_baseButtonColor)
                        {
                            
                        }
                    }

                    break;

                case sf::Event::Resized:

                    std::cout << "new width: " << event.size.width << std::endl;
                    std::cout << "new height: " << event.size.height << std::endl;

                    break;

                case sf::Event::LostFocus:

                    std::cout << "LostFocus " << std::endl;

                    break;

                case sf::Event::GainedFocus:

                    std::cout << "GainedFocus " << std::endl;

                    break;

                case sf::Event::TextEntered:

                    if (event.text.unicode < 128)
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

                    break;

                case sf::Event::KeyPressed:

                    break;

                case sf::Event::MouseWheelScrolled:

                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                        std::cout << "wheel type: vertical" << std::endl;
                    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
                        std::cout << "wheel type: horizontal" << std::endl;
                    else
                        std::cout << "wheel type: unknown" << std::endl;

                    std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                    std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                    std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;

                    break;

                case sf::Event::MouseButtonPressed:

                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    }

                    break;

                case sf::Event::MouseEntered:

                    std::cout << "the mouse cursor has entered the window" << std::endl;

                    break;

                case sf::Event::MouseLeft:

                    std::cout << "the mouse cursor has left the window" << std::endl;

                    break;

                // we don't process other types of events
                default:

                    //std::cout << "f " << std::endl;

                    break;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(evilButton);
        window.draw(evilButton.getButtonText());

        window.draw(prideButton);
        window.draw(prideButton.getButtonText());

        window.draw(wrathButton);
        window.draw(wrathButton.getButtonText());

        window.draw(greedButton);
        window.draw(greedButton.getButtonText());

        window.draw(lustButton);
        window.draw(lustButton.getButtonText());

        window.draw(envyButton);
        window.draw(envyButton.getButtonText());

        window.draw(gluttonyButton);
        window.draw(gluttonyButton.getButtonText());

        window.draw(slothButton);
        window.draw(slothButton.getButtonText());

        window.display();

    }

    return 0;
}
