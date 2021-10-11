#include "TriangleFactory.hpp"
#include "Triangle.hpp"

ITriangle* TriangleFactory::GetTriangle(
    const IExtractorArgs* args,
    const ITriangleArgsExtractor* extractor) const
{
    std::string name = extractor->ExtractName(args);
    std::vector<float> sides(extractor->ExtractSides(args));

    return new Triangle(name, sides[0], sides[1], sides[2]);
}