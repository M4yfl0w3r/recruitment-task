#include "../include/Ex1.h"

bool isBetween(const vec2& a, const vec2& b, float x, float y)
{
  return (std::min(a.x, b.x) <= x && x <= std::max(a.x, b.x) &&
          std::min(a.y, b.y) <= y && y <= std::max(a.y, b.y));
}

vec2 get_coefficients(const line_segment& line)
{
  float A = (line.a.y - line.b.y) / (line.a.x - line.b.x);
  float B = (line.a.y - ((line.a.y - line.b.y) / (line.a.x - line.b.x)) * line.a.x);

  return vec2{A, B};
}

bool isInside(const triangle& t, const vec2& P)
{
  float Ax = t.points[0].x;
  float Ay = t.points[0].y;
  float Bx = t.points[1].x;
  float By = t.points[1].y;
  float Cx = t.points[2].x;
  float Cy = t.points[2].y;

  double w1 = (Ax*(Cy-Ay) + (P.y-Ay)*(Cx-Ax) - P.x*(Cy-Ay)) / ((By-Ay)*(Cx-Ax) - (Bx-Ax)*(Cy-Ay));
  double w2 = (P.y-Ay-w1*(By-Ay)) / (Cy-Ay);

  if (w1 >= 0 && w2 >= 0 && (w1+w2) <= 1) return true;
  else return false;
}

bool areSectionsCrossed(const line_segment& l1, const line_segment& l2)
{
  vec2 l1_coeffs = get_coefficients(l1);
  vec2 l2_coeffs = get_coefficients(l2);

  vec2 common_point;
  common_point.x = (l1_coeffs.y - l2_coeffs.y) / (l2_coeffs.x - l1_coeffs.x);
  common_point.y = (l2_coeffs.x * l1_coeffs.y - l2_coeffs.y * l1_coeffs.x) / (l2_coeffs.x - l1_coeffs.x);

  if (isBetween(l2.a, l2.b, common_point.x, common_point.y)) return true;
  else return false;
}

bool isColliding(const triangle& t1, const triangle& t2)
{
  line_segment 
    t1_ab {t1.points[0], t1.points[1]}, 
    t1_bc {t1.points[1], t1.points[2]},
    t1_ac {t1.points[0], t1.points[2]};
  
  line_segment 
    t2_ab {t2.points[0], t2.points[1]},
    t2_bc {t2.points[1], t2.points[2]},
    t2_ac {t2.points[0], t2.points[2]};

  for (const auto& vertex : t1.points)
  {
    if (isInside(t2, vertex)) return true;
  }
  
  for (const auto& vertex : t2.points)
  {
    if (isInside(t1, vertex)) return true;
  }

  return  areSectionsCrossed(t1_ab, t2_ab) ||
          areSectionsCrossed(t1_ab, t2_bc) ||
          areSectionsCrossed(t1_ab, t2_ac) ||
          areSectionsCrossed(t1_bc, t2_ab) ||
          areSectionsCrossed(t1_bc, t2_bc) ||
          areSectionsCrossed(t1_bc, t2_ac) ||
          areSectionsCrossed(t1_ac, t2_ab) ||
          areSectionsCrossed(t1_ac, t2_bc) ||
          areSectionsCrossed(t1_ac, t2_ac);
}


