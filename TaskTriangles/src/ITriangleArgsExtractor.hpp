#pragma once
#include <vector>
#include <string>
#include "IExtractorArgs.hpp"

class ITriangleArgsExtractor
{
public:
    virtual ~ITriangleArgsExtractor() = default;

    virtual void SetArgs(const IExtractorArgs*& args) = 0;
    virtual std::string ExtractName() const = 0;
    virtual std::vector<float> ExtractSides() const = 0;
};
