#include "aoc/solutions/day09.hpp"

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

struct Coord
{
  int x = 0;
  int y = 0;
};

template<std::size_t Knots>
struct Map
{
  std::unordered_map<std::string, std::size_t> map;

  Coord knots[Knots] = {0};

  static int sign(const int &value)
  {
    if (value == 0) return 0;
    return value > 0 ? +1 : -1;
  }

  void move_head(const Coord &dir)
  {
    this->knots[0].x += dir.x;
    this->knots[0].y += dir.y;
  }

  void move_tail(const std::size_t &knot)
  {
    const int diffx = this->knots[knot - 1].x - this->knots[knot].x;
    const int diffy = this->knots[knot - 1].y - this->knots[knot].y;

    if (std::abs(diffx) <= 1 && std::abs(diffy) <= 1) return;

    this->knots[knot].x += sign(diffx);
    this->knots[knot].y += sign(diffy);
  }

  void move(const Coord &dir, const std::size_t &steps)
  {
    for (std::size_t i = 0; i < steps; ++i)
    {
      this->move_head(dir);
      for (std::size_t j = 1; j < Knots; ++j)
        this->move_tail(j);
      this->map[hash()]++;
    }
  }

  std::string hash() const { return std::to_string(this->knots[Knots - 1].x) + "," + std::to_string(this->knots[Knots - 1].y); }
  std::size_t size() const { return this->map.size(); }
};

std::size_t aoc::day09::part1(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  Map<2>       map;

  for (const auto &cmd : input)
  {
    Coord        coord;
    aoc::vstring temp = aoc::parse::split_by_delimiters(cmd, " ");
    switch (temp[0][0])
    {
      case 'R':
        coord = {+1, 0};
        break;
      case 'L':
        coord = {-1, 0};
        break;
      case 'U':
        coord = {0, +1};
        break;
      case 'D':
        coord = {0, -1};
        break;
    }

    map.move(coord, std::stoull(temp[1]));
  }

  return map.size();
}

std::size_t aoc::day09::part2(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  Map<10>      map;

  for (const auto &cmd : input)
  {
    Coord        coord;
    aoc::vstring temp = aoc::parse::split_by_delimiters(cmd, " ");
    switch (temp[0][0])
    {
      case 'R':
        coord = {+1, 0};
        break;
      case 'L':
        coord = {-1, 0};
        break;
      case 'U':
        coord = {0, +1};
        break;
      case 'D':
        coord = {0, -1};
        break;
    }

    map.move(coord, std::stoull(temp[1]));
  }
  return map.size();
}