#pragma once
#include "num_series.h"

class FibonacciSeries : public NumSeries {
  public:
    FibonacciSeries();
    FibonacciSeries(int bottom_lim, int top_lim);

  private:
    class FibonacciGenerator : public SeriesNumGenerator {
      public:
        FibonacciGenerator(std::deque<float>& series, const float& bottom, 
          const float& top);
        
        float get_next_top();
        float get_next_bottom();
        void init_series();
        bool can_set_top(float number) const;
        bool can_set_bottom(float number) const;
    };

    FibonacciGenerator fib_generator_;
};