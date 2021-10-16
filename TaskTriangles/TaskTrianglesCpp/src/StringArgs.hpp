#pragma once
#include <string>
#include "IExtractorArgs.hpp"

// Args for StringArgsExtractor
struct StringArgs : public IExtractorArgs
{
    std::string triangle_text;
};
