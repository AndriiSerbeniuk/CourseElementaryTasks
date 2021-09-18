#include "fibonacci_series.h"

FibonacciSeries::FibonacciSeries() : NumSeries(),
  fib_generator_(series_, bottom_lim_, top_lim_) {
    set_generator(&fib_generator_);
}

FibonacciSeries::FibonacciSeries(int bottom_lim, int top_lim)
  : NumSeries(bottom_lim, top_lim), 
  fib_generator_(series_, bottom_lim_, top_lim_) {
    set_generator(&fib_generator_);
    adjust_series();
  }
