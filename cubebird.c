#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int hit_detection(int tube_x,int tube_b,float bird_y);

int main(){
    int tube_b,tube_y,space = 0,count_tubes = 0,score = 0;
    float tube_x = 0;
    // int tubes[12];
    float bird_y = 680 / 2;

	sf::RenderWindow window(sf::VideoMode(800,680), "Cube Bird");
	sf::RectangleShape bird(sf::Vector2f(50,50));
    bird.setFillColor(sf::Color::Yellow);

    time_t t;
    srand((unsigned) time(&t));
	while(window.isOpen()){
        if(tube_x < 1){
            tube_x = 750;
            score++;
            tube_b = rand() % 580;
        }
		sf::Event event;
		while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bird.setPosition(50,bird_y);
        sf::RectangleShape uppertube(sf::Vector2f(50,tube_b));//40
        uppertube.setPosition(tube_x,0);
        uppertube.setFillColor(sf::Color::Green);
        sf::RectangleShape lowertube(sf::Vector2f(50,680-tube_b));//640
        lowertube.setPosition(tube_x,tube_b + 200);
        lowertube.setFillColor(sf::Color::Green);

        tube_x -= 0.25;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !space){
            bird_y -= 100;
            space = 100;
        }else{
            bird_y += 0.2 ;
        }
        if(!hit_detection(tube_x,tube_b,bird_y)){
            window.clear();
            window.draw(bird);
            window.draw(uppertube);
            window.draw(lowertube);
            window.display();
        }else{
            sf::RectangleShape lost(sf::Vector2f(800,680));
            lost.setFillColor(sf::Color::Red);
            window.clear();
            window.draw(lost);
            window.display();
            sleep(3);
            window.close();
            printf("Your score is:%d\n",score );
        }
        sleep(0.001);
        if(space != 0){
            space-=1;
        }

	}
	return 0;
}
// g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

int hit_detection(int tube_x,int tube_b,float bird_y){
    if(tube_x <= 100){
        if(tube_b >= bird_y){
            return 1;
        }
        else if(tube_b + 200 <= bird_y){
            return 1;
        }
    }
    return 0;
}
