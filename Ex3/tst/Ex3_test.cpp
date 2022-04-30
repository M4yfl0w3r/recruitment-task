#include <gtest/gtest.h>

#include "../src/cut_whitespaces.h"

TEST(Vector, JednoSlowo)
{
  std::vector<char> text_vector = {' ',' ',' ','t','e','s','t', ' ', ' '};

  cut_whitespaces<std::vector<char>>(text_vector);
 
  EXPECT_FALSE(isspace(text_vector[0]));
  EXPECT_FALSE(isspace(text_vector[text_vector.size() - 1]));
}

TEST(Vector, DwaSlowa)
{
  std::vector<char> text_vector = {' ',' ',' ','t','e',' ',' ',',','s','t', ' ', ' '};

  cut_whitespaces<std::vector<char>>(text_vector);
  
  EXPECT_FALSE(isspace(text_vector[0]));
  EXPECT_FALSE(isspace(text_vector[text_vector.size() - 1]));
}

TEST(Vector, SlowoNaPoczatku)
{
  std::vector<char> text_vector = {'t','e',' ',' ',',','s','t', ' ', ' '};

  cut_whitespaces<std::vector<char>>(text_vector);

  EXPECT_FALSE(isspace(text_vector[0]));
  EXPECT_FALSE(isspace(text_vector[text_vector.size() - 1]));
}

TEST(Vector, SlowoNaKoncu)
{
  std::vector<char> text_vector = {' ',' ','t','e',',','s','t'};

  cut_whitespaces<std::vector<char>>(text_vector);

  EXPECT_FALSE(isspace(text_vector[0]));
  EXPECT_FALSE(isspace(text_vector[text_vector.size() - 1]));
}

TEST(Lista, JednoSlowo)
{
  std::list<char> text_list = {' ',' ',' ','t','e','s','t', ' ', ' '};

  cut_whitespaces<std::list<char>>(text_list);
 
  EXPECT_FALSE(isspace(*(text_list.begin())));
  EXPECT_FALSE(isspace(*(text_list.end())));
}

TEST(Lista, DwaSlowa)
{
  std::list<char> text_list = {' ',' ',' ','t','e',' ',' ',',','s','t', ' ', ' '};

  cut_whitespaces<std::list<char>>(text_list);
  
  EXPECT_FALSE(isspace(*(text_list.begin())));
  EXPECT_FALSE(isspace(*(text_list.end())));
}

TEST(Lista, SlowoNaPoczatku)
{
  std::list<char> text_list = {'t','e',' ',' ',',','s','t', ' ', ' '};

  cut_whitespaces<std::list<char>>(text_list);
  
  EXPECT_FALSE(isspace(*(text_list.begin())));
  EXPECT_FALSE(isspace(*(text_list.end())));
}

TEST(Lista, SlowoNaKoncu)
{
  std::list<char> text_list = {' ',' ','t','e',',','s','t'};

  cut_whitespaces<std::list<char>>(text_list);
  
  EXPECT_FALSE(isspace(*(text_list.begin())));
  EXPECT_FALSE(isspace(*(text_list.end())));
}

TEST(String, JednoSlowo)
{
  std::string text_string = "   test    ";

  cut_whitespaces<std::string>(text_string);
 
  EXPECT_FALSE(isspace(text_string[0]));
  EXPECT_FALSE(isspace(text_string.back()));
}

TEST(String, DwaSlowa)
{
  std::string text_string = "   test  text  ";

  cut_whitespaces<std::string>(text_string);
 
  EXPECT_FALSE(isspace(text_string[0]));
  EXPECT_FALSE(isspace(text_string.back()));
}

TEST(String, SlowoNaPoczatku)
{
  std::string text_string = "test  text  ";

  cut_whitespaces<std::string>(text_string);
 
  EXPECT_FALSE(isspace(text_string[0]));
  EXPECT_FALSE(isspace(text_string.back()));
}

TEST(String, SlowoNaKoncu)
{      
  std::string text_string = "            test    text";
  
  cut_whitespaces<std::string>(text_string);
 
  EXPECT_FALSE(isspace(text_string[0]));
  EXPECT_FALSE(isspace(text_string.back()));
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

