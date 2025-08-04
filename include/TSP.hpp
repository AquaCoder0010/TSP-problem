#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include <limits>


class TSP
{
private:
  sf::VertexArray lines;
  sf::Time update_timer = sf::Time::Zero;
  float min_cost = std::numeric_limits<float>::max();
  int min_index = -1;
public:
  TSP();  
  std::vector<std::vector<int>> get_routes(int city_count);
  float calculate_cost(std::vector<std::vector<int>> routes);

  void solve(std::vector<sf::CircleShape>& p_city_list);
public:  
  void render_lines(sf::RenderWindow& window)
  {
	window.draw(lines);
  }
private:
  void permutations(std::vector<std::vector<int>>& result, std::vector<int> route, int idx)
  {
	if (idx == route.size()) {
	    result.emplace_back(route);
        return;
    }
    for (int i = idx; i < route.size(); i++) {
	    std::swap(route[idx], route[i]);
	    permutations(result, route, idx + 1);
		std::swap(route[idx], route[i]);
    }
  }
  
};
