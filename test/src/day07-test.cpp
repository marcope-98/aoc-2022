#include <gtest/gtest.h>

#include "aoc/solutions/day07.hpp"

#include <string>

TEST(day07, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day07::part1(base + "day07/sample.txt"), 95437);
  ASSERT_EQ(aoc::day07::part1(base + "day07/input.txt"), 1428881);
}

TEST(day07, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day07::part2(base + "day07/sample.txt"), 24933642);
  ASSERT_EQ(aoc::day07::part2(base + "day07/input.txt"), 10475598);
}