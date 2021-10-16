#include "AreaTriangleFactory.hpp"
#include "AreaTriangle.hpp"

ITriangle* AreaTriangleFactory::GetTriangle(
    const IExtractorArgs* args,
    const ITriangleArgsExtractor* extractor) const
{
    std::string name = extractor->ExtractName(args);
    std::vector<float> sides(extractor->ExtractSides(args));

    return new AreaTriangle(name, sides[0], sides[1], sides[2]);
}