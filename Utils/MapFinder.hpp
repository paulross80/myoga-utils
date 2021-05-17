#ifndef MYOGA_UTILS_MAP_FINDER_HPP
#define MYOGA_UTILS_MAP_FINDER_HPP

#include <string>
#include <stdexcept>

namespace myoga
{

// Map item finder
//
// Throws a runtime error exception if no item is found
// Returns constant iterator to the item if it was found
//
// Works with <map> and <unordered_map>
template <typename Container, typename ItemToFind>
auto mapFinder(const Container& cont, const ItemToFind& item, const std::string& errorMessage) -> typename Container::const_iterator
{
    const auto cItr = cont.find(item);

    if (cItr == cont.cend())
        throw std::runtime_error(errorMessage);

    return cItr;
}

} // myoga


#endif // MYOGA_UTILS_MAP_FINDER_HPP
