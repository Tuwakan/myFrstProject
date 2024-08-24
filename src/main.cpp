#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <vector>
//#include <thread>
//#include <mutex>

#include <Button.h>

void startOfButtonAnimation(Button &button)
{
    button.swapColorsOfTextAndRectangle();

    button.m_timePointForAnimation = std::chrono::steady_clock::now();

    button.m_isButtonInAnimation = true;
}

//////////////////////////////////////////////////////////////////////////////

enum Symbol
{
    EVIL,
    PRIDE,
    WRATH,
    GREED,
    LUST,
    ENVY,
    GLUTTONY,
    SLOTH,
    PLAY,
    MAX_OF_SYMBOLS
};

int main()
{
    sf::Font fontForJapanese;
    if (!fontForJapanese.loadFromFile("C:\\Windows\\Fonts\\msgothic.ttc"))
    {
        std::cout << "!fontForJapanese.loadFromFile(\"msgothic.ttc\")" << std::endl;
    }

    sf::Font fontForSpecialChars;
    if (!fontForSpecialChars.loadFromFile("C:\\Windows\\Fonts\\segmdl2.ttf"))
    {
        std::cout << "!fontForSpecialChars.loadFromFile(\"segmdl2.ttf\")" << std::endl;
    }

   // Button::setFontForAllButtons(font);

    const std::vector<sf::String> symbolVector 
    {
        L"悪",    // evil
        L"慢",    // pride
        L"怒",    // wrath
        L"欲",    // greed
        L"情",    // lust
        L"妬",    // envy
        L"飢",    // gluttony
        L"怠",     // sloth
        L"\uE768" // play
    };

    const std::vector<sf::Color> colorVector 
    {
        sf::Color::Black,
        sf::Color(127, 0, 255),   // Violet
        sf::Color::Red,
        sf::Color::Yellow,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color(255, 165, 0),   // Orange
        sf::Color(173, 216, 230), // Light Blue
        sf::Color(6, 66, 18),      // dark dark green

    };

    const std::vector<sf::Color> invertedColorVector 
    {
        sf::Color::White,          // inverted Black
        sf::Color(128, 255, 0),    // inverted Violet
        sf::Color(0, 255, 255),    // inverted Red
        sf::Color(0, 0, 255),      // inverted Yellow
        sf::Color(255, 255, 0),    // inverted Blue
        sf::Color(255, 0, 255),    // inverted Green
        sf::Color(0, 90, 255),     // inverted Orange
        sf::Color(82, 39, 25),     // inverted Light Blue
        sf::Color(0, 255, 0, 128), // dark Green
    };

    const std::vector<sf::Color> outlineColorVector
    {
        sf::Color(128, 128, 128), // Gray
        sf::Color::White,   
        sf::Color::White,
        sf::Color::White,
        sf::Color::White,
        sf::Color::White,
        sf::Color::White,   
        sf::Color::White, 
        sf::Color::White,
    };
    
    std::vector<Button> buttonVector;

    float sizeOfButtons = 100.f;

    // creating and initialization Buttons and Buttons Text
    for (size_t symbolCode {};
         symbolCode < Symbol::MAX_OF_SYMBOLS;
         ++symbolCode)
    {   
        
        Button button (symbolVector[symbolCode], 
                      (symbolCode == Symbol::PLAY) ? fontForSpecialChars : fontForJapanese);
    
        button.setSize(sizeOfButtons, sizeOfButtons);
        button.setFillColor(colorVector[symbolCode]);
        button.setTextColor(invertedColorVector[symbolCode]);
        button.setOutlineColor(outlineColorVector[symbolCode]);

        buttonVector.push_back(button);

        
    };


    sf::Vector2f startPositionOfButtons {250.f, 250.f};

    float gapBetweenButtons = 50.f;

    buttonVector[Symbol::PRIDE]     .setPosition(startPositionOfButtons.x, 
                                                 startPositionOfButtons.y);

    buttonVector[Symbol::EVIL]      .setPosition(sizeOfButtons + gapBetweenButtons + startPositionOfButtons.x,
                                                 startPositionOfButtons.y);

    buttonVector[Symbol::WRATH]     .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                                 startPositionOfButtons.y);


    buttonVector[Symbol::GREED]     .setPosition(startPositionOfButtons.x,
                                                 sizeOfButtons + gapBetweenButtons + startPositionOfButtons.y);

    buttonVector[Symbol::PLAY]      .setPosition(sizeOfButtons + gapBetweenButtons + startPositionOfButtons.x,
                                                 sizeOfButtons + gapBetweenButtons + startPositionOfButtons.y);

    buttonVector[Symbol::LUST]      .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                                 sizeOfButtons + gapBetweenButtons + startPositionOfButtons.y);


    buttonVector[Symbol::ENVY]      .setPosition(startPositionOfButtons.x,
                                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);

    buttonVector[Symbol::SLOTH]     .setPosition(sizeOfButtons + gapBetweenButtons + startPositionOfButtons.x,
                                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);

    buttonVector[Symbol::GLUTTONY]  .setPosition(2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.x,
                                                 2.f * sizeOfButtons + 2.f * gapBetweenButtons + startPositionOfButtons.y);

    // shifting text of middle action button
    buttonVector[Symbol::PLAY].shiftTextPosition(-8, 5);

    sf::RenderWindow window(sf::VideoMode(900, 900), "My window");

    window.setVerticalSyncEnabled(true);
    
    sf::Vector2f localCursorPosition{};
    sf::FloatRect buttonBoundingBox;

    bool isButtonsAnimationInAction (false);

    uint8_t counterOfActiveAnimations {};

    //

    bool playerAction = true;

    bool playSequence = false;

    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        if (isButtonsAnimationInAction)
        {
            for (size_t symbol{};
                 symbol < Symbol::MAX_OF_SYMBOLS;
                 ++symbol)
            { 
                
                if (buttonVector[symbol].m_isButtonInAnimation)
                {
                    if (std::chrono::steady_clock::now() - buttonVector[symbol].m_timePointForAnimation 
                        >= buttonVector[symbol].m_durationOfButtonAnimation)
                    {
                        buttonVector[symbol].swapColorsOfTextAndRectangle();

                        buttonVector[symbol].m_isButtonInAnimation = false;
                        
                        counterOfActiveAnimations -= 1;

                        if (symbol == Symbol::PLAY
                            &&
                            playerAction)
                        {
                            playSequence = true;
                            playerAction = false;
                        }
                    }
                }
                
            }
            
            if (counterOfActiveAnimations == 0)
            {
                isButtonsAnimationInAction = false;
            }
            
        }

        
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
                    
                    for (size_t symbol{};
                        symbol < Symbol::MAX_OF_SYMBOLS;
                        ++symbol)
                    {
                        buttonBoundingBox = buttonVector[symbol].getGlobalBounds();

                        if (buttonBoundingBox.contains(localCursorPosition))
                        {
                            if (!buttonVector[symbol].m_outlineToggle)
                            {
                                buttonVector[symbol].toggleButtonOutline();
                                buttonVector[symbol].m_outlineToggle = true;
                            }
                        }
                        else
                        {
                            if (buttonVector[symbol].m_outlineToggle)
                            {
                                buttonVector[symbol].toggleButtonOutline();
                                buttonVector[symbol].m_outlineToggle = false;
                            }

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

                    if (event.mouseButton.button == sf::Mouse::Left
                        &&
                        playerAction)
                    {
                        for (size_t symbol{};
                        symbol < Symbol::MAX_OF_SYMBOLS;
                        ++symbol)
                        {
                            buttonBoundingBox = buttonVector[symbol].getGlobalBounds();

                            if (buttonBoundingBox.contains(localCursorPosition))
                            {
                        
                                if (!buttonVector[symbol].m_isButtonInAnimation)
                                {
                                    startOfButtonAnimation(buttonVector[symbol]);

                                    counterOfActiveAnimations += 1;

                                    isButtonsAnimationInAction = true;
                                }
                                
                            }
                        }
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

                    break;
            }
        }
        

        window.clear(sf::Color::Black);

        for(Button &button : buttonVector)
        {
            window.draw(button);
            window.draw(button.getButtonText());
        }
        

        window.display();

    }

    return 0;
}
