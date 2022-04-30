#include <gtest/gtest.h>

#include "../src/Ex1.h"

TEST(TrianglesCollision, TrojkatWTrojkacie)
{
  triangle A = {vec2{-10, 14}, vec2{-16, 6}, vec2{-4, 6}};
  triangle B = {vec2{-10, 10}, vec2{-12, 8}, vec2{-8, 8}};

  triangle C = {vec2{-3, 3}, vec2{-5, 1}, vec2{2.3, -1.99}};
  triangle D = {vec2{-3, 3}, vec2{-4, 1}, vec2{-2, 1}};

  EXPECT_TRUE(isColliding(A, B));
  EXPECT_TRUE(isColliding(C, D));
}

TEST(TrianglesCollision, TrojkatyNieStykajaceSie)
{
  triangle C;
  triangle D;
  
  C = {vec2{-10, 14}, vec2{-16, 6}, vec2{-4, 6}};
  D = {vec2{-18, 12}, vec2{-18, 8}, vec2{-26, 8}};

  EXPECT_FALSE(isColliding(C, D));
}

TEST(TrianglesCollision, TrojkatyPokrywajaceSie)
{
  triangle C;
  triangle D;
  
  C = {vec2{-18, 12}, vec2{-18, 8}, vec2{-26, 8}};
  D = {vec2{-18, 12}, vec2{-18, 8}, vec2{-26, 8}};

  EXPECT_TRUE(isColliding(C, D));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieBokami1)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{1, 3}, vec2{1, -3}, vec2{-2, 0}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieBokami2)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{1, 3}, vec2{4, 3}, vec2{4, 0}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieBokami3)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{4, -3}, vec2{1, -3}, vec2{4, 0}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieWierzcholkami1)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{7, 3}, vec2{7, -3}, vec2{4, 0}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieWierzcholkami2)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{1, 3}, vec2{4, 5}, vec2{7,3}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyStykajaceSieWierzcholkami3)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{-2, -5}, vec2{1, -3}, vec2{4, -5}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyPrzecinajaceSie1)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{-1, -1}, vec2{1, -3}, vec2{5, -1}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, TrojkatyPrzecinajaceSie2)
{
  triangle A;
  triangle B;

  A = {vec2{1, 3}, vec2{1, -3}, vec2{4, 0}};
  B = {vec2{-1, -1}, vec2{1, -3}, vec2{4.62, 4.33}};

  EXPECT_TRUE(isColliding(A, B));
}

TEST(TrianglesCollision, GwiazdaDawida)
{
  triangle A;
  triangle B;

  A = {vec2{-4, 5}, vec2{-2, 2}, vec2{-6, 2}};
  B = {vec2{-4, 1}, vec2{-6, 4}, vec2{-2, 4}};

  EXPECT_TRUE(isColliding(A, B));
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

