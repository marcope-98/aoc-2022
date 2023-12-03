#include "aoc/solutions/day06.hpp"

// aoc/utils
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

static std::size_t hash(const char ch) { return std::size_t(ch - 'a'); }

static std::size_t detect_sequence(const std::string &datastream, const std::size_t &sequence)
{
  std::size_t hashmap[26] = {0};
  std::string temp        = "";
  for (std::size_t i = 0; i < datastream.size(); ++i)
  {
    if (temp.size() == sequence) return i;
    std::size_t index = hash(datastream[i]);
    if (hashmap[index] == 0)
    {
      hashmap[index]++;
      temp += datastream[i];
    }
    else
    {
      hashmap[hash(temp[0])]--;
      temp.erase(0, 1);
      i -= 1;
    }
  }
  return 0;
}

static std::size_t start_of_package_marker(const std::string &datastream) { return detect_sequence(datastream, 4); }
static std::size_t start_of_message_marker(const std::string &datastream) { return detect_sequence(datastream, 14); }

std::size_t aoc::day06::part1(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  std::string  str   = input[0];
  return start_of_package_marker(str);
}

std::size_t aoc::day06::part2(const std::string &filename)
{
  aoc::vstring input = aoc::parse::cvt_file_to_vstring(filename);
  std::string  str   = input[0];
  return start_of_message_marker(str);
}
