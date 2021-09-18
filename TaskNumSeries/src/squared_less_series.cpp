#include "squared_less_series.h"

SquaredLessSeries::SquaredLessSeries() : NumSeries(),
  sqr_generator_(series_, bottom_lim_, top_lim_) {
    set_generator(&sqr_generator_);
  }

SquaredLessSeries::SquaredLessSeries(int limit) : NumSeries(1, limit),
  sqr_generator_(series_, bottom_lim_, top_lim_) {
  set_generator(&sqr_generator_);
  adjust_series();
}

void SquaredLessSeries::set_limit(int limit) {
  NumSeries::set_top_limit(limit);
}

void SquaredLessSeries::set_limits(float bottom_limit, float top_limit) {}

void SquaredLessSeries::set_top_limit(float limit) {}

void SquaredLessSeries::set_bottom_limit(float limit) {}
