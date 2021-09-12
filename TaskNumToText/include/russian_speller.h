#pragma once
#include "number_speller.h"

// Number speller in russian
class RussianSpeller : public NumberSpeller {
  public:
    RussianSpeller();
    RussianSpeller(int number);
    virtual ~RussianSpeller();

  private:
    // Numbers 0 - 9
    static const std::vector<const char*> kRusOnes;
    // Numbers 10 - 19
    static const std::vector<const char*> kRusTeens;
    // Numbers 20 - 90 with a step of 10
    static const std::vector<const char*> kRusTenths;
    // Numbers 100 - 900 with a step of 100
    static const std::vector<const char*> kRusHundreds;
    // Vectors of higher orders, like thousands or millions
    static const std::vector<const std::vector<const char*>*> kRusOrders;
    // Numbers 1000 - 9000 with a step of 1000
    static const std::vector<const char*> kRusThousands;
    // Numbers 1000000 - 9000000 with a step of 1000000
    static const std::vector<const char*> kRusMillions;
    // Minus in russian
    static const char* kRusMinus;
};