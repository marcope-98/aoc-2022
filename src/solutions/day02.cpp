#include "aoc/solutions/day02.hpp"

#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

std::size_t aoc::day02::part1(const std::string &filename)
{
  aoc::vstring input = parse::cvt_file_to_vstring(filename);
  std::int32_t score = 0, diff = 0, opponent_move, my_move;

  for (const auto &elem : input)
  {
    opponent_move = std::int32_t(elem.front() - 'A');
    my_move       = std::int32_t(elem.back() - 'X');
    score += my_move + 1;
    diff = my_move - opponent_move;
    if (diff == 0)
      score += 3;
    else if (diff == 1 || diff == -2)
      score += 6;
  }

  return score;
}

std::size_t aoc::day02::part2(const std::string &filename)
{
  aoc::vstring input = parse::cvt_file_to_vstring(filename);
  std::int32_t score = 0, opponent_move, result;

  for (const auto &elem : input)
  {
    opponent_move = std::int32_t(elem.front() - 'A');
    result        = std::int32_t(elem.back() - 'X');
    score += 3 * result;
    switch (result)
    {
      case 0: // loss
        score += ((opponent_move - 1) < 0 ? opponent_move + 2 : opponent_move - 1) + 1;
        break;
      case 1: // draw
        score += opponent_move + 1;
        break;
      case 2: // win
        score += ((opponent_move + 1) > 2 ? opponent_move - 2 : opponent_move + 1) + 1;
        break;
    }
  }
  return score;
}
