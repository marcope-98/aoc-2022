#include <gtest/gtest.h>

#include "aoc/solutions/day06.hpp"

#include <string>

TEST(day06, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/sample1.txt"), 7);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/sample2.txt"), 5);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/sample3.txt"), 6);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/sample4.txt"), 10);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/sample5.txt"), 11);
  ASSERT_EQ(aoc::day06::part1(base + "/day06/input.txt"), 1848);
}

TEST(day06, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/sample1.txt"), 19);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/sample2.txt"), 23);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/sample3.txt"), 23);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/sample4.txt"), 29);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/sample5.txt"), 26);
  ASSERT_EQ(aoc::day06::part2(base + "/day06/input.txt"), 2308);
}