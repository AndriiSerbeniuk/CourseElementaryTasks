#include <iostream>
#include "russian_speller.h"

int main(int argc, char* argv[]) {
	if (argc == 1){
    std::cout << "No arguments provided. Pass integer numbers as agruments.\n";
    return 0;
  }
  int num;
  RussianSpeller rs;
  for (int i = 1; i < argc; i++) {
    try {
      num = std::stoi(argv[i]);
    }
    catch (const std::exception& e) {
      std::cout << argv[i] << ": is not an integer.\n";
      continue;
    }
    rs.set_number(num);
    std::cout << num << ": " << rs.get_spelled() << "\n";
  }
	return 0;
}