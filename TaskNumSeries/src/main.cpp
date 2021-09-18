#include <iostream>
#include "squared_less_series.h"
#include "fibonacci_series.h"

void print_series(const NumSeries& s);

int main() {
  // MutNumSeries s(0, 10);
  // for (float f : s.get_series()) {
  //   std::cout << f << " ";
  // }
  // std::cout << "\n";
  
  // s.set_limits(-5, 5);
  // for (float f : s.get_series()) {
  //   std::cout << f << " ";
  // }
  // std::cout << "\n";

  // s.set_limits(-20, -8);
  // for (float f : s.get_series()) {
  //   std::cout << f << " ";
  // }
  // std::cout << "\n";

  SquaredLessSeries sls(20);
  print_series(sls);

  sls.set_limit(101);
  print_series(sls);

  FibonacciSeries fs(1, 100);
  print_series(fs);

  fs.set_limits(-20, 500);
  print_series(fs);

	return 0;
}

void print_series(const NumSeries& s) {
  for (float v : s.get_series()) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}
