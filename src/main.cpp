#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <vector>
//#include <thread>
//#include <mutex>

#include <Button.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "My window");

    window.setVerticalSyncEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("D:\\resources\\consolab.ttf"))
    {
        std::cout << "!font.loadFromFile(\"arial.ttf\")" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("A");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("CU\nM");
    text2.setCharacterSize(40);
    text2.setFillColor(sf::Color::Green);

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

    //sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    //rectangle.setFillColor(sf::Color(255, 0, 255, 128));

    Button button(text2);
    button.setPosition(sf::Vector2f(200.f, 100.f));

    Button button2(text);
    button2.setPosition(sf::Vector2f(100.f, 100.f));

    sf::Vector2f localCursorPosition{};

    sf::FloatRect buttonBounds = button.getGlobalBounds();

    sf::RectangleShape rectangle(sf::Vector2f(buttonBounds.width, buttonBounds.height));
    rectangle.setFillColor(sf::Color(255, 0, 0, 128));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        buttonBounds = button.getGlobalBounds();
        rectangle.setSize(sf::Vector2f(buttonBounds.width, buttonBounds.height));

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

                    if (button.getGlobalBounds().contains(localCursorPosition))
                    {
                        if (button.getFillColor() == button.m_baseButtonColor)
                        {
                            button.setFillColor(sf::Color(255, 255, 0, 128));
                        }
                    }
                    else
                    {
                        if (button.getFillColor() != button.m_baseButtonColor)
                        {
                            button.setFillColor(button.m_baseButtonColor);
                        }
                    }

                    break;

                case sf::Event::Resized:

                    std::cout << "new width: " << event.size.width << std::endl;
                    std::cout << "new height: " << event.size.height << std::endl;

                    break;

                case sf::Event::LostFocus:

                    std::cout << "LostFocus " << std::endl;

                    button.setButtonText(text2);

                    break;

                case sf::Event::GainedFocus:

                    std::cout << "GainedFocus " << std::endl;

                    break;

                case sf::Event::TextEntered:

                    if (event.text.unicode < 128)
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

                    break;

                case sf::Event::KeyPressed:

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        button.move(0, -10);
                    }
                    else
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        button.move(-10, 0);
                    }
                    else
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        button.move(0, 10);
                    }
                    else
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        button.move(10, 0);
                    }

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

                        button.setSize(sf::Vector2f(200.f, 100.f));
                    }

                    break;

                case sf::Event::MouseEntered:

                    std::cout << "the mouse cursor has entered the window" << std::endl;

                    sf::Mouse::setPosition(sf::Vector2i(250, 250), window);

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

        //window.draw(text);



        //window.draw(rectangle2);





        window.draw(button);
        window.draw(button.getButtonText());

        window.draw(button2);
        window.draw(button2.getButtonText());

        window.draw(rectangle);

        window.display();

    }

    return 0;
}
