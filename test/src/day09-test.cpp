#include <gtest/gtest.h>

#include "aoc/solutions/day09.hpp"

#include <string>

TEST(day09, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day09::part1(base + "day09/sample1.txt"), 13);
  ASSERT_EQ(aoc::day09::part1(base + "day09/input.txt"), 6087);
}

TEST(day09, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day09::part2(base + "day09/sample1.txt"), 1);
  ASSERT_EQ(aoc::day09::part2(base + "day09/sample2.txt"), 36);
  ASSERT_EQ(aoc::day09::part2(base + "day09/input.txt"), 2493);
}