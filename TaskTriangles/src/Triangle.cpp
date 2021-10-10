#include "Triangle.hpp"
#include <math.h>

Triangle::Triangle(std::string name, float side1, float side2, float side3) 
    : ITriangle(side1, side2, side3), m_name(name), m_area(CountArea()) {}

float Triangle::CountArea() const
{
    // Calculated with Heron's formula
    float p = (m_sides[0] + m_sides[1] + m_sides[2]) / 2;
    return sqrtf(p * (p - m_sides[0]) * (p - m_sides[1]) * (p - m_sides[2]));
}

float Triangle::get_area() const
{
    return m_area;
}

std::string Triangle::get_name() const
{
    return m_name;
}

bool operator > (const Triangle& first, const Triangle& second)
{
    return first.get_area() > second.get_area();
}

bool operator < (const Triangle& first, const Triangle& second)
{
    return first.get_area() < second.get_area();
}
