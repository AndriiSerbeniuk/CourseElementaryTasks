#pragma once
#include "ITriangleArgsExtractor.hpp"
#include "StringArgs.hpp"

// Triangle args extractor that extracts from std::string
// Args format is: "name, side1, side2, side3" with any amount of whitespaces
class StringArgsExtractor : public ITriangleArgsExtractor
{
public:
    std::string ExtractName(const IExtractorArgs* args) const override;
    std::vector<float> ExtractSides(const IExtractorArgs* args) const override;

private:
    float ProcessSide(const std::string& side) const;
    void Trim(std::string& str) const;
};
