#pragma once
#include <string>
#include <vector>

// Base for number speller classes
class NumberSpeller {
  public:
    NumberSpeller();
    virtual ~NumberSpeller();

    std::string get_spelled() const;
    int get_number() const;
    void set_number(int number);

  protected:
    int number_;  
    std::string spelled_;

    // Assign actual spellings to the spelling vectors
    void assign_spellings(
      const std::vector<const char*>& ones,
      const std::vector<const char*>& teens,
      const std::vector<const char*>& tenths,
      const std::vector<const char*>& hundreds,
      const std::vector<const std::vector<const char*>*>& orders,
      const char* minus);

  private:
    // Vectors that contain numbers' spelling
    // Inherited classes should assign their own spellings to these variables via assing_spellings
    // Numbers 0 - 9
    const std::vector<const char*>* ones_;
    // Numbers 10 - 19
    const std::vector<const char*>* teens_;
    // Numbers 20 - 90 with a step of 10
    const std::vector<const char*>* tenths_;
    // Numbers 100 - 900 with a step of 100
    const std::vector<const char*>* hundreds_;
    // Vectors of higher orders, like thousands or millions
    const std::vector<const std::vector<const char*>*>* orders_;
    // Word for minus
    const char* minus_;

    // Spells the given number
    void spell();
    // Spells a 3 digit number
    void form_3_digit(int num, int order);
    // Spells a 2 digit number
    void form_2_digit(int num, int order);
    // Spells a 1 digit number
    void form_1_digit(int num, int order);
};