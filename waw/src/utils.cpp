#include "utils.hpp"
#include <filesystem>
#include <string>

std::string getAssetPath(const char *path)
{
    return std::filesystem::path(ASSETS_DIR) / path;
}
