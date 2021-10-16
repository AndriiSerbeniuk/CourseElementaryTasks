#pragma once
#include <vector>

// Base class for triangles/
// Containts sides and name of the triangle
class ITriangle
{
public:
    ITriangle(std::string name, float side1, float side2, float side3);
    virtual ~ITriangle() = default;

protected:
    std::string m_name;
    std::vector<float> m_sides;

    // Returns false if either of the sides is biger than sum of other two
    bool AreSidesValid() const;
};
