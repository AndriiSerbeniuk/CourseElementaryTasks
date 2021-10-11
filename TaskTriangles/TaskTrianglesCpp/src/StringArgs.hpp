#pragma once
#include <string>
#include "IExtractorArgs.hpp"

struct StringArgs : public IExtractorArgs
{
    std::string triangle_text;
};
