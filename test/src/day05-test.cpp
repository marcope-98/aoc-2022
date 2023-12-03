#include <gtest/gtest.h>

#include "aoc/solutions/day05.hpp"

#include <string>

TEST(day05, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_STREQ(aoc::day05::part1(base + "/day05/sample.txt").c_str(), "CMZ");
  ASSERT_STREQ(aoc::day05::part1(base + "/day05/input.txt").c_str(), "SPFMVDTZT");
}

TEST(day05, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_STREQ(aoc::day05::part2(base + "/day05/sample.txt").c_str(), "MCD");
  ASSERT_STREQ(aoc::day05::part2(base + "/day05/input.txt").c_str(), "ZFSJBPRFP");
}