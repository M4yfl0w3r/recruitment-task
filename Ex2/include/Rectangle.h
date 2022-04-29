#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Rectangle : public sf::Drawable
{

private:
  std::unique_ptr<sf::RectangleShape> rect;
  std::unique_ptr<sf::CircleShape> point;

  sf::Vector2f m_pos;
  sf::Vector2f m_size;
  float angle = 2.f;

  std::vector<sf::Vector2f> vertices;

public:
  Rectangle(sf::Vector2f size, sf::Vector2f pos, sf::Color color);

  void set_pos(sf::Vector2f pos);

  sf::Vector2f get_center() const;
  
  sf::Vector2f get_size() const;

  void set_vertices();

  float get_angle() const;

  sf::Vector2f get_vertex(std::size_t index) const;

  void rotate(bool reverse);

  void set_color(sf::Color color);
  
  virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

