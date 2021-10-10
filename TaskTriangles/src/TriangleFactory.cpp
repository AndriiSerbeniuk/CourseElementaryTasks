#include "TriangleFactory.hpp"
#include "Triangle.hpp"

ITriangle* TriangleFactory::GetTriangle(
    ITriangleArgsExtractor* extractor) const
{
    std::string name = extractor->ExtractName();
    std::vector<float> sides(extractor->ExtractSides());

    return new Triangle(name, sides[0], sides[1], sides[2]);
}