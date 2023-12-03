#include "aoc/solutions/day08.hpp"

#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

struct Grid
{
  std::size_t   height{0};
  std::size_t   width{0};
  std::uint8_t *data{nullptr};
  explicit Grid(const aoc::vstring &input)
  {
    this->height = input.size();
    this->width  = input[0].size();
    this->data   = new std::uint8_t[this->width * this->height];
    for (std::size_t i = 0; i < this->height; ++i)
      for (std::size_t j = 0; j < this->width; ++j)
        this->data[i * this->width + j] = std::uint8_t(input[i][j] - '0');
  }

  ~Grid() { delete[] this->data; }

  std::size_t get_perimeter() const { return this->width * 2 + this->height * 2 - 4; }

  std::size_t visible(const std::size_t &x, const std::size_t &y) const
  {
  }
};

std::size_t aoc::day08::part1(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  Grid         grid(input);

  std::size_t result = grid.get_perimeter();
  for (std::size_t y = 1; y < grid.height - 1; ++y)
    for (std::size_t x = 1; x < grid.width - 1; ++x)
      result += grid.visible(x, y);
  return result;
}

std::size_t aoc::day08::part2(const std::string &filename)
{
  aoc::vstring input  = aoc::parse::cvt_file_to_vstring(filename);
  std::size_t  result = 0;

  return result;
}