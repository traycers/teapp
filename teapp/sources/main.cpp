#include <iostream>
#include <vector>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include "person.hpp"

int main()
{
    Person dd;
    fmt::print("{}\n", dd);
    std::vector<int> v = { 1, 2, 3 };
    fmt::print("{}\n", v);
    return 0;
}