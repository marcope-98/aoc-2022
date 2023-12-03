#include <gtest/gtest.h>

#include "aoc/solutions/day08.hpp"

#include <string>

TEST(day08, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day08::part1(base + "day08/sample.txt"), 21);
  ASSERT_EQ(aoc::day08::part1(base + "day08/input.txt"), 0);
}

TEST(day08, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day08::part2(base + "day08/sample.txt"), 0);
  ASSERT_EQ(aoc::day08::part2(base + "day08/input.txt"), 0);
}