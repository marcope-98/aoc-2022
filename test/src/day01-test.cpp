#include <gtest/gtest.h>

#include "aoc/solutions/day01.hpp"

#include <string>

TEST(day01, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day01::part1(base + "/day01/sample.txt"), 24000);
  ASSERT_EQ(aoc::day01::part1(base + "/day01/input.txt"), 69626);
}

TEST(day01, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day01::part2(base + "/day01/sample.txt"), 45000);
  ASSERT_EQ(aoc::day01::part2(base + "/day01/input.txt"), 206780);
}