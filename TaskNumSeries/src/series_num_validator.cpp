#include "mut_num_series.h"

MutNumSeries::SeriesNumValidator::SeriesNumValidator(std::deque<float>& series, 
	const float& bottom_lim, const float& top_lim) : top_lim_(top_lim),
  bottom_lim_(bottom_lim), series_(series) {}

MutNumSeries::SeriesNumValidator::~SeriesNumValidator() {}

float MutNumSeries::SeriesNumValidator::get_next_top() const {
  // Default implementation returns top number + 1
  if (series_.size())
    return series_.back() + 1;
  else
    return 0;
}

float MutNumSeries::SeriesNumValidator::get_next_bottom() const {
  // Default implementation returns bottom number - 1
  if (series_.size())
    return series_.front() - 1;
  else
    return 0;
}

void MutNumSeries::SeriesNumValidator::init_series() {
  series_.clear();
  series_.push_back(0);
}

bool MutNumSeries::SeriesNumValidator::can_set_top(float number) const {
  return number <= top_lim_;
}

bool MutNumSeries::SeriesNumValidator::can_set_bottom(float number) const {
  return number >= bottom_lim_;
}