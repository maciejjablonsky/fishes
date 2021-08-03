#pragma once
#include <concepts>

namespace math
{
constexpr auto power_two(std::integral auto n)
{
    return 1 << n;
}
}
