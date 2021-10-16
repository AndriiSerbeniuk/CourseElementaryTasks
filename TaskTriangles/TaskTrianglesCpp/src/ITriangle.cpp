#include <stdexcept>
#include "ITriangle.hpp"

ITriangle::ITriangle(std::string name, float side1, float side2, float side3) 
    : m_sides(3), m_name(name)
{
    m_sides[0] = side1;
    m_sides[1] = side2;
    m_sides[2] = side3;

    if (!AreSidesValid())
    {
        throw std::invalid_argument("Side of a triangle cannot be greater than sum of two other sides");
    }
}

bool ITriangle::AreSidesValid() const 
{
    return m_sides[0] < m_sides[1] + m_sides[2]
        && m_sides[1] < m_sides[0] + m_sides[2]
        && m_sides[2] < m_sides[1] + m_sides[0];
}