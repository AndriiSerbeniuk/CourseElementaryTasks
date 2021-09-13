#include "squared_less_series.h"
#include <math.h>

SquaredLessSeries::SquaredValidator::SquaredValidator(std::deque<float>& series,
  const float& bottom, const float& top) : SeriesNumValidator(series, bottom, top) {}

SquaredLessSeries::SquaredValidator::~SquaredValidator() {}

float SquaredLessSeries::SquaredValidator::get_next_bottom() const {
  float next_bottom = SeriesNumValidator::get_next_bottom();
  if (next_bottom > 0)
    return next_bottom;
  return 0;
}

void SquaredLessSeries::SquaredValidator::init_series() {
  series_.push_back(1);
}

bool SquaredLessSeries::SquaredValidator::can_set_top(float number) const {
  return powf(number, 2) < top_lim_;
}

bool SquaredLessSeries::SquaredValidator::can_set_bottom(float number) const {
  return number > 0;
}
