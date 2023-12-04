#include <gtest/gtest.h>

#include "aoc/solutions/day10.hpp"

#include <string>

TEST(day10, part1)
{
  std::string base = std::string(TXT_FILE_DIR);
  ASSERT_EQ(aoc::day10::part1(base + "day10/sample.txt"), 13140);
  ASSERT_EQ(aoc::day10::part1(base + "day10/input.txt"), 14920);
}

TEST(day10, part2)
{
  std::string base = std::string(TXT_FILE_DIR);
  const char *sol1 = "##..##..##..##..##..##..##..##..##..##.."
                     "###...###...###...###...###...###...###."
                     "####....####....####....####....####...."
                     "#####.....#####.....#####.....#####....."
                     "######......######......######......####"
                     "#######.......#######.......#######.....";
  const char *sol2 = "###..#..#..##...##...##..###..#..#.####."
                     "...#.#..#.#..#.#..#.#..#.#..#.#..#....#."
                     ".##..#..#.#....#..#.#....###..#..#...#.."
                     "...#.#..#.#....####.#....#..#.#..#..#..."
                     "...#.#..#.#..#.#..#.#..#.#..#.#..#.#...."
                     "###...##...##..#..#..##..###...##..####.";
  ASSERT_STREQ(aoc::day10::part2(base + "day10/sample.txt").c_str(), sol1);
  ASSERT_STREQ(aoc::day10::part2(base + "day10/input.txt").c_str(), sol2);
}

// clang-format off