#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "StringUtils.hpp"

namespace myoga
{

// String to lowercase
auto lowercase(std::string_view str) -> std::string
{
    std::string ret(str);

    for (std::size_t i = 0U; i < ret.length(); i++)
        ret[i] = charToLower(ret[i]);

    return ret;
}


// String -> Boolean
auto boolFromStr(std::string_view str) -> bool
{
    // Why this always returns false???
    //std::istringstream(value.data()) >> std::boolalpha >> boolValue;
    auto lowTrim = myoga::lowercase(myoga::trimStr(str.substr(0, 5)));  // "false" -> 5 chars

    if (lowTrim == "1" || lowTrim == "true")
        return true;

    return false;
}

} // myoga
