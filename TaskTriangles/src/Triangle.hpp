#pragma once
#include <string>
#include "ITriangle.hpp"

// A triangle that can count its area
class Triangle : public ITriangle 
{
public:
    Triangle(std::string name, float side1, float side2, float side3);

    float get_area() const;
    std::string get_name() const;

private:
    std::string m_name;
    float m_area;

    float CountArea() const;
};

// To accomodate for storage in sets
bool operator > (const Triangle& first, const Triangle& second);
bool operator < (const Triangle& first, const Triangle& second);
