#pragma once

#include <iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
#include <list>
#include <cctype>

template <typename T>
void cut_whitespaces(T& text)
{
  std::size_t first_sign = 0;
  std::size_t last_sign = 0;

  auto it = text.begin();

  for (const auto& c : text)
  {
    if (c != ' ')
    {
      std::advance(it, first_sign);
      text.erase(text.begin(), it);
      break;
    }

    first_sign++;
  }

  for (const auto& c : std::ranges::reverse_view(text))
  {
    if(c != ' ')
    {
      break; 
    }

    last_sign++;
  }

  it = text.begin();
  std::advance(it, text.size() - last_sign);
  text.erase(it, text.end());
}
