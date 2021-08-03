#pragma once
#include <filesystem>

namespace lake::graphics
{
class Pipeline
{
  public:
    Pipeline(const std::filesystem::path& vert_path, const std::filesystem::path& frag_path);

  private:
    static void create_pipeline(const std::filesystem::path& vert_path,
                                const std::filesystem::path& frag_path);
};
} // namespace lake::graphics
