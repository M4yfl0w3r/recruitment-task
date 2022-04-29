#include "include/Ex1.h"

int main()
{
  triangle A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  triangle B = {vec2{7, 3}, vec2{4, 5}, vec2{-1, 5}};

  std::cout << "Triangle 1\n";
  for (const auto& e : A.points)
  {
    std::cout << '(' << e.x << ", " << e.y << ")\n";
  }

  std::cout << "\nTriangle 2\n";
  for (const auto& e : B.points)
  {
    std::cout << '(' << e.x << ", " << e.y << ")\n";
  }

  bool res = isColliding(A, B);

  std::cout << "\nCzy się przecinają: " << std::boolalpha << res << '\n';

}
