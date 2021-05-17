#ifndef MYOGA_TEMPLATE_UTILITIES_HPP
#define MYOGA_TEMPLATE_UTILITIES_HPP

#include <string>
#include <sstream>
#include <stdexcept>

#include "StringUtils.hpp"

namespace myoga
{

// Converts string to <Type>
template <typename Type>
auto convert(const std::string& value) -> Type
{
    Type var;

    if (!(std::istringstream(value) >> var))
        throw std::runtime_error(value + " cannot be converted to the requested type!");

    return var;
}

// bool overload
template <>
inline auto convert(const std::string& value) -> bool
{
    return boolFromStr(value);
}


// Converts string value to <Type> value
// Emplaces the converted value at the end of the container
//
// Supports std::deque, std::vector and std::list (uses emplace_back)
template <typename Container>
void backEmplacer(Container& container, const std::string& value)
{
    typename Container::value_type Type;
    container.emplace_back(convert<decltype(Type)>(value));
}

// ----------------------------------------------------------------------
// Parse comma separated values
// Not intended to be used with strings!
template <typename Container>
auto parseCSV(std::string_view str) -> Container
{
    std::istringstream csv(str.data());
    Container cont;

    for (std::string value; std::getline(csv, value, ','); )
        backEmplacer<Container>(cont, value);

    return cont;
}

// Parse comma separated strings
template <typename Container>
auto parseCSStrings(const std::string& str) -> Container
{
    std::istringstream csv(str);
    Container cont;

    for (std::string value; std::getline(csv, value, ','); )
        cont.emplace_back(std::move(value));

    return cont;
}

} // myoga


#endif // MYOGA_TEMPLATE_UTILITIES_HPP
