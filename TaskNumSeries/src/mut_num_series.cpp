#include "mut_num_series.h"
#include <stdexcept>

MutNumSeries::MutNumSeries() 
  : top_lim_(0), bottom_lim_(0), series_(),validator_(nullptr) {}

MutNumSeries::MutNumSeries(float bottom_lim, float top_lim)
  : top_lim_(top_lim), bottom_lim_(bottom_lim), validator_(nullptr) {
    adjust_series();
  }

MutNumSeries::~MutNumSeries() {}

const std::deque<float>& MutNumSeries::get_series() const {
  return series_;
}

void MutNumSeries::set_limits(float bottom_limit, float top_limit) {
  top_lim_ = top_limit;
  bottom_lim_ = bottom_limit;
  adjust_series();
}

void MutNumSeries::set_top_limit(float limit) {
  top_lim_ = limit;
  adjust_series();
}

void MutNumSeries::set_bottom_limit(float limit) {
  bottom_lim_ = limit;
  adjust_series();
}

void MutNumSeries::set_validator(SeriesNumValidator* validator) {
  validator_.reset(validator);
}

void MutNumSeries::adjust_series() {
  if (!validator_.get())
    return;
  if (!series_.size())
    validator_->init_series();
  while (add_top());
  while (add_bottom());
  trim_top();
  trim_bottom(); 
}

bool MutNumSeries::add_top() {
  float add_val = validator_->get_next_top();
  if (validator_->can_set_top(add_val)) {
    series_.push_back(add_val);
    return true;
  }
  return false;
}

bool MutNumSeries::add_bottom() {
  float add_val = validator_->get_next_bottom();
  if (validator_->can_set_bottom(add_val)) {
    series_.push_front(add_val);
    return true;
  }
  return false;
}

void MutNumSeries::trim_top() {
  std::deque<float>::const_iterator i = --series_.cend();
  while (*i > top_lim_)
    i--;
  series_.erase(++i, series_.cend());
}

void MutNumSeries::trim_bottom() {
  std::deque<float>::const_iterator i = series_.cbegin();
  while (*i < bottom_lim_)
    i++;
  series_.erase(series_.cbegin(), i);
}
