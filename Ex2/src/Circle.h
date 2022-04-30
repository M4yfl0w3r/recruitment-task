#pragma once

#include <iostream>
#include <memory>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Circle : public sf::Drawable
{

private:
  std::unique_ptr<sf::CircleShape> circle;

  sf::Vector2f m_pos;
  float m_radius;

public:
  Circle(float radius, sf::Vector2f pos, sf::Color color);
  
  void set_pos(sf::Vector2f pos);

  sf::Vector2f get_center() const;
  
  float get_radius() const;

  void set_color(sf::Color color);

  virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

