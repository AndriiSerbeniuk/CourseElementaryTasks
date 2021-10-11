#pragma once
#include <vector>
#include <string>
#include "IExtractorArgs.hpp"

class ITriangleArgsExtractor
{
public:
    virtual ~ITriangleArgsExtractor() = default;

    virtual std::string ExtractName(const IExtractorArgs* args) const = 0;
    virtual std::vector<float> ExtractSides(const IExtractorArgs* args) const = 0;
};
