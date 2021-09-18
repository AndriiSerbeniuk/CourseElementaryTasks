#include "fibonacci_series.h"

FibonacciSeries::FibonacciGenerator::FibonacciGenerator(std::deque<float>& series,
  const float& bottom, const float& top) 
  : SeriesNumGenerator(series, bottom, top) {}

float FibonacciSeries::FibonacciGenerator::get_next_top() {
  int s_size = series_.size();
  if (s_size < 2) {
    init_series();
  }
  return series_[s_size - 1] + series_[s_size - 2];
}

float FibonacciSeries::FibonacciGenerator::get_next_bottom() {
  if (series_.size() < 2) {
    init_series();
  }
  return series_[1] - series_[0];
}

void FibonacciSeries::FibonacciGenerator::init_series() {
  series_.clear();
  series_.push_front(1);
  series_.push_front(1);
}

bool FibonacciSeries::FibonacciGenerator::can_set_top(float number) const {
  return number <= top_lim_;
}

bool FibonacciSeries::FibonacciGenerator::can_set_bottom(float number) const {
  return number >= bottom_lim_;
}
