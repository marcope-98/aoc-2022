#include "aoc/solutions/day05.hpp"
#include <iostream>
// aoc/utils
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

typedef struct
{
  std::size_t move;
  std::size_t from;
  std::size_t to;
} Moves;

static aoc::vstring generate(const aoc::vstring &map, const std::size_t &numbers_of_stacks)
{
  aoc::vstring out(numbers_of_stacks);
  for (std::size_t i = 0; i < map.size() - 1; ++i)
  {
    std::string row = map[i];
    for (std::size_t j = 1; j < row.size(); j += 4)
    {
      std::size_t index = (j - 1) / 4;
      if (row[j] != ' ') out[index] = row[j] + out[index];
    }
  }
  return out;
}

static aoc::vstring get_crates(const aoc::vstring &input)
{
  aoc::vstring out;
  for (const auto &elem : input)
  {
    if (elem.empty()) break;
    out.emplace_back(elem);
  }
  return out;
}

static std::vector<Moves> get_moves(const aoc::vstring &input)
{
  std::vector<Moves> out;
  Moves              moves;
  for (const auto &elem : input)
  {
    if (elem[0] != 'm')
      continue;
    else
    {
      aoc::vstring temp = aoc::parse::split_by_delimiters(elem, " ");
      moves.move        = std::stoull(temp[1]);
      moves.from        = std::stoull(temp[3]) - 1;
      moves.to          = std::stoull(temp[5]) - 1;
      out.emplace_back(moves);
    }
  }
  return out;
}

static std::string get_top_crates(const aoc::vstring &input)
{
  std::string res = "";
  for (const auto &elem : input)
    if (!elem.empty())
      res += elem.back();
  return res;
}

static std::size_t get_stacks(const aoc::vstring &input)
{
  aoc::vstring temp = aoc::parse::split_by_delimiters(input.back(), " ");
  return std::stoull(temp.back());
}

static void apply_moves_single(aoc::vstring &stack, const std::vector<Moves> &moves)
{
  for (const auto &move : moves)
  {
    for (std::size_t i = 0; i < move.move; ++i)
    {
      // save character da from
      char temp = stack[move.from].back();
      // remove character da from
      stack[move.from].pop_back();
      // append character da from
      stack[move.to] += temp;
    }
  }
}

static void apply_moves_multi(aoc::vstring &stack, const std::vector<Moves> &moves)
{
  for (const auto &move : moves)
  {
    std::string temp;
    for (std::size_t i = 0; i < move.move; ++i)
    {
      // save character da from
      temp += stack[move.from].back();
      // remove character da from
      stack[move.from].pop_back();
    }
    for (std::size_t i = 0; i < move.move; ++i)
    {
      char t = temp.back();
      temp.pop_back();
      stack[move.to] += t;
    }
  }
}

std::string aoc::day05::part1(const std::string &filename)
{
  aoc::vstring       input             = aoc::parse::cvt_file_to_vstring(filename);
  aoc::vstring       map               = get_crates(input);
  std::vector<Moves> moves             = get_moves(input);
  std::size_t        numbers_of_stacks = get_stacks(map);
  vstring            stack             = generate(map, numbers_of_stacks);
  apply_moves_single(stack, moves);

  return get_top_crates(stack);
}

std::string aoc::day05::part2(const std::string &filename)
{
  aoc::vstring       input             = aoc::parse::cvt_file_to_vstring(filename);
  aoc::vstring       map               = get_crates(input);
  std::vector<Moves> moves             = get_moves(input);
  std::size_t        numbers_of_stacks = get_stacks(map);
  vstring            stack             = generate(map, numbers_of_stacks);
  apply_moves_multi(stack, moves);

  return get_top_crates(stack);
}
