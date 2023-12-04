#include "aoc/solutions/day08.hpp"
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"
#include <algorithm>
#include <iostream>

struct Grid
{
  std::size_t  height{0};
  std::size_t  width{0};
  std::size_t *data{nullptr};
  Grid() = default;
  explicit Grid(const aoc::vstring &input)
  {
    this->height = input.size();
    this->width  = input[0].size();
    this->data   = new std::size_t[this->width * this->height];
    for (std::size_t i = 0; i < this->height; ++i)
      for (std::size_t j = 0; j < this->width; ++j)
        this->data[i * this->width + j] = std::size_t(input[i][j] - '0');
  }

  ~Grid() { delete[] this->data; }

  std::size_t get_perimeter() const { return this->width * 2 + this->height * 2 - 4; }

  std::size_t visible(const std::size_t &x, const std::size_t &y) const
  {
    const std::size_t tree_height = this->data[y * this->width + x];
    std::size_t       temp        = this->data[x];
    for (std::size_t i = 1; i < y; ++i)
      if (this->data[i * this->width + x] > temp)
        temp = this->data[i * this->width + x];
    if (temp < tree_height) return 1;

    temp = this->data[x + (y + 1) * this->width];
    for (std::size_t i = y + 2; i < this->height; ++i)
      if (this->data[i * this->width + x] > temp)
        temp = this->data[i * this->width + x];
    if (temp < tree_height) return 1;

    temp = this->data[y * this->width];
    for (std::size_t i = 1; i < x; ++i)
      if (this->data[y * this->width + i] > temp)
        temp = this->data[y * this->width + i];
    if (temp < tree_height) return 1;

    temp = this->data[y * this->width + x + 1];
    for (std::size_t i = x + 2; i < this->width; ++i)
      if (this->data[y * this->width + i] > temp)
        temp = this->data[y * this->width + i];
    if (temp < tree_height) return 1;
    return 0;
  }

  std::size_t scenic_score(const std::size_t &x, const std::size_t &y) const
  {
    std::size_t       a = 0, b = 0, c = 0, d = 0;
    const std::size_t tree_height = this->data[y * this->width + x];
    std::size_t       i;
    if (y != 0)
    {
      for (i = y - 1; i != 0; --i)
      {
        a++;
        if (this->data[i * this->width + x] >= tree_height) break;
      }
      // if (this->data[x] <= tree_height && i == 0) a++;
      if (i == 0) a++;
    }

    for (std::size_t i = y + 1; i < this->height; ++i)
    {
      b++;
      if (this->data[i * this->width + x] >= tree_height) break;
    }

    if (x != 0)
    {
      for (std::size_t i = x - 1; i != 0; --i)
      {
        c++;
        if (this->data[y * this->width + i] >= tree_height) break;
      }
      // if (this->data[x] <= tree_height) c++;
      if (i == 0) c++;
    }

    for (std::size_t i = x + 1; i < this->width; ++i)
    {
      d++;
      if (this->data[y * this->width + i] >= tree_height) break;
    }

    // up down left right
    return a * b * c * d;
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
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  Grid         grid(input);
  Grid         visibility;
  std::size_t  size = grid.height * grid.width;
  visibility.height = grid.height;
  visibility.width  = grid.width;
  visibility.data   = new std::size_t[size]();
  for (std::size_t y = 0; y < visibility.height; ++y)
    for (std::size_t x = 0; x < visibility.width; ++x)
      visibility.data[x + visibility.width * y] = grid.scenic_score(x, y);

  std::size_t *result = std::max_element(visibility.data, visibility.data + size);
  std::cerr << result - visibility.data << "\n";

  return *result;
}