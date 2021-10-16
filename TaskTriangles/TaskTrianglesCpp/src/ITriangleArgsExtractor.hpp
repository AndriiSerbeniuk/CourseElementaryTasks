#pragma once
#include <vector>
#include <string>
#include "IExtractorArgs.hpp"

// Base class for triangle arguments extractors
class ITriangleArgsExtractor
{
public:
    virtual ~ITriangleArgsExtractor() = default;

    virtual std::string ExtractName(const IExtractorArgs* args) const = 0;
    virtual std::vector<float> ExtractSides(const IExtractorArgs* args) const = 0;
};
