#pragma once

#include <iostream>
#include <algorithm>
#include <array>

struct vec2
{
  float x, y;
};

struct triangle
{
  std::array<vec2, 3> points;
};

struct line_segment
{
  vec2 a;
  vec2 b;  
};

auto isBetween(const vec2&, const vec2&, float, float) -> bool;
auto isInside(const triangle&, const vec2&) -> bool;
auto areSectionsCrossed(const line_segment&, const line_segment&) -> bool;
auto isColliding(const triangle&, const triangle&) -> bool;
auto get_coefficients(const line_segment&) -> vec2;

