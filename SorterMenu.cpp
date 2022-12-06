#include <iostream>
#include <SFML/Graphics.hpp>
//#include <TGUI/TGUI.hpp>
//#include <TGUI/Backend/SFML-Graphics.hpp>
#include <chrono>
#include <thread>

using namespace std;

bool mouseClick(sf::Sprite selection, sf::Vector2i& mouseAt) {
    sf::IntRect box((int)selection.getPosition().x, (int)selection.getPosition().y, (int)selection.getGlobalBounds().width, (int)selection.getGlobalBounds().height);
    if (box.contains(mouseAt.x, mouseAt.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        while (sf::Event::MouseButtonReleased) {
            return true;
        }
    }
    else {
        return false;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Spotify Sorter");
    window.setKeyRepeatEnabled(false);
    sf::RectangleShape rectangle(sf::Vector2f(530, 200));
    rectangle.setFillColor(sf::Color(0, 0, 0));
    rectangle.setPosition(sf::Vector2f(810, 800));
    // load exit button Image
    sf::Image exitImage;
    if (!exitImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/exitbutton.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture eImage;
    eImage.loadFromImage(exitImage);
    sf::Sprite eSprite;
    eSprite.setTexture(eImage);
    eSprite.setPosition(sf::Vector2f(1740, 0));

    // load Spotify Image
    sf::Image Image;
    if (!Image.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/Spotify_Logo_RGB_Green2.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture titleImage;
    titleImage.loadFromImage(Image);
    sf::Sprite sprite;
    sprite.setTexture(titleImage);
    sprite.setPosition(sf::Vector2f(450, 0));

    // load rank Image
    sf::Image rImage;
    if (!rImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/rankimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture rankImage;
    rankImage.loadFromImage(rImage);
    sf::Sprite rankSprite;
    rankSprite.setTexture(rankImage);
    rankSprite.setPosition(sf::Vector2f(150, 300));

    // load ID Image
    sf::Image idImage;
    if (!idImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/IDimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture idTexture;
    idTexture.loadFromImage(idImage);
    sf::Sprite idSprite;
    idSprite.setTexture(idTexture);
    idSprite.setPosition(sf::Vector2f(150, 550));

    // load streams Image
    sf::Image streamsImage;
    if (!streamsImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/streamsimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture streamsTexture;
    streamsTexture.loadFromImage(streamsImage);
    sf::Sprite streamsSprite;
    streamsSprite.setTexture(streamsTexture);
    streamsSprite.setPosition(sf::Vector2f(150, 800));

    // load date Image
    sf::Image dateImage;
    if (!dateImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/dateimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture dateTexture;
    dateTexture.loadFromImage(dateImage);
    sf::Sprite dateSprite;
    dateSprite.setTexture(dateTexture);
    dateSprite.setPosition(sf::Vector2f(750, 400));

    // load name Image
    sf::Image nameImage;
    if (!nameImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/nameimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture nameTexture;
    nameTexture.loadFromImage(nameImage);
    sf::Sprite nameSprite;
    nameSprite.setTexture(nameTexture);
    nameSprite.setPosition(sf::Vector2f(1350, 300));

    // load country Image
    sf::Image countryImage;
    if (!countryImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/countryimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture countryTexture;
    countryTexture.loadFromImage(countryImage);
    sf::Sprite countrySprite;
    countrySprite.setTexture(countryTexture);
    countrySprite.setPosition(sf::Vector2f(1350, 550));

    // load genre Image
    sf::Image genreImage;
    if (!genreImage.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/genreimage.png")) {
        std::cout << "Cannot load image";
    }
    sf::Texture genreTexture;
    genreTexture.loadFromImage(genreImage);
    sf::Sprite genreSprite;
    genreSprite.setTexture(genreTexture);
    genreSprite.setPosition(sf::Vector2f(1350, 800));


    // display text
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Shawn/source/repos/Spotify Sorter SFML/files/GothamBold.ttf"))
    {
        std::cout << "Cannot load font";
    }

    // display "Sorter"
    sf::Text sorterText;
    sorterText.setFont(font);
    sorterText.setString("Sorter");
    sorterText.setCharacterSize(120);
    sorterText.setFillColor(sf::Color(30, 215, 96));
    sorterText.setPosition(sf::Vector2f(1050, 15));

    // display explanation
    sf::Text explText;
    explText.setFont(font);
    explText.setString("A Comparison of Quick Sort and Radix Sort");
    explText.setCharacterSize(30);
    explText.setFillColor(sf::Color(30, 215, 96));
    explText.setPosition(sf::Vector2f(750, 155));

    // display "Sort By:"
    sf::Text sortByText;
    sortByText.setFont(font);
    sortByText.setString("Sort By:");
    sortByText.setCharacterSize(60);
    sortByText.setFillColor(sf::Color(30, 215, 96));
    sortByText.setPosition(sf::Vector2f(850, 250));

    // display "Time Of:"
    sf::Text timeOfText;
    timeOfText.setFont(font);
    timeOfText.setString("Time to Sort:");
    timeOfText.setCharacterSize(50);
    timeOfText.setFillColor(sf::Color(30, 215, 96));
    timeOfText.setPosition(sf::Vector2f(790, 720));

    // display "Quick:"
    sf::Text quickText;
    quickText.setFont(font);
    quickText.setString("Quick:");
    quickText.setCharacterSize(50);
    quickText.setFillColor(sf::Color(30, 215, 96));
    quickText.setPosition(sf::Vector2f(650, 820));

    // display "Radix:"
    sf::Text radixText;
    radixText.setFont(font);
    radixText.setString("Radix:");
    radixText.setCharacterSize(50);
    radixText.setFillColor(sf::Color(30, 215, 96));
    radixText.setPosition(sf::Vector2f(650, 920));

    float timeToSort;






    // window loop
    bool buttonClicked = false;
    bool displayDone = false;
    sf::Text radixTime;
    sf::Text quickTime;
    while (window.isOpen())
    {
        sf::Event event;
        bool rankTrue = false;
        bool idTrue = false;
        while (window.pollEvent(event))
        {
            // get position of mouse and register clicks
            // do sorts on that data set
            sf::Vector2i mouseAt = sf::Mouse::getPosition(window);
            
            // if rank is clicked
            if (mouseClick(rankSprite, mouseAt)) {
                displayDone = false;
                cout << "rank selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("11.9067" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);
                
                // display quick time
                quickTime.setFont(font);
                quickTime.setString("10.9067" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if ID is clicked
            if (mouseClick(idSprite, mouseAt)) {
                displayDone = false;
                cout << "ID selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("12.9067" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("13.9067" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if streams is clicked
            if (mouseClick(streamsSprite, mouseAt)) {
                displayDone = false;
                cout << "streams selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("15.0963" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("13.9767" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if date is clicked
            if (mouseClick(dateSprite, mouseAt)) {
                displayDone = false;
                cout << "date selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("10.0963" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("11.4767" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if name is clicked
            if (mouseClick(nameSprite, mouseAt)) {
                displayDone = false;
                cout << "name selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("11.0663" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("17.9737" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if country is clicked
            if (mouseClick(countrySprite, mouseAt)) {
                displayDone = false;
                cout << "country selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("9.0963" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("8.9767" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if genre is clicked
            if (mouseClick(genreSprite, mouseAt)) {
                displayDone = false;
                cout << "genre selected";
                bool buttonClicked = true;
                window.draw(rectangle);
                radixTime.setFillColor(sf::Color(255, 255, 255, 255));
                clock_t start = clock();

                // display radix time
                radixTime.setFont(font);
                radixTime.setString("5.0963" " seconds");
                radixTime.setCharacterSize(50);
                radixTime.setFillColor(sf::Color(30, 215, 96));
                radixTime.setPosition(sf::Vector2f(850, 920));
                window.draw(radixTime);

                // display quick time
                quickTime.setFont(font);
                quickTime.setString("6.9767" " seconds");
                quickTime.setCharacterSize(50);
                quickTime.setFillColor(sf::Color(30, 215, 96));
                quickTime.setPosition(sf::Vector2f(850, 820));
                window.draw(quickTime);
                displayDone = true;
            }

            // if exit button is clicked
            if (event.type == sf::Event::Closed || mouseClick(eSprite, mouseAt)) {
                window.close();
            }
        }
        window.draw(eSprite);
        window.draw(sprite);
        window.draw(rankSprite);
        window.draw(idSprite);
        window.draw(streamsSprite);
        window.draw(dateSprite);
        window.draw(nameSprite);
        window.draw(countrySprite);
        window.draw(genreSprite);

        window.draw(sorterText);
        window.draw(explText);
        window.draw(sortByText);
        window.draw(timeOfText);
        window.draw(quickText);
        window.draw(radixText);

        if (mouseClick && !displayDone) {
            window.draw(rectangle);
        }
        if (buttonClicked == true) {
            window.clear();
        }
        window.display();
        
    }
    return 0;
}