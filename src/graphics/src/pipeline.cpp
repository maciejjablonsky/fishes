#include <graphics/pipeline.hpp>
#include <fmt/format.h>
#include <file/io.hpp>

namespace lake::graphics
{
Pipeline::Pipeline(const std::filesystem::path& vert_path, const std::filesystem::path& frag_path)
{
    create_pipeline(vert_path, frag_path);
}
void Pipeline::create_pipeline(const std::filesystem::path& vert_path,
                                      const std::filesystem::path& frag_path)
{
    const auto vert_code = file::load(vert_path);
    const auto frag_code = file::load(frag_path);
    fmt::print("vertex shader code size: {}\n", vert_code.size());
    fmt::print("fragment shader code size: {}\n", frag_code.size());
}
} // namespace lake::graphics
