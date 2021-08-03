#pragma once

#include <vector>
#include <cstddef>
#include <filesystem>

namespace lake::file
{
std::pmr::vector<std::byte> load(const std::filesystem::path& file_path);
}
