#ifndef MYOGA_STRINGS_UTILITY_HPP
#define MYOGA_STRINGS_UTILITY_HPP

#include <stdexcept>

#include <string>
#include <string_view>

#define MYOGA_STRINGIFY(a) MYOGA_STRINGIFY_FIRST_STEP(a)
#define MYOGA_STRINGIFY_FIRST_STEP(a) #a

namespace myoga
{

// Inline functions:
// Is this string really empty?
constexpr auto isEmptyStr(std::string_view str) -> bool;

// Removes every whitespace character from the string (if any)
constexpr auto trimStr(std::string_view str) -> std::string_view;

// Gets the text between token1 and token2
constexpr auto getTextBetween(std::string_view text,
                              std::string_view token1, std::string_view token2,
                              std::size_t startingPos = 0U) -> std::string_view;

// Gets the text from <starting position> to <token>
constexpr auto getTextBetween(std::string_view text, std::size_t startingPos, std::string_view token) -> std::string_view;

// This token MUST BE found, otherwise an exception will be thrown
constexpr auto stringFinder(std::string_view text, std::string_view token,
                            std::size_t fromPosition = 0, bool skipToken = true) -> std::size_t;

// Single char to lowercase
constexpr auto charToLower(char c) -> char;

// String to lowercase
auto lowercase(std::string_view str) -> std::string;

// String -> Boolean
auto boolFromStr(std::string_view str) -> bool;

} // myoga


#endif // MYOGA_STRINGS_UTILITY_HPP
