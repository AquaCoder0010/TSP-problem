#include "TSP.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <numeric>

static unsigned long long factorial(int n) {
    if (n <= 1) return 1;

    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);  // fills with 1, 2, ..., n

    return std::accumulate(nums.begin(), nums.end(), 1ULL, std::multiplies<>());
}

TSP::TSP()
  :lines()
{
  lines.setPrimitiveType(sf::LineStrip);  
}


std::vector<std::vector<int>> TSP::get_routes(int city_count)
{
  // we always assume that the first element is always the starting node
  std::vector<std::vector<int>> res = {};
  res.reserve(factorial(city_count - 1));
  std::vector<int> city_index = {};
  
  for(int i = 1; i < city_count; i++)
	  city_index.emplace_back(i);

  // recursion function
  permutations(res, city_index, 0);
  for(auto& elem : res)
	  elem.insert(elem.begin(), 0);

  return res;  
}

void TSP::solve(std::vector<sf::CircleShape>& p_city_list)
{
  int city_count = p_city_list.size();  
  auto routes = get_routes(city_count);

  for(int i = 0; i < routes.size(); i++)
	{
	  float curr_cost = 0.f;
	  for(int j = 0; j < routes[i].size() - 1; j++)
		{
		  sf::Vector2f city_1 = p_city_list[routes[i][j]].getPosition();
		  sf::Vector2f city_2 = p_city_list[routes[i][j + 1]].getPosition();
		  
		  float mag = std::sqrt(std::pow(city_2.x - city_1.x, 2) + std::pow(city_2.y - city_1.y, 2));
		  
		  curr_cost += mag;
		}
	  if(min_cost > curr_cost)
		{
		  min_cost = curr_cost;
		  min_index = i;
		}
	}
  
  for(auto& min_route : routes[min_index])
	{
	  std::cout << min_route << " ";
	  sf::Vector2f current_city_position = p_city_list[min_route].getPosition();

	  float city_radius = p_city_list[min_route].getRadius();
	  current_city_position.x += city_radius;
	  current_city_position.y += city_radius;
	  
	  lines.append(sf::Vertex(current_city_position, sf::Color::White));
	}
  std::cout << std::endl;
  sf::Vector2f last_city_position = p_city_list[0].getPosition();
  
  float city_radius = p_city_list[0].getRadius();
  last_city_position.x += city_radius;
  last_city_position.y += city_radius;
  
  lines.append(sf::Vertex(last_city_position, sf::Color::White));
}
