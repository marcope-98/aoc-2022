#include "aoc/solutions/day07.hpp"
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"
#include <iostream>
#include <unordered_map>

static bool is_file(const std::string &str) { return str[0] <= '9' && str[0] >= '0'; }

static std::string name(const aoc::vstring &directory)
{
  std::string out;
  for (const auto &dir : directory)
    out += dir + "/";
  return out;
}

static std::unordered_map<std::string, std::size_t> get_filesystem(const aoc::vstring &input)
{
  std::unordered_map<std::string, std::size_t> filetree, dirtree;
  aoc::vstring                                 cwd;
  for (const auto &line : input)
  {
    aoc::vstring command = aoc::parse::split_by_delimiters(line, " ");
    if (command.size() == 3)
    {
      if (command[1] == "ls") continue;
      if (command[2] == "..")
        cwd.pop_back();
      else
      {
        cwd.emplace_back(command[2]);
        dirtree[name(cwd)] = 0;
      }
    }
    else
    {
      if (is_file(command[0]))
        filetree[name(cwd) + command[1]] = std::stoull(command[0]);
    }
  }

  for (const auto &file : filetree)
    for (const auto &dir : dirtree)
      if (file.first.find(dir.first) != std::string::npos)
        dirtree[dir.first] += file.second;

  return dirtree;
}

std::size_t aoc::day07::part1(const std::string &filename)
{
  aoc::vstring input  = aoc::parse::cvt_file_to_vstring(filename);
  std::size_t  result = 0;

  std::unordered_map<std::string, std::size_t> dirtree = get_filesystem(input);

  for (const auto &dir : dirtree)
    if (dir.second <= 100000)
      result += dir.second;

  return result;
}

std::size_t aoc::day07::part2(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);

  std::unordered_map<std::string, std::size_t> dirtree = get_filesystem(input);

  std::size_t result = -1;
  for (const auto &dir : dirtree)
    if (dir.first != "//" && dir.second >= 8381165)
      result = result >= dir.second ? dir.second : result;
  return result;
}