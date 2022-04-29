#include "include/Circle.h"
#include "include/Rectangle.h"

struct Segment
{
  sf::Vector2f A;
  sf::Vector2f B;
};

double dot_product(const sf::Vector2f& a, const sf::Vector2f& b)
{
  return (a.x * b.x + a.y * b.y);
}

bool point_inside(const sf::Vector2f& point, const Rectangle& rect)
{
  sf::Vector2f AB = rect.get_vertex(1) - rect.get_vertex(0);
  sf::Vector2f AP = point - rect.get_vertex(0);
  sf::Vector2f BC = rect.get_vertex(2) - rect.get_vertex(1);
  sf::Vector2f BP = point - rect.get_vertex(1);

  if ((0 <= dot_product(AB, AP) && dot_product(AB, AP) <= dot_product(AB, AB) &&
       0 <= dot_product(BC, BP) && dot_product(BC, BP) <= dot_product(BC,BC)))
  {
    return true;
  }
  else return false;
}

bool point_inside(const sf::Vector2f& point, const Circle& circle)
{
  double dx = std::abs(point.x - circle.get_center().x);
  double dy = std::abs(point.y - circle.get_center().y);

  if (dx + dy <= circle.get_radius()) return true;
  if (dx > circle.get_radius()) return false;
  if (dy > circle.get_radius()) return false;
  if (std::pow(dx, 2) + std::pow(dy, 2) <= std::pow(circle.get_radius(), 2)) return true;
  else return false;
}

sf::Vector2f get_coefficients(const Segment& line)
{
  float A = (line.A.y - line.B.y) / (line.A.x - line.B.x);
  float B = (line.A.y - ((line.A.y - line.B.y) / (line.A.x - line.B.x)) * line.A.x);

  return sf::Vector2f{A, B};
}

float distance(float x, float y, const sf::Vector2f& coeffs_rect)
{
  return std::abs(y - coeffs_rect.x * x - coeffs_rect.y) / std::sqrt(std::pow(coeffs_rect.x, 2) + 1);
}

bool intersect(const Circle& circle, const Segment& line)
{
  sf::Vector2f coeffs_rect = get_coefficients(line);
  sf::Vector2f coeffs_perp;
  sf::Vector2f common_point;
   
  if (distance(circle.get_center().x, circle.get_center().y, coeffs_rect) <= circle.get_radius())
  {
    if (coeffs_rect.x == 0) coeffs_perp.x = 0;
    else coeffs_perp.x = - 1. / coeffs_rect.x;

    coeffs_perp.y = circle.get_center().y - coeffs_perp.x * circle.get_center().x;

    common_point.x = (coeffs_rect.y - coeffs_perp.y) / (coeffs_perp.x - coeffs_rect.x);
    common_point.y = (coeffs_perp.x * coeffs_rect.y - coeffs_perp.y * coeffs_rect.x) / (coeffs_perp.x - coeffs_rect.x);

    return ((std::min(line.A.x, line.B.x) <= common_point.x && common_point.x <= std::max(line.A.x, line.B.x)) &&
        (std::min(line.A.y, line.B.y) <= common_point.y && common_point.y <= std::max(line.A.y, line.B.y)));
  }
  else return false;
}

bool collides(const Circle& circle, const Rectangle& rect)
{
  Segment AB = {(rect.get_vertex(0)), (rect.get_vertex(1))};
  Segment BC = {(rect.get_vertex(1)), (rect.get_vertex(2))};
  Segment CD = {(rect.get_vertex(2)), (rect.get_vertex(3))};
  Segment DA = {(rect.get_vertex(3)), (rect.get_vertex(0))};

  return point_inside(circle.get_center(), rect) ||
         point_inside(rect.get_vertex(0), circle) ||
         point_inside(rect.get_vertex(1), circle) ||
         point_inside(rect.get_vertex(2), circle) ||
         point_inside(rect.get_vertex(3), circle) ||
         intersect(circle, AB) ||
         intersect(circle, BC) ||
         intersect(circle, CD) ||
         intersect(circle, DA);
}

int main()
{
  constexpr int width = 800;
  constexpr int height = 600;

  sf::RenderWindow window(sf::VideoMode(width, height), "Ex2", sf::Style::Titlebar | sf::Style::Close);
  sf::Event event;

  Circle circle(120, sf::Vector2f(width/2.f, height/2.f), sf::Color(237, 27, 36, 255));
  Circle outline(120, sf::Vector2f(width/2.f, height/2.f), sf::Color::Transparent);
  
  Rectangle rect(sf::Vector2f(60, 170), sf::Vector2f(width/2.f + 180, height/2.f + 20), sf::Color(255, 175, 202, 255));

  while (window.isOpen())
  {
    window.clear(sf::Color::White);

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      else if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
          case sf::Keyboard::Escape: 
            window.close();
            break;

          case sf::Keyboard::Left:
          case sf::Keyboard::Q:
            rect.rotate(false); 
            break;

          case sf::Keyboard::Right:
          case sf::Keyboard::E:
            rect.rotate(true);
            break;

          default:
            break;
        }  
      }
    }

    if (collides(circle, rect))
    {
      circle.set_color(sf::Color(28,178,75,255));
      rect.set_color(sf::Color(182,231,23,255));
    }
    else
    {
      circle.set_color(sf::Color(237, 27, 36, 255));
      rect.set_color(sf::Color(255, 175, 202, 255));
    }
 
    window.draw(circle);
    window.draw(rect);
    window.draw(outline);

    window.display();
  }

  return 0;
}

