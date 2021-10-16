#pragma once
#include <string>
#include "ITriangle.hpp"

// A triangle that can count its area
class AreaTriangle : public ITriangle 
{
public:
    AreaTriangle(std::string name, float side1, float side2, float side3);

    float get_area() const;
    std::string get_name() const;

    operator std::string() const;

private:
    float m_area;

    // Count triangle's area using Heron's formula
    float CountArea() const;
};

// To accomodate for storage in sets
bool operator > (const AreaTriangle& first, const AreaTriangle& second);
bool operator < (const AreaTriangle& first, const AreaTriangle& second);
