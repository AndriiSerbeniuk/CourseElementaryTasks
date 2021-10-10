#pragma once
#include "ITriangleFactory.hpp"

class TriangleFactory : public ITriangleFactory
{
public:
    ITriangle* GetTriangle(
        ITriangleArgsExtractor* extractor) const override;
};
