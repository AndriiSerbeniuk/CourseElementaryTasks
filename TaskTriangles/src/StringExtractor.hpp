#pragma once
#include "ITriangleArgsExtractor.hpp"
#include "StringArgs.hpp"

class StringExtractor : public ITriangleArgsExtractor
{
public:
    StringExtractor(const StringArgs& args);

    void SetArgs(const IExtractorArgs*& args) override;
    std::string ExtractName() const override;
    std::vector<float> ExtractSides() const override;

private:
    StringArgs m_args;

    float ProcessSide(const std::string& side) const;
    void Trim(std::string& str) const;
};
