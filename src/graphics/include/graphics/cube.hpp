#pragma once
#include <array>
#include <glm/glm.hpp>
#include <math/math.hpp>
namespace graphics
{
template <size_t N = 3> constexpr auto generate_cube_mesh()
{
    std::array<glm::vec<N, float>, math::power_of_two(N)> coords = {};

    for (auto i = 0; i < N; ++i)
    {
    }
    return coords;
}

static_assert(generate_cube_coordinates<2>() == {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}});

class Cube
} // namespace graphics
