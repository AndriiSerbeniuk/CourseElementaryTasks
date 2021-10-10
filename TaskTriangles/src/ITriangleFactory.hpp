#pragma once
#include "IExtractorArgs.hpp"
#include "ITriangleArgsExtractor.hpp"
#include "ITriangle.hpp"

class ITriangleFactory
{
public:
    virtual ~ITriangleFactory() = default;

    virtual ITriangle* GetTriangle(
        ITriangleArgsExtractor* extractor) const = 0;

};
