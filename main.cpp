#include <iostream>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "TSP.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "TSP Naive Approach");
	
	std::vector<sf::CircleShape> city_list = {};
	sf::Clock clock;

	sf::Vector2u windowSize = window.getSize();

	sf::Time deltaTime = sf::Time::Zero;
	sf::Time press_timeout_timer = sf::Time::Zero;
	sf::Time update_timeout_timer = sf::Time::Zero;
	float press_timeout_count = 0.5;

	TSP tsp;
	bool solve=false;
	while (window.isOpen())
    {
        sf::Event event;
		bool key_press  = false;
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		deltaTime = clock.restart();
		press_timeout_timer += deltaTime;
		update_timeout_timer += deltaTime;
		
		
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);

		bool insideWindow =
            localPosition.x >= 0 && localPosition.x < static_cast<int>(windowSize.x) &&
            localPosition.y >= 0 && localPosition.y < static_cast<int>(windowSize.y);			

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && press_timeout_timer >= sf::seconds(press_timeout_count) && insideWindow)
		{
		  sf::CircleShape curr_city(8);
		  curr_city.setPosition(localPosition.x, localPosition.y);
		  if(city_list.empty())
			curr_city.setFillColor(sf::Color::Red);
		  
		  
		  city_list.emplace_back(curr_city);
		  
		  press_timeout_timer = sf::Time::Zero;
		}
		// test
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && update_timeout_timer >= sf::seconds(press_timeout_count) && city_list.size() > 1)
		  {
			tsp.solve(city_list);
			update_timeout_timer = sf::Time::Zero;
		  }

				
        window.clear();
		for(auto& city : city_list)
		  {
			window.draw(city);
		  }
		tsp.render_lines(window);
        window.display();
    }

    return 0;
}
