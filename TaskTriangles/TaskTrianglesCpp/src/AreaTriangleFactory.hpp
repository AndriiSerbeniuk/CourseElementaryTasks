#pragma once
#include "ITriangleFactory.hpp"

// Factory for AreaTriangle objects
class AreaTriangleFactory : public ITriangleFactory
{
public:
    // Returns new AreaTriangle
    ITriangle* GetTriangle(
        const IExtractorArgs* args,
        const ITriangleArgsExtractor* extractor) const override;
};
