#include "aoc/solutions/day03.hpp"
#include "aoc/utils/aliases.hpp"
#include "aoc/utils/parse.hpp"

static std::size_t character_to_size_t(const char character)
{
  if (character <= 'z' && character >= 'a') return std::size_t(character - 'a') + 1;
  if (character <= 'Z' && character >= 'A') return std::size_t(character - 'A') + 27;
  return 0;
}

static std::string find_common(const std::string &elf1, const std::string &elf2)
{
  std::string characters;
  for (const auto &character : elf1)
    if (elf2.find(character) != std::string::npos)
      characters += character;
  return characters;
}

static char badgeID(const std::string &elf1, const std::string &elf2, const std::string &elf3)
{
  std::string common = find_common(elf1, elf2);
  common             = find_common(elf3, common);
  return common[0];
}

std::size_t aoc::day03::part1(const std::string &filename)
{
  vstring     input  = parse::cvt_file_to_vstring(filename);
  std::size_t result = 0;
  for (const auto &elem : input)
  {
    std::size_t half               = elem.size() / 2;
    std::string first_compartment  = elem.substr(0, half);
    std::string second_compartment = elem.substr(half);
    for (const auto &character : first_compartment)
    {
      if (second_compartment.find(character) != std::string::npos)
      {
        result += character_to_size_t(character);
        break;
      }
    }
  }
  return result;
}
std::size_t aoc::day03::part2(const std::string &filename)
{
  vstring     input  = parse::cvt_file_to_vstring(filename);
  std::size_t result = 0;
  for (std::size_t i = 0; i < input.size(); i += 3)
    result += character_to_size_t(badgeID(input[i], input[i + 1], input[i + 2]));

  return result;
}