#include "squared_less_series.h"

SquaredLessSeries::SquaredLessSeries() : MutNumSeries() {
  // New here is ok because it's assigned to a smart pointer
  set_validator(new SquaredValidator(series_, bottom_lim_, top_lim_));
}

SquaredLessSeries::SquaredLessSeries(int limit) : MutNumSeries(1, limit) {
  // New here is ok because it's assigned to a smart pointer
  set_validator(new SquaredValidator(series_, bottom_lim_, top_lim_));
  set_limit(limit);
}

SquaredLessSeries::~SquaredLessSeries() {}

void SquaredLessSeries::set_limit(int limit) {
  MutNumSeries::set_top_limit(limit);
}

void SquaredLessSeries::set_limits(float bottom_limit, float top_limit) {}

void SquaredLessSeries::set_top_limit(float limit) {}

void SquaredLessSeries::set_bottom_limit(float limit) {}
