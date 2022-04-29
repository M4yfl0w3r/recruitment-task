#include "../include/Rectangle.h"

Rectangle::Rectangle(sf::Vector2f size, sf::Vector2f pos, sf::Color color) : m_size{size}
{
  rect = std::make_unique<sf::RectangleShape>(size);
  point = std::make_unique<sf::CircleShape>(2.5);

  set_color(color);
  set_pos(pos);
  set_vertices();

  rect -> rotate(-30.f);
  rect -> setOrigin(size.x/2, size.y/2);
  point -> setPosition(m_pos);
}
  
void Rectangle::set_vertices()
{
  vertices.push_back(rect -> getPoint(0));
  vertices.push_back(rect -> getPoint(1));
  vertices.push_back(rect -> getPoint(2));
  vertices.push_back(rect -> getPoint(3));
}
  
void Rectangle::set_pos(sf::Vector2f pos)
{
  m_pos = pos;
  m_pos.x -= (rect -> getSize().x)/2; 
  m_pos.y -= (rect -> getSize().y)/2; 

  rect -> setPosition(m_pos);
  point -> setPosition(rect -> getSize().x/2, rect -> getSize().y/2);
}

sf::Vector2f Rectangle::get_center() const
{
  return sf::Vector2f(rect -> getSize().x/2, rect -> getSize().y/2); 
}

sf::Vector2f Rectangle::get_size() const
{
  return m_size;
}

sf::Vector2f Rectangle::get_vertex(std::size_t index) const
{
  sf::Transform trans = rect -> getTransform();

  return trans.transformPoint(vertices[index]);
}

float Rectangle::get_angle() const
{
  return angle;
}
  
void Rectangle::rotate(bool reverse)
{
  rect -> rotate(reverse ? angle : -angle);
}
  
void Rectangle::set_color(sf::Color color)
{
  rect -> setOutlineColor(sf::Color::Black);
  rect -> setOutlineThickness(2.f);
  rect -> setFillColor(color);

  point -> setFillColor(sf::Color::Black);
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
  target.draw(*rect);
  target.draw(*point);
}

