#ifndef MYOGA_STRINGS_UTILITY_HPP
#define MYOGA_STRINGS_UTILITY_HPP

#include <stdexcept>

#include <string>
#include <string_view>


// Unnamed namespace
namespace
{

constexpr std::string_view whiteChars(" \t\n\f\r\v");

} // Unnamed namespace


namespace myoga
{

// Inline functions:
// Is this string really empty?
constexpr auto isEmptyStr(std::string_view str) -> bool
{
    auto anything = str.find_first_not_of(whiteChars);

    return (str.empty() || (anything == str.npos));
}

// Removes every whitespace character from the string (if any)
constexpr auto trimStr(std::string_view str) -> std::string_view
{
    if (isEmptyStr(str))
        return {};

    auto first = str.find_first_not_of(whiteChars);
    auto last  = str.find_last_not_of (whiteChars);

    return (last > first ? str.substr(first, last - first + 1) : str.substr(first, 1));
}


// Gets the text between token1 and token2
constexpr auto getTextBetween(std::string_view text,
                              std::string_view token1, std::string_view token2,
                              std::size_t startingPos) -> std::string_view
{
    auto t1Pos = text.find(token1, startingPos);

    if (t1Pos == text.npos)
        throw std::runtime_error("getTextBetween(): token1 not found!");

    t1Pos += token1.length();

    auto t2Pos = text.find(token2, t1Pos);

    if (t2Pos == text.npos)
        throw std::runtime_error("getTextBetween(): token2 not found!");

    return text.substr(t1Pos, t2Pos - t1Pos);
}


// Gets the text from <starting position> to <token>
constexpr auto getTextBetween(std::string_view text, std::size_t startingPos, std::string_view token) -> std::string_view
{
    auto tokenPos = text.find(token, startingPos);

    if (tokenPos == text.npos)
        throw std::runtime_error("getTextBetween(): token not found!");

    return text.substr(startingPos, tokenPos - startingPos);
}


// This token MUST BE found, otherwise an exception will be thrown
constexpr auto stringFinder(std::string_view text, std::string_view token,
                            std::size_t fromPosition, bool skipToken) -> std::size_t
{
    auto pos = text.find(token, fromPosition);

    if (pos == text.npos)
        throw std::runtime_error("stringFinder(): token not found!");

    if (skipToken)
        pos += token.length();

    return pos;
}


// Single char to lowercase
constexpr auto charToLower(char c) -> char
{
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}


// String to lowercase
auto lowercase(std::string_view str) -> std::string;

// String -> Boolean
auto boolFromStr(std::string_view str) -> bool;

} // myoga


#endif // MYOGA_STRINGS_UTILITY_HPP
