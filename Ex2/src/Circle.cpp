#include "Circle.h"

Circle::Circle(float radius, sf::Vector2f pos, sf::Color color) : m_radius{radius}
{
  circle = std::make_unique<sf::CircleShape>(radius);
  set_color(color);
  set_pos(pos);
}

void Circle::set_pos(sf::Vector2f pos)
{
  m_pos = pos;
  m_pos.x -= circle -> getRadius();
  m_pos.y -= circle -> getRadius();
  
  circle -> setPosition(m_pos);
}

sf::Vector2f Circle::get_center() const
{
  return sf::Vector2f(m_pos.x + circle -> getRadius(), m_pos.y + circle -> getRadius());
}

float Circle::get_radius() const
{
  return m_radius;
}
  
void Circle::set_color(sf::Color color)
{
  circle -> setOutlineColor(sf::Color::Black);
  circle -> setOutlineThickness(2.f);
  circle -> setFillColor(color);  
}
  
void Circle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
  target.draw(*circle);
}

