#include "squared_less_series.h"
#include <math.h>

SquaredLessSeries::SquaredGenerator::SquaredGenerator(std::deque<float>& series,
  const float& bottom, const float& top) : SeriesNumGenerator(series, bottom, top) {}

float SquaredLessSeries::SquaredGenerator::get_next_bottom() const {
  float next_bottom = SeriesNumGenerator::get_next_bottom();
  if (next_bottom > 0)
    return next_bottom;
  return 0;
}

void SquaredLessSeries::SquaredGenerator::init_series() {
  series_.push_back(1);
}

bool SquaredLessSeries::SquaredGenerator::can_set_top(float number) const {
  return powf(number, 2) < top_lim_;
}

bool SquaredLessSeries::SquaredGenerator::can_set_bottom(float number) const {
  return number > 0;
}
