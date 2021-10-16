#include "AreaTriangle.hpp"
#include <math.h>

AreaTriangle::AreaTriangle(std::string name, float side1, float side2, float side3) 
    : ITriangle(name, side1, side2, side3), m_area(CountArea()) {}

float AreaTriangle::CountArea() const
{
    // Calculated with Heron's formula
    float p = (m_sides[0] + m_sides[1] + m_sides[2]) / 2;
    return sqrtf(p * (p - m_sides[0]) * (p - m_sides[1]) * (p - m_sides[2]));
}

float AreaTriangle::get_area() const
{
    return m_area;
}

std::string AreaTriangle::get_name() const
{
    return m_name;
}

AreaTriangle::operator std::string() const
{
    return "[" + m_name + "]: " + std::to_string(m_area) + " cm";
}

bool operator > (const AreaTriangle& first, const AreaTriangle& second)
{
    return first.get_area() > second.get_area();
}

bool operator < (const AreaTriangle& first, const AreaTriangle& second)
{
    return first.get_area() < second.get_area();
}

