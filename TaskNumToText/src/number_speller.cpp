#include "number_speller.h"
#include <math.h>

NumberSpeller::NumberSpeller() : ones_(nullptr), teens_(nullptr), 
  tenths_(nullptr), hundreds_(nullptr), orders_(nullptr),
  number_(0), spelled_() {}

NumberSpeller::~NumberSpeller() {}

std::string NumberSpeller::get_spelled() const {
  return spelled_;
}

int NumberSpeller::get_number() const {
  return number_;
}

void NumberSpeller::set_number(int number) {
  number_ = number;
  spell();
}

void NumberSpeller::assign_spellings(
  const std::vector<const char*>& ones,
  const std::vector<const char*>& teens,
  const std::vector<const char*>& tenths,
  const std::vector<const char*>& hundreds,
  const std::vector<const std::vector<const char*>*>& orders,
  const char* minus) {
    ones_ = &ones;
    teens_ = &teens;
    tenths_ = &tenths;
    hundreds_ = &hundreds;
    orders_ = &orders;
    minus_ = minus;
}

void NumberSpeller::spell() {
  spelled_.clear();
  bool is_neg = number_ < 0;
  // Divide the number into 3 digit numbers
  std::vector<int> hundreds;
  int whole_number = is_neg ? -number_ : number_, cur_number;
  do {
    cur_number = whole_number % 1000;
    whole_number /= 1000;
    if (whole_number || cur_number){
      hundreds.push_back(cur_number);
    }
  } while (whole_number);
  // If it's a zero
  if (!hundreds.size()) {
    form_1_digit(0, 0);
    return;
  }
  int h_size = hundreds.size(), o_size = orders_->size();
  // Spell each number individually
  for (int i = 0; i < h_size && i < o_size; i++) {
    form_3_digit(hundreds[i], i);
  }
  // In case there are no further orders of numbers provided - just write is as a number
  if (h_size > o_size) {
    for (int i = o_size; i < h_size; i++) {
      spelled_ = std::to_string(hundreds[i]) + " " + spelled_;
    }
  }
  // If the number is negative
  if (is_neg)
    spelled_ = minus_ + (" " + spelled_);
}

void NumberSpeller::form_3_digit(int num, int order) {
  int hundred = num / 100, rest = num % 100;
  // Form continuation first
  form_2_digit(rest, order);
  if (hundred) {
    if (!rest && order)
      form_1_digit(0, order);
    spelled_ = (*hundreds_)[hundred] + (" " + spelled_);
  }
}

void NumberSpeller::form_2_digit(int num, int order) {
  int ten = num / 10, one = num % 10;
  switch (ten) {
    case 0:
      // It's just a one digit number
      if (one)  // No need to spell zeros
        form_1_digit(one, order);
      break;
    case 1:
      // It's 10-19
      if (order)
        form_1_digit(0, order);
      spelled_ = (*teens_)[one] + (" " + spelled_);
      break;
    default:
      if (order || one)
        form_1_digit(one, order);
      spelled_ = (*tenths_)[ten] + (" " + spelled_);
      break;
  }
}

void NumberSpeller::form_1_digit(int num, int order) {
  spelled_ = (*(*orders_)[order])[num] + ( " " + spelled_);
}
