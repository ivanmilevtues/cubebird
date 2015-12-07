#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int rand_y,current_x,tube_x,tube_y,bird_x = 20,bird_y = 680 / 2;

	sf::RenderWindow window(sf::VideoMode(1280,680), "Cube Bird");
	sf::RectangleShape bird(sf::Vector2f(50,50));
    time_t t;
    bird.setFillColor(sf::Color::Green);

	while(window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::RectangleShape tube(sf::Vector2f(50,20));
        bird.setPosition(bird_x,bird_y);
        bird_x++;
        // if(bird_x < 1280/2){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                bird_y -= 100;
            }else{
                bird_y++;
            }
        // }
        window.clear();
        window.draw(bird);
        // window.draw(tube);
        window.display();
        sleep(1.0f);

	}
	return 0;
}
// g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system