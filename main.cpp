#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600,600), "uwu");
    sf::Event event;
    int width = 50;
    int height = 200;

    sf::Clock clock;
    sf::Vector2f e(width,height);
    sf::Vector2u v(600,600);
    sf::SoundBuffer uwuBuffer;
    uwuBuffer.loadFromFile("uwu.mp3");
    sf::Sound uwu;
    uwu.setBuffer(uwuBuffer);
    
    std::vector<sf::RectangleShape> rectangles;
    std::vector<int> arr = {50,30,500,222,180,333,121,531,112,45,96,221};

    for (size_t i = 0; i < arr.size(); i++){
            sf::RectangleShape rectangle(e);
            rectangles.push_back(rectangle);
            //rectangles[i] = rectangle;
    }

    while (window.isOpen())
    {

        if (window.getSize() != v)
        {
            window.setSize(v);
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        
            for (size_t j = 0; j < arr.size(); j++)
            {
                if (clock.getElapsedTime().asSeconds() > 0.1){
                std::cout << clock.getElapsedTime().asSeconds();
                for (size_t i = j; i < arr.size(); i++)
                {

                    height = arr[i];
                    e.y = height;
                    
                    
                    int uwu;
                    if (arr[j] > arr[i])
                    {
                        uwu = arr[j];
                        arr[j] = arr[i];
                        arr[i] = arr[j];
                    }

                }
                clock.restart();
                uwu.play();
            }
            
        }
        for (size_t i = 0; i < arr.size(); i++){
            height = arr[i];
            e.y = height;
            rectangles[i].setSize(e);
            rectangles[i].setPosition(i*50, 600-height);
            rectangles[i].setSize(e);
            rectangles[i].setPosition(i*50, 600-height);
                    
            window.draw(rectangles[i]);
        }
        //uwu.play();
        
        

        window.display();
    }
    
    return 0;
}
