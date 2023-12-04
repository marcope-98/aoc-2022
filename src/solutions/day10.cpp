#include "aoc/solutions/day10.hpp"

#include <iostream>

#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

struct CPU
{
  const std::size_t lut[6] = {20, 60, 100, 140, 180, 220};
  int               X{1};
  std::size_t       cycle{0};

  virtual void noop() { this->cycle++; }
  virtual void addx(const int &V) { this->X += V; }
  bool         is_cycle_interesting() const
  {
    for (std::size_t i = 0; i < 6; ++i)
      if (this->lut[i] == this->cycle)
        return true;
    return false;
  }

  std::size_t signal() const
  {
    if (is_cycle_interesting())
      return std::size_t(this->X) * this->cycle;
    return 0;
  }
};

struct Screen
{
  const std::size_t width  = 40;
  const std::size_t height = 6;
  std::string       crt    = std::string(40 * 6, '.');

  void draw(const CPU &cpu)
  {
    std::size_t x = (cpu.cycle - 1) % 40;
    if (std::size_t(cpu.X) + 1 >= x && x >= std::size_t(cpu.X) - 1)
      this->crt[cpu.cycle - 1] = '#';
  }
};

std::size_t aoc::day10::part1(const std::string &filename)
{
  aoc::vstring input  = aoc::parse::cvt_file_to_vstring(filename);
  std::size_t  result = 0;
  CPU          cpu;
  for (const auto &line : input)
  {
    aoc::vstring temp = aoc::parse::split_by_delimiters(line, " ");
    if (temp.size() == 1)
    {
      cpu.noop();
      result += cpu.signal();
    }
    else
    {
      cpu.noop();
      result += cpu.signal();
      cpu.noop();
      result += cpu.signal();
      cpu.addx(std::stoi(temp[1]));
    }
  }

  return result;
}

std::string aoc::day10::part2(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  CPU          cpu;
  Screen       screen;

  for (const auto &line : input)
  {
    aoc::vstring temp = aoc::parse::split_by_delimiters(line, " ");
    if (temp.size() == 1)
    {
      cpu.noop();
      screen.draw(cpu);
    }
    else
    {
      cpu.noop();
      screen.draw(cpu);
      cpu.noop();
      screen.draw(cpu);
      cpu.addx(std::stoi(temp[1]));
    }
  }
  return screen.crt;
}