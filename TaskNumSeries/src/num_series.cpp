#include "num_series.h"
#include <stdexcept>

NumSeries::NumSeries() 
  : top_lim_(0), bottom_lim_(0), series_(), generator_(nullptr) {}

NumSeries::NumSeries(float bottom_lim, float top_lim)
  : top_lim_(top_lim), bottom_lim_(bottom_lim), generator_(nullptr) {}

const std::deque<float>& NumSeries::get_series() const {
  return series_;
}

void NumSeries::set_limits(float bottom_limit, float top_limit) {
  top_lim_ = top_limit;
  bottom_lim_ = bottom_limit;
  adjust_series();
}

void NumSeries::set_top_limit(float limit) {
  top_lim_ = limit;
  adjust_series();
}

void NumSeries::set_bottom_limit(float limit) {
  bottom_lim_ = limit;
  adjust_series();
}

void NumSeries::set_generator(SeriesNumGenerator* generator) {
  generator_ = generator;
}

void NumSeries::adjust_series() {
  if (!generator_)
    return;
  if (!series_.size())
    generator_->init_series();
  while (add_top());
  while (add_bottom());
  trim_top();
  trim_bottom(); 
}

bool NumSeries::add_top() {
  float add_val = generator_->get_next_top();
  if (generator_->can_set_top(add_val)) {
    series_.push_back(add_val);
    return true;
  }
  return false;
}

bool NumSeries::add_bottom() {
  float add_val = generator_->get_next_bottom();
  if (generator_->can_set_bottom(add_val)) {
    series_.push_front(add_val);
    return true;
  }
  return false;
}

void NumSeries::trim_top() {
  std::deque<float>::const_iterator i = --series_.cend();
  while (*i > top_lim_)
    i--;
  series_.erase(++i, series_.cend());
}

void NumSeries::trim_bottom() {
  std::deque<float>::const_iterator i = series_.cbegin();
  while (*i < bottom_lim_)
    i++;
  series_.erase(series_.cbegin(), i);
}
