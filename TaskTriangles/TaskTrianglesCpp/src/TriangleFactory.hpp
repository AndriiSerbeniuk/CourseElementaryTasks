#pragma once
#include "ITriangleFactory.hpp"

class TriangleFactory : public ITriangleFactory
{
public:
    ITriangle* GetTriangle(
        const IExtractorArgs* args,
        const ITriangleArgsExtractor* extractor) const override;
};
