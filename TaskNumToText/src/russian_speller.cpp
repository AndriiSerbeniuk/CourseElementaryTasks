#include "russian_speller.h"

const std::vector<const char*> RussianSpeller::kRusOnes {
  "ноль", "один", "два", "три", "четыре", "пять",
  "шесть", "семь", "восемь", "девять"
};

const std::vector<const char*> RussianSpeller::kRusTeens {
  "десять", "одинадцать", "двенадцать", "тринадцать",
  "четырнадцать", "пятнадцать", "шестнадцать",
  "семнадцать", "восемнадцать", "девятнадцать"
};

const std::vector<const char*> RussianSpeller::kRusTenths {
  "", "", "двадцать", "тридцать", "сорок", "пятьдесят",
  "шестьдесят", "семьдесят", "восемьдесят", "девяносто"
};

const std::vector<const char*> RussianSpeller::kRusHundreds {
  "", "сто", "двести", "триста", "четыреста", "пятьсот",
  "шестьсот", "семьсот", "восемьсот", "девятьсот"
};

const std::vector<const char*> RussianSpeller::kRusThousands {
  "тысяч", "одна тысяча", "две тысячи", "три тысячи", "четыре тысячи", 
  "пять тысяч", "шесть тысяч", "семь тысяч", "восемь тысяч", 
  "девять тысяч"
};

const std::vector<const char*> RussianSpeller::kRusMillions {
  "миллионов", "один миллион", "два миллиона", "три миллиона", "четыре миллиона", 
  "пять миллионов", "шесть миллионов", "семь миллионов", 
  "восемь миллионов", "девять миллионов"
};

const char* RussianSpeller::kRusMinus = "минус";

const std::vector<const std::vector<const char*>*> RussianSpeller::kRusOrders {
  &kRusOnes, &kRusThousands, &kRusMillions
};

RussianSpeller::RussianSpeller() : NumberSpeller() {
  assign_spellings(kRusOnes, kRusTeens, kRusTenths, kRusHundreds,
    kRusOrders, kRusMinus);
}

RussianSpeller::RussianSpeller(int number) : NumberSpeller() {
  assign_spellings(kRusOnes, kRusTeens, kRusTenths, kRusHundreds,
    kRusOrders, kRusMinus);
  set_number(number);
}
RussianSpeller::~RussianSpeller() {}