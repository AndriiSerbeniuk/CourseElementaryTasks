#pragma once
#include <vector>

class ITriangle
{
public:
    ITriangle(float side1, float side2, float side3);
    virtual ~ITriangle() = default;

protected:
    std::vector<float> m_sides;

    bool AreSidesValid() const;
};
