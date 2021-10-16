#pragma once
#include "IExtractorArgs.hpp"
#include "ITriangleArgsExtractor.hpp"
#include "ITriangle.hpp"

// Base class for triangles factories
class ITriangleFactory
{
public:
    virtual ~ITriangleFactory() = default;

    virtual ITriangle* GetTriangle(
        const IExtractorArgs* args,
        const ITriangleArgsExtractor* extractor) const = 0;

};
