#pragma once
#include <concepts>

namespace math
{
constexpr auto power_of_two(std::integral auto n)
{
    return 1 << n;
}
}
