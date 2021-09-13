#include <iostream>
#include "squared_less_series.h"

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
  for (float f : sls.get_series()) {
    std::cout << f << " ";
  }
  std::cout << "\n";

  sls.set_limit(101);
  for (float f : sls.get_series()) {
    std::cout << f << " ";
  }
  std::cout << "\n";

	return 0;
}