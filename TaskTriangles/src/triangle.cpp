#include "triangle.h"
#include <math.h>

Triangle::Triangle() : name_(), side_a_(0),  side_b_(0),  side_c_(0),
  area_(0) {}

Triangle::Triangle(const std::string triangle) {
  TriangleArgsParser parser;
  try {
    parser.set_raw(triangle);
  }
  catch (const std::invalid_argument& e) {
    throw e;
  }

  name_ = parser.get_name();
  side_a_ = parser.get_side_a();
  side_b_ = parser.get_side_b();
  side_c_ = parser.get_side_c();
  if (side_a_ > side_b_ + side_c_ 
    || side_b_ > side_a_ + side_c_ 
    || side_c_ > side_b_ + side_a_ )
    throw std::invalid_argument("Side of a triangle cannot be greater than sum of two other sides");

  count_area();
}

Triangle::~Triangle() {}

void Triangle::count_area() {
  // Calculated with Heron's formula
  float p = (side_a_ + side_b_ + side_c_) / 2;
  area_ = sqrtf(p * (p - side_a_) * (p - side_b_) * (p - side_c_));
}

float Triangle::get_area() const  {
  return area_;
}

std::string Triangle::get_name() const  {
  return name_;
}

float Triangle::get_side_a() const  {
  return side_a_;
}

float Triangle::get_side_b() const  {
  return side_b_;
}

float Triangle::get_side_c() const  {
  return side_c_;
}

bool operator > (const Triangle& first, const Triangle& second) {
  return first.get_area() > second.get_area();
}

bool operator < (const Triangle& first, const Triangle& second) {
  return first.get_area() < second.get_area();
}
