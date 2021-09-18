#include "num_series.h"

NumSeries::SeriesNumGenerator::SeriesNumGenerator(std::deque<float>& series, 
	const float& bottom_lim, const float& top_lim) : top_lim_(top_lim),
  bottom_lim_(bottom_lim), series_(series) {}

float NumSeries::SeriesNumGenerator::get_next_top() {
  // Default implementation returns top number + 1
  if (series_.size())
    return series_.back() + 1;
  else
    return 0;
}

float NumSeries::SeriesNumGenerator::get_next_bottom() {
  // Default implementation returns bottom number - 1
  if (series_.size())
    return series_.front() - 1;
  else
    return 0;
}

void NumSeries::SeriesNumGenerator::init_series() {
  series_.clear();
  series_.push_back(0);
}

bool NumSeries::SeriesNumGenerator::can_set_top(float number) const {
  return number <= top_lim_;
}

bool NumSeries::SeriesNumGenerator::can_set_bottom(float number) const {
  return number >= bottom_lim_;
}