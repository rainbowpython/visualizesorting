#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
int main(int argc, char const *argv[]){
    sf::RenderWindow window(sf::VideoMode(600,600), "uwu");
    sf::Event event;
    int width = 50;
    int height = 200;

    sf::Clock clock;
    sf::Vector2f e(width,height);
    sf::Vector2u v(600,600);

    
    std::vector<sf::RectangleShape> rectangles;
    std::vector<int> arr = {50,30,500,222,180,333,121,531,112,45,96,221};

    for (size_t i = 0; i < arr.size(); i++){
            sf::RectangleShape rectangle(e);
            rectangles.push_back(rectangle);
    }
    int i = 0;
    int j = 0;
    bool change = false;
    while (window.isOpen()){

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
        if (clock.getElapsedTime().asSeconds() > 0.1){

            change = true;
            if (j < arr.size()){
                if(i < arr.size()){
                    height = arr[i];
                    e.y = height;
                    if (arr[j] > arr[i]) {
                        int uwu = arr[j];
                        arr[j] = arr[i];
                        arr[i] = uwu;
                    }
                    clock.restart();
                    i++;
                }
                else{
                    i = j+1;
                    j++;
                }   
            }
        }   
        
        for (size_t k = 0; k < arr.size(); k++){
            height = arr[k];
            e.y = height;
            rectangles[k].setFillColor(sf::Color().White);
            if (k == i && change){
                rectangles[k].setFillColor(sf::Color().Blue);
            }
            rectangles[k].setSize(e);
            rectangles[k].setPosition(k*50, 600-height);
            rectangles[k].setSize(e);
            rectangles[k].setPosition(k*50, 600-height);
        
            window.draw(rectangles[k]);
        }
        //uwu.play();
        change = false;
        window.display();
    }
    
    return 0;
    
}
