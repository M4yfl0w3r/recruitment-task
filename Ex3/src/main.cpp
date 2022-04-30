#include "cut_whitespaces.h"

int main()
{
  std::string text_string = "  test n test  ";
  std::vector<char> text_vector = {' ', 't', 'e', 's', 't', ' ', ' ', 't', 'e', 's', 't', ' '};
  std::list<char> text_list = {' ', 't', 'e', 's', 't', ' ', ' ', 't', 'e', 's', 't', ' '};

  std::cout << "String version\n";
  cut_whitespaces<std::string>(text_string);
  std::cout << text_string;

  std::cout << "\n\nVector version\n";
  cut_whitespaces<std::vector<char>>(text_vector);
  for (const auto& c : text_vector)
  {
    std::cout << c;
  }

  std::cout << "\n\nList version\n";
  cut_whitespaces<std::list<char>>(text_list);
  for (const auto& c : text_list)
  {
    std::cout << c;
  }
}
