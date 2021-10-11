#pragma once
#include "ITriangleArgsExtractor.hpp"
#include "StringArgs.hpp"

class StringExtractor : public ITriangleArgsExtractor
{
public:
    std::string ExtractName(const IExtractorArgs* args) const override;
    std::vector<float> ExtractSides(const IExtractorArgs* args) const override;

private:
    float ProcessSide(const std::string& side) const;
    void Trim(std::string& str) const;
};
