#include "aoc/solutions/day04.hpp"

#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

static bool contains(const std::size_t &a, const std::size_t &b,
                     const std::size_t &c, const std::size_t &d)
{
  return (a <= c && b >= d) ||
         (c <= a && d >= b);
}

static bool overlap(const std::size_t &a, const std::size_t &b,
                    const std::size_t &c, const std::size_t &d)
{
  return !(b < c || d < a);
}

std::size_t aoc::day04::part1(const std::string &filename)
{
  vstring     input  = parse::cvt_file_to_vstring(filename);
  std::size_t result = 0;
  for (const auto &elem : input)
  {
    vstring ranges = parse::split_by_delimiters(elem, "-,");
    if (contains(std::stoull(ranges[0]), std::stoull(ranges[1]),
                 std::stoull(ranges[2]), std::stoull(ranges[3])))
      ++result;
  }

  return result;
}

std::size_t aoc::day04::part2(const std::string &filename)
{
  vstring input = parse::cvt_file_to_vstring(filename);

  std::size_t result = 0;
  for (const auto &elem : input)
  {
    vstring ranges = parse::split_by_delimiters(elem, "-,");
    if (overlap(std::stoull(ranges[0]), std::stoull(ranges[1]),
                std::stoull(ranges[2]), std::stoull(ranges[3])))
      ++result;
  }

  return result;
}