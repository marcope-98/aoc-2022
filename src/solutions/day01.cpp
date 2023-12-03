#include "aoc/solutions/day01.hpp"

#include <algorithm>
// aoc/utils
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

static std::size_t min_index(const std::size_t *const src, const std::size_t &size)
{
  std::size_t index = 0;
  std::size_t min   = -1;
  for (std::size_t i = 0; i < size; ++i)
  {
    if (min >= src[i])
    {
      min   = src[i];
      index = i;
    }
  }
  return index;
}

std::size_t aoc::day01::part1(const std::string &filename)
{
  aoc::vstring input   = aoc::parse::cvt_file_to_vstring(filename);
  std::size_t  current = 0;
  std::size_t  best    = 0;
  for (const auto &elem : input)
  {
    if (elem.empty())
    {
      if (current > best) best = current;
      current = 0;
    }
    else
      current += std::stoull(elem);
  }

  if (current > best) best = current;

  return best;
}

std::size_t aoc::day01::part2(const std::string &filename)
{
  std::size_t  leaderboard[3] = {0, 0, 0};
  aoc::vstring input          = aoc::parse::cvt_file_to_vstring(filename);
  std::size_t  current        = 0;
  for (const auto &elem : input)
  {
    if (elem.empty())
    {
      std::size_t index = min_index(leaderboard, 3);
      if (leaderboard[index] < current) leaderboard[index] = current;
      current = 0;
    }
    else
      current += std::stoull(elem);
  }
  std::size_t index = min_index(leaderboard, 3);
  if (leaderboard[index] < current) leaderboard[index] = current;

  return leaderboard[0] + leaderboard[1] + leaderboard[2];
}
