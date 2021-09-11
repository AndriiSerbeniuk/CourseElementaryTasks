#pragma once
#include <string>
#include "triangle_args_parser.h"

// A triangle that can count its area
class Triangle {
  public:
    Triangle();
    Triangle(const std::string triangle);
    virtual ~Triangle();

    float get_area() const;
    std::string get_name() const;
    float get_side_a() const;
    float get_side_b() const;
    float get_side_c() const;

	private:
    std::string name_;
    float side_a_;
    float side_b_;
    float side_c_;
    float area_;

    void count_area();
};
// To accomodate for storage in sets
bool operator > (const Triangle& first, const Triangle& second);
bool operator < (const Triangle& first, const Triangle& second);
