#include <graphics/application.hpp>
#include <stdexcept>
#include <fmt/format.h>

int main()
{
    lake::Application app;
    try
    {
        app.run();
    }
    catch (const std::exception & e)
    {
        fmt::print(stderr, "Error occured: {}\n", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
